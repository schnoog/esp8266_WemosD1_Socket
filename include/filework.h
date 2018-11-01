
#include "FS.h"

String SaveFile = "/interval.txt";

void write_interval(String strIntVal){
        File SF = SPIFFS.open(SaveFile,"w");
        if (!SF) {
            Serial.println("file open failed");
        }else{
            FanInt = strIntVal;
            SF.println(strIntVal);
            SF.close();
        }
}

String read_interval(){
        File SF = SPIFFS.open(SaveFile,"r");
        String strTRO = "";
        if(!SF){
            Serial.println("file open failed");
        }else{
            strTRO=SF.readStringUntil('\n');
            SF.close();
        }
        FanInt = strTRO;
    return strTRO;
}

void filework_setup(){
    SPIFFS.begin();
    if(!SPIFFS.exists(SaveFile)){
        write_interval("600000");
    }
}

void filework_stop(){
    SPIFFS.end();
}

String read_file(String FileToRead){
        File SF = SPIFFS.open(FileToRead,"r");
        String strTRO = "";
        if(!SF){
            Serial.println("file open failed");
        }else{
            strTRO=SF.readString();
//            strTRO=SF.readStringUntil('\n');
            SF.close();
        }
        FanInt = strTRO;
    return strTRO;
}
