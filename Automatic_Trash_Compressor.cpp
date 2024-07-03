// Name : Ahmad Zaki Bin Mohamad Hijazi
// Class : Negi
// Date : 21 January 2020
// Session : December 2019 – April 2020
// Jabatan : DKS – Robotic & Automation
// Project : Automatic Trash Compressor

#define trigPin 4
#define echoPin 5
int duration, distance;
int x=0;
int i=0;

void setup() 
{
        Serial.begin (9600); 
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(11, OUTPUT);
        pinMode(12, OUTPUT);
        pinMode(13, OUTPUT);
        pinMode(7, OUTPUT);
        pinMode(6, OUTPUT);
        
}
void loop() 
{

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    x=0;
    
  if (distance >= 0 && distance <= 5)
  {
        
        x=1;
  }

  if (x==1)
  {
        Serial.println("\n object detected \n");
        Serial.print("distance= ");              
        Serial.print(distance);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        digitalWrite(7,HIGH);
        digitalWrite(6,LOW);
        delay(65000);
        i=1;
  }
  else if (x==0)
  {
        Serial.println("no object detected");
        digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        digitalWrite(7,HIGH);
        digitalWrite(6,HIGH); 
        i=0;
  }
  
  if (i==1)
  {
        Serial.println("\n retracting \n");
        digitalWrite(11,LOW);
        digitalWrite(12,HIGH);
        digitalWrite(13,LOW);
        digitalWrite(7,LOW);
        delay(5000);
        digitalWrite(6,HIGH);
        delay(65000);
        x=0;
  }
  
}