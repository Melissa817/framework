# Aufgabestellung: Temperatur und Luftdruck messen & WLAN-Verbindung herstellen
In dieser Aufgabe sollt ihr mit eurem Mikrocontroller (z. B. ESP32 oder ESP8266) eine einfache Wetterstation programmieren. Dabei geht es um folgende 


Teilaufgaben:
1. Temperatur auslesen
Lest die Temperatur mit einem geeigneten Sensor (z. B. BMP280, BME280) aus und zeigt den Wert mit der Einheit °C an.
Beispiel: Temperatur: 23.5°C

2. Luftdruck messen
Lest den Luftdruck über denselben Sensor aus und zeigt den Wert mit der Einheit hPa an.
Beispiel: Luftdruck: 1013.2 hPa

3. WLAN-Verbindung herstellen
Verbindet euch mit einem WLAN-Netzwerk. Die Zugangsdaten bekommt ihr von mir. Diese Verbindung wird benötigt, damit später die erfassten Wetterdaten an einen Server gesendet werden können.

4. Datenanzeige im seriellen Monitor
Gebt die Messwerte übersichtlich im seriellen Monitor aus – ähnlich wie bei einem Wetterbericht.
Beispielausgabe:

## Schritt 1 
- Bevor ihr mit der Aufgabe beginnt, führt des im Terminal aus, nach der Einrichtung wie im Foliensatz beschrieben:

Das ausführen erfolgt immer mit:     
- pio run --target upload

## Schritt 2 
Klasse:   main.cpp

- verbindet euch mit dem WLAN  



## Schritt 3
Klasse:   sensor.cpp

implementiert in euer Code, in folgende Methoden

- uint16_t Sensor::read16(byte reg)
- uint8_t Sensor::read8(byte reg)
- void Sensor::initSensor()
- bool Sensor::readTemperatureAndPressure()

Diese Methoden sind für die Initialisierung und das Auslesen des Sensors verantwortlich.

## Schritt 4 
Klasse:   display.cpp

implementiert euer Code in der folgenden Methode:
- void Display::refreshContent()


# WICHTIG: 
- Ändert nur die Stellen, an denen ein TODO vermerkt ist.

- Achtet auf saubere Code-Formatierung – Variablen und Einrückungen sind wichtig, sonst kann es zu Fehlern kommen!


# TIPP: 
- Wenn der Sensor mal nicht erkannt wird: Sensor kurz ab- und wieder anstecken oder das gesamte Programm neu starten.
- in Schritt 3. kann es schwieriger werden, ihr werdet dazu in Techniche Informatik auch eingeleitet, wie ihr den Sensor ausliest 




Viel Erfolg mit der Bearbeitung dieser Aufgabe :)
