/*!
 * @file mprls_simpletest.ino
 *
 * A basic test of the sensor with default settings
 * 
 * Designed specifically to work with the MPRLS sensor from Adafruit
 * ----> https://www.adafruit.com/products/3965
 *
 * These sensors use I2C to communicate, 2 pins (SCL+SDA) are required
 * to interface with the breakout.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Limor Fried/Ladyada for Adafruit Industries.  
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */
 
#include <Wire.h>
#include "Adafruit_MPRLS.h"

// You dont *need* a reset and EOC pin for most uses, so we set to -1 and don't connect
#define RESET_PIN  12  // set to any GPIO pin # to hard-reset on begin()
#define EOC_PIN    13  // set to any GPIO pin to read end-of-conversion by pin
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

void setup() {
  Serial.begin(115200);
  Serial.println("MPRLS Simple Test");
  if (! mpr.begin()) {
    Serial.println("Failed to communicate with MPRLS sensor, check wiring?");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Found MPRLS sensor");
}

double i = 1.0;
double m = 0.0;
double d = 0;
double a = 0.0;
void loop() {
  float pressure_hPa = mpr.readPressure();
  //Serial.print("Pressure (hPa): "); Serial.println(pressure_hPa);
  double psi = pressure_hPa / 68.947572932;
  double cmh20 = psi*70.307 - 1033.23 + 15.0 +0.31 - 0.861;
  if(d > 1000.0)
  {
    m = (m+cmh20);
    a = m/i;
    i = i+1.0;
  }
  else
  {
    d = d+1.0;
    a = (double)d;
  }
  
  //Serial.print("Pressure (PSI): "); Serial.println(psi);
  Serial.print("Pressure (cmH2O): "); Serial.println(cmh20);
  //Serial.print("Pressure (cmH): "); Serial.println(a,8);
  delay(20);
}
