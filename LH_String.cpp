/***********************************************
*             ___     _       _
*            / __|  _| |_   _| |_
*           | (__  |_   _| |_   _|
*            \___|   |_|     |_|
*
*             Arduino Laser Harp
*
*                LH_String.cpp
*               Mickaël Debalme
*              01/04/2018 (V1.0)
*             Laser harp's string
*
*              Copyright (C) 2018
*
**********************************************/

#include "LH_String.h"

LH_String::LH_String(const byte analogInput, const byte midiPinOut, const byte note, const int treshold) : m_midi(midiPinOut), m_analogPin(analogInput), m_note(note), m_treshold(treshold), m_isActive(false), m_lastAnalogVal(0) {

  // Make sure the note is off
  m_midi.noteOff(m_note);
}

LH_String::~LH_String() {};

void LH_String::checkStringPlayed() {

    // Reading analog input value
    int LDR_val = m_lastAnalogVal = analogRead(m_analogPin);

    // If the note is off and the string is played
    if(m_isActive == false && LDR_val < m_treshold) {
       
      // Play note
      m_midi.noteOn(m_note);
      m_isActive = true;
    }

    // If the note is on as the string is not played anymore
    else if(m_isActive == true && LDR_val >= m_treshold) {

      // Stop playing note
      m_midi.noteOff(m_note);
      m_isActive = false;
    }
}

int LH_String::getLastAnalogVal() const {

  return m_lastAnalogVal;
}
