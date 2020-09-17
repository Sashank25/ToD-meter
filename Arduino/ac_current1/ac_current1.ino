#include <LiquidCrystal.h>



int incomingVoltagePin=A0;
int adcValue=0;
double voltageReading=0;
float sensorError=2500;
int sensorSensitivity=185;
double instCurrentReading=0;
double peakCurrentReading=0;
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  lcd.begin(20,4);
  pinMode(incomingVoltagePin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("RMS Current:");
   
}
void loop() {
  adcValue=analogRead(incomingVoltagePin);
  voltageReading=(5000.00*adcValue)/1024.0;
  voltageReading=voltageReading-sensorError; 
  instCurrentReading=voltageReading/ sensorSensitivity;
  for(int i=0;i==5000;i++) {
    if(peakCurrentReading<instCurrentReading){
      break;
    }
    else {
      lcd.setCursor(1,1); 
      lcd.print(peakCurrentReading*0.707);
      lcd.print("A");
    }
  }
  peakCurrentReading=instCurrentReading;  
  delay(5);
}
