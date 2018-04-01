#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>

#define DEFAULT_RX      5     // Default RX pin. Automatically configured
#define MIDI_BAUDRATE   31250 // Midi baudrate

class LH_Midi {

  private:
     const SoftwareSerial m_serial; // Communication via MIDI

  public:
    LH_Midi(byte serialTx = 1);
    ~LH_Midi();

    void noteOn(byte pitch) const;                  // Plays a note at maximum velocity
    void noteOn(byte pitch, byte velocity) const;   // Plays a note at a defined velocity
    void noteOff(byte pitch) const;                 // Shuts a note (required or il will play infinitely)
};

