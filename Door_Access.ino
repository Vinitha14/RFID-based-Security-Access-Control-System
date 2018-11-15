#include <SPI.h> 
#include <MFRC522.h> 
#include <Servo.h> 
int count = 0; 
#define SS_PIN 10 
#define RST_PIN 9 
#define sw3 2  
#define sw4 3  
#define BUZZER A4 
#define sw1 4 
#define sw2 5 
MFRC522 mfrc522(SS_PIN, RST_PIN);  Servo myServo; // Servo motor 
void setup()  
{ 
Serial.begin(9600);  
SPI.begin();  
mfrc522.PCD_Init();  
pinMode(sw3, OUTPUT); 
pinMode(sw4, OUTPUT); 
pinMode(sw1, OUTPUT); 
pinMode(sw2, OUTPUT); 
pinMode(BUZZER, OUTPUT); 
noTone(BUZZER); 
digitalWrite(sw3, HIGH); 
digitalWrite(sw4, HIGH); 
digitalWrite(sw1, HIGH); 
digitalWrite(sw2, HIGH); 
myServo.attach(8);  
myServo.write(10);  
Serial.println("Put your card to the reader..."); Serial.println(); 
}
void loop()  
{ 
// Look for new cards 
if ( ! mfrc522.PICC_IsNewCardPresent())  
{ 
return; 
} 
// Select one of the cards 
if ( ! mfrc522.PICC_ReadCardSerial())  
{ 
return; 
} 
//Show UID on serial monitor 
Serial.print("UID tag :"); 
String content= ""; 
byte letter; 
for (byte i = 0; i < mfrc522.uid.size; i++)  
{ 
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); Serial.print(mfrc522.uid.uidByte[i], HEX); 
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); content.concat(String(mfrc522.uid.uidByte[i], HEX)); delay(500); 
}
Serial.println(); 
Serial.print("Message : "); 
content.toUpperCase(); 
if (content.substring(1) == "7D 32 CC 73")  { 
myServo.write(170); // Unlocks the door Serial.println("Authorized access"); Serial.println(); 
delay(500); 
//digitalWrite(sw3, HIGH); 
tone(BUZZER, 500); 
delay(300); 
noTone(BUZZER); 
digitalWrite(sw3, LOW); 
delay(300); 
digitalWrite(sw3, HIGH); 
delay(500); 
myServo.write(10); // Locks the door } 
else if (content.substring(1) == "53 17 41 2E")  { 
myServo.write(170); // Unlocks the door Serial.println("Authorized access"); Serial.println();
delay(500); 
//digitalWrite(sw4, HIGH); 
tone(BUZZER, 500); 
delay(300); 
noTone(BUZZER); 
digitalWrite(sw4, LOW); 
delay(300); 
digitalWrite(sw4, HIGH); 
delay(500); 
myServo.write(10); // Locks the door } 
else if (content.substring(1) == "E0 F1 77 A4")  { 
Serial.println("Authorized access"); Serial.println(); 
delay(500); 
// digitalWrite(sw1, HIGH); 
tone(BUZZER, 500); 
delay(300); 
noTone(BUZZER); 
digitalWrite(sw1, LOW);
delay(300); 
digitalWrite(sw1, HIGH); 
} 
else if (content.substring(1) == "82 4C 3F 65")  { 
Serial.println("Authorized access"); Serial.println(); 
delay(500); 
// digitalWrite(sw2, HIGH); 
tone(BUZZER, 500); 
delay(300); 
noTone(BUZZER); 
digitalWrite(sw2, LOW); 
delay(300); 
digitalWrite(sw2, HIGH); 
} 
else 
{ 
Serial.println("Unauthorized access"); Serial.println(); 
delay(500); 
// digitalWrite(sw2, HIGH);
tone(BUZZER, 500); 
delay(300); 
noTone(BUZZER); 
digitalWrite(sw2, LOW); delay(300); 
digitalWrite(sw2, HIGH); } 
} 
