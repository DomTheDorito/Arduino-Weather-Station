/*
Private Open Source License 1.0 Copyright 2024 Dominic Hord

https://github.com/DomTheDorito/Private-Open-Source-License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the “Software”), to deal in the Software without limitation 
the rights to personally use, copy, modify, distribute, and to permit persons to whom the Software 
is furnished to do so, subject to the following conditions:

1. The above copyright notice and this permission notice shall be included in all copies or substantial 
portions of the Software.

2. The source code shall not be used for commercial purposes, including but not limited to sale of the 
Software, or use it products intended for sale, unless express writen permission is given by the source creator.

3. Attribution to source work shall be made plainly available in a reasonable manner.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED 
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
THIS LICENSE MAY BE UPDATED OR REVISED, WITH NOTICE ON THE POS LICENSE REPOSITORY.
*/


#include "DHT.h"
#include <Wire.h>
#include <Adafruit_MPL115A2.h>


#define DHTPIN 2 //Pin D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

Adafruit_MPL115A2 mpl115a2;
/*
Pressure sensor pinout:
VDD: 5V
GND: GND
SDA: A5
SCL: A4

Light Sensor Pinout:
+: 5V
OUT: A1
-: GND

ESP-01S Pinout
TX: RX
RX: TX
VCC: 3.3v
GPIO0: 3.3v
GPIO2: 3.3v
*/


int light = 0;
String cwop;

void setup()
{
  Serial.begin(115200);
  Serial.println("Humidity and Temperature");

  Serial.println("Getting barometric pressure ...");
  if (! mpl115a2.begin()) {
    Serial.println("Sensor not found! Check wiring");
    while (1);
  }

  dht.begin();
}

void loop()
{
  delay(10000);

  light = analogRead(A1);

  float h = dht.readHumidity();

  float t = dht.readTemperature();


  float pressureKPA = 0, temperatureC = 0;    

  pressureKPA = mpl115a2.getPressure();  
  //Serial.print("Pressure (kPa): "); Serial.print(pressureKPA, 4); Serial.println(" kPa");

  temperatureC = mpl115a2.getTemperature();  
  //Serial.print("Temp (*C): "); Serial.print(temperatureC, 1); Serial.println(" *C");

  String slight = String(light, DEC);
  String spressureKPA = String(pressureKPA, 4);
  String st = String(t, 2);
  String sh = String(h, 2);

  String jsonString = "{";
  jsonString += "\"light\": \"" + slight + "\", ";
  jsonString += "\"humidity\": " + sh + ", ";
  jsonString += "\"temp\": " + st + ", ";
  jsonString += "\"pressure\": " + spressureKPA;
  jsonString += "}";

  Serial.println(jsonString);
  Serial.println();

  
  delay(1000);
}
