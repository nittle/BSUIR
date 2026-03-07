# Compilation Commands

This file contains the commands to compile the Restaurant Dish Tracking System using different compilers.

## MSBuild

To build the project using MSBuild (best used within the **Developer Command Prompt**):

```powershell
msbuild restaurant_dish_tracking_system.vcxproj /p:Configuration=Debug /p:Platform=x64
```

To run the compiled executable from CMD:
```cmd
.\x64\Debug\restaurant_dish_tracking_system.exe
```

## Clang

To build the project using Clang:

```powershell
clang++ -std=c++20 main.cpp cli.cpp dish_tracking_lib/*.cpp -o dish_tracking_system.exe
```

To run the compiled executable from CMD:
```cmd
.\dish_tracking_system.exe
```

## MSVC (cl.exe)

To build the project directly using the MSVC compiler (best used within the **Developer Command Prompt**):

```powershell
cl /EHsc /std:c++20 main.cpp cli.cpp dish_tracking_lib\*.cpp /Fe:dish_tracking_system.exe
```

To run the compiled executable from CMD:
```cmd
.\dish_tracking_system.exe
```
