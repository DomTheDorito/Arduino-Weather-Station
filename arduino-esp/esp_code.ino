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


#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "YOUR WIFI SSID";
const char *password = "YOUR PASSWORD";

ESP8266WebServer server(80);


void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    server.enableCORS(true);

    // Handle root URL
    server.on("/", HTTP_GET, []() {
        server.send(200, "application/json", Serial.readString());
    });

    // Start server
    server.begin();
}

void loop() {
    server.handleClient();
}

