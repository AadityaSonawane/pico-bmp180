/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/

/**
 * @file main.c
 * @author Misha Zaslavskis
 * @date 13 May 2023
 * @brief A main code of how work with BMP180 sensor for Raspberry Pi Pico board.  
 * */

#include <stdio.h> /* Standard libary for printing the UART console */
#include "pico/stdlib.h" /* Libary of PICO SDK C/C++ for support function for RPI PICO */
#include "bmp180.h" /* Own header of BMP180 */

/**
 * @brief A main function that able measure air temperature and atmosphere pressure and print the results of measurment in UART interface 
 * All c/c++ code must include int main() or int main(int argc, char **argv) function. 
*/
int main() {

    stdio_init_all(); /* Initialize that supporting printf standard function via UART interface */

    i2c_init_bmp180(); /* Initialize I2C interface for BMP180 sensor */

    for (;;) /* Infinite loops */ 
    {
        data_from_bmp180 current_data = get_bmp180_sensor_data(3); /* Get data from BMP180 sensor */
        
        printf("T: %.1f oC | Pressure: %.1f Pa \r\n", current_data.air_temperature_in_celisus, current_data.atmospheric_pressure_in_Pa); /* Print about data of BMP180 in UART console*/

        sleep_ms(1000); /* Delay for 1000 ms */
    }
}
