cmake_minimum_required(VERSION 3.22)
project(CircuitSimulatorDemoProj)

file(GLOB CIRCUIT_SIM_DEMO_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/User/*.h ${CMAKE_CURRENT_SOURCE_DIR}/User/*.cpp)
add_executable(CircuitSimulatorDemo ${CIRCUIT_SIM_DEMO_SOURCES} )
target_include_directories(CircuitSimulatorDemo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/User)

target_link_libraries(CircuitSimulatorDemo PUBLIC SDL2::SDL2main)

add_custom_command(
        TARGET CircuitSimulatorDemo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/Resources
                $<TARGET_FILE_DIR:CircuitSimulatorDemo>/Resources)

if (WIN32)
    add_custom_command(
        TARGET CircuitSimulatorDemo 
        POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                "$<TARGET_FILE:SDL2_image::SDL2_image>" # This refers to the SDL2 image DLL
                "$<TARGET_FILE_DIR:CircuitSimulatorDemo>" # Destination directory
        VERBATIM
    )
    add_custom_command(
        TARGET CircuitSimulatorDemo  
        POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                "$<TARGET_FILE:SDL2::SDL2>" # This refers to the SDL2 DLL
                "$<TARGET_FILE_DIR:CircuitSimulatorDemo>" # Destination directory
        VERBATIM
    )
endif()
