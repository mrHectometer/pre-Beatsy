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

AudioEffectEnvelope		env0;
AudioEffectEnvelope		env1;
AudioEffectEnvelope		env2;
AudioEffectEnvelope		env3;
AudioEffectEnvelope		env4;
AudioEffectEnvelope		env5;
AudioEffectEnvelope		env6;
AudioEffectEnvelope		env7;
AudioEffectEnvelope		env8;
AudioEffectEnvelope		env9;
AudioEffectEnvelope		env10;
AudioEffectEnvelope		env11;

AudioMixer16        mixL;   
AudioMixer16        mixR;   
AudioOutputI2S     headphones;
AudioOutputAnalog  dac;     // play to both I2S audio board and on-chip DAC
// Create Audio connections between the components
//samplers to envelopes



AudioConnection c100(sound0, 0, env0, 0);
AudioConnection c101(sound1, 0, env1, 0);
AudioConnection c102(sound2, 0, env2, 0);
AudioConnection c103(sound3, 0, env3, 0);
AudioConnection c104(sound4, 0, env4, 0);
AudioConnection c105(sound5, 0, env5, 0);
AudioConnection c106(sound6, 0, env6, 0);
AudioConnection c107(sound7, 0, env7, 0);
AudioConnection c108(sound8, 0, env8, 0);
AudioConnection c109(sound9, 0, env9, 0);
AudioConnection c110(sound10, 0, env10, 0);
AudioConnection c111(sound11, 0, env11, 0);

//envelopes to mixers
//left
AudioConnection cL500(sound0, 0, mixL, 0);
AudioConnection cL501(sound1, 0, mixL, 1);
AudioConnection cL502(sound2, 0, mixL, 2);
AudioConnection cL503(sound3, 0, mixL, 3);
AudioConnection cL504(sound4, 0, mixL, 4);
AudioConnection cL505(sound5, 0, mixL, 5);
AudioConnection cL506(sound6, 0, mixL, 6);
AudioConnection cL507(sound7, 0, mixL, 7);
AudioConnection cL508(sound8, 0, mixL, 8);
AudioConnection cL509(sound9, 0, mixL, 9);
AudioConnection cL510(sound10, 0, mixL, 10);
AudioConnection cL511(sound11, 0, mixL, 11);
//right
AudioConnection cR500(sound0, 0, mixR, 0);
AudioConnection cR501(sound1, 0, mixR, 1);
AudioConnection cR502(sound2, 0, mixR, 2);
AudioConnection cR503(sound3, 0, mixR, 3);
AudioConnection cR504(sound4, 0, mixR, 4);
AudioConnection cR505(sound5, 0, mixR, 5);
AudioConnection cR506(sound6, 0, mixR, 6);
AudioConnection cR507(sound7, 0, mixR, 7);
AudioConnection cR508(sound8, 0, mixR, 8);
AudioConnection cR509(sound9, 0, mixR, 9);
AudioConnection cR510(sound10, 0, mixR, 10);
AudioConnection cR511(sound11, 0, mixR, 11);

AudioConnection c8(mixL, 0, headphones, 0);
AudioConnection c9(mixR, 0, headphones, 1);
AudioConnection c10(mixL, 0, dac, 0);

AudioPlaySerialFlash *samplePlayer[12] = {&sound0,&sound1,&sound2,&sound3,&sound4,&sound5,&sound6,&sound7,&sound8,&sound9,&sound10,&sound11};
AudioEffectEnvelope *env[12] = {&env0,&env1,&env2,&env3,&env4,&env5,&env6,&env7,&env8,&env9,&env10,&env11};
void connectionInit()
{
	for(int i = 0; i <= 12;i++)
	{
		mixL.gain(i, 0.3);
		mixR.gain(i, 0.3);
	}
	for(int i = 0; i <= 5;i++)
	{
		env[i]->attack(1);
		env[i]->hold(1);
		env[i]->decay(1);
		env[i]->sustain(65536);
		env[i]->release(1);
	}
	mixL.gain(2, 0.2);
	mixR.gain(2, 0.2);
	
	Hatfilter.frequency(4000);
}