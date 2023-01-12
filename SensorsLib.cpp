#include "WeatherStation.h"
#include <configuration.h>
#include "pinSetup.h"
#include <Wire.h>
// #include <OneWire.h>
// #include <DallasTemperature.h>


    // OneWire barramento(soiltemperaturePin);
    // DallasTemperature sensor(&barramento);

      


    #include <DHTesp.h>
    DHT dht(dhtPin, DHTTYPE); 

    // #include <Adafruit_BMP085.h>
    // Adafruit_BMP085 bmp180;



    // #include <BH1750.h>
    
    // BH1750 lightMeter(0x23);



    #include "RTClib.h"
    RTC_DS3231 rtc;
        
            int rainTip = 0;
            long last_time = 0;



// void IRAM_ATTR newTip()
// {
//   if((long)(micros()-last_time) >= raingaugeDebounce *1000)
//   {
//     rainTip += 1;
//     last_time = micros();
//   }
// }


// void WeatherStation::setupRainGaugeISR()
// {
//      pinMode(raingaugePin,INPUT);
//      attachInterrupt(digitalPinToInterrupt(raingaugePin),newTip,FALLING);      
// }

WeatherStation::WeatherStation()
{

        // pinMode(windvanePin,INPUT);
        // int i;
        // for ( i = 0; i<windvane_size; i ++)     Vwindvane[i] = Vin *( (Rwindvane_table[i] + Rwindvane_2) / (Rwindvane_table[i]+ Rwindvane_1 + Rwindvane_2));
        // for ( i = 0; i<windvane_size; i ++)     Vwindvane_min[i] = 0.9 * Vwindvane[i];
        // for ( i = 0; i<windvane_size; i ++)     Vwindvane_max[i] = 1.1 * Vwindvane[i];
        // #if forcewindvanevoltage
        //     float Vwindvanetemp[16] = {2.32, 1.22, 1.39, 0.22, 0.26, 0.14, 0.52, 0.33, 0.85, 0.71, 1.88, 1.80, 2.83, 2.44, 2.62, 2.09};
        //     for ( i = 0; i<windvane_size; i ++)     Vwindvane[i] = Vwindvanetemp[i];
        // #endif
  

        // pinMode(anemometerPin,INPUT);   
    

    
        // pinMode(soilhumidityPin,INPUT);
    

        // pinMode(leafwetnessAPin,INPUT);
      

        // pinMode(uvlevelPin,INPUT);

    
        // Wire.begin();
       // lightMeter.begin();
       
         
    
}

long WeatherStation::mapa(long x, long in_min, long in_max, long out_min, long out_max) 
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


// float WeatherStation::wind_direction()
// {    int i = 0;

//     float temp;                          // Store the diference between sample and table
//     int flag_i = 0;                     // Flag to store the closest value
//     int adc = analogRead(windvanePin);   // Reads the analog input
   
//     //adc = 978;                         // Uncomment to force a value
//     float Vsample;
//     Vsample=float(Vin)*adc/adcresolution; // Convert digital to analog  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 
//     temp =  abs(Vsample - Vwindvane[0]); // First comparation value
//     flag_i = -1;
//  /*   for (i = 0; i<windvane_size; i =i +2)   
//         if ((Vsample >= Vwindvane_min[i]) && (Vsample <= Vwindvane_max[i]))
//             {   
//                 Serial.print("\nmin: ");
//                 Serial.print(Vwindvane_min[i]);
//                 Serial.print(" sample: ");
//                 Serial.print(Vsample);
//                 Serial.print(" max: ");
//                 Serial.println(Vwindvane_max[i]);
//                 flag_i = i;
//             }
// */
//     for ( i = 0; i<windvane_size; i = i + 2)  
//       if (abs(Vsample - Vwindvane[i]) < temp)
//        {
//           temp =  abs(Vsample - Vwindvane[i]);
//           flag_i = i;
//        }       
    
//     #if DEBUG
//        // Serial.print("\necho_debug: Windvane sample: ");
//        // Serial.print(adc);
//        // Serial.print(", voltage: ");
//       //  Serial.print(Vsample);
//         //Serial.print(". Index: ");
//         //Serial.print(flag_i);
        
