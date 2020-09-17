#include <LiquidCrystal.h>
int incomingVoltagePin=A0;
int adcValue=0;
double voltageReading=0;
float sensorError=2500;
int sensorSensitivity=100;
double currentReading=0;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  
  lcd.begin(20,4);
  pinMode(incomingVoltagePin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("Current=");
}

void loop() {
  adcValue=analogRead(incomingVoltagePin);
  voltageReading=(5000.00*adcValue)/1024.0;
  voltageReading=voltageReading-sensorError;
  currentReading=voltageReading/ sensorSensitivity;
  lcd.setCursor(9,0);
  lcd.print(currentReading);
  lcd.print("A");
  
  delay(500);
  
} 
