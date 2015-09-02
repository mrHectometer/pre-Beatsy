// sequence.h

#ifndef _TRACK_h
#define _TRACK_h


#include "arduino.h"
#include <ILI9341_t3.h>
#include <SD.h>

class TrackClass
{
 protected:
	char filename[11];
	uint8_t columns=16;
	uint8_t instruments=12;
	uint8_t signature_upper = 4;
	uint8_t signature_lower = 4;
 public:
	uint16_t measure_ticks = 16;
	uint8_t data[32][12];
	//void renderFLoad();
	//void renderFSave();
	void empty()
	{
		for(int i = 0;i < 32;i++)
		{
			for(int j = 0;j < 12;j++)
			{
				data[i][j] = 0;
			}
		}
	}
	void empty(int _instrument)
	{
		for(int i = 0;i < 32;i++)
		{
			data[i][_instrument] = 0;
		}
	}
	uint8_t getEntry(uint8_t _column, uint8_t _instrument);
	void setEntry(uint8_t _column, uint8_t _instrument, uint8_t _entry);
	void loadData(char* filename);
	void saveData(char* filename);
	void render(ILI9341_t3* tft, int currentStep);
	int set_measure_ticks()
	{
		if(signature_upper > signature_lower * 2) return 0;//not supported
		measure_ticks = (16 * signature_upper) / signature_lower;
		return measure_ticks;
	}
};

extern TrackClass Track[16];

#endif

