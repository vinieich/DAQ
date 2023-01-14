#if !defined(pinSetup_h)
#define pinSetup_h

#if (uC == 1)
#define windvanePin A0
#define anemometerPin 2
#define pluviometerPin 3
#define DHTPIN 5 // Digital pin connected to the DHT sensor
#define leafwetnessDPin 6
#define leafwetnessAPin A1
#define soilhumidityPin A2
#define soiltemperaturePin 7

#define Vi 5
#define adcresolution 1024
#elif (uC == 2)

/// GPIO a ser utilizado pelo respectivo módulo no microcontrolador
/// @name PINS
///@{
#define DHT_TYPE DHT11
#define DHT_PIN 32
#define HW484_PIN 2
#define RTC_CLOCK_PIN 25
#define RTC_DATA_PIN 33
#define MQ2_PIN 36
///@}

#define windvanePin 36
// #define raingaugePin 39
#define raingaugePin 32 // needs interruption: 39 doenst work
#define leafwetnessAPin 34
#define soilhumidityPin 35
#define soiltemperaturePin 26
#define anemometerPin 39
#define uvlevelPin 33

#define ledPin 15

#define Vin 3.3
#define adcresolution 4096
#endif

/**
 *  DHT
 */
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

#endif // pinSetup_h
