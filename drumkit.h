// drumkit.h

#ifndef _DRUMKIT_h
#define _DRUMKIT_h

#include "arduino.h"
#include <play_serialflash.h>
#include <audio.h>
#include <ILI9341_t3.h>

//FAT:
//4 bytes adress
//8 bytes name
//1 byte type
//3 reserved for future use

const int Samples[172] = {
	0x0000000,  //"BELLTR~1.TRW"
	0x0011F00,  //"BELLTR~2.TRW"
	0x0049C00,  //"CR10.TRW"
	0x005F000,  //"CR11.TRW"
	0x006FC00,  //"CR12.TRW"
	0x0082D00,  //"CR13.TRW"
	0x009FC00,  //"CR14.TRW"
	0x00AFC00,  //"CR3.TRW"
	0x00D3E00,  //"CR4.TRW"
	0x00F3E00,  //"CR5.TRW"
	0x0111300,  //"CR6.TRW"
	0x0133900,  //"CR7.TRW"
	0x0155D00,  //"CR8.TRW"
	0x0160A00,  //"CR9.TRW"
	0x0168C00,  //"HH1.TRW"
	0x016AB00,  //"HH10.TRW"
	0x016BC00,  //"HH11.TRW"
	0x016F300,  //"HH1CLO~1.TRW"
	0x0171200,  //"HH1CLO~2.TRW"
	0x0173600,  //"HH1HAL~1.TRW"
	0x0178600,  //"HH1HAL~2.TRW"
	0x017ED00,  //"HH1OPEN.TRW"
	0x018DD00,  //"HH1PEDAL.TRW"
	0x018F400,  //"HH1PED~1.TRW"
	0x0197E00,  //"HH2.TRW"
	0x019A700,  //"HH2CLO~1.TRW"
	0x019C200,  //"HH2CLO~2.TRW"
	0x019DD00,  //"HH2HAL~1.TRW"
	0x01A2C00,  //"HH2OPEN.TRW"
	0x01AA500,  //"HH2PEDAL.TRW"
	0x01AB800,  //"HH2PED~1.TRW"
	0x01B9A00,  //"HH3.TRW"
	0x01BD000,  //"HH3CLO~1.TRW"
	0x01BFF00,  //"HH3CLO~2.TRW"
	0x01C3C00,  //"HH3OPEN.TRW"
	0x01E1600,  //"HH3PEDAL.TRW"
	0x01E2500,  //"HH3PED~1.TRW"
	0x01F5B00,  //"HH4.TRW"
	0x01F7B00,  //"HH5.TRW"
	0x01F9F00,  //"HH6.TRW"
	0x01FC100,  //"HH7.TRW"
	0x0200B00,  //"HH8.TRW"
	0x0202300,  //"HH9.TRW"
	0x0203500,  //"K1.TRW"
	0x020AA00,  //"K10.TRW"
	0x020E700,  //"K11.TRW"
	0x0214A00,  //"K12.TRW"
	0x021BA00,  //"K13.TRW"
	0x0222C00,  //"K14.TRW"
	0x0228500,  //"K15.TRW"
	0x022D900,  //"K16.TRW"
	0x0236500,  //"K17.TRW"
	0x0239600,  //"K18.TRW"
	0x023E300,  //"K19.TRW"
	0x0246500,  //"K2.TRW"
	0x0248800,  //"K20.TRW"
	0x024C900,  //"K21.TRW"
	0x0251100,  //"K22.TRW"
	0x0258900,  //"K23.TRW"
	0x0263500,  //"K24.TRW"
	0x0267500,  //"K25.TRW"
	0x026D400,  //"K26.TRW"
	0x0271800,  //"K27.TRW"
	0x0278100,  //"K28.TRW"
	0x027C000,  //"K29.TRW"
	0x0283700,  //"K3.TRW"
	0x0285600,  //"K30.TRW"
	0x028A800,  //"K31.TRW"
	0x0290800,  //"K32.TRW"
	0x0298B00,  //"K33.TRW"
	0x029F400,  //"K34.TRW"
	0x02A6B00,  //"K35.TRW"
	0x02AB300,  //"K36.TRW"
	0x02AEE00,  //"K37.TRW"
	0x02B7200,  //"K38.TRW"
	0x02BF800,  //"K39.TRW"
	0x02C7100,  //"K4.TRW"
	0x02CE300,  //"K40.TRW"
	0x02D6B00,  //"K41.TRW"
	0x02DB300,  //"K42.TRW"
	0x02E2300,  //"K43.TRW"
	0x02E9B00,  //"K44.TRW"
	0x02F2C00,  //"K45.TRW"
	0x02F8F00,  //"K46.TRW"
	0x02FBC00,  //"K47.TRW"
	0x0302600,  //"K48.TRW"
	0x0306300,  //"K49.TRW"
	0x030C100,  //"K5.TRW"
	0x0310000,  //"K50.TRW"
	0x0316500,  //"K51.TRW"
	0x031A500,  //"K52.TRW"
	0x0323300,  //"K53.TRW"
	0x032B600,  //"K54.TRW"
	0x0331200,  //"K55.TRW"
	0x0337400,  //"K56.TRW"
	0x033D700,  //"K57.TRW"
	0x0340500,  //"R1.TRW"
	0x0367600,  //"R2.TRW"
	0x0384000,  //"R3.TRW"
	0x03CCC00,  //"R4.TRW"
	0x0419000,  //"R5.TRW"
	0x045FA00,  //"R6.TRW"
	0x047B300,  //"R7.TRW"
	0x0492D00,  //"RIM1.TRW"
	0x0496900,  //"RIM2.TRW"
	0x0499500,  //"RIM3.TRW"
	0x049D200,  //"RIM4.TRW"
	0x049F800,  //"RIM5.TRW"
	0x04A2800,  //"RIM6.TRW"
	0x04A6700,  //"S1.TRW"
	0x04AA700,  //"S10.TRW"
	0x04AD300,  //"S11.TRW"
	0x04B0B00,  //"S12.TRW"
	0x04B5E00,  //"S13.TRW"
	0x04BDB00,  //"S14.TRW"
	0x04C6A00,  //"S15.TRW"
	0x04D0E00,  //"S16.TRW"
	0x04D4600,  //"S17.TRW"
	0x04DA000,  //"S18.TRW"
	0x04E1800,  //"S19.TRW"
	0x04E8B00,  //"S2.TRW"
	0x04EE600,  //"S20.TRW"
	0x04F6000,  //"S21.TRW"
	0x04FE000,  //"S22.TRW"
	0x0508F00,  //"S23.TRW"
	0x0513200,  //"S24.TRW"
	0x0519500,  //"S25.TRW"
	0x0520400,  //"S26.TRW"
	0x0525000,  //"S27.TRW"
	0x052B700,  //"S28.TRW"
	0x0530400,  //"S29.TRW"
	0x0536500,  //"S3.TRW"
	0x0541C00,  //"S30.TRW"
	0x054F700,  //"S31.TRW"
	0x0563400,  //"S32.TRW"
	0x0572100,  //"S33.TRW"
	0x0580000,  //"S34.TRW"
	0x0585200,  //"S35.TRW"
	0x058AD00,  //"S36.TRW"
	0x0590100,  //"S37.TRW"
	0x0596800,  //"S38.TRW"
	0x0599900,  //"S39.TRW"
	0x059E800,  //"S4.TRW"
	0x05A0B00,  //"S40.TRW"
	0x05A4700,  //"S41.TRW"
	0x05A8300,  //"S44.TRW"
	0x05AD300,  //"S45.TRW"
	0x05B1600,  //"S46.TRW"
	0x05B4600,  //"S47.TRW"
	0x05B8200,  //"S48.TRW"
	0x05BB700,  //"S49.TRW"
	0x05BF700,  //"S5.TRW"
	0x05C2700,  //"S50.TRW"
	0x05C6600,  //"S51.TRW"
	0x05CAD00,  //"S52.TRW"
	0x05D0C00,  //"S6.TRW"
	0x05D3700,  //"S7.TRW"
	0x05DF900,  //"S8.TRW"
	0x05E9800,  //"S9.TRW"
	0x05ED600,  //"SHAKE1.TRW"
	0x05EE800,  //"SHAKE2.TRW"
	0x05EF800,  //"SHAKE3.TRW"
	0x05F0800,  //"SHAKE4.TRW"
	0x05F1800,  //"SHAKE5.TRW"
	0x05F2900,  //"SHAKE6.TRW"
	0x05F5400,  //"TAM1.TRW"
	0x05F8800,  //"TAM2.TRW"
	0x05FC000,  //"TAM3.TRW"
	0x05FDA00,  //"TAM4.TRW"
	0x05FF400,  //"TAM5.TRW"
	0x0602200,  //"S42.TRW"
0x0605D00}; //"S43.TRW"

