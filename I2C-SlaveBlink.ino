/***************************************************
 *    SISTEMA SLAVE I2C ESEMPIO BLINK
 *    
 *    
 *    Author: Stefano Capezzone
 *    Version: 1.0
 *    Corso Arduino Avanzato
 *    
 */
#include <Wire.h>

int volatile stato = 0;

void setup() {
  Wire.begin(8);                // Si collega al bus i2c come slave di indirizzo #8
  Wire.onReceive(receiveEvent); // Registra la funzione di gestione dell'evento
  Serial.begin(9600);           // Preparo la comunicazione sul monitor seriale
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  delay(100); // In pratica non faccio nulla, la comunicazione è gestita da ISR
}

// Funzione di gestione dell'evento, riceve come parametro il numero di byte trasmessi
void receiveEvent(int howMany) {
  
  int x = Wire.read();    // riceve il byte e lo forza a tipo "int"
  Serial.println(x); // stampa sul monitor il numero intero
  stato = !stato;
  digitalWrite(LED_BUILTIN,stato);
}
