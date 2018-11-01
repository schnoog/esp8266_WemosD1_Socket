

#define CONFIG_SHELL_MAX_COMMANDS 10 // manuell in shell.h angepasst....
#include <Shell.h>

#include "console_commands.h"

int command_help(int argc, char** argv){
    Serial.println("Shell-help");
    Serial.println("Available commands:");
    Serial.println("help -- This help");
    Serial.println("set X -- Set interval to X milliseconds");
    Serial.println("time -- Get the current time");
    Serial.println("get -- get saved interval");
    Serial.println("sync -- sync time");
//    Serial.println("");
//    Serial.println("");
//    Serial.println("");
    Serial.println("test -- prebuilt test function");
    return SHELL_RET_SUCCESS;
}


void console_setup(){
  shell_init(shell_reader, shell_writer, 0);
  shell_register(command_help, PSTR("help"));
  shell_register(command_sync, PSTR("sync"));
  shell_register(command_getinterval,PSTR("get"));
  shell_register(command_test, PSTR("test"));
  shell_register(command_setinterval,PSTR("set"));
  shell_register(command_time, PSTR("time"));
  shell_register(command_count,PSTR("count"));
}

void console_loop(){
  shell_task();
}