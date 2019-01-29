/***************************************************
 *    ESEMPIO SLAVE READER I2C 
 *    
 *    
 *    Author: N. Zambetti edited by S. Capezzone
 *    Version: 1.0
 *    Corso Arduino Avanzato
 *    
 */
#include <Wire.h>

void setup() {
  Wire.begin(8);                // Si collega al bus i2c come slave di indirizzo #8
  Wire.onReceive(receiveEvent); // Registra la funzione di gestione dell'evento
  Serial.begin(9600);           // Preparo la comunicazione sul monitor seriale
}

void loop() {
  delay(100); // In pratica non faccio nulla, la comunicazione è gestita da ISR
}

// Funzione di gestione dell'evento
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // Cicla leggendo tutti caratteri trasmessi tranne l'ultimo
    char c = Wire.read(); // Riceve un byte e lo forza a tipo "char"
    Serial.print(c);         // stampa sul monitor il carattere
  }
  int x = Wire.read();    // riceve l'ultimo byte e lo forza a tipo "int"
  Serial.println(x);         // stampa sul monitor il numero intero
}
