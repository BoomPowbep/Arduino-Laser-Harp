#include "LH_String.h" // "Laser Harp String" class

SoftwareSerial myMonitor(0, 1); // For debug purpose

LH_String myA = LH_String(A0, 1, 69, 1011); // Wired on input A0, uses MIDI channel 1, note 69 (A4), analog treshold: 1011
LH_String myC = LH_String(A2, 1, 41, 999);

void setup() {

  myMonitor.begin(9600);
}

void loop() {

  myA.checkStringPlayed(); // Detects if this string is played and so plays an A
  
  //myMonitor.println(myA.getLastAnalogVal()); // Prints sensor analog value, so I can easily configure analog treshold
  
  myC.checkStringPlayed();
  
  //myMonitor.println(myC.getLastAnalogVal());
  
  delay(10);
}

