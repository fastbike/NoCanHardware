# 24v to 12v Adapter

Add-in adapter board to power 12v peripherals from 24v supply

E.g. PIR sensors etc

## Specifications

Input: 23-27v DC

Output 12v DC @ 350mA (nominal)

Interface: Multicomp 3 way pcb plug (similar to Lonworks switch), or 0.1" pitch board to board header.

Based on CanZero 24v to 5v circuit, omitting the polarity protection input diode and adding the zener diode.

Inductor value is 56uH, from the datasheet.

Feedback resistors are 10k (Rbot) and 140k (Rtop) as per the formula in section 5.2 of the datasheet (where Vfb = 0.8v), tolerance is 1%

<img src="file:///home/david/.config/marktext/images/2022-11-07-12-21-44-image.png" title="" alt="" width="271">

## Components

Components as per Figure 6-2 from the datasheet as modified for this lower current version.

| Res Def | Value     | Maker and Part No           | Comments                                 | Footprint   |
| ------- | --------- | --------------------------- | ---------------------------------------- | ----------- |
| C6/C7   | 2x 10uF   | ~~Samsung CL32Y106KCVZNWE~~ | Input Capacitor, 100V, X7S, 2220         | 1206        |
| C1/C2   | 2x 10uF   | Murata GRM21BZ71E106KE15L   | Output Capacitor, Ceramic, 25V, X7R, 10% | 0805        |
| C4      | 0.1uF     | Kyocera 0603YC104KAT2A      | Boost Capacitor, Ceramic, 10V, X5R/X7R   | 0603        |
| L1      | 56uH      | Bourns SRR4028-560Y         | 56uH 56 μH, Shielded Power Inductor      | SMD 4.8x4.8 |
| R1      | 140K      | Panasonic ERJ-3EKF1403V     | Rtop, 140 KΩ, 1/10W, 1%                  | 0603        |
| R2      | 10K       | Panasonic ERJ-3EKF1002V     | Rbot, 10 KΩ, 1/10W, 1%                   | 0603        |
| D1      | 1N4148    | Micro Commercial 1N4148WTP  | Boost Diode 100V 150mA                   | SOD123      |
| D2      | BAS100    | Panjit BAS100AS_R1          | Freewheeling Schotty Diode 100V 1A       | SOD123      |
| D3      | 7.5 Zener | Diodes Inc MMSZ4693-TP      | Diode Zener, 7.5V, 500 mW                | SOD123      |
