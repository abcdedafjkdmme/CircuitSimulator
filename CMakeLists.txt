cmake_minimum_required(VERSION 3.2...4.1)
project(CircuitSimulatorProj)

add_subdirectory(CircuitSimulator)
add_subdirectory(CircuitSimulatorDemo)

target_link_libraries(CircuitSimulatorDemo PUBLIC CircuitSimulatorLib)