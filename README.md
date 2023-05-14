# pico-bmp180
A code of BMP180 temperature and barometer I2C sensor for supporting Raspberry Pi Pico board 

Hello Raspberry PI Pico developers and users, we made a small and simple library BMP180 I2C sensor for Raspberry PI Pico. I didn't find source code of BMP180 sensor for Raspberry Pi Pico board in C/C++, but in python source codes are already exist in internet, so I deciced to write code of BMP180 sensor for supporting Raspberry Pico.

The BMP180 sensor is worked fine with Raspberry Pi Pico board!!!

BMP180 I2C sensor is still popular for Arduino's projects. Moreover, I able buy this sensor freely in current time. 

Links of ordering sensor: https://www.amazon.co.uk/UMTMedia%C2%AE-Pressure-Arduino-Precision-Atmospheric/dp/B0983V8115/ref=sr_1_4?crid=13S470NQVCI59&keywords=BMP180+3.3+V&qid=1684018689&sprefix=bmp180+3.3+v%2Caps%2C109&sr=8-4


# Prerequisite

* **BMP180 with support 3.3 V logic and power**
* **Raspberry Pi Pico OR Raspberry Pi Pico W**
* **4 pcs Male-Male breadboard jumper**
* **Micro USB cable (which we can connect into laptop)**
* **Putty software or any serial port terminal software** 
* **Breadboard**
* **Installed PICO C SDK, cmake and visual studio code** (In PICO SDK will install automatically visual studio code IDE, cmake and other essential softwares)

# Gallery

