#include "Arduino.h"
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>

#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <CMMC_OTA.h>
CMMC_OTA ota;
#include "FS.h"
#include "wman.h"

#include "CMMCEasy.h"
CMMCEasy easy;
CMMC_Interval &interval = easy.interval;

#define FANPIN 7

int FanStatus;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    wifisetup();
    pinMode(13, OUTPUT);
    FanStatus = 1;
}

void loop() {
    // put your main code here, to run repeatedly:
    ota.loop();
  interval.every_ms(301, [&]() {
      if (FanStatus == 1){
        FanStatus = 0;
      }else{
        FanStatus = 1;
      }


    Serial.printf("M = %lu\n", millis());
    Serial.println(FanStatus);
  });

}