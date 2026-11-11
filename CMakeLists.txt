cmake_minimum_required(VERSION 3.21)

project(ImmersiveActivate VERSION 1.4.1 LANGUAGES CXX)

find_package(CommonLibSSE CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(xbyak CONFIG REQUIRED)

# clib-util is header-only; extern/CLibUtil is pinned to the commit in cmake/ports/clib-util.
add_commonlibsse_plugin(${PROJECT_NAME}
    AUTHOR "dann1"
    SOURCES src/Manager.cpp src/PCH.cpp src/Settings.cpp src/Renamer.cpp src/main.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_include_directories(${PROJECT_NAME} PRIVATE src extern/CLibUtil/include)
target_precompile_headers(${PROJECT_NAME} PRIVATE src/PCH.h)
target_compile_definitions(${PROJECT_NAME} PRIVATE SKSE_SUPPORT_XBYAK)
