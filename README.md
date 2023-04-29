# Termux:GUI C/C++ Bindings
A C/C++ library to interact with the Termux:GUI plugin.

This is currently only a static library, so you only need to install it to compile software using it.

[HTML Documentation](https://tareksander.github.io/termux-gui-c-bindings/html/index.html)  
  
[Tutorial](TUTORIAL.md)

## Features

[x] View creation  
[x] Activity functions  
[x] Task functions  
[x] Global functions  
[x] ImageView & Buffer  
[x] Events  
[x] Event control  
[x] WebView  
[x] View functions  
[x] RemoteViews, Widgets, Notifications  
[x] GLES2 accelerated rendering with SurfaceView


## Installation

### From source (on device only)

You have to clone the repository configure cmake and install:

```bash
pkg install git build-essential protobuf-static # install git, clang, protobuf-static and cmake if not installed
git clone "https://github.com/tareksander/termux-gui-c-bindings.git" # clone the repository
cd termux-gui-c-bindings # go into the repository
cmake . -DCMAKE_INSTALL_PREFIX="$PREFIX" # configure cmake with the Termux prefix
make install # install
```


### As a package (on device only)

Run `pkg install termux-gui-c` once the package is included in the repositories.


## Usage

### On device or using the [termux-packages repo](https://github.com/termux/termux-packages)

Just use it like a normal C/C++ library.


### From source

Include this repository as a submodule or any other way.

## License

The license is the [Mozilla Public License 2.0](https://www.mozilla.org/en-US/MPL/2.0/).  
TL;DR: You can use this library in your own projects, regardless of the license you choose for it. Modifications to this library have to be published under the MPL 2.0 (or a GNU license in some cases) though.


