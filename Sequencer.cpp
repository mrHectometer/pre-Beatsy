#include "Sequencer.h"
volatile int renderenable;
/////////////////////////////////////////////////////////////////////////////////////////////////
//initialize.
//set the bpm, which also starts the sequencer
void SequencerClass::init()
{
	setbpm(bpm);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void SequencerClass::setbpm(uint16_t newbpm)
{
	bpm = newbpm;
	if(newbpm == 0)
	{
		seqTimer.end();
		Serial.println("Sequencer stopped");
	}
	else
	{
		uint32_t newTickTime = (1000*1000*60)/(newbpm*4);
		seqTimer.begin(sequencePlay,newTickTime);
		seqTimer.priority(255);//Default value of 128 clashes with another interrupt. Probably serial?
		Serial.print("Sequencer BPM changed:");
		Serial.println(newbpm);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//render full sequence
void SequencerClass::renderFull()
{
	const int startX = 80;
	const int BOXWIDTH = 12;
	const int BOXHEIGHT = 14;
	
	int EndY = tft.height()-60;
	Track[0].render(&tft, currentTick);

	//selector
	int c = selector[0];
	int r = selector[1];
	tft.drawRect(startX+c*14+2, EndY - r*16+2, BOXWIDTH, BOXHEIGHT, ILI9341_YELLOW);
	//render texts
	tft.setTextColor(ILI9341_WHITE);
	for(int r = 0; r < 12; r++)
	{
		//if a sample is loaded
		if(Drumkit.getSample(r) >=0)
		{
			tft.setCursor(4,EndY - r*16+2);
			tft.print(SampleName[Drumkit.getSample(r)]);
		}
	}
}
void UISequenceRenderer()
{
	Sequencer.renderFull();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//play sequence
void SequencerClass::play()
{
	for(int r = 0; r < 12; r++)
	{
		//get the entry from the track
		if(currentTrack->data[currentTick][r] > 0)
		{
			Drumkit.playSample(r);
		}
	}
	currentTick+=1;
	//overflow:
	//reached the end of the track/measure.
	//if a next track is selected, play it.
	//reset the step to 0 
	if(currentTick > currentTrack->measure_ticks-1) 
	{
		if(nextTrack != NULL)
		{
			currentTrack = nextTrack;
		}
		currentTick = 0;
	}
	renderenable = 1;
}
//a small wrapper is needed because we can't pass class member functions as pointers
//so we pass a function that calls the sequence play member function
void sequencePlay()
{
	//AudioNoInterrupts();
	Sequencer.play();
	//AudioInterrupts();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
SequencerClass Sequencer;
IntervalTimer seqTimer;