# Virtual Pet

This is a virtual pet coded in **C++** as an interactive pet for YouTube streams.
You can interact, change the **code/art**, and feel free to **fork** and **port**.

Some ideas were suggested by live chat.

**Streams**  
<a href="https://www.youtube.com/watch?v=gCGUQKaPO1M">First Stream</a>
<a href="https://www.youtube.com/watch?v=8KaYNM7taxQ&t=915s">Second Stream</a>

## Build & Run (Windows, VS2022 + vcpkg)

> One-time tools: **Visual Studio 2022 Build Tools**, **CMake ≥ 3.21**.  
> vcpkg is included as a git submodule.

```bash
# 1) Clone with submodule
git clone --recurse-submodules https://github.com/austridg/virtual-pet.git
cd virtual-pet

# 2) Bootstrap vcpkg (first time on a machine)
.\vcpkg\bootstrap-vcpkg.bat

# 3) Configure & build (Visual Studio generator)
cmake --preset win-vs2022
cmake --build --preset win-vs2022 --config Release

# 4) Run
.\build\win-vs2022\Release\virtual-pet.exe