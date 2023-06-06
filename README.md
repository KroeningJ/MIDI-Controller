# Projektdokumentation *Nano RPS*

- [Projektdokumentation *MIDI-Controller*](#projektdokumentation-MIDI-Controller)
  - [1 Einführung](#1-einführung)
    - [1.1 Motivation](#11-motivation)
    - [1.2 Zielstellung](#12-zielstellung)
    - [1.3 Vorgehensweise](#13-vorgehensweise)

---

## 1 Einführung

### 1.1 Motivation
Im Rahmen des Moduls "Wissensmanagement" an der HTW Berlin hatten wir die Aufgabe in zwei Wochen ein Machine Learning Projekt mit Arduino Bauteilen umzusetzen. Bei der Projektfindung haben wir uns für Bildklassifizierung, LED Matrizen und der Kommunikation zwischen Mikrocontrollern über Bluetooth Low Energy (BLE) interessiert. Nach etwas Brainstorming kamen wir auf die Idee, die verschiedenen Aspekte in einem Schere-Stein-Papier-Computer zu integrieren.

### 1.2 Zielstellung
Durch eine Kamera sollen die Handgesten _Schere_, _Stein_ und _Papier_ aufgenommen werden. Diese sollen dann richtig klassifiziert werden. Das Modell für die Klassifizierung soll in Edge Impulse mit verschiedenen Datensätzen trainiert werden. Die dann richtig erkannte Geste soll über BLE an einen ESP32 gesendet werden. Dieser wählt für den Computer zufällig eine Geste aus und entscheidet, wer gewinnt. Die Auswahl vom Mensch und Computer sowie das Ergebnis sollen dann grafisch auf einer LED-Matrix dargestellt werden.

### 1.3 Vorgehensweise
Das Projekt wurde in drei Arbeitspakete unterteilt:

1. Machine Learning Modell trainieren
2. Modell als Bibliothek auf dem Nano einbinden und Bilder erstellen lassen
3. BLE Verbindung herstellen und Grafiken erstellen und anzeigen

Zuerst wurde sämtliche Hardware zusammengesteckt. Daraufhin wurde mithilfe von Edge Impulse ein Modell zur Bilderklassifikation trainiert. Genaueres dazu ist in im Kapitel [Impulse Learning](#impulse-learning) erläutert. Hier wurde das Modell über mehrere Iterationen verfeinert und verkleinert, um später mit BLE gut zu harmonieren. Genutzt wurden für die Datensätze, nach anfänglichen Schwierigkeiten mit eigenen Daten, bereits existierende Datensätze aus dem Internet.
Auf dem ESP32 wurde die Spiellogik implementiert, welche aus der BLE Verbindung die Geste des Spielers ausliest und für den COM eine Geste spielt. Abhängig von dieser Kombination soll dann eine Animation auf der LED Matrix ausgegeben. Für dies wurden für die jeweiligen Spielsituationen GIFs angefertigt und in für C++ verwertbare Variablen konvertiert.
