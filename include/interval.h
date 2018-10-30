#include "CMMCEasy.h"
CMMCEasy easy;
CMMC_Interval &interval = easy.interval;

#define FANPIN 7

int FanStatus;


void interval_loop(){
// 
interval.every_ms(600000, [&]() {
      if (FanStatus == 1){
        FanStatus = 0;
      }else{
        FanStatus = 1;
      }
    Serial.printf("M = %lu\n", millis());
    Serial.println(FanStatus);
  });
//
interval.every_ms(10000, [&]() {
    Serial.println("Alive");
  });






}