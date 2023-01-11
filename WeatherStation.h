#ifndef WeatherStation_h
#define WeatherStation_h

#include <Arduino.h>
#include <configuration.h>
#include "pinSetup.h"

#include <OneWire.h>
#include <DallasTemperature.h>

class WeatherStation
{
    public:
        WeatherStation();
          
            /**
              * @brief setup the rain gauge ISR
              */
            void setupRainGaugeISR();

            /**
              * @brief map a value with a range to other
              */
            long mapa(long x, long in_min, long in_max, long out_min, long out_max);
        
            /** 
              * @brief  reads analog value, and compares with Vwindvane,
              *         [Vwindvane =  Vin *( (Rwindvane_table[i] + Rwindvane_2) / (Rwindvane_table[i]+ Rwindvane_1 + Rwindvane_2)),
              *         resistors values available in configuration.h
              * @retval wind direction in degrees (0 to 360)
              */        
            float wind_direction();

                float Vwindvane[windvane_size];
                float Vwindvane_min[windvane_size];
                float Vwindvane_max[windvane_size]; 

            /** 
              * @brief takes pulse samples on digitalPin for x seconds
              * @retval wind speed in Km/h or MPH
              */
            float wind_speed();

                int Rotations;

            /** @brief reads an analog value and mapping the range [100,0, wet,dry] (configuration.h)             
              * @retval soil moisture in percent 
              */                
            float soil_humidity();

            /** @brief reads an analog value and mapping the range [100,0, wet,dry] (configuration.h)
              * @retval leafwetness in percent
              */
            float leaf_wetness();

            /** @brief reads soil temperature by one wire commmunication
              * @retval soil temperature in degrees Celcius
              */
            float soil_temperature();

            /** @brief reads air temperature by one wire communication
              * @retval air temperature in degrees Celcius
              */
            float air_temperature();

            /** @brief  : reads relative air humidity by one wire communication
              * @retval : relative air humidity in percent
              */
            float air_humidity();

            /** @brief uses an ISR (edges in a digitalPin) to counts tips, with tip means +1x bucketAmount
              * @param[out] bucketAmount the amount precipitation in mm it causes the ISR
              * @retval precipitation amount in mm
              */
            float raingauge();

            /** @brief reset the rain tip couting
             */    
            void rst_raingauge();

            /** @brief reads analog value with is proportional to UV level (1 ot 11) 
              * @param  
              * @retval UV level (1 to 11) 
              */                
            int uv_level();

            /** @brief reads BMP temperature using I2C communication
              * @retval BMP's temperature in degrees Celcius
              */
            float BMPtemperature();
            
            /** @brief read BMP barometric pressure using I2C communication 
              * @retval BMP barometric pressure
              */
            float pressure();

            /** @brief read BMP altitude, based on barometric pressure using I2C communication 
              * @retval BMP altitude
              */
            float altitude();

            /** @brief read the luminous flux by I2C communication 
              * @retval luminous flux in lux
              */
            float light_meter();

            /** @brief read the now date by I2C communication
              * @retval now date (year, month, day, hour, minute, second)
              */
            int rtc_time();

                int year;
                int month;
                int day;
                int hour;
                int minute;
                int seconds;
                int dayOfWeek;

    private:

        boolean flag_soiltemperature = false;
        boolean flag_dht = false;
        boolean flag_pressure = false;
        boolean flag_lux = false;
        boolean flag_rtc = false;
        int p2;

};

#endif