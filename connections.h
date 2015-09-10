#include <play_serialflash.h>
#include <Audio.h>
#include "effect_gain.h"
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

AudioEffectGain		gain0;
AudioEffectGain		gain1;
AudioEffectGain		gain2;
AudioEffectGain		gain3;
AudioEffectGain		gain4;
AudioEffectGain		gain5;
AudioEffectGain		gain6;
AudioEffectGain		gain7;
AudioEffectGain		gain8;
AudioEffectGain		gain9;
AudioEffectGain		gain10;
AudioEffectGain		gain11;

AudioMixer16        mixL;   
AudioMixer16        mixR;   
AudioOutputI2S     headphones;
AudioOutputAnalog  dac;     // play to both I2S audio board and on-chip DAC
// Create Audio connections between the components
//samplers to gain modulators

AudioConnection c100(sound0, 0, gain0, 0);
AudioConnection c101(sound1, 0, gain1, 0);
AudioConnection c102(sound2, 0, gain2, 0);
AudioConnection c103(sound3, 0, gain3, 0);
AudioConnection c104(sound4, 0, gain4, 0);
AudioConnection c105(sound5, 0, gain5, 0);
AudioConnection c106(sound6, 0, gain6, 0);
AudioConnection c107(sound7, 0, gain7, 0);
AudioConnection c108(sound8, 0, gain8, 0);
AudioConnection c109(sound9, 0, gain9, 0);
AudioConnection c110(sound10, 0, gain10, 0);
AudioConnection c111(sound11, 0, gain11, 0);

//gainers to mixers
//left
AudioConnection cL500(gain0, 0, mixL, 0);
AudioConnection cL501(gain1, 0, mixL, 1);
AudioConnection cL502(gain2, 0, mixL, 2);
AudioConnection cL503(gain3, 0, mixL, 3);
AudioConnection cL504(gain4, 0, mixL, 4);
AudioConnection cL505(gain5, 0, mixL, 5);
AudioConnection cL506(gain6, 0, mixL, 6);
AudioConnection cL507(gain7, 0, mixL, 7);
AudioConnection cL508(gain8, 0, mixL, 8);
AudioConnection cL509(gain9, 0, mixL, 9);
AudioConnection cL510(gain10, 0, mixL, 10);
AudioConnection cL511(gain11, 0, mixL, 11);
//right
AudioConnection cR500(gain0, 0, mixR, 0);
AudioConnection cR501(gain1, 0, mixR, 1);
AudioConnection cR502(gain2, 0, mixR, 2);
AudioConnection cR503(gain3, 0, mixR, 3);
AudioConnection cR504(gain4, 0, mixR, 4);
AudioConnection cR505(gain5, 0, mixR, 5);
AudioConnection cR506(gain6, 0, mixR, 6);
AudioConnection cR507(gain7, 0, mixR, 7);
AudioConnection cR508(gain8, 0, mixR, 8);
AudioConnection cR509(gain9, 0, mixR, 9);
AudioConnection cR510(gain10, 0, mixR, 10);
AudioConnection cR511(gain11, 0, mixR, 11);

AudioConnection c8(mixL, 0, headphones, 0);
AudioConnection c9(mixR, 0, headphones, 1);
AudioConnection c10(mixL, 0, dac, 0);

AudioPlaySerialFlash *samplePlayer[12] = {&sound0,&sound1,&sound2,&sound3,&sound4,&sound5,&sound6,&sound7,&sound8,&sound9,&sound10,&sound11};
AudioEffectGain *sampleGain[12] = {&gain0,&gain1,&gain2,&gain3,&gain4,&gain5,&gain6,&gain7,&gain8,&gain9,&gain10,&gain11};
void connectionInit()
{
	for(int i = 0; i <= 12;i++)
	{
		mixL.gain(i, 0.3);
		mixR.gain(i, 0.3);
	}
	mixL.gain(2, 0.2);
	mixR.gain(2, 0.2);
	
}