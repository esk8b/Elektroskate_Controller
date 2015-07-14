/*
 * Based on ArduinoNunchuk.h changed wrong types removed unused Axes
 * 2013 Barney
 * ArduinoNunchuk.h - Improved Wii Nunchuk library for Arduino
 * 
 * Copyright 2011-2012 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *
 * Project URL: http://www.gabrielbianconi.com/projects/arduinonunchuk/
 *
 * Based on the following projects/websites:
 *   http://www.windmeadow.com/node/42
 *   http://todbot.com/blog/2008/02/18/wiichuck-wii-nunchuck-adapter-available/
 *   http://wiibrew.org/wiki/Wiimote/Extension_Controllers
 * 
 */

#ifndef Nunchuk_H
#define Nunchuk_H

#if (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif
#include <i2c_t3.h>

class Nunchuk
{  
  public:  
    byte analogX;
    byte analogY;
    uint16_t accelX;
    uint16_t accelY;
    uint16_t accelZ;	
    byte zButton;
    byte cButton;
  
    void init();    
    void update();
    
  private:  
    void _sendByte(byte data, byte location);
};

#endif
