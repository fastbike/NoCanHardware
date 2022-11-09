# 24v to 12v Adapter

Add-in adapter board to power 12v peripherals from 24v supply

E.g. PIR sensors etc

## Specifications

Input: 23-27v DC

Output 12v DC @ 250mA (nominal)

Interface: Multicomp 3 way pcb plug (similar to Lonworks switch), or 0.1" pitch board to board header.

Based on CanZero 24v to 5v circuit, omitting the polarity protection input diode.

Inductor value is 56uH, from the datasheet

Feedback resistors are 10k (Rbot) and 140k (Rtop) as per the formula in section 5.2 of the datasheet (where Vfb = 0.8v)

<img src="file:///home/david/.config/marktext/images/2022-11-07-12-21-44-image.png" title="" alt="" width="271">

## Components

Components as per Figure 6-2 from the datasheet as modified for this lower current version.

| Res Def | Value     | Maker and Part No | Comments                                        | Footprint |
| ------- | --------- | ----------------- | ----------------------------------------------- | --------- |
| C6/C7   | 2x 10uF   |                   | Input Capacitor, 10 μF, 100V, X7S, 2220         | 0805      |
| C1/C2   | 2x 10uF   |                   | Output Capacitor, Ceramic, 10 μF, 25V, X7R, 10% | 0805      |
| L1      | 56uH      | Wurth 74408943560 | 56uH 56 μH, Shielded Power Inductor             | SMD       |
| R1      | 140K      |                   | Rtop, 140 KΩ, 1/10W, 1%                         | 0603      |
| R2      | 10K       |                   | Rbot, 10 KΩ, 1/10W, 1%                          | 0603      |
| D1      | 1N4148    |                   | Boost Diode  75V 200mA                          | SOD323    |
| D2      | B1100     |                   | Freewheeling Schotty Diode 100V 1A              | SMB       |
| D3      | 7.5 Zener |                   | Diode Zener, 7.5V, 200 mW                       | SOD323    |
