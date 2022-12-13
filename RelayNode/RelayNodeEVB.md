# RelayNode Evaluation Board

Test rig for prototyping / testing of 24V latching relay circuits

## Specifications

Input: 23-27v DC for relay. 

3v3 for logic

Based on eBOS Lonworks RON03 output node with mosfet driver for single coild latching relay. Adds extra resistor to drop gate to source voltage under 20v, and a 1N4148 to protect Q3 mosfet from spikes caused by collapse of coil magnetic field.

Also used to prototype the Service Pin functionality

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
