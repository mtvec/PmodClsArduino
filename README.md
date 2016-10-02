# PmodCLS driver for Arduino

This is a simple Arduino driver for the Digilent [PmodCLS](http://store.digilentinc.com/pmodcls-character-lcd-with-serial-interface/) LCD module.
It is meant to be as much as a drop-in replacement for [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal) as possible.
However, the following incompatibilities currently exist:
 - The autoscroll feature is not present on the PmodCLS.
   This could be implemented in software but currently is not;
 - The right-to-left feature is not present either.
   This is probably impossible to emulate in software;
 - Defining custom characters *is* supported by the hardware but not implemented yet;
 - The constructors are completely different.

Since there are different ways to communicate with the PmdCLS (UART, SPI and I²C), this driver does not talk to the hardware directly.
Instead, it writes a command stream to a user-provided function which is responsible of communicating with the hardware.
See the [HelloWorld](examples/HelloWorld/HelloWorld.ino) example for a simple way to communicate over UART.
