# looloog

The looloog is a DIY midi instrument intended to make custom inputs for [vcvrack](https://vcvrack.com/)

![Front of the looloog](pictures/front.jpg)

![Buttons of the looloog](pictures/buttons.jpg)

![Back of the looloog](pictures/back.jpg)

The case is made out of wood, the electronics is based on arduino, and custom pcb allows for 56 pots and 8 buttons wired simultaneously, all encoded in midi and transmitted through USB. Of course it's a USB type B, it's a controller :)

## Hardware
The hardware is made out of :
- an arduino "pro micro" board; this board is an equivalent of the arduino leonardo board which allows for HID devices and classic arduino programming on the same USB port, all in a condensed package. The version is the 5v/16Mhz version.
- four CD74HC4067 multiplexers; these are 16 inputs multiplexers that allows to connect analog or digital inputs and route them to a single input on the arduino board. The revision used is the E version which was more available than the standard version and has a larger footprint
- Custom PCBs, one for the main board of the arduino, two for the controls on each panel
- 56x 100k linear variable potentiometers (with dust covers)
- 8 push buttons
- 1 white LED to know that the device is plugged in
- a USB type B block for external connectivity, which converts to USB type A, and then to type C through a small USB cable :)

## Prototype

Original prototype was made on a breadboard to validate the minimum hardware and that digital and analog input could be used on the same multiplexer.

![Breadboard](schematics/breadboard-looloog-proto.png)

## PCBs

All PCB designs made with EasyEDA; the choice has been made to handle all the wiring with JST-XH connectors, which looked like a good compromise between connectivity and space used on the PCB.

### Main PCB
![Main PCB](schematics/pcb/pcb_looloog_main.png)

The main PCB holds the arduino board and connects to the two module boards. A small capacitor has been added to the board to handle possible power issues. While designing the PCB, external wires were planned in case the arduino does not provide enough current for the circuit, but this turned out to not be a problem when the full assembly was finished.

Gerber file available here : [Main PCB gerber](schematics/pcb/pcb-looloog-main.zip)

### Module PCB
![Main PCB](schematics/pcb/pcb_looloog_module.png)

A module PCB holds two multiplexers to handle 28 potentiometers and 4 push buttons. The connectors layout has been lined up so that the inputs can be wired along all the length of the controller. Planning the push buttons in the middle turned out to be a bit short on one of the layouts, this could be improved on other revisions of the PCB design.

Gerber file available here : [Module PCB gerber](schematics/pcb/pcb-looloog-module.zip)

## Code

The project is made for VSCode and PlatformIO, all configured for the pro micro board selected for the project.
The code makes use of an already existing usb midi library which does most of the job in terms of HID device; the only change happens in *configureUSBInfos.py*, where the device reports its name as the "Looloog" :)

There is an option that outputs the commands on serial instead of sending them through USB midi; this is available for debugging purposes and can be enabled by commenting out the line in platformio.ini :
```
;build_flags = -D DEBUG_MIDI_THROUGH_SERIAL
```
All inputs send CC changes through USB midi, being split into 4 midi channels. An improvement could be to create a Module class that would represent one panel with its two multiplexers instead of having 4 multiplexers declared; that would make the instrument have 2 midi channels instead of 4, making things a bit easier on the logic when being used on the computer.

Some of the potentiometers turned out to be jiggling a bit when being used; that is due to the arduino ADC reading the value on 10bit with a precision that was somewhat low, and the code mapping the reading to midi 7bit values. When reading the potentiometer values, there is now a margin that allows measuring little variations before considering a real midi CC change.