//     #endif

//     return WindDegrees[flag_i];
// }


// bool DIGread()
// {
//     int i;
//     int pos = 0;
//     int neg = 0;
    
//     for(i = 0; i< samplingAVG; i++)
//     {
//         if (digitalRead(anemometerPin))
//             pos++;
//         else
//             neg++;
//     }
//     if (pos > neg)
//         return 1;
//     else
//         return 0;
// }


// float WeatherStation::wind_speed()
// {
//     bool state, lastState;
//     long bouncetime = 0;
//     lastState = DIGread();
//     Rotations = 0;
//     long tsample_start = millis();
//     while( (millis() - tsample_start) < anemometer_timesample * 1000)
//     {
//         state = DIGread();
//         if (state != lastState)
//         {
//             if((state == false ) && ((long(micros()) - bouncetime) > 1000* anemometer_debounce ) )
//             {
//                 Rotations++;
//                 bouncetime = micros();
//             }
//             lastState = state;
//         }
//      }    

//     float windspeed = Rotations * anemometer_factor / anemometer_timesample;
//     #if DEBUG
//         Serial.print("\necho_debug:");
//         Serial.print(Rotations);
//         Serial.print(" rotations in ");
//         Serial.print(anemometer_timesample);
//         Serial.print("seconds.");
//     #endif


//     return windspeed;
// }



// float WeatherStation::soil_humidity()
// {   

//     int sample = analogRead(soilhumidityPin);
//     #if DEBUG
//         Serial.print("\necho_debug: Soil moisture Sample: ");
//         Serial.print(sample);
//     #endif
//     sample = constrain(sample,wetsoilfactor,drysoilfactor);
//     float soilhumiditpercent = mapa(sample,wetsoilfactor,drysoilfactor,100,0);

//     return soilhumiditpercent;
// }


// float WeatherStation::leaf_wetness()
// {
//     int sample = analogRead(leafwetnessAPin);
//     #if DEBUG
//         Serial.print("\necho_debug: Leafwetness Sample: ");
//         Serial.print(sample);
//     #endif
//     sample = constrain(sample,wetleaffactor,dryleaffactor);
//     float wet = mapa(sample,wetleaffactor,dryleaffactor,100,0);
   
//     return (wet);
// }

// float WeatherStation::soil_temperature()
// {
//     if (!flag_soiltemperature)
//     {   
//         #if DEBUG
//             Serial.print("\necho_debug: Starting soil temperature sensor");
//         #endif 

//         sensor.begin();
//         flag_soiltemperature = true;
//     }
//     sensor.requestTemperatures();
//     float temp = (sensor.getTempCByIndex(0));
//     delay(temperature_timesample);
//     return temp;
// }

float WeatherStation::air_temperature()
{
    if (!flag_dht)
    {
        #if DEBUG
            Serial.print("\necho_debug: Starting DHT sensor..");
            
        #endif
        dht.begin(DHT11_PIN, DHTesp::DHT11); 
        flag_dht = true;
    }
    float temperature = dht.readTemperature(); 
    delay(dht_timesample); 

    return temperature;
}

float WeatherStation::air_humidity()
{
    if (!flag_dht)
    {
        #if DEBUG
            Serial.print("\necho_debug: Starting DHT sensor..");
        #endif
        dht.begin(); 
        flag_dht = true;
    }
    float humidity =  dht.readHumidity();
    delay(dht_timesample); 

    return humidity;
}

// float WeatherStation::raingauge()
// {
//     #if DEBUG
//         Serial.print("\necho_debug: ");
//         Serial.print(rainTip);
//         Serial.print("tips");
//     #endif
//     float rainAmount = rainTip * bucketAmount;

//     return rainAmount;
// }

// void WeatherStation::rst_raingauge()
// {
//     rainTip = 0;
// }

