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

ATMega328p in Arduino configuration
Fuses:
Low: 0xFF
High: 0xDE
Extended: 0x05

An 8 way multiplexer is used for digital inputs,
and a 16 way multiplexer is used for analogue.

D0 - 1 are rx/tx

D2 - D7 is LED indication
D8 - D11 maps to PORTB lower - muxer control.
D12 digital muxer input

A0 - analog muxer input.

Digital inputs:
PlayPause A Note B3  (59)
Cue A       Note Eb3 (51)
FX1         Note F6  (89)
PlayPause B Note F#4 (66)
Cue B       Note C4  (60)
FX2         Note A6  (93)

Analogue inputs:
EQ H A    0x10
EQ M A    0x12
EQ B A    0x14
Channel A 0x16
EQ H B    0x11
EQ M B    0x13
EQ B B    0x15
Channel B 0x07

Crossfade 0x0A - val 0 - is right, val 127 is left
Master    0x17

 */ 

#include <avr/io.h>
#include <Arduino.h>

#include "AnalogueControl.hpp"
#include "DigitalControl.hpp"
#include "Callbacks.hpp"

using namespace midi;

namespace
{
	const int AnalogueCount = 10;
	const int DigitalCount = 6;
}

void activateMuxChannel(uint8_t channel)
{
	auto current = (PORTB & 0xF0);
	current |= (channel & 0x0F);
	PORTB = current;
}

int main(void)
{
    //init arduino lib
	init();

	//output for LED indication
	pinMode(LED::PlayPauseA, OUTPUT);
	pinMode(LED::CueA, OUTPUT);
	pinMode(LED::FX1, OUTPUT);
	pinMode(LED::PlayPauseB, OUTPUT);
	pinMode(LED::CueB, OUTPUT);
	pinMode(LED::FX2, OUTPUT);
	PORTD = 0;

	//output to control mux channel
	//this maps to lower half of PORTB
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);

	//digital input from mux
	pinMode(12, INPUT);
	digitalWrite(12, HIGH); //pullup

	MidiInterface<HardwareSerial> midiPort((HardwareSerial&)Serial);
	midiPort.begin(MIDI_CHANNEL_OMNI);
	midiPort.setHandleNoteOn(noteOnCallback);
	midiPort.setHandleNoteOff(noteOffCallback);
	midiPort.turnThruOff(); //prevent getting in a feedback loop

	//analogue inputs
	AnalogueControl analogueControls[]	=
	{
		AnalogueControl(ControllerID::EQ_H_A, midiPort), //eq h a
		AnalogueControl(ControllerID::EQ_M_A, midiPort), //eq m a
		AnalogueControl(ControllerID::EQ_B_A, midiPort), //eq b a
		AnalogueControl(ControllerID::ChannelA, midiPort), //channel a
		AnalogueControl(ControllerID::EQ_H_B, midiPort), //eq h b
		AnalogueControl(ControllerID::EQ_M_B, midiPort), //eq m b
		AnalogueControl(ControllerID::EQ_B_B, midiPort), //eq b b
		AnalogueControl(ControllerID::ChannelB, midiPort), //channel b
		AnalogueControl(ControllerID::Crossfader, midiPort), //crossfader
		AnalogueControl(ControllerID::Master, midiPort)  //master
	};

	DigitalControl digitalControls[] = 
	{
		DigitalControl(NoteID::PlayPauseA, midiPort), //play/pause a
		DigitalControl(NoteID::CueA, midiPort), //cue a
		DigitalControl(NoteID::FX1, midiPort), //FX 1
		DigitalControl(NoteID::PlayPauseB, midiPort), //play/pause b
		DigitalControl(NoteID::CueB, midiPort), //cue b
		DigitalControl(NoteID::FX2, midiPort) //FX 2
	};

    for(;;)
    {
		//for each analogue control
		for(auto i = 0; i < AnalogueCount; ++i)
		{
			//activate mux i
			activateMuxChannel(i);

			//update control
			analogueControls[i].update();
		}


		//foreach digital control
		for(auto i = 0; i  < DigitalCount; ++i)
		{		
			//activate mux i
			activateMuxChannel(i);

			//update control
			digitalControls[i].update();
		}

		midiPort.read(); //handle callbacks
    }
}

