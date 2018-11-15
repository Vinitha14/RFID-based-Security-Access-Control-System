#include <SoftwareSerial.h> 
SoftwareSerial GPRS(9,10); boolean state, lastState; 
boolean state1, lastState1; 
boolean state2, lastState2; 
boolean state3, lastState3; 
void setup() 
{ 
pinMode(2, INPUT_PULLUP); pinMode(3, INPUT_PULLUP); pinMode(4, INPUT_PULLUP); pinMode(5, INPUT_PULLUP); state = digitalRead(2); 
lastState = state; 
state1 = digitalRead(3); 
lastState1 = state1; 
state2 = digitalRead(4); 
lastState2 = state2; 
state3 = digitalRead(5);
lastState3 = state3; 
GPRS.begin(9600); 
Serial.begin(9600); 
GPRS.println("AT+CMGF=1"); 
delay(1000); 
} 
void loop() 
{ 
while(GPRS.available()) { 
Serial.write(GPRS.read()); 
} 
lastState = state; 
state = digitalRead(2); 
lastState1 = state1; 
state1 = digitalRead(3); 
lastState2 = state2; 
state2 = digitalRead(4);
lastState3 = state3; 
state3 = digitalRead(5); 
if ( state != lastState ) { 
sendSMS(); 
} 
if ( state1 != lastState1 ) { 
sendSMS1(); 
} 
if ( state2 != lastState2 ) { 
sendSMS2(); 
} 
if ( state3 != lastState3 ) { 
sendSMS3(); 
} 
delay(500); 
}
void sendSMS() { 
GPRS.println("AT+CMGS=\"+918754439985\"\r");  delay(500); 
GPRS.println(" This is VINITHA"); 
delay(100); 
GPRS.println((char)26); 
delay(500); 
} 
void sendSMS1() { 
GPRS.println("AT+CMGS=\"+918754439985\"\r");  delay(1000); 
GPRS.println(" This is MEGHANA"); 
delay(100); 
GPRS.println((char)26); 
delay(100); 
}
void sendSMS2() { 
GPRS.println("AT+CMGS=\"+9659197779\"\r");  delay(1000); 
GPRS.println(" This is VENI"); 
delay(100); 
GPRS.println((char)26); 
delay(100); 
} 
void sendSMS3() { 
GPRS.println("AT+CMGS=\"+8754439985\"\r");  delay(1000); 
GPRS.println(" This is CHINNI"); 
delay(100); 
GPRS.println((char)26); 
delay(100); 
}
