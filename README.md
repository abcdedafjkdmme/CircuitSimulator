# CircuitSimulator

## Description 
This is an interactive circuit (?) simulator

## Requirements
- Compiler that supports C++20
- CMake

## Building
```shell
$ git clone https://github.com/abrka/CircuitSimulator.git
$ cd CircuitSimulator
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```
Now run CircuitSimulatorDemo/CircuitSimulatorDemo executable

### For Visual Studio
- Open CircuitSimulatorProj.sln in Visual Studio
- Build and run CircuitSimulatorDemo

## Usage

### How to Use
1. Create a SimulatorApplication Object in your main
2. Call the Init function of application object.
3. Create necessary game objects
4. call the Run function of application

### How to create your own microcontrollers
1. Create a new class inheriting from Arduino
2. Now you can put your code in your custom arduino's constructor or in the overridden Tick function which runs every frame
3. To learn more about how to create your custom microcontroller look into the Arduinos header file. I dont have enough time to write documentation 

### How to connect different components with a wire
1. Create a new Wire object
2. Call the wire's connect function and pass in the electric pins you want to connect
