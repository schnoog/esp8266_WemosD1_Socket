
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