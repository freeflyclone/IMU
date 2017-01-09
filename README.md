### IMU
STM32F429-Nucleo144 project to develop I2C expertise on STMicrodevices and tools

Learning a new uC always involves getting a hardware dev board, setting up a 
development environment, writing some code to blink an LED.

In this case, I need to get cozy with STM32 products, and the usual serial I/O goodies.
I'm starting with I2C, which I'll use to talk to an [Adafruit 10 DOF IMU](https://www.adafruit.com/product/1604) sensor board.

This project was created on 64 bit Linux (Ubuntu 16.04) using STM32CubeMX, exporting to SW4STM32 build system, and using Eclipse IDE.  I installed the [System Workbench for STM32](http://www.openstm32.org/HomePage) from inside Eclipse following [these](http://www.openstm32.org/Installing+System+Workbench+for+STM32+from+Eclipse?structure=Documentation) instructions.

Some combination of my system (I think it's GTK3) causes eclipse to hang in *Properties - C/C++Build / Settings*.  The remedy is to set an environment variable by adding `export SWT_GTK3=0` in .profile.  This requires logging out and logging back in.  Adding this to .bashrc won't do if you launch Eclipse from a desktop GUI system.

## Note
There is a bug in the .cproject file exported by STM32CubeMX that prevents building the project in Eclipse.  It's easily remedied, however.  To fix it, open the .cproject XML file, and search for "weak" (without the quotes).  You'll find it in a &lt;listOptionValue&gt; element.  Delete that entire element and the one right after it, save the file and you'll be good to go. 
Anyone want to write an XSL script to filter this out with *xsltproc*?
### WTF?
Why does this break the build on Linux?  Because *make* issues commands to the Linux shell, and parenthesis have special meaning to the shell, so the actual compiler command line gets borked.  Removing the two elements is okay, because what they define is already defined in `Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h` Apparently this has been known for quite some time, it wasn't until I figured it out on my own that I discovered I wasn't the first to solve the problem.
