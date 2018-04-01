#pragma once

#include "LH_Midi.h"

class LH_String {

  private: 
    LH_Midi m_midi;                   // MIDI object
    const byte m_channel;             // MIDI channel (not used)
    const byte m_analogPin;           // Analog input used
    const byte m_note;                // Note to play
    const int m_treshold;             // Sensor sensibility treshold
    bool m_isActive;                  // Is a note playing?
    int m_lastAnalogVal;              // Last analog value got

  public:
    LH_String(const byte analogInput, const byte channel, const byte note, const int treshold);
    ~LH_String();

  void checkStringPlayed(); // Checks if the string is 'cut', and plays a note

  int getLastAnalogVal() const;   // Gets last analog value got
};

