#include "CMMCEasy.h"
CMMCEasy easy;
CMMC_Interval &interval = easy.interval;







void interval_setup(){
    pinMode(FANPIN, OUTPUT);
    FanStatus = 1;
    String test = read_interval();
    Serial.println("Setup - set interval to "+ FanInt);
}

void interval_loop(){
  int intv = FanInt.toInt();
  if (intv < 1000){
    intv = 1000;
  }

    interval.every_ms(intv, [&]() {
      if (FanStatus == 1){
        FanStatus = 0;
        digitalWrite(FANPIN,LOW);
      }else{
        FanStatus = 1;
        digitalWrite(FANPIN,HIGH);
      }
      SwitchCount = SwitchCount + 1;
    });


}