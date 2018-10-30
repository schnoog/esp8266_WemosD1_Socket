

ESP8266WebServer server(80);
const char* www_username = "admin";
const char* www_password = "esp8266";
//////////////////////////////////////////////////
void webserver_setup(){
  server.on("/", []() {
    if (!server.authenticate(www_username, www_password)) {
      return server.requestAuthentication();
    }
    server.send(200, "text/plain", "Login OK");
  });
  server.begin();

  Serial.print("Open http://");
  Serial.print(WiFi.localIP());
  Serial.println("/ in your browser to see it working");
}
//////////////////////////////////////////////////
void webserver_loop(){
    server.handleClient();
}