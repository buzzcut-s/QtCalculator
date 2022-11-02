# Overview

> QtCalculator is a simple calculator written in Qt and C++.

QtCalculator is a calculator with the UI written in QML, which is hooked up to a pure C++ backend. It supports the basic mathematical operations. Viewing the calculator history is also implemented.

# Release Build

QtCalculator is built using CMake and requires at least C++17 and Qt 5.13. clang-tidy and clang-format config files are also provided.

QtCreator may additionally be used by opening the CMakeLists.txt file as a project.

```
git clone https://github.com/buzzcut-s/QtCalculator.git
cd QtCalculator/
mkdir build
cd build/
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
cd src/
```

The binary is built in the `QtCalculator/build/src/` directory

QtCalculator was developed to familiarize myself with integrating C++ and QML.

# License

QtCalculator is licensed under the MIT License, © 2022 Piyush Kumar. See [LICENSE](https://github.com/buzzcut-s/QtCalculator/blob/main/LICENSE) for more details.
