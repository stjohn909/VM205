# VM205 C library using pigpio and pigpiod, (RPi, ArchLinux)

This library provides an API to the [Whadda WPSH206/Velleman VM205](https://whadda.com/product/oscilloscope-and-logic-analyzer-shield-for-raspberry-pi-wpsh206/) (Raspberry Pi oscilloscope shield) using the C interface to the pigpio daemon.  

This library is in development on a Raspberry Pi 3B+ running Pi OS Bullseye, although theoretically it should function on any OpenGL-enabled pi running pigpiod.

The VM205 has been rebranded and is now sold by [Whadda](https://whadda.com) as the VPSH206, but you'll have better luck searching for forum discussions if you reference the VM205.  

Required packages:  
* pigpio
* pigpiod_if2
* SDL

Requires sudo to run without the pigpio daemon running.

The SDL window displays over XRDP when using the pigpio daemon. 

Oscilloscope tests good with a 220Hz sine wave from a Tiptop Z3000 eurorack oscillator module.   Logic probe inputs have not been tested.

References:
[https://github.com/joan2937/pigpio](https://github.com/joan2937) - This is the source repo for the pigpio library.  It contains many useful examples.

Forked from:
[https://github.com/xhargh/VM205](https://github.com/xhargh/VM205) - This is the class I hacked to support pigpio.  Since the original VM205 demo app was written in Pascal, this C++ class is a huge leg up.
