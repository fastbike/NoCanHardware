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
