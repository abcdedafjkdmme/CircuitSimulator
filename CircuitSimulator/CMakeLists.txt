cmake_minimum_required(VERSION 3.22)
project(CircuitSimulatorLibProj)


file(GLOB_RECURSE CIRCUIT_SIM_LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.h ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp)

add_library(CircuitSimulatorLib STATIC ${CIRCUIT_SIM_LIB_SOURCES})
target_include_directories(CircuitSimulatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Core ${CMAKE_CURRENT_SOURCE_DIR}/Core/Engine ${CMAKE_CURRENT_SOURCE_DIR}/Core/NElectro ${CMAKE_CURRENT_SOURCE_DIR}/Core/Physics ${CMAKE_CURRENT_SOURCE_DIR}/Core/SDLWrapper)




add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/External/SDL2)
if(MSVC)
    set_property(TARGET SDL2 PROPERTY MSVC_RUNTIME_CHECKS "") # Disable all runtime checks for sdl2
endif()
target_link_libraries(CircuitSimulatorLib PUBLIC SDL2::SDL2)

set(SDL2IMAGE_VENDORED OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/External/SDL2_image)
target_link_libraries(CircuitSimulatorLib PUBLIC SDL2_image::SDL2_image)


target_include_directories(CircuitSimulatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/External/Eigen/Eigen)

# create a library for sdl2_gfx
file(GLOB SDL2_GFX_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/External/SDL2_gfx/*.h ${CMAKE_CURRENT_SOURCE_DIR}/External/SDL2_gfx/*.c)
add_library(SDL2_gfx STATIC ${SDL2_GFX_SOURCES})
if (MSVC)
    target_compile_options(SDL2_gfx PUBLIC "/Oi-")
endif()
target_include_directories(SDL2_gfx PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/External/SDL2_gfx)
target_link_libraries(SDL2_gfx PRIVATE SDL2::SDL2)
target_link_libraries(CircuitSimulatorLib PUBLIC SDL2_gfx)


