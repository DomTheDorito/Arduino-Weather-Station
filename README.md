# Arduino-Weather-Station
Weather station using an Arduino, ESP-01S, and a variety of sensors


# Foreword:
This project was a passion project of mine to achieve a few goals, mainly publishing the code to a local dashboard, and also publishing it as weather data to the APRS-IS network.
With that being said, all of those files will be in this repo. If you wish to only use portions of it, it will be addressed in the readme later on.

This is a work in progress, so expect this readme to change frequently in the coming days or weeks.



At a low level of understanding, the Arduino pulls information from the sensors, and formats them into a JSON format string.
The ESP then reads it from the TX pin of the arduino and hosts a very basic webpage with the JSON data on the page.
From there the dashboard pulls the JSON data and plots it on a graph; the C++ program pulls the JSON data with cURL and generates a wxnow.txt file.
The wxnow.txt can be used to send weather data to the APRS network via YAAC if you're a licensed amateur radio operator.

# Hardware:
Arduino Nano
ESP-01S
DHT-11
ALS-PT19 
MPl115A2

# Putting it all together:
Photos coming soon.

# Prerequisites:
Arduino Libraries - DHT.h, Wire.h, Adafruit_MPL115A2
ESP Libraries - ESP8266WiFi.h, ESP8266WebServer.h
C++ Libraries - nlohmann/json, curl.


# Editing files to your needs:
You will need to edit a few lines across your code, namely the top of your ESP code for your WiFi information (You'll get that when you upload the code to your ESP-01S, and the ESPs IP address in script.js and cppAprs.cpp

# HTML/Dashboard:
You can choose to host the site however you wish. Obviously a local web server will be the easiest, but you could possibly host it remotely.

# Arduino/ESP:
Uploading code to the Arduino and ESP is pretty straight forward. Help will be provided in the wiki if you get stuck.

# C++:
Be sure you have the required libraries installed before you compile your code.
Once compiled, you may a JSON parsing error or a 0 value error. This is a known issue on on the list of bugs to be squashed.
