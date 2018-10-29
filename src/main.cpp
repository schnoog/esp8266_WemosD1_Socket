#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>

#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <CMMC_OTA.h>
CMMC_OTA ota;
#include "wman.h"





void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    wifisetup();

}

void loop() {
    // put your main code here, to run repeatedly:
    ota.loop();

}