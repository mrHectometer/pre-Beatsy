#include <ILI9341_t3.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Bounce.h>
#include <play_serialflash.h>
#include <SerialFlash.h>#include "Sequencer.h"
#include "track.h"
#include "connections.h"
#include "drumkit.h"#include "Periphery.h"
#include "UIrenderer.h"
// Create an object to control the audio shield.
AudioControlSGTL5000 audioShield;


void setup()
{
	pinMode(10,OUTPUT);
	digitalWrite(10, HIGH);
	SPI.setMOSI(7);
	SPI.setMISO(12);
	SPI.setSCK(14);	

	AudioMemory(40);
	// turn on the output
	audioShield.enable();
	audioShield.volume(0.4);
	connectionInit();
	//init_tft();
	init_SD();
	
	Drumkit.init();
	
	// Audio connections require memory to work.  For more
	// detailed information, see the MemoryAndCpuUsage example
	
	
	init_buttons();
	
	Track[0].setEntry(4, 2, 1);
	Track[0].setEntry(0, 0, 1);
	Track[0].setEntry(12, 2, 1);
	Track[0].setEntry(8, 1, 1);
	Track[0].setEntry(14, 1, 1);
	Sequencer.init();
	Sequencer.setCurrentTrack(&Track[0]);
	UISetRenderer(&UISequenceRenderer);
	
}


void updateButtons()
{
	if(bUp.update())
	{
		if(bUp.risingEdge())
		{
			UISetRenderer(&UIdrumkitRenderer);
		}
	}
	if(bDown.update())
	{
		if(bDown.risingEdge())
		{
			UISetRenderer(&UISequenceRenderer);
		}
	}
}
int bpm = 100;
void loop() 
{
		
}