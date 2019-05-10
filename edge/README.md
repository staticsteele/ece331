ECE 331 S18 Kernel Driver Project

******************************
* Press SW5 - firmware git commit printed to ttyACM0
* Press any key except 'D' to get sensor data
*   High res temp in celcius
*   IR light
*   Full Light
*   Visible Light
*   Lux
*   temperature*100
*   Pressure millibars*10000
*   humidity*1000
* Press 'D' to boot to firmware update

******************************

External temp required - I2C TC74A0 sensor connected to JP6

Date/Time must be set over I2C from RPi to be valid

DFU Update via USB
---------------------------
 - Download dfu-util, compile, install
 - Download firmware from course website
 - Press SW4 (next to JP11 text) for 1/2 second -or- Press 'D' in minicom on ttyACM0
 - LED7 turns on.
 - Connect micro USB cable to your RPi and 331hat
 - LED7 turns off.
 - Use dfu-util to flash:

  `$ dfu-util -a 0 -s 0x08000000:leave -R -D thermostat.bin`
  
where 

-a 0 is the alternate setting (Internal Flash is 0)
  
-s 0x08000000 is the program address

:leave askes for reset after programming
  
-R Issue USB Reset
  
-D thermostat.bin is the firmware to download


***** DO NOT COMMIT IN THIS PROJECT *****

