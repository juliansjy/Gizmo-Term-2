#include <Servo.h> //Servo Library which turns the metal wires
#include <SPI.h> //Serial Peripheral Interface Library for various modules to communicate with each other quickly
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //LCD I2C Library to display actions required by human
#include <MFRC522.h> //RFID Library to read card in order to obtain snack

#define SS_PIN 53
#define RST_PIN 9
//#define NEW_UID {17, F8, 51, B4}

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

int a, b, c, d;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Wire.begin();
  SPI.begin();
  lcd.init();
  lcd.backlight();
  pinMode(OUTPUT, 5);
  pinMode(OUTPUT, 6);
  pinMode(OUTPUT, 7);
  pinMode(OUTPUT, 8);
  mfrc522.PCD_Init();
  lcd.print("   Press Button");
}

void loop() {
  // put your main code here, to run repeatedly
  lcd.clear();
  lcd.print("   Press Button");
  a = digitalRead(5);
  b = digitalRead(6);
  c = digitalRead(7);
  d = digitalRead(8);
  Serial.print(a);
  Serial.print(b);
  Serial.print(c);
  Serial.print(d);

  if(a==0){
    lcd.clear();
    //lcd.setCursor(1, 1);
    lcd.print("   $5    ");
    lcd.print("   Give me your card!");
    delay(2000);
    if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }

    if(!mfrc522.PICC_ReadCardSerial()){
      return;
    }

    Serial.print("UID tag:");
    String content = "";
    byte letter;
    for(byte i=0; i<mfrc522.uid.size; ++i){
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message:");
    content.toUpperCase();
    if(content.substring(1) == "17 F8 51 B4"){
      servo.attach(A0);
      servo.write(18);
      delay(2000);
      servo.write(0);
      delay(2000);
      servo.detach();
      delay(2000);
      lcd.clear();
      //lcd.setCursor(1, 1);
      lcd.print(" Take your snack!");
      delay(1000);
    }
  }
  if(b==0){
    lcd.clear();
    //lcd.setCursor(1, 1);
    lcd.print("   $5    ");
    lcd.print("   Give me your card!");
    delay(2000);
    if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }

    if(!mfrc522.PICC_ReadCardSerial()){
      return;
    }

    Serial.print("UID tag:");
    String content = "";
    byte letter;
    for(byte i=0; i<mfrc522.uid.size; ++i){
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message:");
    content.toUpperCase();
    if(content.substring(1) == "17 F8 51 B4"){
      servo.attach(2);
      servo.write(180);
      delay(2000);
      servo.write(0);
      delay(2000);
      servo.detach();
      delay(2000);
      lcd.clear();
      //lcd.setCursor(1, 1);
      lcd.print(" Take your snack!");
      delay(1000);
    }
  }
  if(c==0){
    lcd.clear();
    //lcd.setCursor(1, 1);
    lcd.print("   $5    ");
    lcd.print("   Give me your card!");
    delay(2000);
    if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }

    if(!mfrc522.PICC_ReadCardSerial()){
      return;
    }

    Serial.print("UID tag:");
    String content = "";
    byte letter;
    for(byte i=0; i<mfrc522.uid.size; ++i){
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message:");
    content.toUpperCase();
    if(content.substring(1) == "17 F8 51 B4"){
      servo.attach(3);
      servo.write(180);
      delay(2000);
      servo.write(0);
      delay(2000);
      servo.detach();
      delay(2000);
      lcd.clear();
      //lcd.setCursor(1, 1);
      lcd.print(" Take your snack!");
      delay(1000);
    }
  }
  if(d==0){
    lcd.clear();
    //lcd.setCursor(1, 1);
    lcd.print("   $5    ");
    lcd.print("   Give me your card!");
    delay(2000);
    if(!mfrc522.PICC_IsNewCardPresent()){
      return;
    }

    if(!mfrc522.PICC_ReadCardSerial()){
      return;
    }

    Serial.print("UID tag:");
    String content = "";
    byte letter;
    for(byte i=0; i<mfrc522.uid.size; ++i){
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "  0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message:");
    content.toUpperCase();
    if(content.substring(1) == "17 F8 51 B4"){
      servo.attach(4);
      servo.write(180);
      delay(2000);
      servo.write(0);
      delay(2000);
      servo.detach();
      delay(2000);
      lcd.clear();
      //lcd.setCursor(1, 1);
      lcd.print(" Take your snack!");
      delay(1000);
    }
  }
  delay(100);
}