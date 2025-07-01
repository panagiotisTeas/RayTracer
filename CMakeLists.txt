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

# list of all source files
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

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

target_sources(ray_tracer PRIVATE ${SRCS})

if(MSVC) # If using the VS compiler...
	target_compile_definitions(ray_tracer PUBLIC _CRT_SECURE_NO_WARNINGS)
	set_target_properties(ray_tracer PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") #no console
endif()

target_include_directories(ray_tracer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

target_link_libraries(ray_tracer PRIVATE
    glfw glad stb_image imgui)