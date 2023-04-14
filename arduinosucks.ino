int trigpin1 = 12;
int echopin1 = A1;
int trigpin2 = 8;
int echopin2 = A0;
int trigpin3 = 7;
int echopin3 = A2;
int trigpin4 = 4;
int echopin4 = A3;
int buzzer = 3;
int Servo1;
long duration1;
long distance1;
long duration2;
long distance2;
long duration3;
long distance3;
long duration4;
long distance4;
int maxdistance = 50;
long t1;
long t2;
long t3;
long t4;
unsigned long start_time ;
int i = 0;
int i2 = 0;


void setup() {
 pinMode(trigpin1,OUTPUT);
 pinMode(trigpin2,OUTPUT);
 pinMode(trigpin3,OUTPUT);
 pinMode(trigpin4,OUTPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(echopin1,INPUT);
 pinMode(echopin2,INPUT);
 pinMode(echopin3,INPUT);
 pinMode(echopin4,INPUT);
 Serial.begin(9600);
 delay(1000);
 t1 = 0;
 t2 = 0;
 t3 = 0;
 t4 = 0;
 start_time = millis();
}

void loop() {

  //Sensor1
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
  duration1 = pulseIn(echopin1,HIGH);
  distance1 = duration1 * 0.034/2;

  //Sensor2
  digitalWrite(trigpin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2,LOW);
  duration2 = pulseIn(echopin2,HIGH);
  distance2 = duration2 * 0.034/2;

  //Sensor3
  digitalWrite(trigpin3,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin3,LOW);
  duration3 = pulseIn(echopin3,HIGH);
  distance3 = duration3 * 0.034/2;

  //Sensor4
  digitalWrite(trigpin4,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin4,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin4,LOW);
  duration4 = pulseIn(echopin4,HIGH);
  distance4 = duration4 * 0.034/2;

  if (distance1<=maxdistance){
    t1 = millis();
  }
  else if (distance2<=maxdistance){
    t2 = millis();
  }
  if (distance3<=maxdistance){
    t3 = millis();
  }
  else if  (distance4<=maxdistance){
    t4 = millis();
  }

  if (t1>0 && t2>0){
    if (t1<t2){
      Serial.println("Left to right");
      //Correct way
    }
    else if (t2<t1){
      Serial.println("Right to left");
      //Wrong way
      while (i<=5){
        digitalWrite(buzzer,255);
        delay(500);
        i++;
        if (i == 4){
          digitalWrite(buzzer,0);
        }
      }
    }
    else{
      Serial.println("");
    }
    t1 = 0;
    t2 = 0;
  }
  if (t3>0 && t4>0){
    if (t3<t4){
      Serial.println("Left to right");
      while (i2<=5){
        digitalWrite(buzzer,255);
        delay(500);
        if (i2 == 4){
          digitalWrite(buzzer,0);
        }
        i2++;
      }
    }
    else if(t4<t3){
      Serial.println("Right to Left");
      //Correct way
    }
    else{
      Serial.println("");
    }
    t3 = 0;
    t4 = 0;
  }
}
