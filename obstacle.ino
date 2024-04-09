#include<LiquidCrystal.h>
#define LED_PIN 4
#define LCD_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 9
#define LCD_D5_PIN 8
#define LCD_D6_PIN 10
#define LCD_D7_PIN 11
#define buzzer_PIN 7
#define ECHO_PIN 6
#define Trigger_PIN 5
unsigned long lasttime=millis();
unsigned long timedelay=100;
LiquidCrystal MAD(LCD_PIN,LCD_E_PIN,LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN);
void trigger(){
  MAD.setCursor(6,0);
  digitalWrite(Trigger_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger_PIN,LOW);


  double duration=pulseIn(ECHO_PIN,HIGH);
  double distance=duration/58.0;
  MAD.print(distance);
  if(distance<100){
    buzzer();
    led();
  }
  else{
    MAD.print(distance);
    buzzeroff();
    ledoff();
  }
}
 





void buzzer(){
  tone(buzzer_PIN,450);
}
void led(){
  digitalWrite(LED_PIN,HIGH);
  delay(100);
  digitalWrite(LED_PIN,LOW);
}
void buzzeroff(){
  tone(buzzer_PIN,20);
}
void ledoff(){
  digitalWrite(LED_PIN,LOW);
}

void setup(){
  MAD.begin(16,2);
  Serial.begin(115200);
  pinMode(LED_PIN,OUTPUT);
  pinMode(buzzer_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(Trigger_PIN,OUTPUT);
}
void loop(){
  int timenow=millis();
  if(timenow-lasttime>timedelay){
    lasttime=timedelay;  
	trigger();
      
    
    }
  }

