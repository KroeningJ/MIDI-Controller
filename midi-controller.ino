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
const char INDEX_HTML[] =
  "<!DOCTYPE html>"
  "<html>"
  "<head>"
  "  <title>MIDI Controller Surface</title>"
  "  <style>"
  "    @import url('https://fonts.googleapis.com/css2?family=VT323&display=swap');"
  ""
  "    body {"
  "      background-color: #222;"
  "      color: #fff;"
  "      font-family: 'VT323', monospace;"
  "      margin: 0;"
  "      padding: 0;"
  "    }"
  ""
  "    .container {"
  "      display: flex;"
  "      flex-direction: column;"
  "      justify-content: center;"
  "      align-items: center;"
  "      height: 100vh;"
  "    }"
  ""
  "    .rounded-rectangle {"
  "      background-color: rgba(255, 255, 255, 0.1);"
  "      border-radius: 10px;"
  "      padding: 20px;"
  "      margin: 10px;"
  "    }"
  ""
  "    .slider-container {"
  "      text-align: center;"
  "      margin: 10px;"
  "    }"
  ""
  "    .slider-label {"
  "      font-family: 'VT323', monospace;"
  "      margin-top: 10px;"
  "      margin-bottom: 30px;"
  "    }"
  ""
  "    .retro-display {"
  "      font-family: 'VT323', monospace;"
  "      font-size: 20px;"
  "      color: #0f0;"
  "      display: inline-block;"
  "      padding: 2px 4px;"
  "      width: 24px;"
  "      text-align: center;"
  "      box-shadow: 0 0 15px rgba(0, 255, 0, 0.5);"
  "      border-radius: 4px;"
  "      margin-bottom: 10px;"
  "    }"
  ""
  "    .title {"
  "      font-family: 'VT323', monospace;"
  "      font-size: 30px;"
  "      color: #0f0;"
  "      margin-bottom: 40px;"
  "      text-align: center;"
  "      border-radius: 4px;"
  "      box-shadow: 0 0 15px rgba(0, 255, 0, 0.5);"
  "    }"
  ""
  "    .slider {"
  "        -webkit-appearance: none;"
  "        appearance: none;"
  "        width: 100%;"
  "        height: 25px;"
  "        background: linear-gradient(to right, #444, #111);"
  "        outline: none;"
  "        opacity: 0.7;"
  "        -webkit-transition: .2s;"
  "        transition: opacity .2s;"
  "    }"
  ""
  "    .slider:hover {"
  "        opacity: 1;"
  "    }"
  ""
  "    .slider::-webkit-slider-thumb {"
  "        -webkit-appearance: none;"
  "        appearance: none;"
  "        width: 25px;"
  "        height: 25px;"
  "        background: #04AA6D;"
  "        cursor: pointer;"
  "    }"
  ""
  "    .slider::-moz-range-thumb {"
  "        cursor: pointer;"
  "        width: 16px;"
  "        height: 36px;"
  "        background-color: #666;"
  "        border-radius: 4px;"
  "    }"
  ""
  "  </style>"
  "</head>"
  "<body>"
  ""
  "  <div class=\"container\">"
  "      <div class=\"rounded-rectangle\">"
  "          <div class=\"title\">MIDI-Controller</div>"
  ""
  "          <FORM action=\"/\" method=\"post\">"
  "              <div class=\"slider-container\">"
  "                  <output class=\"retro-display\" id=\"display1\"></output>"
  "                  <input type=\"range\" min=\"0\" max=\"127\" name=\"slider1\" onchange=\"this.form.submit()\" , class=\"slider\">"
  "                  <div class=\"slider-label\">Slider 1</div>"
  "              </div>"
  "          </FORM>"
  ""
  "          <FORM action=\"/\" method=\"post\">"
  "              <div class=\"slider-container\">"
  "                  <output class=\"retro-display\" id=\"display2\"></output>"
  "                  <input type=\"range\" min=\"0\" max=\"127\" name=\"slider2\" onchange=\"this.form.submit()\" , class=\"slider\">"
  "                  <div class=\"slider-label\">Slider 2</div>"
  "              </div>"
  "          </FORM>"
  ""
  "          <FORM action=\"/\" method=\"post\">"
  "              <div class=\"slider-container\">"
  "                  <output class=\"retro-display\" id=\"display3\"></output>"
  "                  <input type=\"range\" min=\"0\" max=\"127\" name=\"slider3\" onchange=\"this.form.submit()\" , class=\"slider\">"
  "                  <div class=\"slider-label\">Slider 3</div>"
  "              </div>"
  "          </FORM>"
  ""
  "          <FORM action=\"/\" method=\"post\">"
  "              <div class=\"slider-container\">"
  "                  <output class=\"retro-display\" id=\"display4\"></output>"
  "                  <input type=\"range\" min=\"0\" max=\"127\" name=\"slider4\" onchange=\"this.form.submit()\" , class=\"slider\">"
  "                  <div class=\"slider-label\">Slider 4</div>"
  "              </div>"
  "          </FORM>"
  ""
  "      </div>"
  "  </div>"
  ""
  "  <script>"
  ""
  "      function enableSliderDrag(index) {"
  "          const slider = document.getElementsByName(`slider${index}`)[0];"
  "          const output = document.getElementById(`display${index}`);"
  "          output.innerHTML = slider.value;"
  ""
  "          slider.oninput = function () {"
  "              output.innerHTML = this.value;"
  "          }"
  "      }"
  ""
  "      enableSliderDrag(1)"
  "      enableSliderDrag(2)"
  "      enableSliderDrag(3)"
  "      enableSliderDrag(4)"
  "  </script>"
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
String html=String(INDEX_HTML); 

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
