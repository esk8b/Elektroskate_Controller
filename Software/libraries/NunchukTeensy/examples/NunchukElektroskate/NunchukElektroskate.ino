/*
Achtung, nach der Aktivierung des Programms 
und Anschluss des Nunchuks, 
die Reset-Taste am Arduino druecken.
*/

#include <NunchukTeensy.h>
#include <i2c_t3.h>

#define BAUDRATE 19200

Nunchuk nunchuk = Nunchuk();
unsigned long time;

void setup()
{
  Serial.begin(BAUDRATE);
  nunchuk.init();
}

void loop()
{
  time = millis();
  Serial.println(time);
  nunchuk.update();
  Serial.println(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.cButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.zButton, DEC);
}

