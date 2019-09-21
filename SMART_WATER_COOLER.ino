#include <Servo.h>
#include <DHT.h>
int DHTPIN=12;  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
Servo servo;
int angle = 10;
const int trigPin = 9;
const int echoPin = 10;
int LED=5;
int LED2=6;


long duration;
int distance;
void open() 
 { 
    digitalWrite(LED2,HIGH);
    digitalWrite(LED,LOW);
    for(angle = 10; angle < 100; angle++)  
  {                                  
    servo.write(angle);               
    delay(10);                   
  }  
  for(angle; angle > 10; angle--)  
  {                                  
    servo.write(angle);               
    delay(10);                   
  }          
 }


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(LED,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(DHTPIN,INPUT);
Serial.begin(9600);
dht.begin(); 
servo.attach(8);
servo.write(angle);
}
void close()
 {
    digitalWrite(LED,HIGH);
    digitalWrite(LED2,LOW);
 }
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;   
float h=dht.readHumidity();
Serial.println(distance);
if(distance<=10 || h<5)
  close();
else if (distance>10) 
  open();
}
