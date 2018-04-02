/***********************************************
*             ___     _       _
*            / __|  _| |_   _| |_
*           | (__  |_   _| |_   _|
*            \___|   |_|     |_|
*
*             Arduino Laser Harp
*
*                LH_Midi.cpp
*               Mickaël Debalme
*              01/04/2018 (V1.0)
*           Laser harp's MIDI link
*
*              Copyright (C) 2018
*
**********************************************/

#include "LH_Midi.h"

LH_Midi::LH_Midi(byte serialTx) : m_serial(DEFAULT_RX, serialTx) {

  m_serial.begin(MIDI_BAUDRATE); // Open serial port
}

LH_Midi::~LH_Midi() {}

void LH_Midi::noteOn(byte pitch) const {

  m_serial.write(0x90);   // Note ON mode
  m_serial.write(pitch);
  m_serial.write(0x7F);   // Maximum velocity
}

void LH_Midi::noteOn(byte pitch, byte velocity) const {

  // Max velocity is 127 (0x7F)
  if(velocity <= 0x7F) {
    m_serial.write(0x90);     // Note ON mode
    m_serial.write(pitch);
    m_serial.write(velocity);
  }
}

void LH_Midi::noteOff(byte pitch) const {

  m_serial.write(0x80);     // Note OFF mode
  m_serial.write(pitch);
  m_serial.write((byte)0);  // Minimum velocity(cut off)
}

