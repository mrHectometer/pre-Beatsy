#include <play_serialflash.h>
#include <Audio.h>
// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
//
AudioPlaySerialFlash    sound0;
AudioPlaySerialFlash    sound1;  // six memory players, so we can play
AudioPlaySerialFlash    sound2;  // all six sounds simultaneously
AudioPlaySerialFlash    sound3;
AudioPlaySerialFlash    sound4;
AudioPlaySerialFlash    sound5;
AudioPlaySerialFlash    sound6;
AudioPlaySerialFlash    sound7;  // six memory players, so we can play
AudioPlaySerialFlash    sound8;  // all six sounds simultaneously
AudioPlaySerialFlash    sound9;
AudioPlaySerialFlash    sound10;
AudioPlaySerialFlash    sound11;
AudioMixer16        mixL;   
AudioMixer16        mixR;   
AudioOutputI2S     headphones;
AudioOutputAnalog  dac;     // play to both I2S audio board and on-chip DAC

// Create Audio connections between the components
//
AudioConnection cL100(sound0, 0, mixL, 0);
AudioConnection cL101(sound1, 0, mixL, 1);
AudioConnection cL102(sound2, 0, mixL, 2);
AudioConnection cL103(sound3, 0, mixL, 3);
AudioConnection cL104(sound4, 0, mixL, 4);
AudioConnection cL105(sound5, 0, mixL, 5);
AudioConnection cL106(sound6, 0, mixL, 6);
AudioConnection cL107(sound7, 0, mixL, 7);
AudioConnection cL108(sound8, 0, mixL, 8);
AudioConnection cL109(sound9, 0, mixL, 9);
AudioConnection cL110(sound10, 0, mixL, 10);
AudioConnection cL111(sound11, 0, mixL, 11);

AudioConnection cR100(sound0, 0, mixR, 0);
AudioConnection cR101(sound1, 0, mixR, 1);
AudioConnection cR102(sound2, 0, mixR, 2);
AudioConnection cR103(sound3, 0, mixR, 3);
AudioConnection cR104(sound4, 0, mixR, 4);
AudioConnection cR105(sound5, 0, mixR, 5);
AudioConnection cR106(sound6, 0, mixR, 6);
AudioConnection cR107(sound7, 0, mixR, 7);
AudioConnection cR108(sound8, 0, mixR, 8);
AudioConnection cR109(sound9, 0, mixR, 9);
AudioConnection cR110(sound10, 0, mixR, 10);
AudioConnection cR111(sound11, 0, mixR, 11);

AudioConnection c8(mixL, 0, headphones, 0);
AudioConnection c9(mixR, 0, headphones, 1);
AudioConnection c10(mixL, 0, dac, 0);

AudioPlaySerialFlash *samplePlayer[12] = {&sound0,&sound1,&sound2,&sound3,&sound4,&sound5,&sound6,&sound7,&sound8,&sound9,&sound10,&sound11};

void connectionInit()
{
	for(int i = 0; i <= 12;i++)
	{
		mixL.gain(0, 0.3);
		mixR.gain(0, 0.3);
	}
}