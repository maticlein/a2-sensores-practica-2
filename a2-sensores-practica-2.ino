#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int EchoPin = 5;
const int TriggerPin = 6;
long duracion, distancia;
float temperatura;

Servo servoMotor;
LiquidCrystal_I2C lcd(0x3F,16,2);  //

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   servoMotor.attach(9);
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("Dist: ")
   lcd.setCursor(0, 1);
   lcd.print("Temp: ")
}

void loop() {   
   digitalWrite(TriggerPin, LOW);  
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duracion = pulseIn(EchoPin, HIGH);  
   distancia = duracion * 10 / 292/ 2;
  
   temperatura = analogRead(A0) / 1023.0 * 5000.0 / 10.0 ;
  
   Serial.print("Distancia: ");
   Serial.println(distancia);
   lcd.setCursor(6, 0);
   lcd.print(distancia)
   Serial.print("Temperatura: ");
   Serial.println(temperatura);
   lcd.setCursor(6, 1);
   lcd.print(temperatura)
   delay(1000);
  
  servoMotor.write(0);
  delay(1000);
  servoMotor.write(90);
  delay(1000);
  servoMotor.write(180);
  delay(1000);
}