# GDExample

How to build the GDExtension (using Godot 4.1):

```sh
cd godot-cpp
git submodule update --init
scons platform=<platform> -j16
cd ..
scons platform=<platform>
```
Note: `-j16` indicates that you CPU can use 16 threads

`<platform>` can be `windows`, `macos` or `linux`.

Then, open the Godot proyect in `demo` folder.

To use another version of Godot, read the official Godot documentation on using C++ GDExtensions

