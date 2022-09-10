//Libarys
#include <Servo.h>
Servo myservo;

//Fahrt
bool Uhrzeigersin = true;
bool gegenUhrzeigersin = false;
int Rundenzaehler = 0;
bool schonpassiert = false;

//Ultraschallvariablen
int Ultraschaltrigger1 = 4;
int Ultraschalecho1 = 5;
int Ultraschaltrigger2 = 6;
int Ultraschalecho2 = 7;

int Ultraschal(){
  digitalWrite(Ultraschaltrigger1, LOW);
  delay(5);
  digitalWrite(Ultraschaltrigger1, HIGH);
  delay(10);
  digitalWrite(Ultraschaltrigger1, LOW);

  float abstand1 = pulseIn(Ultraschalecho1, HIGH);
  int abstand_cm1 = 0.017 * abstand1;
  return abstand_cm1;
}


int Ultraschal2(){
  digitalWrite(Ultraschaltrigger2, LOW);
  delay(5);
  digitalWrite(Ultraschaltrigger2, HIGH);
  delay(10);
  digitalWrite(Ultraschaltrigger2, LOW);

  float abstand2 = pulseIn(Ultraschalecho2, HIGH);
  int abstand_cm2 = 0.017 * abstand2;
  return abstand_cm2;
}



void setup() {
// put your setup code here, to run once:
pinMode(Ultraschaltrigger1, OUTPUT);
pinMode(Ultraschalecho1, INPUT);
pinMode(Ultraschaltrigger2, OUTPUT);
pinMode(Ultraschalecho2, INPUT);
digitalWrite(Ultraschaltrigger1, LOW);
digitalWrite(Ultraschaltrigger2, LOW);
Serial.begin(9600);
myservo.attach(9);
//Motor Starten
digitalWrite(3, LOW);
digitalWrite(2, HIGH);
Serial.begin(9600);

}

void loop() {
// put your main code here, to run repeatedly:


//Ultraschall Abfragen
Ultraschal();
Ultraschal2();
Serial.println(Rundenzaehler);

//Fahrt

if(Uhrzeigersin == true)
  while(true){
     if(Ultraschal2() > 180){
        kurvenfahrt();
     }
     if(Ultraschal2() < 20){
      myservo.write(80);
      delay(10);
      }
     if(Ultraschal2() == 20){
      myservo.write(90);
      delay(10);
      }
     if(Ultraschal2() > 20){
      myservo.write(100);
      delay(10);
      }
   }
}

void kurvenfahrt(){
      myservo.write(120);
      if(schonpassiert == false){
         Rundenzaehler ++;
         Serial.println(Rundenzaehler);
         delay(10);
         schonpassiert = true;
         delay(10);
         
      }
     if(Ultraschal2() < 20){
       schonpassiert = false;
       delay(10);
       return;
     }
     if(Rundenzaehler >=12){
        Serial.println(Rundenzaehler);
        while(Ultraschal2() > 20){
          myservo.write(120);
        }
        while(true) {
           digitalWrite(2, LOW);
        }
      
     }
     kurvenfahrt();
}