const char SampleName[172][13] = {
		"BELLTR~1.TRW",
		"BELLTR~2.TRW",
		"CR10.TRW",
		"CR11.TRW",
		"CR12.TRW",
		"CR13.TRW",
		"CR14.TRW",
		"CR3.TRW",
		"CR4.TRW",
		"CR5.TRW",
		"CR6.TRW",
		"CR7.TRW",
		"CR8.TRW",
		"CR9.TRW",
		"HH1.TRW",
		"HH10.TRW",
		"HH11.TRW",
		"HH1CLO~1.TRW",
		"HH1CLO~2.TRW",
		"HH1HAL~1.TRW",
		"HH1HAL~2.TRW",
		"HH1OPEN.TRW",
		"HH1PEDAL.TRW",
		"HH1PED~1.TRW",
		"HH2.TRW",
		"HH2CLO~1.TRW",
		"HH2CLO~2.TRW",
		"HH2HAL~1.TRW",
		"HH2OPEN.TRW",
		"HH2PEDAL.TRW",
		"HH2PED~1.TRW",
		"HH3.TRW",
		"HH3CLO~1.TRW",
		"HH3CLO~2.TRW",
		"HH3OPEN.TRW",
		"HH3PEDAL.TRW",
		"HH3PED~1.TRW",
		"HH4.TRW",
		"HH5.TRW",
		"HH6.TRW",
		"HH7.TRW",
		"HH8.TRW",
		"HH9.TRW",
		"K1.TRW",
		"K10.TRW",
		"K11.TRW",
		"K12.TRW",
		"K13.TRW",
		"K14.TRW",
		"K15.TRW",
		"K16.TRW",
		"K17.TRW",
		"K18.TRW",
		"K19.TRW",
		"K2.TRW",
		"K20.TRW",
		"K21.TRW",
		"K22.TRW",
		"K23.TRW",
		"K24.TRW",
		"K25.TRW",
		"K26.TRW",
		"K27.TRW",
		"K28.TRW",
		"K29.TRW",
		"K3.TRW",
		"K30.TRW",
		"K31.TRW",
		"K32.TRW",
		"K33.TRW",
		"K34.TRW",
		"K35.TRW",
		"K36.TRW",
		"K37.TRW",
		"K38.TRW",
		"K39.TRW",
		"K4.TRW",
		"K40.TRW",
		"K41.TRW",
		"K42.TRW",
		"K43.TRW",
		"K44.TRW",
		"K45.TRW",
		"K46.TRW",
		"K47.TRW",
		"K48.TRW",
		"K49.TRW",
		"K5.TRW",
		"K50.TRW",
		"K51.TRW",
		"K52.TRW",
		"K53.TRW",
		"K54.TRW",
		"K55.TRW",
		"K56.TRW",
		"K57.TRW",
		"R1.TRW",
		"R2.TRW",
		"R3.TRW",
		"R4.TRW",
		"R5.TRW",
		"R6.TRW",
		"R7.TRW",
		"RIM1.TRW",
		"RIM2.TRW",
		"RIM3.TRW",
		"RIM4.TRW",
		"RIM5.TRW",
		"RIM6.TRW",
		"S1.TRW",
		"S10.TRW",
		"S11.TRW",
		"S12.TRW",
		"S13.TRW",
		"S14.TRW",
		"S15.TRW",
		"S16.TRW",
		"S17.TRW",
		"S18.TRW",
		"S19.TRW",
		"S2.TRW",
		"S20.TRW",
		"S21.TRW",
		"S22.TRW",
		"S23.TRW",
		"S24.TRW",
		"S25.TRW",
		"S26.TRW",
		"S27.TRW",
		"S28.TRW",
		"S29.TRW",
		"S3.TRW",
		"S30.TRW",
		"S31.TRW",
		"S32.TRW",
		"S33.TRW",
		"S34.TRW",
		"S35.TRW",
		"S36.TRW",
		"S37.TRW",
		"S38.TRW",
		"S39.TRW",
		"S4.TRW",
		"S40.TRW",
		"S41.TRW",
		"S44.TRW",
		"S45.TRW",
		"S46.TRW",
		"S47.TRW",
		"S48.TRW",
		"S49.TRW",
		"S5.TRW",
		"S50.TRW",
		"S51.TRW",
		"S52.TRW",
		"S6.TRW",
		"S7.TRW",
		"S8.TRW",
		"S9.TRW",
		"SHAKE1.TRW",
		"SHAKE2.TRW",
		"SHAKE3.TRW",
		"SHAKE4.TRW",
		"SHAKE5.TRW",
		"SHAKE6.TRW",
		"TAM1.TRW",
		"TAM2.TRW",
		"TAM3.TRW",
		"TAM4.TRW",
		"TAM5.TRW",
		"S42.TRW",
		"S43.TRW"};
