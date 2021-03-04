[![MCHP](images/microchip.png)](https://www.microchip.com)

# Getting Started with Timer/Counter Type D (TCD) Examples (Microchip Studio)

  This repository contains examples of bare metal source code for Timer/Counter Type D (TCD) as described in [TB3212 - Getting Started with Timer/Counter Type D (TCD)](https://ww1.microchip.com/downloads/en/Appnotes/TB3212-Getting-Started-with-TCD-DS90003212.pdf) document from Microchip. The repository contains an Atmel Studio Solution with multiple projects inside:

  * [<strong>Generating complementary driving signals:</strong>](Generating_complementary_driving_signals) This use case shows how to configure the TCD to generate two complementary driving signals of 50 kHz frequency with 100 ns dead time (for more details, see [<strong>Generating complementary driving signals</strong>](Generating_complementary_driving_signals)).
  * [<strong>Controlling synchronous signals using input events:</strong>](Controlling_synchronous_signals_using_input_events) This use case shows how to configure the TCD to generate four signals with 10 kHz frequency that can be stopped when a fault signal is detected (for more details, see [<strong>Controlling synchronous signals using input events</strong>](Controlling_synchronous_signals_using_input_events)).

## Related Documentation
More details and code examples on the ATTINY817 can be found at the following links:
- [TB3212 - Getting Started with Timer/Counter Type D (TCD)](https://ww1.microchip.com/downloads/en/Appnotes/TB3212-Getting-Started-with-TCD-DS90003212.pdf)
- [ATTINY817 Product Page](https://www.microchip.com/wwwproducts/en/ATTINY817)
- [ATTINY817 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=attiny817)
- [ATTINY817 Project Examples in START](https://start.atmel.com/#examples/ATTINY817XplainedMini)


## Software Used
- Microchip Studio 7.0.2542 or newer [(https://www.microchip.com/mplab/microchip-studio)](https://www.microchip.com/mplab/microchip-studio)
- ATtiny_DFP 1.7.330 or newer Device Pack


## Hardware Used
- ATTINY817 Xplained Mini [(attiny817-xmini)](https://www.microchip.com/developmenttools/ProductDetails/attiny817-xmini)
