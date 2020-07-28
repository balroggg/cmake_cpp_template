# CMake cpp project template

## Supported tools:
* [CPM.cmake](https://github.com/TheLartians/CPM.cmake)
* clang-format
* clang-tidy

## How to build:
```
mkdir build && cd build
cmake .. -GNinja
ninja
```

## Directories:
```
tree
.
├── CMakeLists.txt
├── LICENSE
├── README.md
├── srcs
│   └── hello_world.cpp
└── tests
    └── test.cpp
```
