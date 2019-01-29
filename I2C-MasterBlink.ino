/***************************************************
 *    SISTEMA MASTER I2C ESEMPIO BLINK
 *    
 *    
 *    Author: Stefano Capezzone
 *    Version: 1.0
 *    Corso Arduino Avanzato
 *    
 */
#include <Wire.h>

void setup() {
  Wire.begin(); // si connette al bus i2c come master (non c'è l'indirizzo)
}

byte comando = 1; 

void loop() {
  Wire.beginTransmission(8); 
  Wire.write(comando);           
  Wire.endTransmission();    
  delay(1000);
}
