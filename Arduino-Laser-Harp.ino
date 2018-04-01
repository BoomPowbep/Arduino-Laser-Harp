#include "LH_String.h"

SoftwareSerial myMonitor(0, 1);

LH_String myA = LH_String(A0, 1, 69, 1011);
LH_String myC = LH_String(A2, 1, 41, 999);

void setup() {

  myMonitor.begin(9600);
}

void loop() {

  myA.checkStringPlayed();
  //myMonitor.println(myA.getLastAnalogVal());
  myC.checkStringPlayed();
  //myMonitor.println(myC.getLastAnalogVal());
  
  delay(10);
}

