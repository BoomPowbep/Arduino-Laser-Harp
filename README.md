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

The [Fritzing](http://fritzing.org/home/) file contains a simple sketch of the wiring.

```
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
```

## Built With

* [Arduino](https://www.arduino.cc/en/Tutorial/Midi) - Used SoftwareSerial to write to MIDI

## Author

* **Mickaël Debalme** - *Initial work* - [BoomPowbep](https://github.com/BoomPowbep)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
