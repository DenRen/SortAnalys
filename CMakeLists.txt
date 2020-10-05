cmake_minimum_required(VERSION 3.14)
project(SortAnalys)

set(CMAKE_CXX_FLAGS)
set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "/usr/include/SFML")
set(SFML_LIBRARY_DIR "/usr/lib/SFML")

link_directories (SFML_LIBRARY_DIR)
include_directories (SFML_INCLUDE_DIR)

add_executable(SortAnalys main.cpp
                          widget.h            widget.cpp
                          point.h             point.cpp
                          MyWindow.h
                          WinApp.h            WinApp.cpp
                          MyFuncs.h           MyFuncs.cpp
                          GraphicsSettings.h  GraphicsSettings.cpp GraphicMgrs.cpp GraphicMgrs.h MySorts.h MySorts.cpp)

target_link_libraries (SortAnalys sfml-graphics sfml-window sfml-system sfml-audio)