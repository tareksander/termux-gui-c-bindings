#include <termuxgui/termuxgui.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


#include <EGL/egl.h>
#include <EGL/eglext.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>


/*
Not every single EGL and GLES call is documented here.
If you want to know about specific calls check:
- The EGL specification: https://registry.khronos.org/EGL/specs/eglspec.1.4.pdf
- The GLESv2 specification: https://registry.khronos.org/OpenGL/specs/es/2.0/es_full_spec_2.0.pdf
- The GLES shading language specification for the shaders(though the shaders are very simple
   in this example, a tutorial for GLES shading language should suffice instead of the specification):
    https://registry.khronos.org/OpenGL/specs/es/2.0/GLSL_ES_Specification_1.00.pdf
The EGL extensions:
- EGL_KHR_image_base: https://registry.khronos.org/EGL/extensions/KHR/EGL_KHR_image_base.txt
- EGL_ANDROID_image_native_buffer: https://registry.khronos.org/EGL/extensions/ANDROID/EGL_ANDROID_image_native_buffer.txt
- EGL_ANDROID_get_native_client_buffer: https://registry.khronos.org/EGL/extensions/ANDROID/EGL_ANDROID_get_native_client_buffer.txt
The GLES extensions:
- GL_OES_EGL_image: https://registry.khronos.org/OpenGL/extensions/OES/OES_EGL_image.txt
*/



// convenience function to exit when an gles error is encountered
static void checkGLError(const char* function) {
    GLint err = glGetError();
    if (err != GL_NO_ERROR) {
        printf("%s: 0x%x\n", function, err);
        exit(1);
    }
}

// creates a shader of a specific type from source, to not duplicate the code for both the
// vertex and fragment shader
static GLuint createShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    checkGLError("glCreateShader");
    glShaderSource(shader, 1, &source, NULL);
    checkGLError("glShaderSource");
    glCompileShader(shader);
    checkGLError("glCompileShader");
    GLint compiled = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    checkGLError("glGetShaderiv");
    if (compiled != GL_TRUE) {
        GLint len;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
        checkGLError("glGetShaderiv");
        char* log = calloc(len, 1);
        glGetShaderInfoLog(shader, len, NULL, log);
        checkGLError("glGetShaderInfoLog");
        printf("Shader compilation error:\nshader source:\n%s\nCompilation log:\n%s\n", source, log);
        exit(1);
    }
    return shader;
}


