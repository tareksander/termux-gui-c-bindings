# Tutorial


Make sure you installed the library like explained in the README.  
This tutorial assumes you have the basic understanding of the Android GUI from the [crash course](https://github.com/tareksander/termux-gui#using-the-plugin).  


[C Tutorial](#ctut)<!-- @IGNORE PREVIOUS: anchor -->  
<!--[C++ Tutorial](#cpptut)<!-- @IGNORE PREVIOUS: anchor -->

<!--The main difference is that the C++ API is object-oriented an the C one is not.  -->



## <a name="ctut"></a>C Tutorial


### Hello World

Initializing the library, displaying "Hello World" and deinitializing.


[hello_world.c](tutorial/c/hello_world.c)


### Hello Activity

Starting an Activity and exiting when it's closed.


[hello_activity.c](tutorial/c/hello_activity.c)


### Hello TextView

Showing text in a TextView.


[hello_textview.c](tutorial/c/hello_textview.c)


### Hello Reactivity

Reacting to a button press to change the text of a TextView.

[hello_reactivity.c](tutorial/c/hello_reactivity.c)



### Hello ScrollView

Using NestedScrollView for content longer than the screen.

[hello_scrollview.c](tutorial/c/hello_scrollview.c)



### Special Activity Events

It is possible to intercept the default behavior of the volume buttons and the back button and get an event instead.  
Also includes setting the Activity to fullscreen mode.


[activity_events.c](tutorial/c/activity_events.c)


### Text Input

Using EditText to get text input from the user, and also introducing dialog Activities.






### Checkboxes & More

Using toggleable Views like RadioButton, CheckBox, Switch and ToggleButton.






### Images

Using ImageViews to display images.






### Buffers + SDL

Using a shared buffer to display images and drawing into it with SDL.  
This requires the X11 repo to be enabled and SDL to be installed.  
  
You have to use the `-lSDL2` compiler option to link to SDL2.


[buffer_sdl.c](tutorial/c/buffer_sdl.c)


### Refreshing, Tabs & HorizontalScrollView


Using swipe-to-refresh for swipable tabs in a HorizontalScrollView that can also be navigated with tabs in a TabLayout.




### Lockscreen Activites, Unlocking and Spinners

Displaying an Activity on the lockscreen, selecting text options with a Spinner, turning on the screen and requesting an unlock.





### ProgressBar, Text Gravity, Margins & Paddings, Dynamic Layouts

Using a ProgressBar, setting text gravity for better alignment, using margins and paddings for alignment and layouting and modifying the layout at runtime.





### Notifications

Posting notifications and different notification types.





### RemoteViews and Widgets

Using remote layouts to display content in a widget.





### WebView

Using WebView to display web content.





### Hardware Accelerated Rendering

It's possible to share a GPU buffer with the plugin for hardware accelerated rendering on Android 8.0 and higher. Your EGL and GLES2 implementations have to also support some extensions though, so support isn't guaranteed.  
  
You have to compile the example with the `-lEGL -lGLESv2` compiler options to link against EGL and GLES2.  
If you have Mesa installed, you have to run `LD_PRELOAD='/system/lib/:/system/lib64/' buffer_gl` to run the example, because otherwise the Mesa libraries take priority over the Android ones. Also try that if you get an error about the EGL extension `EGL_ANDROID_image_native_buffer` missing.  
  
Additionally, the example assumes basic familiarity with graphics APIs in general and EGL and OpenGL ES2 specifically.

[buffer_gl.c](tutorial/c/buffer_gl.c)








<!--## <a name="cpptut"></a>C++ Tutorial-->





 
