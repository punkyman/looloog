# looloog

![Front of the looloog](pictures/front.jpg)

The looloog is a custom-made midi instrument intended to make inputs for [vcvrack](https://vcvrack.com/)

![Buttons of the looloog](pictures/buttons.jpg)

![Back of the looloog](pictures/back.jpg)

The case is made out of wood, the electronics is based on arduino, and custom pcb allows for 56 pots and 8 buttons wired simultaneously, all encoded in midi and transmitted through USB. Of course it's a USB type B, it's a controller :)

## Hardware
The hardware is made out of :
- an arduino "pro micro" board; this board is an equivalent of the arduino leonardo board which allows for HID devices and classic arduino programming on the same USB port, all in a condensed package. The version is the 5v/16Mhz version.
- four CD74HC4067 multiplexers; these are 16 inputs multiplexers that allows to connect analog or digital inputs and route them to a single input on the arduino board. The revision used is the E version which was more available than the standard version and has a larger footprint

## Code


## Prototype

Original prototype was made on a breadboard to validate the minimum hardware and that digital and analog input could be used on the same multiplexer.

![Breadboard](schematics/breadboard-looloog-proto.png)

