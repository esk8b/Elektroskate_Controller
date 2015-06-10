// Version v41p4
// Serielle Geschwindigkeit
#define BT_BAUDRATE (uint32_t) 230400   // Datenrate fuer das Bluetooth Modul, ggf. fuer ein anderes BT-Modul anpassen (Ausgabe auf Serial1, Pwd 1234)
#define US_BAUDRATE (uint32_t) 230400   // Datenrate fuer das Debugging in der Arduino IDE per USBSerial

// Wertebereich von (Min..Max,SinnvollUntererWert..SinnvollObererWert)

// Nunchuk - Steuerparameter Sollwertvorgabe und Programmablaufsteuerung (12bit Normierung beachten: 255 eq. 4095)
//               WiiNunchuk     Mad Catz
// YAchseMin             27            0
// YAchseMax            250          255
// YAchseNeutral        140          128
// YAchseUT             124          118
// YAchseOT             145          130
#define YAchseMin (uint16_t)     0 // MinimalWert y-Achse ganz unten (0..65535,0..30)
#define YAchseMax (uint16_t)   255 // MaximalWert y-Achse ganz oben (0..65535, 240..255)
#define YAchseNeutral          128 // Neutralstellung Y-Achse (0..65535, 125..140)
#define YAchseUT               118 // Wert der Nunchuk Y-Achse unterhalb dessen die Beschleunigung zurueckgenommen wird(Integrationssteuerung) (0..65535, 115..124)
#define YAchseOT               130 // Wert der Nunchuk Y-Achse oberhalb dessen beschleunigt wird(Integrationssteuerung) (0..65535, 141..145)

// Plausibilitaetscheck und ggf. Korrektur
#if YAchseUT > YAchseNeutral
  #define (uint16_t) YAchseUT (uint16_t) YAchseNeutral
#endif
#if YAchseOT < YAchseNeutral
  #define (uint16_t) YAchseOT (uint16_t) YAchseNeutral
#endif

// Exponentialfunktion
#define YAchseExpNeg (float)              1.0 // Beschleunigungsfunktion 1 linear, 2 quadratisch (0.1..3.0, 1.0..2.0)
#define YAchseExpPos (float)              1.0 // Bremsfunktion 1 linear, 2 quadratisch (0.1..3.0, 1.0..2.0)

#define XAchseMin (uint16_t)                0 // MinmalWert X-Achse ganz unten (0..65535,0..30)
#define XAchseMax (uint16_t)              255 // MinmalWert X-Achse ganz unten (0..65535,0..30)
#define XAchseLinks  (uint16_t)            30 // X-Achse wird fuer kleinere Werte als Linksstellung angenommen
#define XAchseRechts (uint16_t)           220 // X-Achse wird fuer groessere Werte als Rechtsstellung angenommen

#define PairingLostTrigger (uint16_t)      55 // Schwellwert fuer Funkabriss, wird dieser Wert ueberschritten liegt ein Funkabriss vor (0..65535, 20..70)
#define PairingSuccessTrigger (uint16_t)    5 // Schwellwert fuer erfolgreiche Verbindung (0..65535, 5..10)

// Temperatursensoren
#define defTempSensorAnzahl (uint8_t)       2 // Die Temperatursensoranzahl hier eintragen
uint8_t defTempAddress[2][8] = {{ 0x28, 0x75, 0x3F, 0x2A, 0x04, 0x00, 0x00, 0x73 }     // Seriennummer der Temperatursensoren, diese muss extra ermittelt werden
                               ,{ 0x28, 0x0D, 0xE2, 0x00, 0x04, 0x00, 0x00, 0x93 }};   // Seriennummer der Temperatursensoren, diese muss extra ermittelt werden

