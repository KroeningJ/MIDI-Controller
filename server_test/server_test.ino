#include <Ticker.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <MIDI.h>

typedef void (*func_ptr)(void);
func_ptr WebServerHousekeeping = yield;

MIDI_CREATE_DEFAULT_INSTANCE();

IPAddress myOwnIP; // ownIP for mDNS 

ESP8266WebServer server(80);
//------------------------------ Server Hompage html-Code
const char INDEX_HTML_START[] =
 "<!DOCTYPE HTML>"
  "<html>"
   "<head>"
   "<meta name = \"viewport\" content = \"width = device-width, initial-scale = 1.0, maximum-scale = 1.0, user-scalable=0\">"
	   "<title>ESP8266 IoT.OCTOPUS</title>"
	 "</head>"
	 "<body>"
"  <CENTER>"
	   "<h1>"
"MIDI Controller 1.0"
"</h1>"
	   "<FORM action=\"/\" method=\"post\">"
     "<P>"
        "Slider 1<br>"
        "<input type=\"range\" min=\"0\" max=\"127\" name=\"slider1\" onchange=\"this.form.submit()\"><br>"
     "</P>"
     "</FORM>"
     "<FORM action=\"/\" method=\"post\">"
     "<P>"
        "Slider 2<br>"
        "<input type=\"range\" min=\"0\" max=\"127\" name=\"slider2\" onchange=\"this.form.submit()\"><br>"
     "</P>"
     "</FORM>"
     "<FORM action=\"/\" method=\"post\">"
     "<P>"
        "Slider 3<br>"
        "<input type=\"range\" min=\"0\" max=\"127\" name=\"slider3\" onchange=\"this.form.submit()\"><br>"
     "</P>"
     "</FORM>"
     "<FORM action=\"/\" method=\"post\">"
     "<P>"
        "Slider 4<br>"
        "<input type=\"range\" min=\"0\" max=\"127\" name=\"slider4\" onchange=\"this.form.submit()\"><br>"
     "</P>"
     "</FORM>"
     "<FORM action=\"/\" method=\"post\">"
     "<P>"
        "Slider 5<br>"
        "<input type=\"range\" min=\"0\" max=\"127\" name=\"slider5\" onchange=\"this.form.submit()\"><br>"
     "</P>"
     "</FORM>"
     "<FORM action=\"/\" method=\"post\">"
     "<P>"
        "Slider 6<br>"
        "<input type=\"range\" min=\"0\" max=\"127\" name=\"slider6\" onchange=\"this.form.submit()\"><br>"
     "</P>"
	   "</FORM>"
"</CENTER>";
const char INDEX_HTML_END[] =
	 "</body>"
	"</html>";
//------------------------------ Server Unterprogramm zur Bearbeitung der Anfragen
void serverHomepage() { 
 if (server.hasArg("slider1")) {
 MIDI.sendControlChange(70, server.arg("slider1").toInt(), 1);  
 }
 if (server.hasArg("slider2")) {
 MIDI.sendControlChange(71, server.arg("slider2").toInt(), 1);  
 }
 if (server.hasArg("slider3")) {
 MIDI.sendControlChange(72, server.arg("slider3").toInt(), 1);  
 }
 if (server.hasArg("slider4")) {
 MIDI.sendControlChange(73, server.arg("slider4").toInt(), 1);  
 }
 if (server.hasArg("slider5")) {
 MIDI.sendControlChange(74, server.arg("slider5").toInt(), 1);  
 }
 if (server.hasArg("slider6")) {
 MIDI.sendControlChange(75, server.arg("slider6").toInt(), 1);  
 }
 String html=String(INDEX_HTML_START);  // Hompage zusammenbauen
 html=html+String(INDEX_HTML_END);      // Http-Body abschliessen 
 server.send(200, "text/html", html); // Homepage ausgeben
}


void setup(){ // Einmalige Initialisierung
MIDI.begin(1);
Serial.begin(115200);
//------------ HTML-Server initialisieren
server.on("/", serverHomepage);
server.begin();// Server starten
//------------ WLAN initialisieren 
WiFi.disconnect();WiFi.persistent(false);
WiFi.mode(WIFI_STA);

//----------WERTE ENTSPRECHEND ERSETZEN
Serial.print("WIFI-NAME");
WiFi.begin("WIFI-NAME","PASSWORT");
//-------------------------------------

while (WiFi.status() != WL_CONNECTED) { // Warte bis Verbindung steht 
  delay(500); Serial.print(".");
};
myOwnIP = WiFi.localIP();

}

void loop() { // Kontinuierliche Wiederholung 
//Block------------------------------ HTML-Server
server.handleClient(); //Homepageanfragen versorgen
delay(1);
 server.handleClient();// Web-Server bedienen
} //end loop
