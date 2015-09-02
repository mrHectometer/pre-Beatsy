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

volatile int rendernow;
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
	audioShield.volume(0.3);
	connectionInit();
	init_tft();
	init_SD();
	
	Drumkit.init();
	
	init_buttons();
	
	//kick
	Track[0].setEntry(0, 0, 1);
	Track[0].setEntry(5, 0, 1);
	Track[0].setEntry(13, 0, 1);
	//snare
	Track[0].setEntry(8, 1, 1);
	//hats
	for(int i = 0; i < 16; i+=2)
	{
		Track[0].setEntry(i, 2, 1);
	}
	Sequencer.init();
	Sequencer.setbpm(150);
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
void loop() 
{
	//enable rendering only after a sequencer interrupt has occurred
	//must be ready before next sequence interrupt starts
//	if(renderenable)
//	{
//		UIrenderer();
//		renderenable = 0;
//	}
	delayMicroseconds(1000);
}