extern ILI9341_t3 tft;
extern AudioMixer4  mix1;
extern AudioMixer4  mix2;

extern AudioPlaySerialFlash    sound0;
extern AudioPlaySerialFlash    sound1;  // six memory players, so we can play
extern AudioPlaySerialFlash    sound2;  // all six sounds simultaneously
extern AudioPlaySerialFlash    sound3;
extern AudioPlaySerialFlash    sound4;
extern AudioPlaySerialFlash    sound5;
extern AudioPlaySerialFlash *samplePlayer[];
extern AudioEffectEnvelope *env[];

class DrumkitClass
{
 protected:
	//0: samples
	//1: gain
	//2: pan
	uint16_t sampleIndex[12][3];
 public:
	void init();
	void setSample(uint16_t index, int16_t address)
	{
		sampleIndex[index][0] = address;
		samplePlayer[index]->preparefast(Samples[address]);
	}
	int getSample(uint16_t index)
	{
		return sampleIndex[index][0];
	}
	void setGain(uint16_t index, int16_t gain)
	{
		sampleIndex[index][1] = gain;
	}
	void setPan(uint16_t index, int8_t pan)
	{
		if(pan < -127) pan = -127;
		if(pan > 127) pan = 127;
		sampleIndex[index][1] = pan;
	}
	void clrSample(uint16_t index)
	{
		sampleIndex[index][0] = -1;
	}
	void playSample(int sample)
	{
		samplePlayer[sample]->playfast();
		//env[sample]->sustain(65536);
	}
	void renderOverview();
};

extern DrumkitClass Drumkit;

void UIdrumkitRenderer();

#endif

