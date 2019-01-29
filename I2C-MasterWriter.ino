/***************************************************
 *    ESEMPIO MASTER WRITER I2C 
 *    
 *    
 *    Author: N. Zambetti edited by S. Capezzone
 *    Version: 1.0
 *    Corso Arduino Avanzato
 *    
 */
#include <Wire.h>

void setup() {
  Wire.begin(); // si connette al bus i2c come master (non c'è l'indirizzo)
}

byte x = 0; 

void loop() {
  Wire.beginTransmission(8); // dichiaro la trasmissione verso il device #8
  Wire.write("x = ");        // accodo 5 bytes sul buffer
  Wire.write(x);              // accodo un byte
  Wire.endTransmission();    // effettuo la trasmissione e termino la trasmissione

  x++;
  delay(1000);
}
