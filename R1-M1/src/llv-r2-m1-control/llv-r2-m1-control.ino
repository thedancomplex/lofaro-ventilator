#include <Servo.h>
#include <math.h>
Servo s1;
Servo s2;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  s1.attach(10);
  s2.attach(9);
}


int theMax = 140;
int theMin = 40;
void doSet(int val){
  int ss1 = 90 - val;
  int ss2 = 90 + val;
  if(ss1 > theMax) ss1 = theMax;
  if(ss1 < theMin) ss1 = theMin;
  if(ss2 > theMax) ss2 = theMax;
  if(ss2 < theMin) ss2 = theMin;

  s1.write(ss1);
  s2.write(ss2);
  return;
}


double f = 12.0/60.0;
double dtheta = 30.0;
//unsigned long t = 0;
int T = 10;
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long t = millis();
  double td = t/1000.0;
  double val = sin(2.0*3.14159*td*f)*dtheta;
  int vali = (int)val-20;// + 20;
  doSet(vali);
  Serial.print(vali);
  Serial.print(',');
  Serial.println(val);
  t = t+T;
  delay(T);
}
