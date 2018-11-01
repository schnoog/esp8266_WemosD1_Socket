#include "CMMCEasy.h"
CMMCEasy easy;
CMMC_Interval &interval = easy.interval;







void interval_setup(){
    pinMode(FANPIN, OUTPUT);
    FanStatus = 1;
}

void interval_loop(){
  int intv = FanInt.toInt();
  if (intv < 1000){
    intv = 10000;
  }

    interval.every_ms(intv, [&]() {
      if (FanStatus == 1){
        FanStatus = 0;
      }else{
        FanStatus = 1;
      }
      SwitchCount = SwitchCount + 1;
    });
//
    interval.every_ms(10001, [&]() {
      Serial.println("Alive");
    });
//
    interval.every_ms(5002, [&]() {
      Serial.println(read_interval());
    });

    interval.every_ms(8003, [&]() {
      Serial.print("Current looptime: " );
      Serial.print(intv);
      Serial.println(" ms");
    });

}