int main() {
    
    tgui_connection c;
    if (tgui_connection_create(&c) != 0) {
        puts("error connection create\n");
        exit(1);
    }
    
    tgui_activity a;
    if (tgui_activity_create(c, &a, TGUI_ACTIVITY_NORMAL, NULL, false) != 0) {
        puts("error activity create\n");
        exit(1);
    }
    
    
    
    tgui_view sv = -1;
    // create 2 buffers, so we have a back buffer to draw to and a front buffer that is shown.
    tgui_hardware_buffer hb1, hb2;
    if (tgui_hardware_buffer_create(c, &hb1, TGUI_HARDWARE_BUFFER_FORMAT_RGBX8888, 500, 500, TGUI_HARDWARE_BUFFER_CPU_NEVER, TGUI_HARDWARE_BUFFER_CPU_NEVER) != 0) {
        puts("error hardware buffer create\n");
        exit(1);
    }
    if (tgui_hardware_buffer_create(c, &hb2, TGUI_HARDWARE_BUFFER_FORMAT_RGBX8888, 500, 500, TGUI_HARDWARE_BUFFER_CPU_NEVER, TGUI_HARDWARE_BUFFER_CPU_NEVER) != 0) {
        puts("error hardware buffer create\n");
        exit(1);
    }
    
    // initialize EGL
    EGLDisplay d = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (d == EGL_NO_DISPLAY) {
        printf("No egl display\n");
        exit(1);
    }
    
    EGLint major, minor;
    if (! eglInitialize(d, &major, &minor)) {
        printf("eglInitialize: 0x%x\n", eglGetError());
        exit(1);
    }
    // check for requirements
    if (major != 1 || minor < 2) {
        printf("Too old EGL version: %d.%d\n", major, minor);
        exit(1);
    }
    const char* eglExts = eglQueryString(d, EGL_EXTENSIONS);
    if (eglExts == NULL) {
        printf("eglQueryString: 0x%x\n", eglGetError());
        exit(1);
    }
    if (strstr(eglExts, "EGL_KHR_image_base") == NULL) {
        printf("EGL extension EGL_KHR_image_base not found\n");
        exit(1);
    }
    if (strstr(eglExts, "EGL_ANDROID_image_native_buffer") == NULL) {
        printf("EGL extension EGL_ANDROID_image_native_buffer not found\n");
        exit(1);
    }
    if (strstr(eglExts, "EGL_ANDROID_get_native_client_buffer") == NULL) {
        printf("EGL extension EGL_ANDROID_get_native_client_buffer not found\n");
        exit(1);
    }
    // get extension functions
    PFNEGLCREATEIMAGEKHRPROC createImage = (PFNEGLCREATEIMAGEKHRPROC) eglGetProcAddress("eglCreateImageKHR");
    PFNEGLDESTROYIMAGEKHRPROC destroyImage = (PFNEGLDESTROYIMAGEKHRPROC) eglGetProcAddress("eglDestroyImageKHR");
    PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC getClientBuffer = (PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC) eglGetProcAddress("eglGetNativeClientBufferANDROID");
    PFNGLEGLIMAGETARGETRENDERBUFFERSTORAGEOESPROC imageTargetRenderbufferStorage = (PFNGLEGLIMAGETARGETRENDERBUFFERSTORAGEOESPROC) eglGetProcAddress("glEGLImageTargetRenderbufferStorageOES");
    
    
    
    
    
    
    
    // choose a matching config
    const EGLint configAttribs[] = {
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_COLOR_BUFFER_TYPE, EGL_RGB_BUFFER,
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_NONE
    };
    EGLConfig config;
    EGLint configSize;
    
    if (! eglChooseConfig(d, configAttribs, &config, 1, &configSize)) {
        printf("eglChooseConfig: 0x%x\n", eglGetError());
        exit(1);
    }
    if (configSize == 0) {
        printf("no matching EGL config found\n");
        exit(1);
    }
    
    // create an GLES2 context
    if (! eglBindAPI(EGL_OPENGL_ES_API)) {
        printf("eglBindAPI: 0x%x\n", eglGetError());
        exit(1);
    }
    
    const EGLint contextAttribs[] = {
        EGL_CONTEXT_MAJOR_VERSION, 2,
        EGL_NONE
    };
    EGLContext gles2 = eglCreateContext(d, config, NULL, contextAttribs);
    if (gles2 == EGL_NO_CONTEXT) {
        printf("eglCreateContext: 0x%x\n", eglGetError());
        exit(1);
    }
    // Create a dummy framebuffer, so the context can be activated.
    // You need an EGLSurface to make the context current, but you can't convert a
    // HardwareBuffer to an EGLSurface.
    // So we instead create a dummy 1x1 surface and then create 2 framebuffers ourselves
    // for the 2 HardwareBuffers.
    const EGLint pbufferAttribs[] = {
        EGL_WIDTH, 1,
        EGL_HEIGHT, 1,
        EGL_NONE
    };
    EGLSurface dummySurface = eglCreatePbufferSurface(d, config, pbufferAttribs);
    if (dummySurface == EGL_NO_SURFACE) {
        printf("eglCreatePbufferSurface: 0x%x\n", eglGetError());
        exit(1);
    }
    
    // activate the GLES2 context
    if (! eglMakeCurrent(d, dummySurface, dummySurface, gles2)) {
        printf("eglMakeCurrent: 0x%x\n", eglGetError());
        exit(1);
    }
    
    // check for required GLES2 extensions
    const char* glesExts = (const char*) glGetString(GL_EXTENSIONS);
    checkGLError("glGetString");
    if (glesExts == NULL || strstr(glesExts, "GL_OES_EGL_image") == NULL) {
        printf("GLES2 doesn't support the GL_OES_EGL_image extension\n");
        exit(1);
    }
    
    // basic gles setup
    glClearColor(0.2, 0.2, 0.2, 1);
    checkGLError("glClearColor");
    glViewport(0, 0, 500, 500);
    checkGLError("glViewport");
    
    // Create EGLImages for the buffers
    
    EGLint imageAttribs[] = {EGL_IMAGE_PRESERVED_KHR, EGL_TRUE, EGL_NONE};
    
    EGLClientBuffer cb1 = getClientBuffer(hb1.buffer), cb2 = getClientBuffer(hb2.buffer);
    EGLImage img1 = createImage(d, EGL_NO_CONTEXT, EGL_NATIVE_BUFFER_ANDROID, cb1, imageAttribs);
    if (img1 == EGL_NO_IMAGE_KHR) {
        printf("eglCreateImageKHR: 0x%x\n", eglGetError());
        exit(1);
    }
    EGLImage img2 = createImage(d, EGL_NO_CONTEXT, EGL_NATIVE_BUFFER_ANDROID, cb2, imageAttribs);
    if (img2 == EGL_NO_IMAGE_KHR) {
        printf("eglCreateImageKHR: 0x%x\n", eglGetError());
        exit(1);
    }
    
    
    // create a new framebuffer for each image
    glBindFramebuffer(GL_FRAMEBUFFER, 1);
    checkGLError("glBindFramebuffer");
    glBindRenderbuffer(GL_RENDERBUFFER, 1);
    checkGLError("glBindRenderbuffer");
    imageTargetRenderbufferStorage(GL_RENDERBUFFER, img1);
    checkGLError("glEGLImageTargetRenderbufferStorageOES");
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, 1);
    checkGLError("glFramebufferRenderbuffer");
    
    glBindFramebuffer(GL_FRAMEBUFFER, 2);
    checkGLError("glBindFramebuffer");
    glBindRenderbuffer(GL_RENDERBUFFER, 2);
    checkGLError("glBindRenderbuffer");
    imageTargetRenderbufferStorage(GL_RENDERBUFFER, img2);
    checkGLError("glEGLImageTargetRenderbufferStorageOES");
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, 2);
    checkGLError("glFramebufferRenderbuffer");
    
    
    
    
    int currentBuffer = 2;
    
    
    // create program
    
    GLuint prog = glCreateProgram();
    checkGLError("glCreateProgram");
    
    // The vertex shader just passes the 2D position on to the vertex processing as-is.
    GLuint vert = createShader(GL_VERTEX_SHADER, "#version 100\n"
    "attribute vec2 pos;\n"
    "void main() {\n"
    "  gl_Position = vec4(pos, 0.0, 1.0);\n"
    "}\n");
    
    // The fragment shader sets the pixel to fully red opaque.
    GLuint frag = createShader(GL_FRAGMENT_SHADER, "#version 100\n"
    "precision mediump float;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n");
    
    
    glAttachShader(prog, vert);
    checkGLError("glAttachShader");
    glAttachShader(prog, frag);
    checkGLError("glAttachShader");
    
    glLinkProgram(prog);
    GLint linked = GL_FALSE;
    glGetProgramiv(prog, GL_LINK_STATUS, &linked);
    checkGLError("glGetProgramiv");
    if (linked != GL_TRUE) {
        GLint len;
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
        checkGLError("glGetProgramiv");
        char* log = calloc(len, 1);
        glGetProgramInfoLog(prog, len, NULL, log);
        checkGLError("glGetProgramInfoLog");
        printf("Program linking error:\nLinking log:\n%s\n", log);
        exit(1);
    }
    
    
    glUseProgram(prog);
    checkGLError("glUseProgram");
    
    
    GLuint posI = glGetAttribLocation(prog, "pos");
    checkGLError("glGetAttribLocation");
    glEnableVertexAttribArray(posI);
    checkGLError("glEnableVertexAttribArray");
    
    
    
    // animation progress
    int progress = 0;
    
    // pause when the Activity isn't visible
    bool paused = true;
    time_t start = time(NULL);
    while (true) {
        tgui_event e;
        bool available;
        do {
            if (tgui_poll_event(c, &e, &available) != 0) {
                puts("error poll\n");
                exit(1);
            }
            if (available) {
                
                if (e.type == TGUI_EVENT_CREATE) {
                    // Activity created, we can create the ImageView now
                    if (sv == -1) {
                        if (tgui_create_surface_view(c, a, &sv, NULL, TGUI_VIS_VISIBLE, true) != 0) {
                            puts("error create SurfaceView\n");
                            exit(1);
                        }
                        if (tgui_surface_view_config(c, a, sv, 0xffffffff, TGUI_MISMATCH_STICK_TOPLEFT, TGUI_MISMATCH_STICK_TOPLEFT, 30) != 0) {
                            puts("error SurfaceView config\n");
                            exit(1);
                        }
                        tgui_send_touch_event(c, a, sv, true);
                        tgui_focus(c, a, sv, true);
                    }
                    paused = false;
                }
                // pause and resume the animation on pause/resume
                if (e.type == TGUI_EVENT_PAUSE) {
                    paused = true;
                }
                if (e.type == TGUI_EVENT_RESUME) {
                    paused = false;
                }
                
                if (e.type == TGUI_EVENT_DESTROY) {
                    exit(0);
                }
                if (e.type == TGUI_EVENT_KEY) {
                    printf("key: %c\n", (char) e.key.codePoint);
                }
                if (e.type == TGUI_EVENT_TOUCH && e.touch.action == TGUI_TOUCH_DOWN) {
                    puts("touch down\n");
                    tgui_focus(c, a, sv, true);
                }
                if (e.type == TGUI_EVENT_TOUCH && e.touch.action == TGUI_TOUCH_MOVE) {
                    printf("move: x: %d, y: %d\n", e.touch.pointers[0][0].x, e.touch.pointers[0][0].y);
                }
                
                tgui_event_destroy(&e);
            }
        } while (available);
        // if the SurfaceView is created and we aren't paused, render the animation
        if (sv != -1 && ! paused) {
            float x = -1.0f + ((float)progress)/50.0f;
            float y = 1.0f - ((float)progress)/50.0f;
            const GLfloat vertices[] = {
                x, y,
                x + 0.2f, y,
                x, y - 0.2f,
                x + 0.2f, y - 0.2f
            };
            glClear(GL_COLOR_BUFFER_BIT);
            checkGLError("glClear");
            glVertexAttribPointer(posI, 2, GL_FLOAT, false, 0, vertices);
            checkGLError("glVertexAttribPointer");
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
            checkGLError("glDrawArrays");
            // set the next buffer to use and set the SurfaceView to display
            // the buffer that was just drawn to.
            tgui_hardware_buffer* setHb;
            if (currentBuffer == 2) {
                currentBuffer = 1;
                setHb = &hb2;
            } else {
                setHb = &hb1;
                currentBuffer = 2;
            }
            glBindFramebuffer(GL_FRAMEBUFFER, currentBuffer);
            checkGLError("glBindFramebuffer");
            
            glFlush();
            checkGLError("glFlush");
            
            if (tgui_surface_view_set_buffer(c, a, sv, setHb) != 0) {
                puts("error setbuffer\n");
                exit(1);
            }
            // loop the animation
            progress++;
            if (progress > 100) {
                progress = 1;
            }
        }
        usleep(15000);
    }
    
    // you should destroy all resources in GLES and EGL here, but the program exits directly after, so it doesn't matter
    
    tgui_connection_destroy(c);
    
    return 0;
}




