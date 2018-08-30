/*
 * license    MIT - Copyright (c) 2018 Matt Marchant
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */ 

#include "DigitalControl.hpp"
#include <Arduino.h>

namespace
{
const uint8_t INPUT_PIN = 12;
}

DigitalControl::DigitalControl(uint8_t note, midi::MidiInterface<HardwareSerial>& interface)
	: m_note	(note),
	m_interface	(interface),
	m_lastValue	(0)
{

}

void DigitalControl::update()
{
	auto value = digitalRead(INPUT_PIN);
	if(value != m_lastValue)
	{
		if(value == LOW)
		{
			//button PRESSED
			m_interface.sendNoteOn(m_note, 127, 1);
		}
		else
		{
			m_interface.sendNoteOff(m_note, 0, 1);
		}
	}
	m_lastValue = value;
}