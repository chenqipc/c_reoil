cmake_minimum_required(VERSION 3.28)
project(recoil)

set(CMAKE_CXX_STANDARD 17)

add_executable(recoil main.cpp
        WeaponDataAccess.h
        Weapon.cpp
        Weapon.h
        PlayerStats.cpp
        PlayerStats.h
        ScreenCoords.cpp
        ScreenCoords.h
        EventListener.cpp
        EventListener.h)

# 添加 libuiohook 的 include 路径
include_directories(/usr/local/include)

# 链接 libuiohook 库路径
link_directories(/usr/local/lib)