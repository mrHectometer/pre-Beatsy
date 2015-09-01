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
	uint8_t numerator = 4;
	uint8_t denumerator = 4;
 public:
	uint8_t data[16][12];
	//void renderFLoad();
	//void renderFSave();
	uint8_t getEntry(uint8_t _column, uint8_t _instrument);
	void setEntry(uint8_t _column, uint8_t _instrument, uint8_t _entry);
	void loadData(char* filename);
	void saveData(char* filename);
	void render(ILI9341_t3* tft, int currentStep);
};

extern TrackClass Track[16];

#endif

