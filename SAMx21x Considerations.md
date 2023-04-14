# SAMx21x Considerations

The base CanZero uses a Microchip/Atmel SAMD21G microcontroller, which has a 3.3v core with 38 IO pins. There are other variants of the core which may be more suitable.

The SAML21x is a low power version, however the low power features require additional complexity which is not required. However they also include peripherals like 2x Op Amps which could be useful. More importantly they are availble in a TFQP48 package now, albeit at a higher price.

The SAMC21x variant is a 5v version, consideration to be given if this is better from legacy IO point of view. Supply issues need to be considered.

It is useful to consider variants available in a TFQP32 package, while this does not save any PCB space the pitch is 0.8mm vs 0.5mm on the TFQP48 device so easier for fabrication. However the number of IO is decreased (and on reflection may not be enough for a six switch input node with aux inputs for PIR and temp).

## CanZero IO

Of the 37 general IO pins on the CanZero, 3 are not connected, 2 are required for programming, 1 for the built in LED and 6 for STM/CanBus communication leaving 25 for application use. A device in TFQP32 format will therefore only have 13 available for application use. Take away one for service pin, leaves 12, which is not enough to run a 6 switch input node that includes an auxilliary temperature and/or occupancy sensor.

| CanZero Port | Description / Mapping | TFQP32 | Notes            |
| ------------ | --------------------- | ------ | ---------------- |
| Reset        |                       | Y      | External         |
| PA00         | Xin                   | Y      |                  |
| PA01         | Xout                  | Y      |                  |
| PA02         | Ain0 / A0             | Y      |                  |
| PA03         | Ain1 / Aref           | Y      |                  |
| PA04         | Ain4 / A3             | Y      |                  |
| PA05         | Ain5 / A4             | Y      |                  |
| PA06         | Ain6 / A5             | Y      |                  |
| PA07         | Ain7 / A6             | Y      |                  |
| PB02         | Ain10 / A1            | n/a    |                  |
| PB03         | Ain11 / A2            | n/a    |                  |
| PB08         | Ain2                  | n/a    | Built in LED     |
| PA08         | D11 / S0_SDA          | Y      | Ext I2C          |
| PA09         | D12 / S0_SCL          | Y      | Ext I2C          |
| PA10         | D2                    | Y      |                  |
| PA11         | D3                    | Y      |                  |
| PA12         | S2_MOSI               | n/a    | Canbus SPI       |
| PA13         | S2_SCK                | n/a    | Canbus SPI       |
| PA14         | S2_SS                 | Y      | CanBus SPI       |
| PA15         | S2_MISO               | Y      | CanBus SPI       |
| PA16         | D8 / S1_MOSI          | Y      | Ext SPI          |
| PA17         | D9 / S1_SCK           | Y      | Ext SPI          |
| PA18         | n/c                   | Y      |                  |
| PA19         | D10 / S1_MISO         | Y      | Ext SPI          |
| PA20         | D6                    | n/a    |                  |
| PA21         | D7                    | n/a    |                  |
| PA22         | D0                    | Y      |                  |
| PA23         | D1                    | Y      |                  |
| PA24         | n/c                   | Y      |                  |
| PA25         | n/c                   | Y      |                  |
| PA27         | CAN_TX_INT            | Y      | CanBus Interrupt |
| PA28         | CAN_RX_INT            | n/a    | CanBus Interrupt |
| PA30         | SWCLK2                | Y      | Programming      |
| PA31         | SWDIO2                | Y      | Programming      |
| PB10         | D4                    | n/a    |                  |
| PB11         | D5                    | n/a    |                  |
| PB22         | D14 / S5_TX           | n/a    | Ext TX           |
| PB23         | D13 / S5_RX           | n/a    | EXt RX           |

Therefore a TFQP48 device is required.

## Program Space and RAM

This has not yet been computed. However the device has 32KB of RAM and 256KB or Flash (for config and program)
