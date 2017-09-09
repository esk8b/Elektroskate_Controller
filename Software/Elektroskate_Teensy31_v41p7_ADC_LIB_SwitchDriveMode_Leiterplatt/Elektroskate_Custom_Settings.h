// Version v41p4

// Sonderfunktionen
#define UIMESS     true        // HW UI-Messung vorhanden (true,false)
#define LICHTHUPE  false        // HW Licht, Hupe vorhanden (true,false)
#define TEMPMESS   false        // HW Temperaturmessung vorhanden (true,false)
#define LESOFT     false        // HW Leistungselektronik langsam hochfahren vorhanden (true,false)

// Debugflag
#define DEBUG_Funktion     false // Aktivieren der Debugausgabe Welche Funktionen werden aufgerufen (true,false)
#define DEBUG_ISR          false // Aktivieren der Debugausgabe Aufruf der ISR Interrupt Service Routinen (true,false)
#define DEBUG_Nunchuk      false // Aktivieren der Debugausgabe Nunchuk Werte x,y-Achse, Beschleunigung, c,z-Button(true,false)
#define DEBUG_Messung      false // Aktivieren der Debugausgabe interne Messwerte und Berechnungen (true,false)
#define DEBUG_Motorsteller false // Aktivieren der Debugausgabe interne Werte Motorsteller (true,false)
#define DEBUG_DriveMode    false // Aktivieren der Debugausgabe Umschaltung des DriveMode (true,false)
#define DEBUG_Bremse       false // Aktivieren der Debugausgabe Ansteuerung Bremsservo (true,false)

// Ausgabeschnittstellen zur Laufzeit fr die beiden Ausgabekanaele Serial_BT, Serial_US
// Serial  -> USBSerial-Anschluss Teensy 3.1
// Serial1 -> BT-Schnittstelle (auf Baudrate in Elektroskate_Custom_Parameters achten)
#define Serial_A Serial1  // Ausgabeschnittstelle A (i.d.R. Messwerte auf BT)
#define Serial_B Serial   // Ausgabeschnittstelle B (i.d.R. Debuginformationen auf BT oder USBSerial)

