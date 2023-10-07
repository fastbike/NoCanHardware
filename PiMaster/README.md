# PiMaster HAT Hardware

Also design a PiSlave which will supply power onto the network - the firmware will listen to the Power Up / Power Down command (will need to add one because currently the HAT just turns off the power - would be good if the nodes knew there was a shutdown coming). Will be the same same hardware just with a different firmware that can hear the power on/off commands

## Changes from the Omzlo Design

Additional electro cap added as we are also powering a SSD

Change the network connector to be a std 5.08mm pitch Phoenix part

Change the VIn(raw) connector to be a rising cage clamp design

Higher amperage 24 to 5v buck coverter (needs to supply 3A) such as  TPS54335ADDA

The stand offs need to be higher to allow for the heatsink/cooling fan HAT that sits on the PI. This requires an absolute min clearance of 13.5mm. However to allow for airflow etc a clearance of 20mm between boards is required.

The Pi GPIO headers will need to allow for this. Standard headers are 8.5mm high, so two stacked should suffice with a small spacer (2x1.5mm) (Part number 1528-2831-ND)

Standoffs will need to be 20mm and 15mm (for over the fan mount) and threaded both ends. A M2.5 x 15 threaded rod will old the heatsink in place (with existing hardware).







///////////////////////////////////////////////////////

This repository contains the design files and schematics of the Omzlo PiMaster HAT (Hardware Attached on Top).

See: http://omzlo.com/pimaster

This work is licensed under the [Creative Commons Attribution-ShareAlike 4.0 International Public License][1].

[1]: https://creativecommons.org/licenses/by-sa/4.0/