![image](https://github.com/misha-dig/pico-bmp180/assets/55639759/8021c95e-e0e8-4662-a0ad-58a35fe5a814)

A built simplest circuit in breadboard with BMP180 sensor and Raspberry Pi Pico

# Screenshot result of air temperature and pressure 

![PUTTY_SCREENSHOOT_BMP180_SENSOR](https://github.com/misha-dig/pico-bmp180/assets/55639759/93d44e74-1c56-4e95-8f4c-7ae87be4087a)

# Sechmatics and pinouts (I used Fritzing software)

## Breadboard

![Sechmatic_bmp180_breadboard_bb](https://github.com/misha-dig/pico-bmp180/assets/55639759/e0398448-72d8-4f70-922c-ee3bfb7d78f7)

Graphical represenatation schematic with BMP180 and Raspberry Pi Pico in Breadboard

## Circuit diagramm

![Sechmatic_bmp180_breadboard_schem](https://github.com/misha-dig/pico-bmp180/assets/55639759/d015a2c3-07e0-4031-914a-d786219e3c64)

Minimal schematic diagramm for ablity to work BMP180 sensor in any projects 

## Pinout 

Assume: Use minimal circuit diagramm to able work with BMP180 sensor

Sensor:      Raspberry Pi Pico

VIN -------> 3.3 V OUT 

GND -------> GND

SDA -------> GP4

SCL -------> GP5

# Basic code

Minimum amount of code that able work with BMP180 sensor in Raspberry Pi Pico.

Main code of usage example with BMP180 sensor for Raspberry PI Pico board. (You can look in main.c code file)

```
#include <stdio.h> /* Standard libary for printing the UART console */
#include "pico/stdlib.h" /* Libary of PICO SDK C/C++ for support function for RPI PICO */
#include "bmp180.h" /* Own header of BMP180 */

int main() {

    stdio_init_all(); /* Initialize that supporting printf standard function via UART interface */

    i2c_init_bmp180(); /* Initialize I2C interface for BMP180 sensor */

    for (;;) /* Infinite loops */ 
    {
        data_from_bmp180 current_data = get_bmp180_sensor_data(3); /* Get data from BMP180 sensor */
        
        printf("T: %.1f oC | Pressure: %.1f Pa \r\n", 
                               current_data.air_temperature_in_celisus, 
                               current_data.atmospheric_pressure_in_Pa); /* Print about data of BMP180 in UART console*/

        sleep_ms(1000); /* Delay for 1000 ms */
    }   
}
```
# Building code (We used Linux Mint 21.1 OS)

## How get binary file for uploading your Raspberry Pi Pico

1. Download own repository by using command ```git clone https://github.com/misha-dig/pico-bmp180.git```

2. Go to direcitory ```pico-bmp180``` by command ```cd pico-bmp180```

3. Set enviroment path of PICO_SDK_PATH with your pico-sdk directory path by command ```export PICO_SDK_PATH=/your_sdk_path/pico-sdk```

4. Create directory ```build``` by command ```mkdir build```

5. Go to ```build``` directory by command ```cd build```

6. Hit command ```cmake ..```

7. Hit command ```make``` and wait until building code finished  

8. Flash into your Raspberry Pi Pico file ```pico_bmp180.uf2``` from ```build``` directory (You need first hold a button BOOTSEL until file manager appeared for Raspberry Pi Pico drive)

9. Enjoy your project !!! :) :) :)

## How generate doxygen HTML documentation

If you don't have doxygen package in your Linux PC

Please run two simple command (for debian based Linux OS users)

```sudo apt-get update```

```sudo apt-get install doxygen```

And genrate doxygen HTML documentation by invoking command in this directory

```doxygen``` 

Open your documentation by path ```html/index.html```

## Setting UART via USB (after flashing your Raspberry Pi Pico)

We use Pico's setting default speed of UART

The default parameter for Raspberry Pico is

* Baudrate: ```115200``` bit/s
* Data bit: ```8``` bit
* Stopbit: ```1``` bit 
* Parity: ```NONE```
* Flow control: ```XON/XOFF```

So we enter 115200 and select serial port in main page of Putty software

# How to create own projects with own libary BMP180

## Creating empty project with BMP180 sensor library (As similary building instruction above)

We used with instruction how create any project with using Pico C SDK. 

1. Clone by hitting command ```git clone https://github.com/misha-dig/pico-bmp180.git```

2. Go to direcitory ```pico-bmp180``` by command ```cd pico-bmp180```

3. Set enviroment path of ```PICO_SDK_PATH``` with your pico-sdk directory path by command ```export PICO_SDK_PATH=/your_sdk_path/pico-sdk```

4. Modify project name in ```CMakeLists.txt``` file by using text editor (seach and replace all text from ```pico_bmp180``` into your name of project (for example ```meteostation```) and save this text file) 

5. Create directory ```build``` by command ```mkdir build```

6. Go to ```build``` directory by entering command ```cd build``` 

7. Hit command ```cmake ..```

8. Build your source of code for your project by hitting command ```make``` in ```build``` directory path 

## Your existing project

Just you need to follow few step ... 

1. Download and unzip own this repository from github OR using ```git clone https://github.com/misha-dig/pico-bmp180.git```

2. Go to directory ```pico-bmp180```

3. Copy ```bmp180.c``` and ```bmp180.h``` into your existing project directory

4. You may be need to modify your ```CMakeLists.txt``` (Such adding file bmp180.c code in section ```add_executable``` and add dependencies ```hardware_i2c``` in section ```target_link_libraries``` )  

5. Enjoy your coding!!! :) Good Luck!!!  

# Credits and resources

Controllerstech. Interface BMP180 with STM32. Controllerstech. https://controllerstech.com/interface-bmp180-with-stm32/ (Tutorial + video training how write code BMP180 I2C sensor stm32)

Bosch Sensortec. (2022, August 15th). Data Sheet BMP180 Digital pressure sensor. https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf (Datasheets of sensor BMP180)

Raspberry Pi Ltd. hardware_i2c. https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#hardware_i2c (API Documentation of Raspberry PI Pico C SDK)

Raspberry Pi Ltd. The C/C++ SDK. https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html#say-hello-world (How create new project with Raspberry Pico)
