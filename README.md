# Projektdokumentation *MIDI-Controller*
Projekt-Team: Jens Kröning, Moritz Reischenbach, Felix Riedel

Start Datum: 08.05.2023

End Datum: 17.07.2023

- [Projektdokumentation *MIDI-Controller*](#projektdokumentation-midi-controller)
  - [1 Einführung](#1-einführung)
    - [1.1 Motivation](#11-motivation)
    - [1.2 Zielstellung](#12-zielstellung)
    - [1.3 Vorgehensweise](#13-vorgehensweise)
   - [2 Konzept](#2-konzept)
   - [3 Setup](#3-setup)
      - [3.1 Hardware](#31-hardware)
      - [3.2 Hardwareaufbau](#32-hardwareaufbau)
      - [3.2 Software](#33-software)
    - [4 Programmierung](#4-programmierung)
    - [5 Musikproduktion mit Ableton](#5-musikproduktion-mit-ableton)
      - [5.1 Grundlage](#51-grundlage)
      - [5.2 Vorgehen](#52-vorgehen)
      - [5.3 Ergebnis](#53-ergebnis)
    - [6 Projektergebnisse](#6-projektergebnisse)
    - [7 Fehlerbetrachtung](#7-fehlerbetrachtung)
    - [8 Fazit und Ausblick](#7-fazit-und-ausblick)
      - [8.1 Fazit](#81-fazit)
      - [8.2 Ausblick](#82-ausblick)
---

## 1 Einführung

### 1.1 Motivation
Diese Projektdokumentation enthält alle relevanten Informationen für das kommende Projekt "IoT MIDI Controller". Neben den Anforderungen finden sich hier die Kontaktdaten aller Teammitglieder sowie die Ziele für Anbieter und Nutzer. Zusätzlich wird das Projekt inhaltlich abgegrenzt. Des Weiteren können diesem Dokument die verschiedenen Rahmenbedingungen entnommen werden. Dazu gibt es einen Zeitplan, eine Übersicht über die verschiedenen Risiken und eine entsprechende Qualitätssicherung. Ein MIDI-Controller ist ein elektronisches Musikinstrument, das über MIDI-Schnittstellen mit anderen Geräten verbunden werden kann. Mit ihm lassen sich verschiedene Musikprogramme und Synthesizer steuern. Die Verwendung von MIDI-Controllern ist in der Musikproduktion weit verbreitet. In diesem Projekt soll ein MIDI-Controller mit Hilfe eines Arduino-Boards erstellt werden. Dazu müssen sowohl die technischen Voraussetzungen als auch das Ziel genau definiert werden.

### 1.2 Zielstellung
Ziel des Projekts ist es, einen funktionsfähigen MIDI-Controller zu erstellen, der unabhängig mit einem Arduino-Board programmiert werden kann. In der erfolgreichen Umsetzung soll der MIDI-Controller über verschiedene Knöpfe und Regler verfügen, die über MIDI-Signale Notenwerte und Steuerbefehle an andere Geräte senden können. Die Programmierung soll mit einer geeigneten Arduino-Entwicklungsumgebung erfolgen, so dass der MIDI-Controller flexibel an unterschiedliche Anforderungen angepasst werden kann. Der MIDI-Controller soll einfach und intuitiv zu bedienen sein und es dem Benutzer ermöglichen, seine eigene Musik zu produzieren. Außerdem soll der MIDI-Controller über eine Webanwendung ferngesteuert werden können. Die MIDI-Signale des Controllers werden über USB, Bluetooth oder optional über WLAN an den Endanwender gesendet.
Das Projekt soll im Rahmen des Moduls M.1.6 Methoden der Wissensverarbeitung im Sommersemester 2023 durchgeführt werden. Durch die erfolgreiche Umsetzung des Projekts soll durch die Programmierung von Soft- und Hardware erkenntnisreiches Lernen im Kontext der Wissensverarbeitung entwickelt werden.

### 1.3 Vorgehensweise
Nachdem eine konkrete Zielstellung für das vorliegende Projekt definiert wurde, lässt sich die Projektarbeit in fünf Hauptaspekte unterteilen: 

1. Hardwareauswahl
2. Hardwareaufbau
3. Programmierung
4. Musik-Produktion mit Ableton Live
5. Test und Fehlerbehebung

Zuerst wurde der Zweck und die Funktionen des Projektes definiert. Der MIDI Controller soll in der Lage sein durch die gezielte Verknüpfung mit Ableton Live bestehende Soundmuster zu ändern. Hierfür sollen eine Auswahl an fünf Steuerelementen genutzt werden. Anstatt physischer Tasten, Drehregler oder Schieberegler werden online Slider programmiert, welche beliebig mit den Effekten in Ableton Live verknüpft werden können. Für den MIDI Controller wurde ein WLAN-fähiges Octopus-Board als Grundlage genutzt. Das genaue Setup kann im späteren Kapitel *Setup* nachgelesen werden. Nachdem die Funktionen und die damit verbundene Hardwareauswahl erörtert wurde, folgten einige Überlungen zur Webseite und Programmierung. Da die Slider nicht physisch an dem Octopus-Board angebracht werden, sondern als IoT-Anwendung mit einem HTML-Server kommunizieren sollen, bedarf es einem entsprechenden Server und der Programmierung der Slider. Außerdem muss das Octopus-Board eine ebenfalls entsprechende Programmierung zur Konnektivität mit Ableton Live beinhalten. Für die abschließende Endpräsentation bedarf es zusätzlich einer Musikproduktion in Ableton Live. Nachfolgend zu diesen anfänglichen Überlegungen und Definitonen im Rahmen der Projektarbeit wird eine nähere Betrachtung der genutzten Hardware vorgenommen und das zugrundeliegende Konzept beschrieben. 

## 2 Konzept
Im nachstehenden Ablaufdiagramm wird die Konzeption zur Erstellung des MIDI-Controllers verdeutlicht. 


![Ablaufdiagramm MWV](https://github.com/KroeningJ/MIDI-Controller/assets/135695441/930e4293-63e6-422f-9f6b-fedf25d988d3)


Hierfür gibt es im ersten Schritt einen lokalen Rechner, welcher eine Grundlage für die Struktur bildet. Dieser lokale Rechner kommuniziert über einen entsprechenden Server, welcher die gewünschten Signale an den Octopus IoT sendet. Durch die Programmierung vom Octopus IoT können die gewünschten Regler und Schieber im MIDI-Device festgelegt werden und mit den entsprechenden Effekten in Ableton verknüpft werden. In diesem Fall wird das MIDI-Device in Form von einem Server erstellt.

## 3 Setup
Im Folgenden wird das Setup für die Projektumsetzung beschrieben. Hierfür erfolgt eine Aufteilung in Hard- und Software. 

### 3.1 Hardware
Für die Erstellung des MIDI-Controllers dient ein Octopus-Board als Grundlage:
- Octopus IoT (Modell ergänzen) 
- USB A to USB Micro B Kabel 
  

### 3.2 Hardwareaufbau 
Die Zusammensetzung der Hardware beläuft sich lediglich auf das Octopus-Board und einem entsprechenden USB-Kabel, welches eine integrierte Datenübertargungs-Funktion hat. Somit kann das Octopus-Board mit einem Rechner verbunden werden. 

### 3.3 Software

#### Octopus QuickStart 
Für die Projektarbeit wird mit dem Octopus IoT gearbeitet. Die Schnellstarteinrichtung und IDE ist unter dem folgenden Link zu finden: 
- Link: https://www.umwelt-campus.de/iot-werkstatt/tutorials/schnellstart-octopus-anschliessen-und-einrichten/page

#### Hairless MIDI 
Hairless Midi wird verwendet, um MIDI-Signale zu lesen, die über die serielle Schnittstelle des Mikrocontrollers gesendet wurden.

- Link: https://projectgus.github.io/hairless-midiserial/?source=post_page---------------------------
- GitHub: https://github.com/projectgus/hairless-midiserial
- Download(Windows): https://www.mediafire.com/file/rlj5s681ds4ashf/hairless-midiserial-0.4-windows.zip/file

#### Loop MIDI
Dieses Programm wird benötigt, um einen virtuellen MIDI-Port zu erstellen, der von der DAW gefunden werden kann.
- Link: https://www.tobias-erichsen.de/software/loopmidi.html

#### Ableton Live DAW
- Link: https://www.ableton.com/de/trial/
  


## 4 Programmierung

Im Folgenden wird die Funktionsweise sowohl für den Octopus, als auch für die HTML Website beschrieben. 

### 4.1 Octopus

Der gegebene Code ist ein Arduino-Sketch, der auf dem ESP8266-Mikrocontroller läuft und einen MIDI-Controller über eine WLAN-Verbindung und eine Webserver-Schnittstelle implementiert. Es ermöglicht die Steuerung von sechs Schiebereglern über eine HTML-basierte Benutzeroberfläche.

Hier eine Beschreibung der wichtigsten Bestandteile des Codes:

Bibliotheken und Initialisierungen:
   - Verschiedene Bibliotheken wie "Ticker", "Wire", "Adafruit_GFX", "Adafruit_IS31FL3731", "ESP8266WiFi" und "ESP8266WebServer"         werden eingebunden.
   - Eine Instanz für die MIDI-Kommunikation wird mit `MIDI_CREATE_DEFAULT_INSTANCE()` erstellt.
   - Eine globale Funktion mit dem Namen `WebServerHousekeeping` wird als Funktionszeiger deklariert und auf "yield" gesetzt.

Konstanten und Variablen:
   - Der HTML-Code für die Startseite und das Ende (INDEX_HTML_START und INDEX_HTML_END) wird definiert. Dieser enthält HTML-           Formulare mit sechs Schiebereglern und einem "Submit"-Button.
   - Eine Variable `myOwnIP` wird deklariert, um die IP-Adresse des ESP8266 zu speichern.
   - Ein ESP8266WebServer-Objekt mit dem Namen `server` wird erstellt und auf Port 80 initialisiert.

3. Setup-Funktion:
   - MIDI wird initialisiert und auf Kanal 1 gestartet.
   - Der serielle Monitor wird mit einer Baudrate von 115200 gestartet.
   - Der Webserver wird gestartet, und die Homepage ("serverHomepage") wird der Haupt-URL "/" zugeordnet.
   - WLAN wird initialisiert, und der ESP8266 verbindet sich mit dem angegebenen WLAN-Netzwerk ("WIFI-NAME" und "PASSWORT"). Der ESP8266 wartet, bis die Verbindung hergestellt ist.

4. Loop-Funktion:
   - In der loop-Funktion werden kontinuierlich zwei Funktionen behandelt:
   - `server.handleClient()` kümmert sich um die Bedienung von Homepage-Anfragen und die Ausgabe der HTML-Seite mit den             Schiebereglern.
   - `server.handleClient()` kümmert sich um die Bedienung des Web-Servers, um die Werte der Schieberegler zu verarbeiten, die der Benutzer über die Webseite ändert.
   - Die Werte der Schieberegler werden über die MIDI-Kommunikation an einen MIDI-Empfänger (z. B. Musiksoftware oder Hardware-Synthesizer) gesendet.

Die Benutzeroberfläche ermöglicht es dem Benutzer, die Werte von sechs Schiebereglern über eine einfache Webseite zu ändern. Wenn der Benutzer einen Schieberegler bewegt, wird der Wert über eine POST-Anfrage an den ESP8266 gesendet, und der ESP8266 leitet die MIDI-Befehle entsprechend weiter. Der MIDI-Kanal, auf dem die Steueränderungen gesendet werden, ist auf Kanal 1 festgelegt.

Wichtig zu erwähen ist, dass die Midi Signale über einen Serial Port (USB) gesendet werden, wodurch man ein extra Programm benötigt (MIDI Serial, welches den Port für Midi freischaltet, welcher für die kommunikation mit dem Arduino verantwortlich ist. 
Hierfür muss ein zusätzliches MIDI Port am PC mit hairless MIDI eingerichtet an den das Signal gesendet wird. Der Port muss dann in der DAW (Ableton) ausgewählt werden. 

### 4.2 HTML Website

Die HTML Website durchlief meherere Versionen, welche nachträglich auf den Octopus abgestimmt werden mussten. V1 beinhaltete einen HTML-Code welcher eine MIDI-Controller-Oberfläche darstellt, die es Benutzern ermöglicht, vier Schieberegler zu verwenden, um MIDI-Werte einzustellen. 

Die Seite besitzt ein ausgewähltes Retro-Design und besteht aus mehreren Elementen, die mithilfe von CSS gestaltet wurden:

Die HTML-Struktur:
Die Seite ist in einem HTML5-Grundgerüst eingebettet und hat einen <head> und <body> Bereich.
Im <head>-Bereich wird der Titel der Seite festgelegt und ein externer Google Font namens "VT323" importiert, der für den Text verwendet wird.
Der <body>-Bereich enthält ein zentrales Container-Div mit der Klasse "container". Darin befindet sich eine abgerundete Rechteck-Box "rounded-rectangle", die die gesamte MIDI-Controller-Oberfläche umschließt.

Die 4 Slider:
Die Schieberegler für die später gesetzten Effekte  werden in einzelnen Slider-Containern "slider-container" gruppiert.
Jeder Slider-Container enthält:
Eine retro-förmige Anzeige "retro-display" mit einer grünen Hintergrundfarbe und grünen Schatten. Diese Anzeige zeigt den aktuellen Wert des Schiebereglers an und hat standardmäßig den Wert "0".

JavaScript-Funktionalität:
Das JavaScript im <script>-Bereich ermöglicht das Ziehen der Slider-Buttons, um den Wert der retro-förmigen Anzeige und den MIDI-Wert zu ändern. Die Slider-Werte gehen von 0 bis 127.
Jeder Slider hat eine entsprechende Funktion (enableSliderDrag), die das Ziehen des Daumens ermöglicht. Diese Funktion wird für vier Schieberegler mit den Indizes 1 bis 4 aufgerufen.
Die Werte der Schieberegler werden mithilfe des localStorage gespeichert, sodass sie nach einem Seitenrefresh erhalten bleiben.

V2 wurde in diesem Fall auf die Benutzung innerhalb des Octopus abgestimmt und mithilfe von ChatGPT als String umgewandelt, um diesen für den ESP lesbar zu machen.

Bei einer Eingabe der Slider werden die möglichen Werte von 0-127 mithilfe einer pos-request an den Server gesendet, welche anschließend vom Octopus verarbeitet werden, welche dann über DAW angesteuert werden können.


### 4.4 MIDI-Controller Surface 

Das Ergebnis des MIDI-Controller Surface kann nachgehend betrachtet werden:

<img width="272" alt="MIDI Controller" src="https://github.com/KroeningJ/MIDI-Controller/assets/135695441/0f3bf8ae-6c78-47b9-8f0c-304c1308f5ee">

## 5 Musikproduktion mit Ableton

Für die Präsentation der Projektergebnisse wird mit Hilfe der Musikproduktionssoftware Ableton Live ein einfacher Beat/Loop gebaut. Dieser kann im Zuge der Präsentation durch die Studierenden mittels des MIDI-Controllers gesteuert und verändert werden. Ziel ist ein individuelles Soundbild durch die vorab definierten Slider-Effekte. 

### 5.1 Grundlage
Ableton Live ist eine professionelle Musikproduktionssoftware, die von vielen Musikern, Produzenten und DJs weltweit genutzt wird. Mit ihrem einzigartigen Ansatz und ihren leistungsstarken Funktionen bietet Ableton Live eine flexible und kreative Plattform für die Komposition, Aufnahme, Bearbeitung, das Arrangement und die Performance von Musik. Durch die Kombination von intuitiver Bedienung, einer Vielzahl von virtuellen Instrumenten und Effekten, fortschrittlicher Audiobearbeitung und einer nahtlosen Integration von Hardware und MIDI-Controllern bietet Ableton Live eine inspirierende Umgebung für die Umsetzung musikalischer Ideen. 

### 5.2 Vorgehen 
Für die Beatproduktion mit Ableton Live werden die foldenden Schritte beachtet. 

1. Konzept
   - Beatkonzept
   - Genre
   - Stimmung
   - Atmospähre
2. Vorbereitung
   - Tempo und Takt festlegen
   - Auswahl an Drums, Instrumenten und Effekten
3. Drum-Programmierung
   - rythmische Drums erstellen
   - Drumsamples auf die gewünschten Schläge festlegen
   - ggf. Fills und Breaks ergänzen
4. Bassline und Harmonien
   - einfügen von Synthesizern, Samples oder Instrumenten
   - Effekte einfügen (Beispielsweise: Reverb, Delay oder Filter)
5. Struktur
   - Struktur-Entwicklung
   - Erstellung von Übergängen, Variationen oder Breaks
6. Mixing und Mastering
   - Klangbild überarbeiten
   - Export Audio 

### 5.3 Ergebnis 
Für die vorliegende Projektarbeit wird eine simple Produktion vorgenommen, da es sich um reine Präsentationszwecke handelt.

![Ableton Live Spur](https://github.com/KroeningJ/MIDI-Controller/assets/135695441/e19c6104-2f11-43f0-b4a8-51e242f4f58e)

![Ableton Live Spur 2](https://github.com/KroeningJ/MIDI-Controller/assets/135695441/391e4cb0-4847-4cf3-ba1a-cf2cdfac17a1)

Den Abbildungen kann die Zusammensetzung der Musikproduktion entnommen werden. Hierfür wurden Kick, Snare, Bass, ein Perc, zwei verschiedene Synthesizer und Hyper Riser genutzt. Dieser ist als mp3.Datei im Repository beigefügt. 






## 6 Projektergebnisse

Das Projektergebnis beläuft sich auf die Steuerung eines MIDI-Controllers innerhalb einer Website, welche durch einen Octopus auf ein Musikproduktionsprogramm, Ableton, übertragen wird. Es wurden 4 verschiedene Slider realisiert, welche mithilfer gesetzter Variablen MIDI-Signale an Ableton senden, um  einen laufenden Song anzupassen. Dies geschieht durch den Einsatz eines Hilfprogramms "MIDI-Serial", welches die MIDI-Signale aufgreifen und weiterverarbeiten kann.   


## 7 Fehlerbetrachtung 

Bei der Betrachtung der Projektarbeit sind einige kritische Punkte zu identifizieren. Ein Hauptproblem besteht in der Schwierigkeit der Einrichtung des MIDI-Signals über den Serial Port (USB). Hierfür wird zusätzliches Programm wie "MIDI Serial" benötigt, um den Port für die MIDI-Kommunikation freizuschalten. Dies ist erforderlich, da der Serial Port normalerweise für die Kommunikation mit dem Arduino verwendet wird, beispielsweise zum Hochladen von einem entsprechenden Code. Darüber hinaus muss noch ein zusätzlicher MIDI-Port am PC eingerichtet werden, an den das Signal gesendet wird. Ein solche Lösung kann beispielsweise durch "Hairless MIDI" bereitgestellt werden. Dieser Port muss dann in der DAW Ableton ausgewählt werden. Zusätzlich müssen die Komponenten, wie beispielsweise Regler, ebenfalls Ziel-DAW ausgewählt werden.

Diese Einrichtungsprozesse erfordern zusätzliche Schritte und den Einsatz von Drittanbieterprogrammen, was zu einer erhöhten Komplexität und potenziellen Schwierigkeiten bei der korrekten Konfiguration führen kann. Dies kann insbesondere  den Zugang zur MIDI-Kommunikation erschweren.

Außerdem dient ein HTML Dokument als UI und wurde mit Hilfe von ChatGPT als string umgewandelt, damit das ESP Modul damit arbeiten kann. 

Ein weiteres Problem betrifft den Server, der lokal auf dem Arduino läuft. Da alle Geräte im gleichen Netzwerk sein müssen, um darauf zugreifen zu können, kann dies die Flexibilität und Einsatzmöglichkeiten einschränken. Wenn das System beispielsweise von unterwegs aus ferngesteuert werden soll oder sich die Geräte an verschiedenen Standorten befinden, kann dies zu Einschränkungen führen.

Insgesamt lässt sich sagen, dass die Einrichtung des MIDI-Signals über den Serial Port und die Abhängigkeit von Drittanbieterprogrammen die Konzeption und Projektumsetzung erschwierigt haben. Die Komplexität der Konfiguration und die eingeschränkte Flexibilität des Servers sind weitere kritische Punkte, die im Rahmen der Projektarbeit ausschlaggebend waren. 

## 8 Fazit und Ausblick 

### 8.1 Fazit
Zusammenfassend lässt sich sagen, dass die Integration eines zusätzlichen MIDI-Ports in zukünftigen Geräten eine vielversprechende Option darstellt. Dieser zusätzliche Port würde es ermöglichen, den Serial-Port zu umgehen und die Kommunikation zwischen Mikrocontroller und Anwender über MIDI direkt zu erleichtern. Dies könnte zu einer verbesserten Konnektivität und reibungsloseren Datenübertragung führen.

Außerdem ist weiterer interessanter Aspekt ist die mögliche Implementierung eines externen Servers, der sowohl vom Mikrocontroller als auch vom Anwender remote angesteuert werden kann. Dieser Server könnte als zentrale Schnittstelle dienen, um verschiedene Geräte und Anwendungen miteinander zu verbinden und die Steuerung über das Internet zu ermöglichen. So könnte das MIDI-System flexibler und vielseitiger eingesetzt werden.

### 8.2 Ausblick

Die Zukunft sieht vielversprechend aus, wenn es darum geht, die Möglichkeiten der Mikrocontroller-Kommunikation zu erweitern. Die Integration eines zusätzlichen MIDI-Ports könnte eine Standardfunktion in zukünftigen Geräten werden, um die Verbindung mit anderen MIDI-fähigen Geräten zu vereinfachen. Dies würde der Musikproduktion mehr Flexibilität bieten und die Entwicklung neuer Anwendungen und Geräte fördern.
Die Einführung eines externen Servers, der remote von Mikrocontrollern und Anwendern gesteuert wird, eröffnet ebenfalls spannende Möglichkeiten. Durch diese zentrale Schnittstelle könnten Geräte und Anwendungen miteinander vernetzt werden, auch wenn diese nicht physisch am gleichen Ort sind. Dies ermöglicht eine Fernsteuerung der MIDI-Controller und könnte zu spannenden Innovationen in der Musikproduktion führen. 

