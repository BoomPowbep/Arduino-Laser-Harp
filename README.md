# Arduino Laser Harp - v 1.0 [WORK IN PROGRESS]

A very simple Laser Harp running with an Arduino UNO.

### Prerequisites

- [x] Synthesizer with MIDI input
- [x] Arduino
- [x] LDRs
- [x] Laser diodes (5V)
- [x] 2 x 220 ohm and as much 10kohm as LDRs
- [x] MIDI female jack

## Deployment

The [Fritzing] (http://fritzing.org/home/) file contains a simple sketch of the wiring.

```
#include "LH_String.h" // "Laser Harp String" class

SoftwareSerial myMonitor(0, 1); // For debug purpose

// Here we have two strings
LH_String myA = LH_String(A0, 1, 69, 1011); // Wired on input A0, uses MIDI channel 1, note 69 (A4), analog treshold: 1011
LH_String myF = LH_String(A2, 1, 41, 999);

void setup() {

  myMonitor.begin(9600);
}

void loop() {

  myA.checkStringPlayed(); // Detects if this string is played and so plays an A
  
  myMonitor.println(myA.getLastAnalogVal()); // Prints sensor analog value, so you can easily configure analog treshold
  
  myF.checkStringPlayed();
  
  //myMonitor.println(myF.getLastAnalogVal()); // Detects if this string is played and so plays an F
  
  delay(10);
}
```

## Built With

* [Arduino](https://www.arduino.cc/en/Tutorial/Midi) - Used SoftwareSerial to write to MIDI

## Author

* **Mickaël Debalme** - *Initial work* - [BoomPowbep](https://github.com/BoomPowbep)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
