/* Disclaimer IoT-Werkstatt CC 4.0 BY NC SA 
       This program is distributed in the hope that it will be useful,
       but WITHOUT ANY WARRANTY; without even the implied warranty of
       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For Ardublock see the
       GNU General Public License for more details. */
#include <Ticker.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

String matrixausgabe_text  = " "; // Ausgabetext als globale Variable

volatile int matrixausgabe_index = 0;// aktuelle Position in Matrix

volatile int matrixausgabe_wait  = 0;// warte bis Anzeige durchgelaufen ist

typedef void (*func_ptr)(void);
func_ptr WebServerHousekeeping = yield;

//--------------------------------------- Charlieplex Matrix
Adafruit_IS31FL3731_Wing matrix = Adafruit_IS31FL3731_Wing();

Ticker matrixausgabe;
void matrixUpdate(){ // Update Charlieplexmatrix über Ticker
    int anzahlPixel=(matrixausgabe_text.length())*6;
    if (anzahlPixel > 15) { // Scrollen 
     if (matrixausgabe_index >= -anzahlPixel) {
      matrix.clear();
      matrix.setCursor(matrixausgabe_index,0);
      matrix.print(matrixausgabe_text);
      matrixausgabe_index--;
     } else {matrixausgabe_index = 12;matrixausgabe_wait=0;}
    } else {// nur 3 Zeichen lang-> kein Scroll 
     matrix.setCursor(0,0);
     matrix.print(matrixausgabe_text);
     matrixausgabe_wait  = 0; // no wait
   }
}
void matrixAnzeige(String text, int wait) { // Setze Ausgabetext
 if (matrixausgabe_text  != text) { // update nur bei neuem Text 
    matrix.clear();
    matrixausgabe_index = 10;
    matrixausgabe_text  = text;
    matrixausgabe_wait  = wait;
    while (matrixausgabe_wait) {
       delay(100);  
       (*WebServerHousekeeping)(); // look at WebCients
      } // warte bis Text einmal ausgegeben ist
 }
};

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
"    <img src=' data:image/jpeg;base64,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' alt=''>"
"  </CENTER> "
	   "<h1>"
"Team xyz"
"</h1>"
	   "<FORM action=\"/\" method=\"post\">"
     "<P>"
        "Deine Nachricht<br>"
        "<input type=\"range\" min=\"1\" max=\"100\" name=\"message\" onchange=\"this.form.submit()\"><br>"
        "<INPUT type=\"text\" name=\"message\" onchange=\"this.form.submit()\"><br>"
	    "</P>"
	   "</FORM>";
const char INDEX_HTML_END[] =
	 "</body>"
	"</html>";
//------------------------------ Server Unterprogramm zur Bearbeitung der Anfragen
void serverHomepage() { 
 if (server.hasArg("message")) {// Wenn neuer Anzeigetext eingetroffen,
   matrixausgabe_text = server.arg("message");     // dann Text vom Client einlesen
   matrixausgabe_index=0;
   Serial.print("Server Anzeigetext: "); Serial.println(matrixausgabe_text);
 }
 String html=String(INDEX_HTML_START);  // Hompage zusammenbauen
 html=html+String(INDEX_HTML_END);      // Http-Body abschliessen 
 server.send(200, "text/html", html); // Homepage ausgeben
}


void setup(){ // Einmalige Initialisierung
Serial.begin(115200);
Wire.begin(); // ---- Initialisiere den I2C-Bus 

if (Wire.status() != I2C_OK) Serial.println("Something wrong with I2C");

matrix.begin();// Matrix initialisieren 
delay(10);
matrix.clear(); 

matrix.setTextColor(60); // Helligkeit begrenzen 
matrixausgabe.attach(0.09, matrixUpdate); // zyklisch aktualisieren

//------------ HTML-Server initialisieren
server.on("/", serverHomepage);
 server.begin();// Server starten
matrixAnzeige(String("Hallo IoT"),1);
//------------ WLAN initialisieren 
WiFi.disconnect();WiFi.persistent(false);
WiFi.mode(WIFI_STA);
delay(100);
Serial.print ("\nWLAN connect to:");

//----------WERTE ENTSPRECHEND ERSETZEN
Serial.print("WIFI-NAME");
WiFi.begin("WIFI-NAME","PASSWORT");
//-------------------------------------

while (WiFi.status() != WL_CONNECTED) { // Warte bis Verbindung steht 
  delay(500); Serial.print(".");
};
Serial.println ("\nconnected, meine IP:"+ WiFi.localIP().toString());
matrixausgabe_text = " Meine IP:" + WiFi.localIP().toString();
myOwnIP = WiFi.localIP();
matrixausgabe_index=0;

}

void loop() { // Kontinuierliche Wiederholung 
//Block------------------------------ HTML-Server
server.handleClient(); //Homepageanfragen versorgen
delay(1);
 server.handleClient();// Web-Server bedienen
} //end loop
