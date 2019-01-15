/***************************************************
 *    ESEMPIO GESTIONE AVANZATA DEL BLINK
 *    
 *    Author: Stefano Capezzone
 *    Version: 1.0
 *    Corso Professionale di arduino Avanzato
 *    
 */
// Utilizzo uno switch di compilazione per attivare o meno il debug sul serial terminal
#define DEBUG  

int ledState = LOW;             
unsigned long tempoAttuale;
unsigned long tempoPrecedente = 0;       
const long interval = 1000;           

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Nell'attuale IDE Arduino è definita la MACRO LED_BUILTIN
  pinMode(10,OUTPUT); // Pin Usato per il led collegato al sensore
  
#ifdef DEBUG  
  Serial.begin(9600);
#endif
}

void loop() {
  // prendo nota del tempo corrente
  tempoAttuale = millis();

// verifico se è trascorso l'intervallo di blink ed in caso cambio stato al led
  if (tempoAttuale - tempoPrecedente >= interval) {   
    tempoPrecedente = tempoAttuale;
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
  int val = analogRead(A0);
  if (val<400) digitalWrite(10,HIGH);
  else digitalWrite(10,LOW); 
  
#ifdef DEBUG
  Serial.println(val);
#endif
}
