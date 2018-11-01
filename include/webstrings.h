

String strPageHeader = "<!DOCTYPE HTML><html lang='de'><head><meta content='de' http-equiv='Content-Language'><title>ESP8266-MinWebServer</title><meta charset='UTF-8'></head><body><center>";


String strPageFooter = "</center></body></html>";


String basicForm(String strInterval){
    int intSet = strInterval.toInt();
    intSet = intSet / 1000;
    String strInt = String(intSet);
    String tmp =    "<h2>Interval length (s)</h2><form method='post'><input type='number' name='interval' value='" + strInt  +"'></br><input type='submit' value='setzen'></form>";
    return tmp;
}