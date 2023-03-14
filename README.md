# EmbeddedSystems-CustomArduinoFunctions
<p align="justify"> This code is written for Arduino and provides functions for configuring digital input and output pins.</p>

<p align="justify"> The code defines some constants (HIGH, LOW, OUTPUT, and INPUT) and three functions that are used to configure the DDRx, PORTx, and PINx registers that control the digital pins on an Arduino board. These functions are configureDDRxPointer(), configurePORTxPointer(), and configurePINxPointer().</p>

<p align="justify"> In addition, there are three functions that perform specific actions on the digital pins: _pinMode(), _digitalWrite(), and _digitalRead(). _pinMode() configures a pin to behave as an input or output, _digitalWrite() sets a pin to a specific value (HIGH or LOW), and _digitalRead() reads the value of a pin.</p>

<p align="justify"> The setup() function is used to initialize the pins by setting pin 7 on port 1 as an output and turning it on. Pins 4 on port 2 and pin 6 on port 4 are set as inputs and turned on as well.</p>

<p align="justify"> The loop() function is the main loop of the program. It continuously reads the values of pins 4 on port 2 and pin 6 on port 4 using _digitalRead() and turns the LED on pin 7 of port 1 on or off based on which button is clicked. If the button on pin 4 is clicked, the LED is turned off, and if the button on pin 19 is clicked, the LED is turned on.</p>

<p align="justify"> Overall, this code provides a simple way to control digital pins on an Arduino board and can be used as a starting point for more complex projects.</p>
