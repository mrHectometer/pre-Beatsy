// 
// 
// 

#include "drumkit.h"
/*
int16_t kit[12] =
{
	49,
	129,
	29,
	29,
	163,
	168,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1
};*/
void DrumkitClass::init()
{
	setSample(0,56);
	setSample(1,129);
	setSample(2,29);
	setSample(3,29);
	setSample(4,163);
	setSample(5,168);
	setSample(6,170);
	setSample(7,171);
	setSample(8,171);
	setSample(9,140);
	setSample(10,130);
	setSample(11,120);
}
void DrumkitClass::renderOverview()
{
	int EndY = tft.height() - 60;
	int MidX = tft.width()/2;
	int rowHeight = 35;
	tft.setTextColor(ILI9341_WHITE);
	tft.setTextSize(2);
	const int BUTTONWIDTH = 100;
	const int BUTTONHEIGHT = 30;
	uint16_t colorKitBG = tft.color565(190,200,190);
	int row = 0;
	int columnX=0;
	for(int s = 0; s < 12; s++)
	{
		if(s == 6)
		{
			row = 0;
			columnX = MidX;
		}
		tft.drawRect(columnX, EndY - row*rowHeight,  BUTTONWIDTH, BUTTONHEIGHT, colorKitBG);
		if(sampleIndex[s][0] >=0)
		{
			
			//tft.setCursor(columnX+6,EndY - row*rowHeight+6);
			//tft.print(SampleName[sampleIndex[s][0]]);
		}
		//check if the samples are playing
		if(samplePlayer[s]->isPlaying())
		{
			//tft.fillRect(columnX, EndY - row*rowHeight,  BUTTONWIDTH, BUTTONHEIGHT, ILI9341_CYAN);
			//tft.drawRect(columnX+BUTTONWIDTH+4, EndY - row*rowHeight,  10, BUTTONHEIGHT, ILI9341_CYAN);
		}
		else
		{
			//tft.drawRect(columnX+BUTTONWIDTH+4, EndY - row*rowHeight,  10, BUTTONHEIGHT, ILI9341_BLACK);
		}
		row+=1;
	}
	
}
void UIdrumkitRenderer()
{
	Drumkit.renderOverview();
}
DrumkitClass Drumkit;

