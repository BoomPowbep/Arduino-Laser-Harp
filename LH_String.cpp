#include "LH_String.h"

LH_String::LH_String(const byte analogInput, const byte channel, const byte note, const int treshold) : m_midi(6), m_analogPin(analogInput), m_channel(channel), m_note(note), m_treshold(treshold), m_isActive(false) {

  // Make sure the note is off
  m_midi.noteOff(m_note);
}

LH_String::~LH_String() {};

void LH_String::checkStringPlayed() {

    // Reading analog input value
    int LDR_val = m_lastAnalogVal = analogRead(m_analogPin);

    // If the note is off and the string is 'cut'
    if(LDR_val < m_treshold && m_isActive == false) {
       
      // Play note
      m_midi.noteOn(m_note);
      m_isActive = true;
    }

    // If the note is on as the string is 'free'
    else if(LDR_val >= m_treshold && m_isActive == true) {

      // Stop playing note
      m_midi.noteOff(m_note);
      m_isActive = false;
    }
}

int LH_String::getLastAnalogVal() const {

  return m_lastAnalogVal;
}

