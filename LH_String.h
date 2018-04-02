/***********************************************
*             ___     _       _
*            / __|  _| |_   _| |_
*           | (__  |_   _| |_   _|
*            \___|   |_|     |_|
*
*             Arduino Laser Harp
*
*                 LH_String.h
*               Mickaël Debalme
*              01/04/2018 (V1.0)
*             Laser harp's string
*
*              Copyright (C) 2018
*
**********************************************/

#pragma once

#include "LH_Midi.h"

class LH_String {

  private: 
    LH_Midi m_midi;                   // "Laser Harp MIDI" object
    const byte m_analogPin;           // Analog input used
    const byte m_note;                // Note to play
    const int m_treshold;             // Sensor sensibility treshold
    bool m_isActive;                  // Is a note playing?
    int m_lastAnalogVal;              // Last analog value got

  public:
    LH_String(const byte analogInput, const byte midiPinOut, const byte note, const int treshold);
    ~LH_String();

  void checkStringPlayed(); // Checks if the string is 'cut', and plays a note

  int getLastAnalogVal() const;   // Gets last analog value got
};

