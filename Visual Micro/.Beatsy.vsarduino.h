/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Teensy 3.1, Platform=avr, Package=teensy
*/

#define __PROGRAMMING_MK20dx256__
#define __PROGRAMMING_MK20DX256__
#define ARDUINO 165
#define ARDUINO_MAIN
#define __AVR__
#define __MK20DX256__
#define TEENSYDUINO 125
#define ARDUINO 165
#define F_CPU 96000000
#define ARDUINO_ARCH_AVR
#define USB_SERIAL
#define LAYOUT_US_ENGLISH
extern "C" void __cxa_pure_virtual() {;}

//
//

#include "C:\Programming\arduino-1.6.5-r5\hardware\teensy\avr\cores\teensy3\arduino.h"
#include <box.ino>
#include <Periphery.h>
#include <Sequencer.cpp>
#include <Sequencer.h>
#include <TestTracks.h>
#include <UIrenderer.h>
#include <connections.h>
#include <drumkit.cpp>
#include <drumkit.h>
#include <effect_gain.cpp>
#include <effect_gain.h>
#include <tft.c>
#include <tft.h>
#include <track.cpp>
#include <track.h>
