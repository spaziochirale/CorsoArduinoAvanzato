/***************************************************
 *    ESEMPIO SALVATAGGIO DELLO STATO USANDO LA EEPROM
 *    Derivato dall'esempio Interrupt con la gestione del 'debounce'
 *    
 *    Author: Stefano Capezzone
 *    Version: 1.0
 *    Corso Professionale di Arduino Avanzato
 *    
 */
#include <EEPROM.h>
const byte BUTTON = 2; // Modificare con il PIN scelto anche in base al tipo di scheda
volatile byte stato;
volatile unsigned long tempo;



void buttonPressed() {
  if ((millis() - tempo) > 200) 
    {
      stato = !stato;
      EEPROM.update(10,stato);
    }
  digitalWrite(LED_BUILTIN, stato);  
  tempo = millis();
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, RISING);
  tempo = millis();
  stato=EEPROM.read(10);
  digitalWrite(LED_BUILTIN, stato);

}

void loop() {
  
  // Non ho nulla da fare...
}
