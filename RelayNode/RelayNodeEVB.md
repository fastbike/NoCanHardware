# RelayNode Evaluation Board

Test rig for prototyping / testing of 24V latching relay circuits

## Comments

Notes form actual version built:

- the inputs labelled ON and OFF are reversed. This relates to the polarity of the relay (Omron) - think the datsheet pins 1&8 are wrong.

- The service pin part of the circuit was not populated as the switch is likely to burn out the mcu if grounded during the part of the duty cycle when the pin is an output (if high)

- Q4 was a SOT23 on the pcb, actual part was smaller SOT323

- We did not measure the output current at the mcu pins, however SPICE modelling shows a peak of 11mA at switch on at Q1, for a brief period. It may be safer to use a small gate resistor, 150R shows this reducing the current to 3.6mA.
  Peak current at Q2/Q2 was under 3mA, but a gate resistor is added for good measure.
  Also, the Neuron chip could easily source in excess of 20mA at 5v, this did not seem to cause a problem in practice but for the sake of 2 additional resistors per channel it is cheap protection.

- MOV was not populated

- Coil pins on relay are smaller than load pins so pattern needs altering

- Jumpers for swapping the coil polarity used standard vias - these were too small so filled with solder mask and were hard to actually solder.

- The pads for the TH diode were quite small, so hard to solder

- Is the diode required ? A small spike was seen on the scope with the diode in place. With it removed a 3v spike was observed when switching. Given the eBOS (12v vs 24v in our design) circuit did not include it, we can safely omit it. (Coil current of 25mA will run through the 390R resistor, giving 9.75V plus 24v rail. This is less than Vds of MOSFET).

- The coil took a min of 5mSec to operate reliably, would recommend a longer time in a production setting. NB: modelling using a resistive load showed 1mSec but this does not account for the inductive nature of the coil.

- Resistor R5 briefly passes 60mA (390R) or 75ma (330R), at 24v this is 1.44W or 1.8W. Is a higher rated resistor needed ?

## Specifications

Input: 23-27v DC for relay. 

3v3 for logic

Based on eBOS Lonworks RON03 output node with mosfet driver for single coil latching relay. Adds extra resistor to drop Vgs (gate to source voltage) under 20v, and a 1N4148 to protect Q3 mosfet from spikes caused by collapse of coil magnetic field.

~~Also used to prototype the Service Pin functionality~~

## Components

| Res Def        | Value    | Maker and Part No       | Comments           | Footprint        |
| -------------- | -------- | ----------------------- | ------------------ | ---------------- |
| S1             |          | DK CKN9092-ND           | Service Pin Switch | CK_PTS645SL50-2  |
| LED1           |          | DK 160-1427-1-ND        | Service Pin LED    | LED-0805         |
| Q1,Q2,Q3       | DMN65D8L | DK DMN65D8L-7DICT-ND    |                    | SOT23            |
| Q4             | BS884    | BSS84PWH6327XTSA1       |                    | SOT23            |
| R1, R2, R3, R4 | 10K      | Panasonic ERJ-3EKF1002V | 1/10W, 1%          | 0603             |
| R5             | 330R     | ESR03EZPJ331            | 1/4W 5%            | 0603             |
| R6             | 330R     | ESR03EZPJ331            | 1/4W, 5%           | 0603             |
| K1             | Relay    | Omron G5RL-U1A-24DC     | Relay              | G5RL-U1A         |
| D1             | 1N4148   | 1N4148                  | Flyback diode      | 8mm through hole |
| VR1            | 275V     | Littlefuse V275LA4P     | Snubber            | V275LA4P         |
