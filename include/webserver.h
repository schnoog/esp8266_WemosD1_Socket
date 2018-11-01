
#include "webstrings.h"
#include <detail\RequestHandlersImpl.h>

ESP8266WebServer server(80);
const char* www_username = "admin";
const char* www_password = "esp8266";
//////////////////////////////////////////////////
void webserver_setup(){
  server.on("/", []() {
    if (!server.authenticate(www_username, www_password)) {
      return server.requestAuthentication();
    }
    server.send(200, "text/html", strPageHeader + basicForm(FanInt) + strPageFooter);
  });

  server.on("/set", []() {
    if (!server.authenticate(www_username, www_password)) {
      return server.requestAuthentication();
    }
  String message = "Anfrage\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  String strSet;
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    if(server.argName(i) == "interval"){
        strSet = server.arg(i) + "000";
Serial.println("Set by web to " + strSet);
        write_interval(strSet);
        String dummy = read_interval();
    }
  }


  Serial.println(message);
    server.send(200, "text/html", strPageHeader + basicForm(FanInt) + strPageFooter);
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

// Sendet "Not Found"-Seite
void notFound()
{ String HTML = F("<html><head><title>404 Not Found</title></head><body>"
                  "<h1>Not Found</h1>"
                  "<p>The requested URL was not found on this webserver.</p>"
                  "</body></html>");
  server.send(404, "text/html", HTML);
}

// Es wird versucht, die angegebene Datei aus dem SPIFFS hochzuladen
void handleUnknown()
{ String filename = server.uri();

  File pageFile = SPIFFS.open(filename, "r");
  if (pageFile)
  { String contentTyp = StaticRequestHandler::getContentType(filename);
    server.streamFile(pageFile, contentTyp);
    pageFile.close();
  }
  else
    notFound();
}