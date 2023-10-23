#include <ESP8266WiFi.h>
#include <tcs3200.h>
#define S0 D0
#define S1 D1
#define S2 D2
#define S3 D3
#define sensorOut D4

int redFrequency = 0;
int greenFrequency = 0;
int whiteFrequency = 0;

int redColor = 0;
int greenColor = 0;
int whiteColor = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  Serial.begin(9600);
}

void loop() {
  //red
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);

  redFrequency = pulseIn(sensorOut, LOW);
  redColor = map(redFrequency, 39, 103, 255,0);

  Serial.print("R= ");
  Serial.print(redColor);
  delay(100);

  //green
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency, 61, 109, 255, 0);

  Serial.print(" G= ");
  Serial.print(greenColor);
  delay(100);

  //white
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  whiteFrequency = pulseIn(sensorOut, LOW);
  whiteColor = map(whiteFrequency, 38, 125, 255, 0);

  Serial.print(" W= ");
  Serial.print(whiteColor);
  delay(100);

  if(redColor > greenColor && redColor > whiteColor){
    Serial.println(" - RED detected!");
  }
  if(greenColor > redColor && greenColor > whiteColor){
    Serial.println(" - GREEN detected!");
  }
  if(whiteColor > redColor && whiteColor > greenColor){
    Serial.println(" - WHITE detected!");
  }
}