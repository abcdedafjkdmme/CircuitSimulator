# CircuitSimulator
A simple prototype I'm creating to learn more about c++ and game engines

# How to download

PS: the project will be sorted out later. for now you have to follow these steps
1. Clone the repo
2. You can use the CircuitSimulatorDemo as an example


# How to Use
1. Create a SimulatorApplication Object in your main
2. Call the Init function of application object.
3. Create necessary game objects
4. call the Run function of application

# How to create your own microcontrollers
1. Create a new class inheriting from Arduino
2. Now you can put your code in your custom arduino's constructor or in the overridden Tick function which runs every frame
3. To learn more about how to create your custom microcontroller look into the Arduinos header file. I dont have enough time to write documentation 

# How to connect different components with a wire
1. Create a new Wire object
2. Call the wire's connect function and pass in the electric pins you want to connect