// int WeatherStation::uv_level()
// {
//     int UV = 1 ;
//     int sample = analogRead(uvlevelPin);
//     float Vsample = Vin * sample / adcresolution * 1000;
//     #if DEBUG
//         Serial.print("\necho_debug: UV sample: ");
//         Serial.print(sample);
//         Serial.print(", ");
//         Serial.print(Vsample);
//         Serial.print(" milivolts");
//     #endif
//     if (Vsample > 0 && Vsample < 50)
//         UV = 0;
//     else if (Vsample > 50 && Vsample <= 227)
//         UV = 1;
//     else if (Vsample > 227 && Vsample <= 318)
//         UV = 2;
//     else if (Vsample > 318 && Vsample <= 408)
//         UV = 3;
//     else if (Vsample > 408 && Vsample <= 503)
//         UV = 4;
//     else if (Vsample > 503 && Vsample <= 606)
//         UV = 5;
//     else if (Vsample > 606 && Vsample <= 696)
//         UV = 6;
//     else if (Vsample > 696 && Vsample <= 795)
//         UV = 7;
//     else if (Vsample > 795 && Vsample <= 881)
//         UV = 8;
//     else if (Vsample > 881 && Vsample <= 976)
//         UV = 9;
//     else if (Vsample > 976 && Vsample <= 1079)
//         UV = 10;
//     else if (Vsample > 1079)
//         UV = 11;

//     return UV;
// }

// float WeatherStation::BMPtemperature()
// {
//     if (!flag_pressure)
//     {
//         #if DEBUG
//             Serial.print("\necho_debug: Starting pressure sensor... ");
//             if (bmp180.begin(0x77))
//                 Serial.print("OK");
//             else
//                 Serial.print("ERROR");
//         #else
//             bmp180.begin(0x77);
//         #endif

//         flag_pressure = true;

//     }

//     float temp_inside = bmp180.readTemperature();
//     return temp_inside;    
// }

// float WeatherStation::altitude()
// {
//     if (!flag_pressure)
//     {
//         #if DEBUG
//             Serial.print("\necho_debug: Starting pressure sensor... ");
//             if (bmp180.begin(0x77))
//                 Serial.print("OK");
//             else
//                 Serial.print("ERROR");
//         #else
//             bmp180.begin(0x77);
//         #endif

//         flag_pressure = true;

//     }
//     float alt = bmp180.readAltitude();
//     return alt;
// }

// float WeatherStation::pressure()
// {

//     if (!flag_pressure)
//     {
//         #if DEBUG
//             Serial.print("\necho_debug: Starting pressure sensor... ");
//             if (bmp180.begin(0x77))
//                 Serial.print("OK");
//             else
//                 Serial.print("ERROR");  
//         #else
//             bmp180.begin(0x77);
//         #endif

//         flag_pressure = true;

//     }    
//     float press = bmp180.readPressure();

//     return press;
// }
   
// float WeatherStation::light_meter()
// {
//     float lux ;
//     if (!flag_lux)
//     {
//         #if DEBUG
//             Serial.print("\necho_debug: Starting lux sensor... ");
//             if (lightMeter.begin())
//             {
//               flag_lux = true ;  
//               Serial.print("OK");
//             } 
//             else
//                 Serial.print("ERROR"); 
//         #else
//             if( lightMeter.begin())
//                flag_lux = true ;   
//         #endif

      
//     }
    
//     lux = lightMeter.readLightLevel();

//     return lux;
// }


    int WeatherStation::rtc_time()
    {
    if (!flag_rtc)
    {
        #if DEBUG
            Serial.print("\necho_debug: Starting RTC... ");
            if (rtc.begin())
                Serial.print("OK");
            else
                Serial.print("ERROR"); 
        #else
            rtc.begin();
        #endif

        flag_rtc = true ;
    }
    DateTime now = rtc.now();


     year =0;
      year = ((now.year() ) & 0xFF00);
      year += ((now.year()) & 0x00FF);
       month = (now.month() & 0xFF);
      day = (now.day() & 0xFF);
       hour = now.hour() & 0xFF;
       minute = now.minute() & 0xFF;
      seconds = now.second() & 0xFF; 
      dayOfWeek = now.dayOfTheWeek() & 0xFF;
    
    return 0;
    }

/*
int classeteste::f1(int f1a)
{
    int temp = f1a + p1;
    return temp;
}

int classeteste::f2(int f2a)
{
    int temp = f2a + p2 ;
    return temp;
}
*/