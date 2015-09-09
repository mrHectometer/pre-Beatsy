#include <Adafruit_Trellis.h>
#include <ILI9341_t3.h>
#include <Audio.h>
#include <Wire.h>
#include <SerialFlash.h>
#include <SPI.h>
#include <SD.h>
#include <Bounce.h>
#include <play_serialflash.h>#include "Sequencer.h"
#include "track.h"
#include "connections.h"
#include "drumkit.h"#include "Periphery.h"
#include "UIrenderer.h"
#include "testtracks.h"
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
	SPI.begin();
	SPI.usingInterrupt(255);

	AudioMemory(40);
	// turn on the output
	audioShield.enable();
	audioShield.volume(0.5);
	connectionInit();
	init_tft();
	init_SD();
	init_trellis();
	Drumkit.init();
	
	init_buttons();
	init_track0();
	init_track1();
	init_track2();
	init_track3();
	init_track4();
	init_track5();
	init_track6();
	init_track7();
	init_track8();
	init_track9();
	Sequencer.init();
	Sequencer.setbpm(120);
	Sequencer.setCurrentTrack(&Track[0]);
	UISetRenderer(&UISequenceRenderer);
}


elapsedMicros renderTime;
elapsedMillis serialTime;
uint32_t realRenderTime;
void loop() 
{
	//enable rendering only right after a sequencer interrupt has occurred
	//must be ready before next sequence interrupt starts
	renderTime = 0;
	if(renderenable)
	{
		UIrenderer();
		renderenable = 0;
		if(renderTime > realRenderTime) realRenderTime = renderTime;
	}
	if(serialTime > 5000)
	{
		serialTime = 0;
		Serial.print("render time = ");
		Serial.println(realRenderTime);
		uint32_t TickTime = (1000*1000*60)/(Sequencer.getbpm()*4);
		Serial.print("Sequencer.TickTime = ");
		Serial.println(TickTime);
	}
	if (trellis.readSwitches())
	{
		// go through every button
		for (uint8_t i=0; i<numKeys; i++)
		{
			// if it was pressed, turn it on
			if (trellis.justPressed(i))
			{
				Serial.print("v");
				Serial.println(i);
				Sequencer.setNextTrack(&Track[i]);
				trellis.setLED(i);
			}
		}
		delay(30);
	}
	//read analog and digital inputs
}