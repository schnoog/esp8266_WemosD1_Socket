#include "Arduino.h"

#include "globals.h"

#include "filework.h"
#include "wman.h"
#include "webtime.h"
#include "webserver.h"

#include "console.h"


#include "interval.h"

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    wifisetup();  
    webserver_setup();
    filework_setup();
    console_setup();
    time_setup();
    interval_setup();    
}

void loop() {
    // put your main code here, to run repeatedly:
    ota.loop();
    webserver_loop();
    interval_loop();
    console_loop();
    time_loop();
}