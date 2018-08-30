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


#ifndef CONTROLLERDEFINITIONS_H_
#define CONTROLLERDEFINITIONS_H_

namespace ControllerID
{
	enum
	{
		EQ_H_A     = 0x10, //High
		EQ_M_A     = 0x12, //Middle
		EQ_B_A     = 0x14, //Bass
		ChannelA   = 0x16,
		EQ_H_B     = 0x11,
		EQ_M_B     = 0x13,
		EQ_B_B     = 0x15,
		ChannelB   = 0x07,
		Crossfader = 0x0A,
		Master     = 0x17
	};
}

namespace NoteID
{
	enum
	{
		PlayPauseA = 59,
		CueA       = 51,
		FX1        = 89,
		PlayPauseB = 66,
		CueB       = 60,
		FX2        = 93
	};
}

namespace LED
{
	enum
	{
		PlayPauseA = 2,
		CueA       = 3,
		FX1        = 4,
		PlayPauseB = 5,
		CueB       = 6,
		FX2        = 7
	};
}

#endif /* CONTROLLERDEFINITIONS_H_ */