
int shell_reader(char * data)
{
  // Wrapper for Serial.read() method
  if (Serial.available()) {
    *data = Serial.read();
    return 1;
  }
  return 0;
}


/**
 * Function to write data to serial port
 * Functions to write to physical media should use this prototype:
 * void my_writer_function(char data)
 */
void shell_writer(char data)
{
  // Wrapper for Serial.write() method
  Serial.write(data);
}

int command_setinterval(int argc, char** argv){
    int i;
    for(i=0; i<argc; i++)
    {
    if (i == 1){
        write_interval(argv[i]);
    }

    }    
    
return 0;
}

int command_getinterval(int argc, char** argv){
    String test = read_interval();
    Serial.println("Saved interval:" + test);
    Serial.println("Global var:" + FanInt);
return 0;
}


int command_test(int argc, char** argv)
{
  int i;

  shell_println("-----------------------------------------------");
  shell_println("SHELL DEBUG / TEST UTILITY");
  shell_println("-----------------------------------------------");
  shell_println("");
  shell_printf("Received %d arguments for test command\r\n",argc);

  // Print each argument with string lenghts
  for(i=0; i<argc; i++)
  {
    // Print formatted text to terminal
    shell_printf("%d - \"%s\" [len:%d]\r\n", i, argv[i], strlen(argv[i]) );
  }

  return SHELL_RET_SUCCESS;
}

int command_time(int argc, char** argv){
      Serial.println("Time:");
      Serial.println(int(hour() * 10000 + minute() * 100 + second()));
      return SHELL_RET_SUCCESS;
}

int command_sync(int argc, char** argv){
    Serial.println("Last Time Sync: ");
    Serial.println(lastTimeSync);
    time_sync();
      return SHELL_RET_SUCCESS;
}

int command_count(int argc, char** argv){
    char buf[50];
    unsigned long tmp;
    tmp = SwitchCount;
    ltoa(tmp, buf, 10);
    Serial.print("Switched ");
    Serial.print(SwitchCount);
    Serial.println(" times with (current rate: " + FanInt + " ms)");
    return SHELL_RET_SUCCESS;
}

int command_wificonfig(int argc, char** argv){
    WiFiManager wifiManager;
    if (!wifiManager.startConfigPortal("OnDemandAP")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
    }
    return SHELL_RET_SUCCESS;
}