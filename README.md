# Snake clone

## Setup

A few packages are needed to have SDL2 and a C++ compiler.

```sh
sudo apt install -y build-essential libsdl2-dev libsdl2-image-dev
```

Make sure you have CMake installed!

You have to generate your build system of choice. The default for Linux
is "Unix Makefiles"

```sh
cmake -S . -B build
```

To build the project, you can let CMake invoke the build system for you.

```sh
cmake --build build
```

## Running

Running the application is _relatively_ straightforward.

```sh
cd Snake/ && ../build/snake
```

Currently, this is necessary because there are some relative paths
baked into the code requiring the executable be ran from this directory.
