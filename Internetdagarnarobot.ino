
#include <Servo.h> 
 
Servo myservo;
int pos = 90;
int vled = 13;
int hled = 13;
int vledb = 0;
int hledb = 0;
int maxled = 255;
 
void setup() 
{ 
  myservo.attach(9);
  pinMode(vled, OUTPUT);     
  pinMode(hled, OUTPUT);     

  //ground-pins
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  
  randomSeed(analogRead(0));

  //Vakna!!
//  fadebothleds(maxled, 100, 200);
  blinkeyes(2, 2000);
moveservo(20, 10,1000);
moveservo(180, 10,1000);
}
 
void loop() {
  moveservo(random(160)+20, random(30+10), random(500+300));  
  if (random(30) == 14) {
    sov();  
  }

  if (random(3) == 2) {
//    blinkeyes(1, 0);
  }

  if (random(20) == 2) {
    blinkeyes(2, 0);
  }

} 

void sov() {
  //Move to sleepposition
  moveservo(90, 50, 200);

  //Almost fall asleep
  fadebothleds(10, 30, 0);

  //Twitch
  fadebothleds(maxled, 0, 0);
  moveservo(85, 0, 100);
  moveservo(95, 0, 100);
  moveservo(85, 0, 100);
  moveservo(95, 0, 400);

  //Blink
  blinkeyes(2, 1000);
  //This time he falls asleep
  fadebothleds(0, 30, 6000);

  //Wake
  fadebothleds(maxled, 0, 0);
  moveservo(69, 2, 100);
  moveservo(109, 2, 100);
  moveservo(69, 2, 100);
  moveservo(90, 2, 400);
  //Blink
  blinkeyes(2, 2000);
}

void blinkeyes(int cnt, int adelay) {
  for (int i=0; i < cnt; i++){
    fadebothleds(0, 1, 200);
    fadebothleds(maxled, 1, 200);
  } 
  delay(adelay);
}

void fadebothleds(int newb, int rdelay, int adelay) {
  do {
    if (newb > vledb) { vledb = vledb + 1; } else { vledb = vledb - 1; }
    hledb = vledb;    
    analogWrite(hled, hledb);
    analogWrite(vled, vledb);
    delay(rdelay);
  } while (newb != vledb);
  delay(adelay);
}

void moveservo(int newpos, int rdelay, int adelay) {
  do {
    if (newpos > pos) { pos = pos + 1; } else { pos = pos - 1; }
    myservo.write(pos);
    delay(rdelay);
  } while (newpos != pos);
  delay(adelay);
}

