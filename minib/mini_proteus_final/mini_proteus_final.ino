#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 12, 5, 4, 3, 2);

#define MQPin A0
#define buzzer 6

void setup() 
{
   lcd.begin(16, 2);
   pinMode(MQPin, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
   Serial.begin(9600);
   lcd.setCursor(3, 0);
   lcd.print("GAS DETECTOR");
   delay(2000);  //The preheat duration of MQ2 is 20 sec
   lcd.clear();
}

void loop() {

int gas_value = digitalRead(MQPin);

if(gas_value==HIGH)
{
  digitalWrite(buzzer, HIGH);
  lcd.setCursor(1, 0);
  lcd.print("GAS DETECTED");
  delay(2000);
  lcd.clear();
  delay(200);
  
}
else
{
 digitalWrite(buzzer, LOW); 
}
  

}
