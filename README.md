# Projektdokumentation *MIDI-Controller*
Projekt-Team: Jens Kröning, Moritz Reischenbach, Felix Riedel

Start Datum: 08.05.2023

End Datum: 17.07.2023

- [1 Einführung](#1-einführung)
  - [1.1 Motivation](#11-motivation)
  - [1.2 Zielstellung](#12-zielstellung)
  - [1.3 Vorgehensweise](#13-vorgehensweise)
- [2 Konzept](#2-konzept)
- [3 Setup](#3-setup)
  - [3.1 Hardware](#31-hardware)
  - [3.2 Hardwareaufbau](#32-hardwareaufbau)
  - [3.3 Software](#33-software)
    - [Octopus QuickStart](#octopus-quickstart)
    - [Hairless MIDI](#hairless-midi)
    - [Loop MIDI](#loop-midi)
    - [Ableton Live DAW](#ableton-live-daw)
- [4 Implementation](#4-implementation)
  - [4.1 Octopus](#41-octopus)
  - [4.2 Website](#42-website)
  - [4.3 Kommunikation zwischen Octopus und Ableton](#43-kommunikation-zwischen-octopus-und-ableton)
- [5 Musikproduktion mit Ableton](#5-musikproduktion-mit-ableton)
  - [5.1 Grundlage](#51-grundlage)
  - [5.2 Vorgehen](#52-vorgehen)
  - [5.3 Ergebnis](#53-ergebnis)
- [6 Projektergebnisse](#6-projektergebnisse)
- [7 Fehlerbetrachtung](#7-fehlerbetrachtung)
- [8 Fazit und Ausblick](#8-fazit-und-ausblick)
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

---

## 2 Konzept
Im nachstehenden Ablaufdiagramm wird die Konzeption zur Erstellung des MIDI-Controllers verdeutlicht. 


!![Ablaufdiagramm MWV](https://github.com/KroeningJ/MIDI-Controller/assets/135695441/00d79a34-3e4f-4e8a-8c7a-de0f7a0585a9)


Hierfür gibt es im ersten Schritt einen lokalen Rechner, welcher eine Grundlage für die Struktur bildet. Dieser lokale Rechner kommuniziert über einen entsprechenden Server, welcher die gewünschten Signale an den Octopus IoT sendet. Auf dem Server läuft eine WebApplikation, welche den MIDI-Controller darstellt und die Möglichkeit bietet anahnd von 6 Reglern Einstellungen für MIDI Geräte vorzunehmen. Der Octopusmikrocontroller erhält die Konfigurationen der Regler und wandelt diese in MIDI-Signale um, welche über den USB-Port des Arduinos an das gewünschte MIDI-Gerät bzw. die DAW (Digital Audio Workstation) sendet.

---
## 3 Setup
Im Folgenden wird das Setup für die Projektumsetzung beschrieben. Hierfür erfolgt eine Aufteilung in Hard- und Software. 

### 3.1 Hardware
Für die Erstellung des MIDI-Controllers dient ein Octopus-Board als Grundlage:
- Octopus IoT
- USB A zu USB Micro B Kabel 
  

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
  

---
## 4 Implementation

Im Folgenden wird die Funktionsweise sowohl für den Octopus, als auch für die HTML Website beschrieben und die Kommunikation mit der DAW. 

### 4.1 Octopus

Der gegebene Code ist ein Arduino-Sketch, der auf dem ESP8266-Mikrocontroller läuft und einen MIDI-Controller über eine WLAN-Verbindung und eine Webserver-Schnittstelle implementiert. Es ermöglicht die Steuerung von sechs Schiebereglern über eine HTML-basierte Benutzeroberfläche.

Hier eine Beschreibung der wichtigsten Bestandteile des Codes:

Bibliotheken und Initialisierungen:
   - Verschiedene Bibliotheken wie "Ticker", "Wire", "Adafruit_GFX", "Adafruit_IS31FL3731", "ESP8266WiFi" und "ESP8266WebServer"         werden eingebunden.
   - Eine Instanz für die MIDI-Kommunikation wird mit "MIDI_CREATE_DEFAULT_INSTANCE()" erstellt.
   - Eine globale Funktion mit dem Namen "WebServerHousekeeping" wird als Funktionszeiger deklariert und auf "yield" gesetzt.

Konstanten und Variablen:
   - Der HTML-Code für die WebOberfläche wird definiert. Dieser enthält Formulare mit sechs Schiebereglern.
   - Eine Variable "myOwnIP" wird deklariert, um die IP-Adresse zu speichern, auf der der Server gehostet wird.
   - Ein Objekt mit dem Namen "server" wird erstellt und auf Port 80 initialisiert.

3. Setup-Funktion:
   - MIDI wird initialisiert und auf Kanal 1 gestartet.
   - Der Webserver wird gestartet, und die Homepage ("serverHomepage") wird der Haupt-URL "/" zugeordnet.
   - WLAN wird initialisiert, und der ESP8266 verbindet sich mit dem selbst angegebenen WLAN-Netzwerk ("WIFI-NAME" und "PASSWORT").

4. Loop-Funktion:
   - In der loop-Funktion werden kontinuierlich zwei Funktionen behandelt:
   - "server.handleClient()" kümmert sich um die Bedienung von Homepage-Anfragen und die Ausgabe der HTML-Seite mit den Schiebereglern.
   - "server.handleClient()" kümmert sich zusätzlich um die Bedienung des Web-Servers, um die Werte der Schieberegler zu verarbeiten, die der Benutzer über die Webseite ändert.
   - Die Werte der Schieberegler werden über die MIDI-Kommunikation an einen MIDI-Empfänger (z. B. Musiksoftware oder Hardware-Synthesizer) gesendet.

Die Benutzeroberfläche ermöglicht es dem Benutzer, die Werte von sechs Schiebereglern über eine einfache Webseite zu ändern. Wenn der Benutzer einen Schieberegler bewegt, wird der Wert über eine POST-Anfrage an den ESP8266 gesendet, und der ESP8266 leitet die MIDI-Befehle entsprechend weiter. Der MIDI-Kanal, auf dem die Steueränderungen gesendet werden, ist auf Kanal 1 festgelegt.

Wichtig zu erwähen ist, dass die Midi Signale über einen Serial Port (USB) gesendet werden, wodurch man ein extra Programm benötigt (MIDI Serial, welches den Port für Midi freischaltet, welcher für die kommunikation mit dem Arduino verantwortlich ist. 
Hierfür muss ein zusätzliches MIDI Port am PC mit hairless MIDI eingerichtet an den das Signal gesendet wird. Der Port muss dann in der DAW (Ableton) ausgewählt werden. 

### 4.2 Website

Die Website durchlief meherere Versionen, welche nachträglich auf den Octopus abgestimmt werden mussten. Version 1 beinhaltete einen HTML-Code welcher eine MIDI-Controller-Oberfläche darstellt, die es Benutzern ermöglicht, sechs Schieberegler zu verwenden, um MIDI-Werte einzustellen. 

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
Jeder Slider hat eine entsprechende Funktion (enableSliderDrag), die das Ziehen des Daumens ermöglicht. Diese Funktion wird für sechs Schieberegler mit den Indizes 1 bis 6 aufgerufen.
Die Werte der Schieberegler werden mithilfe des localStorage gespeichert, sodass sie nach einem Seitenrefresh erhalten bleiben.

Version wurde in diesem Fall auf die Benutzung innerhalb des Octopus abgestimmt und mithilfe von ChatGPT als String umgewandelt, um diesen für den ESP lesbar zu machen.

![grafik](https://github.com/KroeningJ/MIDI-Controller/assets/61734168/2d4f2dc7-0b19-4f53-a5f0-f666370e6b41)


Bei einer Eingabe der Slider werden die möglichen Werte von 0-127 mithilfe einer POST-request an den Server gesendet, welche anschließend vom Octopus verarbeitet werden, welche dann über DAW angesteuert werden können.

![grafik](https://github.com/KroeningJ/MIDI-Controller/assets/61734168/e16415e8-208a-4764-b65a-2b907c01c531)


### 4.3 Kommunikation zwischen Octopus und Ableton

Wie bereits am Anfang erwähnt, wird Drittanbieter-Software benötigt, damit die MIDI Signale vom Octopus an die DAW gesendet werden können.
Dafür muss zunächst ein virtueller MIDI-Port eingerichtet werden, welcher dann in Ableton als MIDI Eingang ausgewählt werden kann.

![grafik](https://github.com/KroeningJ/MIDI-Controller/assets/61734168/46131017-623a-4f4f-b0ed-039e926e2f5a)


Dadurch, dass auf dem Octopus kein extra Ausgang benutzt wird, sondern die Signale direkt per USB Port verschickt werden, muss der Serial Port des Octopus dafür freigeschaltet werden.
Das geschieht mit Hilfe von Hairless MIDI. Dort wird als Eingang der entsprechende Serial Port des Octopus ausgewählt und als Ausgang der zuvor konfigurierte virtuelle MIDI Port.

![grafik](https://github.com/KroeningJ/MIDI-Controller/assets/61734168/4de0ac46-57cf-4405-949d-f3ce20cbb0ff)


Die Debuganzeige zeigt an welche Signale aktuell verschickt werden.


In Ableton kann dann über die MIDI Schaltfläche ein beliebiger Regler angewählt werden und dem aktuell verschicktem MIDI-Signal zugewiesen werden.

![grafik](https://github.com/KroeningJ/MIDI-Controller/assets/61734168/fa64af00-116e-4db2-b9ae-d6bb14f6a0a5)

---

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

![Ableton Live Spur](https://github.com/KroeningJ/MIDI-Controller/assets/135695441/fe2b0125-b798-4b25-87ff-a3d99e98b47f)

![Ableton Live Spur 2](https://github.com/KroeningJ/MIDI-Controller/assets/135695441/6415f58d-9046-446a-b89e-6bb7b6bffe99)

Den Abbildungen kann die Zusammensetzung der Musikproduktion entnommen werden. Hierfür wurden Kick, Snare, Bass, ein Perc, zwei verschiedene Synthesizer und Hyper Riser genutzt. Dieser ist als .mp3 Datei im Repository beigefügt. 

---

## 6 Projektergebnisse

Das Projektergebnis beläuft sich auf die Steuerung eines MIDI-Controllers innerhalb einer Website, welche durch einen Octopus auf ein Musikproduktionsprogramm, Ableton, übertragen wird. Es wurden 4 verschiedene Slider realisiert, welche mit Hilfe gesetzter Variablen MIDI-Signale an Ableton senden, um  einen laufenden Song anzupassen.

## 7 Fehlerbetrachtung 

Bei der Betrachtung der Projektarbeit sind einige kritische Punkte zu identifizieren. Ein Hauptproblem besteht in der Schwierigkeit der Einrichtung. 

Hierfür wird zusätzliches Programm wie "Hairless MIDI" benötigt, um den Port für die MIDI-Kommunikation freizuschalten. Dies ist erforderlich, da der Serial Port normalerweise für die Kommunikation mit dem Arduino verwendet wird, beispielsweise zum deployen von Code auf den Arduino bzw. Octopus. Darüber hinaus muss noch ein zusätzlicher MIDI-Port am PC eingerichtet werden, an den das Signal gesendet wird. Ein solche Lösung kann beispielsweise durch "loopMIDI" bereitgestellt werden. Dieser Port muss dann in der DAW Ableton ausgewählt werden. Zusätzlich müssen die Komponenten, wie beispielsweise Regler, ebenfalls in der Ziel-DAW ausgewählt werden.
Eine deutlich bessere Lösung wäre es gewesen einen extra MIDI-Ausgang an den Mikrocontroller zu verbauen und diesen mit einem MIDI-Eingang am Endgerät zu verbinden, dies würde die Notwendigkeit der Drittanbieterprogramme ausschließen.

Des weiteren ist zu kritisieren, dass der Server nur lokal auf dem Octopus läuft, demzufolge kann auf die Website nur über die eigene IP-Adresse zugegriffen werden und nur Geräte, die sich im selben Netz, befinden haben zugriff darauf. Was direkt zu einem weiteren Problem führt: Die Bereitstellung der Website auf den Arduino erfolgt als String welcher das Escapen bestimmer Sonderzeichen erfordert, was sich als sehr mühselig herausstellt. 

Insgesamt lässt sich sagen, dass die Einrichtung des MIDI-Signals über den Serial Port und die Abhängigkeit von Drittanbieterprogrammen die Konzeption und Projektumsetzung erschwierigt haben. Die Komplexität der Konfiguration und die eingeschränkte Flexibilität des Servers sind weitere kritische Punkte, die im Rahmen der Projektarbeit ausschlaggebend waren. 

---
## 8 Fazit und Ausblick 

### 8.1 Fazit
Zusammenfassend lässt sich sagen, dass die Integration eines zusätzlichen MIDI-Ports in zukünftigen Geräten eine vielversprechende Option darstellt. Dieser zusätzliche Port würde es ermöglichen, den Serial-Port zu umgehen und die Kommunikation zwischen Mikrocontroller und Anwender über MIDI direkt zu erleichtern. Dies könnte zu einer verbesserten Konnektivität und reibungsloseren Datenübertragung führen.

Außerdem ist weiterer interessanter Aspekt ist die mögliche Implementierung eines externen Servers, der sowohl vom Mikrocontroller als auch vom Anwender remote angesteuert werden kann. Dieser Server könnte als zentrale Schnittstelle dienen, um verschiedene Geräte und Anwendungen miteinander zu verbinden und die Steuerung über das Internet zu ermöglichen. So könnte das MIDI-System flexibler und vielseitiger eingesetzt werden.

### 8.2 Ausblick

Die Zukunft sieht vielversprechend aus, wenn es darum geht, die Möglichkeiten der Mikrocontroller-Kommunikation zu erweitern. Die Integration eines zusätzlichen MIDI-Ports könnte eine Standardfunktion in zukünftigen Geräten werden, um die Verbindung mit anderen MIDI-fähigen Geräten zu vereinfachen. Dies würde der Musikproduktion mehr Flexibilität bieten und die Entwicklung neuer Anwendungen und Geräte fördern.
Die Einführung eines externen Servers, der remote von Mikrocontrollern und Anwendern gesteuert wird, eröffnet ebenfalls spannende Möglichkeiten. Durch diese zentrale Schnittstelle könnten Geräte und Anwendungen miteinander vernetzt werden, auch wenn diese nicht physisch am gleichen Ort sind. Dies ermöglicht eine Fernsteuerung der MIDI-Controller und könnte zu spannenden Innovationen in der Musikproduktion führen. 

