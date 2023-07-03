# Projektdokumentation *MIDI-Controller*
Projekt-Team: Jens Kröning, Moritz Reischenbach, Felix Riedel

Start Datum: 08.05.2023

End Datum: 10.07.2023

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
---

## 1 Einführung

### 1.1 Motivation
Diese Projektdokumentation enthält alle relevanten Informationen für das kommende Projekt "IoT MIDI Controller". Neben den Anforderungen finden sich hier die Kontaktdaten aller Teammitglieder sowie die Ziele für Anbieter und Nutzer. Zusätzlich wird das Projekt inhaltlich abgegrenzt. Des Weiteren können diesem Dokument die verschiedenen Rahmenbedingungen entnommen werden. Dazu gibt es einen Zeitplan, eine Übersicht über die verschiedenen Risiken und eine entsprechende Qualitätssicherung. Ein MIDI-Controller ist ein elektronisches Musikinstrument, das über MIDI-Schnittstellen mit anderen Geräten verbunden werden kann. Mit ihm lassen sich verschiedene Musikprogramme und Synthesizer steuern. Die Verwendung von MIDI-Controllern ist in der Musikproduktion weit verbreitet. In diesem Projekt soll ein MIDI-Controller mit Hilfe eines Arduino-Boards erstellt werden. Dazu müssen sowohl die technischen Voraussetzungen als auch das Ziel genau definiert werden.

### 1.2 Zielstellung
Ziel des Projekts ist es, einen funktionsfähigen MIDI-Controller zu erstellen, der unabhängig mit einem Arduino-Board programmiert werden kann. In der erfolgreichen Umsetzung soll der MIDI-Controller über verschiedene Knöpfe und Regler verfügen, die über MIDI-Signale Notenwerte und Steuerbefehle an andere Geräte senden können. Die Programmierung soll mit einer geeigneten Arduino-Entwicklungsumgebung erfolgen, so dass der MIDI-Controller flexibel an unterschiedliche Anforderungen angepasst werden kann. Der MIDI-Controller soll einfach und intuitiv zu bedienen sein und es dem Benutzer ermöglichen, seine eigene Musik zu produzieren. Außerdem soll der MIDI-Controller über eine Webanwendung ferngesteuert werden können. Die MIDI-Signale des Controllers werden über USB, Bluetooth oder optional über WLAN an den Endanwender gesendet.
Das Projekt soll im Rahmen des Moduls M.1.6 Methoden der Wissensverarbeitung im Sommersemester 2023 durchgeführt werden. Durch die erfolgreiche Umsetzung des Projekts soll durch die Programmierung von Soft- und Hardware erkenntnisreiches Lernen im Kontext der Wissensverarbeitung entwickelt werden.

### 1.3 Vorgehensweise
Nachdem eine konkrete Zielstellung für das vorliegende Projekt definiert wurde lässt sich die Projektarbeit in fünf Hauptaspekte unterteilen: 

1. Hardwareauswahl
2. Hardwareaufbau
3. Programmierung
4. Musik-Produktion mit Ableton Live
5. Test und Fehlerbehebung

Zuerst wurde der Zweck und die Funktionen des Projektes definiert. Der MIDI Controller soll in der Lage sein durch die gezielte Verknüpfung mit Ableton Live besthende Soundmuster zu ändern. Hierfür sollen eine Auswahl an fünf Steuerelementen genutzt werden. Anstatt physischer Tasten, Drehregler oder Schiebereglern werden online Slider programmiert, welche beliebig mit den Effekten in Ableton Live verknüft werden können. FÜr den MIDI Controller wurde ein WLAN-fähiges Octopus-Board als Grundlage genutzt. Das genaue Setup kann im späteren Kapitel *Setup* nachglesen werden. Nachdem die Funktionen und die damit verbundene Hardwareauswahl erörtert wurde, folgten einige Überlungen zur Webseite und Programmierung. Da die Slider nicht physisch an dem Octopus-Board angebracht werden, sonder als IoT-Anwendung mit einem HTML-Server kommunizieren sollen, bedarf es einem entsprechenden Server und der Programmierung der Slider. Außerdem muss das Octopus-Board eine ebanfalls entsprechende Programmierung zur Konnektivität mit Ableton Live beinhalten. Für die abschließende Endpräsentation bedarf es zusätzlich einer Musikproduktion in Ableton Live. Nachfolgend zu diesen anfänglichen Überlegungen und Definitonen im Rahmen der Projektarbeit wird eine nähere Betrachtung der genutzen Hardware vorgenommen und das zugrundeliegende Konzept beschrieben. 

## 2 Konzept

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

#### Hairless MIDI 
Dieses Programm wird benötigt, um einen virtuellen MIDI-Port zu erstellen, der von der DAW gefunden werden kann.
- Link: https://www.tobias-erichsen.de/software/loopmidi.html

#### Ableton Live DAW
- Link: https://www.ableton.com/de/trial/
  


## 4 Programmierung

### 4.1 Octopus

### 4.2 HTML Server

### 4.3 MIDI-Controller Surface 






## 5 Musikproduktion mit Ableton

Für die Präsentation der Projektergebnisse wird mit Hilfe der Musikproduktionssoftware Ableton Live ein einfacher Beat/Loop gebaut. Dieser kann im Zuge der Präsentation durch die Studierenden mittels des MIDI-Controllers gesteuert und verändert werden. Ziel ist ein individuelles Soundbild durch die vorab definierten Slider Effekte. 

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

Den Abbildungen kann die Zusammensetzung der Musikproduktion entnommen werden. Hierfür wurden Kick, Snare, Bass, ein Perc, zwei verschiedene Synthesizer und Hyper Riser genutzt. Dieser kann als mp3.Datei gehört werden: 

https://github.com/KroeningJ/MIDI-Controller/blob/main/Ableton%20Pr%C3%A4sentationsbeat.mp3




## 6 Projektergebnisse



## 7 Fehlerbetrachtung 

## 8 Fazit und Ausblick 





