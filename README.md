# Description
You can see information about the task in **info.md**.
# Build
This application requires following libraries:
- Qt5  
- [Boost](https://sourceforge.net/projects/boost/files/boost-binaries/1.83.0/boost_1_83_0-msvc-14.3-64.exe/download)

Also compiler required that supports C++23 features. For example [g++](http://www.equation.com/servlet/equation.cmd?fa=fortran). Download ***latest*** version!  
Install [CMake](https://cmake.org/download/) after this.
## Windows
First install [Ninja](https://github.com/ninja-build/ninja/releases) and add it's executable to PATH variable.  
Then go to project directory and execute in powershell the next script.
```sh
mkdir build
cd build
cmake -G Ninja ..
cmake -S ../ -B .
cmake --build . 
```
After this you should see **aps** executable in build directory.
## Linux
Install cmake on linux and just go with
```bash
mkdir build
cd build
cmake -S ../ -B .
cmake --build . 
```
After this you should see **aps** executable in build directory.
