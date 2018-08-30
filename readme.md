MIDI Controller Arduino project
-------------------------------

This repository contains the Atmel Studio 7 project to build
the Arduino Uno based software used in my MIDI controller
project. The MIDI controller is designed to work with DJ
software such as Traktor DJ, Mixxx or Serato. For more info
and details of construction of the project check out my blog
here:

[trederia.blogspot.com](https://trederia.blogspot.com/2018/08/building-custom-midi-controller-part-1.html)

This project uses the [Arduino MIDI library](https://github.com/FortySevenEffects/arduino_midi_library)
by FortySevenEffects, and [Hiduino](https://github.com/ddiakopoulos/hiduino)

A fritzing schematic and wiring diagram is also included in the fritzing directory.


###### Building
Open the atsln in Atmel Studio 7 (sorry I can't find reliable CMake support)
and click build. The console may output an error 'required from here' which
is apparently a bug in the toolchain - the binary is still compiled successfully.
If someone wants to submit makefile support via a pull request, it would be
very welcome.

 license    MIT - Copyright (c) 2018 Matt Marchant
 
 Permission is hereby granted, free of charge, to any person obtaining a copy  
 of this software and associated documentation files (the "Software"), to deal  
 in the Software without restriction, including without limitation the rights  
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
 copies of the Software, and to permit persons to whom the Software is  
 furnished to do so, subject to the following conditions:  
 
 The above copyright notice and this permission notice shall be included in  
 all copies or substantial portions of the Software.  
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  
 THE SOFTWARE.