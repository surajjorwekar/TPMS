/*Code to get data from BMP180 Air Pressure Monitoring System
and trasmitting it to central arduino*/
#include "Barometer.h"
#include <Wire.h>
#define rfTransmitPin 4
float temperature;
float pressure;
float atm;
float altitude;
float psi = 0.145038;
Barometer myBarometer;

void setup()
{
  Serial.begin(9600);
  myBarometer.init();
  pinMode(rfTransmitPin, OUTPUT); 
}

void loop()
{
  while(1)
  {
    temperature = myBarometer.bmp085GetTemperature(myBarometer.bmp085ReadUT()); //Get the temperature, bmp085ReadUT MUST be called first
    pressure = myBarometer.bmp085GetPressure(myBarometer.bmp085ReadUP())/1000;//Get the temperature
    altitude = myBarometer.calcAltitude(pressure); //Uncompensated calculation - in Meters 
    atm = pressure / 101325; 
    if((pressure*psi) < 30 || (pressure*psi) < 35)
      digitalWrite(rfTransmitPin,HIGH);
    else
      digitalWrite(rfTransmitPin,LOW);
    delay(1000);
  }
   
  
}

/*
  Serial.print("Temperature: ");
  Serial.print(temperature, 2); //display 2 decimal places
  Serial.println("deg C");

  Serial.print("Pressure: ");
  Serial.print(pressure, 0); //whole number only.
  Serial.println(" Pa");

  Serial.print("Ralated Atmosphere: ");
  Serial.println(atm, 4); //display 4 decimal places

  Serial.print("Altitude: ");
  Serial.print(altitude, 2); //display 2 decimal places
  Serial.println(" m");

  Serial.println();

  delay(1000); //wait a second and get values again.*/
