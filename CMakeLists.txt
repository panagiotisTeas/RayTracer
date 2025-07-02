cmake_minimum_required(VERSION 3.16)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Production build -> True : Shipping
# Changes RESOURCES_PATH to be the local path
# Delete build folder after changing
set(PRODUCTION_BUILD OFF CACHE BOOL "Production build" FORCE)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")     # statically linked, multi-threaded debug runtime
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>") # statically linked, multi-threaded release runtime

#* Link time optimization for production build
if(PRODUCTION_BUILD)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)
endif()

# SIMD optimizations
if(MSVC)
add_compile_options(/arch:AVX2)
endif()

project(ray_tracer
    VERSION 0.1.0
    LANGUAGES C CXX)

# --- Testing ---
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2
)

FetchContent_MakeAvailable(Catch2)
# --- Testing ---

# GLFW CMake cache options
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# external libraries
add_subdirectory(external/glfw-3.3.2)
add_subdirectory(external/glad)
add_subdirectory(external/imgui-docking)
add_subdirectory(external/stb_image)

# ============================
# === Core Library (No GL) ===
# ============================

# Add only testable, non-GL source files (math, utils, etc.)
file(GLOB_RECURSE CORE_SRCS
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/*.cpp
    # Add more logic paths here
)

add_library(ray_tracer_lib STATIC ${CORE_SRCS})
target_include_directories(ray_tracer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# =======================
# === Main Application ===
# =======================

file(GLOB_RECURSE WIN_SRCS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/window/*.cpp)
file(GLOB_RECURSE PPM_SRCS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/ppm/*.cpp)
set(MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(ray_tracer)
set_property(TARGET ray_tracer PROPERTY CXX_STANDARD 17)

target_compile_definitions(ray_tracer PUBLIC GLFW_INCLUDE_NONE=1)

if(PRODUCTION_BUILD)
    target_compile_definitions(ray_tracer PUBLIC RESOURCES_PATH=./res/)
    target_compile_definitions(ray_tracer PUBLIC PRODUCTION_BUILD=1)
else()
    target_compile_definitions(ray_tracer PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/")
    target_compile_definitions(ray_tracer PUBLIC PRODUCTION_BUILD=0)
endif()

target_sources(ray_tracer PRIVATE ${MAIN_SRC} ${WIN_SRCS} ${PPM_SRCS})
target_include_directories(ray_tracer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_link_libraries(ray_tracer PRIVATE
    ray_tracer_lib
    glfw glad stb_image imgui)

if(MSVC)
    target_compile_definitions(ray_tracer PUBLIC _CRT_SECURE_NO_WARNINGS)
    set_target_properties(ray_tracer PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()

# =============
# === Tests ===
# =============

file(GLOB_RECURSE TEST_SRCS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

add_executable(tests ${TEST_SRCS})
target_link_libraries(tests PRIVATE ray_tracer_lib Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

include(CTest)
include(Catch)
catch_discover_tests(tests)