// PWM Motorsteuerung
#define PWM_ObererStellWertMotorIgel 1.65 // Wert berechnen fuer obere Pulsweite Igel (ms Pulsweite) (0.0..2.5, 1.6..1.8)
#define PWM_ObererStellWertMotorHase 2.0  // Wert berechnen fuer obere Pulsweite Hase (ms Pulsweite) (0.0..2.5, 1.9..2.1)
#define LeerlaufOffset (uint32_t)      0  // Offset zum schnelleren Ansprechen des ESC bei inkrementeller Steuerung (0..65535, 0..300)
#define PWM_LeerlaufStellWertMotor   1.5  // Wert berechnen fuer Leerlauf (ms Pulsweite)  (0.0..5.0, 1.4..1.6)
#define PWM_UntererStellWertMotor    1.0  // Wert berechnen fuer untersten Wert (ms Pulsweite)  (0.0..5.0, 0.9..1.1)

// PWM Brems-Servo
#define PWM_Bremse_Ungebremst   1.0 // Servostellung ungebremst (ms Pulsweite)  (0.0..2.5, 1.0..1.5)
#define PWM_Bremse_Vollbremse   2.0 // Servostellung Vollbremsung (ms Pulsweite)  (0.0..2.5, 1.8..2.5)
#define PWM_Bremse_Exp (float)  1.0 // Bremsweg-Servo 1 linear, 2 quadratisch  (0.1..3.0, 1.0..2.0)

// Steuermodus (Startwert false des Fahrverhaltens nicht ändern!)
uint32_t DirectDrive = false; // true -> Direct Drive, false -> Integrations Drive.

// Incremental Drive Parameter
#define BeschleunigungsDaempfung (uint32_t)  112 // Je groesser die BeschleunigungsDaempfung, desto langsamer wird inkrementell beschleunigt (ggf. anpassen)   (0..32^2, 0..250)
#define BremsDaempfung           (uint32_t)  80  // Je groesser die BremsDaempfung, desto langsamer wird die Bremskraft inkrementell aufgebaut (ggf. anpassen)   (0..32^2, 0..250)

// Spannungs/- und Strommessung
#define BattSpgMMax (float) 42.9 // Maximale messbare Batterienspannung (Koeffizienten im Ausgleichspolynom muessen angepasst werden) 
                                 // 32.7V (10k Ohm / 2 x 180k Ohm) 
                                 // 40V   (10k Ohm / 121k Ohm) 
                                 // 42.9V (10k Ohm / 120k Ohm)
                                 // 52.8V (10k Ohm / 150k Ohm)
#define StromMMax   (float) 50.0 // Maximal messbarer Strom in A (ACS756SCA-050B Stromsensor)

// Die Spanungsmessung ist nicht linear daher Polynom dritter Ordnung

// Koeffizienten fuer 32.7V Wertebereich
//#define PolynomX0 (float) -24.744834   // Polynom Koeffizient X0
//#define PolynomX1 (float)  3.8060089   // Polynom Koeffizient X1
//#define PolynomX2 (float) -0.1118917   // Polynom Koeffizient X2
//#define PolynomX3 (float)  0.0015586   // Polynom Koeffizient X3
//#define UBatPoly  (float) ( PolynomX3 * pow(Ubatt,3) + PolynomX2 * pow(Ubatt,2) + PolynomX1 * Ubatt + PolynomX0 )

// Koeffizienten fuer 42.9V Wertebereich (Gltigkeitsbereich 20-42 V)
#define PolynomX0 (float)  3.0212116625866255e+01   // Polynom Koeffizient X0
#define PolynomX1 (float) -2.8686634871513985e+00   // Polynom Koeffizient X1
#define PolynomX2 (float)  8.4582160196230438e-02   // Polynom Koeffizient X2
#define PolynomX3 (float) -7.8271727383718973e-04   // Polynom Koeffizient X3
#define UBatPoly  (float) ( Ubatt + PolynomX0 + PolynomX1 * Ubatt + PolynomX2 * pow(Ubatt,2) + PolynomX3 * pow(Ubatt,3) )

// Strombegrenzung und Kurzschlusserkennung
#define Ishort  (uint16_t) 50    // Maximaler Strom, dieser fuehrt zur sofortigen Abschaltung (<= StromMMax)
#define Imax    (uint16_t) 40    // Grenzwert, ab dem die Strombegrenzung einsetzt
#define Strom0A (float)    50.45 // 0A Messwert, wird angezeigt wenn kein Strom fliesst und Strom0A = 0 (muss kalibriert werden)


