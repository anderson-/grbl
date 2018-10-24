#include <grbl.h>

void servo(int pin, int pos, int duration){
  const int period = 20; //ms
  int dc = map(pos, -90, 90, 700, 2400);
  int p = (period*1000) - dc;
  int t = duration/period;
  for (;t>0;t--){
    digitalWrite(pin, HIGH);
    delayMicroseconds(dc);
    digitalWrite(pin, LOW);
    delay(p/1000);
    delayMicroseconds(p%1000);
  }
}

int servoPin = 12;

void spindle_up(){
  servo(servoPin, 0, 1000);
}

void spindle_down(){
  servo(servoPin, 90, 1000);
}

void setup(){
  pinMode(servoPin, OUTPUT);
  grbl_run();
}

void loop(){
}
