#include <IRremote.h>

#define IR_RECEIVE_PIN 13
#define motoreD 6
#define motoreS 10
#define vel 5
#define LEDG 4
#define LEDR 3
#define LEDV 2
#define indietroD 8
#define indietroS 9
int veloc = 0;
char cont;

void setup() {
IrReceiver.begin(IR_RECEIVE_PIN);
Serial.begin(9600);
pinMode(motoreD, OUTPUT);
pinMode(motoreS, OUTPUT);
pinMode(indietroD, OUTPUT);
pinMode(indietroS, OUTPUT);
pinMode(vel, OUTPUT);
pinMode(LEDG, OUTPUT);
pinMode(LEDR, OUTPUT);
pinMode(LEDV, OUTPUT);

} 

void loop() {
 
 if (IrReceiver.decode()) {

    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

switch (code){

  case 0xF30CBF00: // STOP
  
digitalWrite(motoreD, LOW);
digitalWrite(motoreS, LOW);
digitalWrite(indietroD, LOW);
digitalWrite(indietroS, LOW);
digitalWrite(LEDG, LOW);
digitalWrite(LEDV, LOW);
digitalWrite(LEDR, HIGH);
analogWrite(vel, 0);
Serial.println("0 = STOP");
  break;

  case 0xEE11BF00: // VELOCITA' +

if(veloc<256){
veloc = veloc + 10;
analogWrite(vel, veloc);
Serial.println("2 = AUMENTA VELOCITA'");
break;
 
  case 0xED12BF00: // AVANTI
 
 digitalWrite(motoreD, HIGH);
digitalWrite(motoreS, HIGH);
digitalWrite(indietroD, LOW);
digitalWrite(indietroS, LOW);
digitalWrite(LEDG, LOW);
digitalWrite(LEDV, HIGH);
digitalWrite(LEDR, LOW);
cont = 'a';
Serial.println("3 = VAI AVANTI");
analogWrite(vel, 100);
break;
 
  case 0xE916BF00: // INDIETRO

digitalWrite(motoreD, LOW);
digitalWrite(motoreS, LOW);
digitalWrite(indietroD, HIGH);
digitalWrite(indietroS, HIGH);
digitalWrite(LEDG, HIGH);
digitalWrite(LEDV, LOW);
digitalWrite(LEDR, LOW);
cont = 'i';
Serial.println("6 = VAI INDIETRO");
analogWrite(vel, 100);
break;

  case 0xE718BF00: // GIRA A SINISTRA

 if(cont == 'a'){
digitalWrite(motoreD, HIGH);
digitalWrite(motoreS, LOW);
digitalWrite(indietroD, LOW);
digitalWrite(indietroS, LOW);
digitalWrite(LEDG, LOW);
digitalWrite(LEDV, HIGH);
digitalWrite(LEDR, LOW);
 }else if(cont == 'i'){
digitalWrite(motoreD, LOW);
digitalWrite(motoreS, LOW);
digitalWrite(indietroD, HIGH);
digitalWrite(indietroS, LOW);
digitalWrite(LEDG, HIGH);
digitalWrite(LEDV, LOW);
digitalWrite(LEDR, LOW);
 }
   Serial.println("7 = GIRA A SINISTRA");
}
break;

  case 0xE619BF00: // VELOCIA' -

   if(veloc>50){
    veloc = veloc - 10;
analogWrite(vel, veloc); 
   }
    Serial.println("8 = RIDUCI VELOCITA'");
  break;

  case 0xE51ABF00: // GIRA A DESTRA

if(cont == 'a'){
digitalWrite(motoreD, LOW);
digitalWrite(motoreS, HIGH);
digitalWrite(indietroD, LOW);
digitalWrite(indietroS, LOW);
digitalWrite(LEDG, LOW);
digitalWrite(LEDV, HIGH);
digitalWrite(LEDR, LOW);
 }else if(cont == 'i'){
digitalWrite(motoreD, LOW);
digitalWrite(motoreS, LOW);
digitalWrite(indietroD, LOW);
digitalWrite(indietroS, HIGH);
digitalWrite(LEDG, LOW);
digitalWrite(LEDV, HIGH);
digitalWrite(LEDR, LOW);
 }
     Serial.println("9 = GIRA A DESTRA");
 break;
}



} 
IrReceiver.resume();
  delay(10);
}