#include "LH_String.h" // "Laser Harp String" class

SoftwareSerial myMonitor(0, 1); // For debug purpose

LH_String myA4 = LH_String(A0, 6, 69, 1016); // Analog input A0, MIDI output 6, note 69 (A4), analog treshold: 1016
LH_String myA3 = LH_String(A2, 6, 57, 1010);

void setup() {

  myMonitor.begin(9600);
}

void loop() {

  myA4.checkStringPlayed(); // Detects if this string is played and so plays an A4
  
  //myMonitor.println(myA4.getLastAnalogVal()); // Prints sensor analog value, so I can easily configure analog treshold
  
  myA3.checkStringPlayed();
  
  //myMonitor.println(myA3.getLastAnalogVal());
  
  delay(5);
}

