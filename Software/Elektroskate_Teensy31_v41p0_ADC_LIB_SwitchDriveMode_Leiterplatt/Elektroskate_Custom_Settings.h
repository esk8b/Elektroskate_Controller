// Version v4p9

// Sonderfunktionen
#define UIMESS     true         // HW UI-Messung vorhanden (true,false)
#define LICHTHUPE  true         // HW Licht, Hupe vorhanden (true,false)
#define TEMPMESS   true         // HW Temperaturmessung vorhanden (true,false)
#define LESOFT     true         // HW Leistungselektronik langsam hochfahren vorhanden (true,false)

// Debugflag
#define DEBUG              false // Aktivieren der Debugausgabe (true,false)
#define DEBUG_Funktion     false // Aktivieren der Debugausgabe Welche Funktionen werden aufgerufen (true,false)
#define DEBUG_ISR          false // Aktivieren der Debugausgabe Aufruf der ISR Interrupt Service Routinen (true,false)
#define DEBUG_Nunchuk      false // Aktivieren der Debugausgabe Nunchuk Werte x,y-Achse, Beschleunigung, c,z-Button(true,false)
#define DEBUG_Messung      false // Aktivieren der Debugausgabe interne Messwerte und Berechnungen (true,false)
#define DEBUG_Motorsteller false // Aktivieren der Debugausgabe interne Werte Motorsteller (true,false)
#define DEBUG_DriveMode    false // Aktivieren der Debugausgabe interne Werte Motorsteller (true,false)


// Welche Schnittstellen sollen verwendet werden
// Serial  -> USB-Anschluss Teensy 3.1
// Serial1 -> Bluetooth Schnittstelle, auf die Baudrate in Elektroskate_Custom_Parameters achten!
#define Serial_BT Serial1       // Sollen die Werte fuer die BT-Schnittstelle auf USB oder Serial fuer das Debugging ausgegeben werden?
#define Serial_DB Serial        // Ausgabe der Debug Werte auf USB oder Serial ausgegeben werden?

