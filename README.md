# VM205 C library using pigpiod (RPi, ArchLinux)

This library provides an API to the [Whadda WPSH206/Velleman VM205](https://whadda.com/product/oscilloscope-and-logic-analyzer-shield-for-raspberry-pi-wpsh206/) (Raspberry Pi oscilloscope shield) using the C interface to the pigpio daemon.  

This library is in development on a Raspberry Pi 3B+ running Pi OS Bullseye, although theoretically it should function on any OpenGL-enabled pi running pigpiod.

The VM205 has been rebranded and is now sold by [Whadda](https://whadda.com) as the VPSH206, but you'll have better luck searching for forum discussions if you reference the VM205.  

Requirements: pigpio, SDL, OpenGL.

The API and demo application successfully compile and run without the VM205 hardware connected and with the calls to querying the device commented out, which is as far as I can go until the board arrives in a couple of days. 


I've also been messing around with a clone of [xhargh's repo](https://github.com/xhargh/VM205) for a couple of days before properly forking it and committing my local changes to this repo, apologies.


References:
https://github.com/joan2937/pigpio
https://github.com/joan2937
https://github.com/xhargh/VM205
