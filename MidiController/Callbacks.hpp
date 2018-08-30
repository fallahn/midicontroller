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


#ifndef CALLBACKS_H_
#define CALLBACKS_H_

#include <Arduino.h>

#include "ControllerDefinitions.hpp"

void noteOnCallback(uint8_t channel, uint8_t note, uint8_t velocity)
{
	switch(note)
	{
	default: break;
	case NoteID::CueA:
		digitalWrite(LED::CueA, HIGH);
		break;
	case NoteID::CueB:
		digitalWrite(LED::CueB, HIGH);
		break;
	case NoteID::FX1:
		digitalWrite(LED::FX1, HIGH);
		break;
	case NoteID::FX2:
		digitalWrite(LED::FX2, HIGH);
		break;
	case  NoteID::PlayPauseA:
		digitalWrite(LED::PlayPauseA, HIGH);
		break;
	case NoteID::PlayPauseB:
		digitalWrite(LED::PlayPauseB, HIGH);
		break;
	}
}

void noteOffCallback(uint8_t channel, uint8_t note, uint8_t velocity)
{
	switch(note)
	{
		default: break;
		case NoteID::CueA:
		digitalWrite(LED::CueA, LOW);
		break;
		case NoteID::CueB:
		digitalWrite(LED::CueB, LOW);
		break;
		case NoteID::FX1:
		digitalWrite(LED::FX1, LOW);
		break;
		case NoteID::FX2:
		digitalWrite(LED::FX2, LOW);
		break;
		case  NoteID::PlayPauseA:
		digitalWrite(LED::PlayPauseA, LOW);
		break;
		case NoteID::PlayPauseB:
		digitalWrite(LED::PlayPauseB, LOW);
		break;
	}
}

#endif /* CALLBACKS_H_ */