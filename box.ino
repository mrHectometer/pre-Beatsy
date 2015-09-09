#include <Adafruit_Trellis.h>
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
	 // INT pin requires a pullup
	 pinMode(INTPIN, INPUT);
	 digitalWrite(INTPIN, HIGH);
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
	
	Drumkit.init();
	init_trellis();
	
	//kick
	Track[0].setEntry(0, 0, 1);
	Track[0].setEntry(8, 0, 1);
	//snare
	Track[0].setEntry(4, 1, 1);
	Track[0].setEntry(12, 1, 1);
	//hats
	for(int i = 0; i < 16; i+=2)
	{
		Track[0].setEntry(i, 2, 1);
	}
	//kick
	Track[1].setEntry(0, 0, 1);
	Track[1].setEntry(8, 0, 1);
	//snare
	Track[1].setEntry(4, 1, 1);
	Track[1].setEntry(11, 1, 1);
	Track[1].setEntry(12, 1, 1);
	Track[1].setEntry(14, 1, 1);
	//hats
	for(int i = 0; i < 16; i+=2)
	{
		Track[1].setEntry(i, 2, 1);
	}
	Track[2].setEntry(0, 0, 1);
	Track[2].setEntry(6, 1, 1);
	for(int i = 0; i < 16; i+=2)
	{
		Track[2].setEntry(i, 2, 1);
	}
	Track[2].signature_upper = 3;
	Track[2].signature_lower = 4;
	Track[3].setEntry(0, 0, 1);
	Track[3].setEntry(9, 0, 1);
	Track[3].setEntry(10, 0, 1);
	Track[3].setEntry(1, 1, 1);
	//snare
	Track[3].setEntry(4, 1, 1);
	Track[3].setEntry(12, 1, 1);
	for(int i = 0; i < 14; i+=2)
	{
		Track[3].setEntry(i, 2, 1);
	}
	Track[3].signature_upper = 7;
	Track[3].signature_lower = 8;
	Sequencer.init();
	//Sequencer.setbpm(120);
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
	
	//if(renderenable)
	//{
		UIrenderer();
	//	renderenable = 0;
	//	realRenderTime = renderTime;
	//}
	if(serialTime > 5000)
	{
		serialTime = 0;
		Serial.print("render time = ");
		Serial.println(realRenderTime);
		uint32_t TickTime = (1000*1000*60)/(Sequencer.getbpm()*4);
		Serial.print("Sequencer.TickTime = ");
		Serial.println(TickTime);
	}
	//choosing a sequence
	/*
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
	}*/
	//read analog and digital inputs
}