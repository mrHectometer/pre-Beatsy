// Sequencer.h

#ifndef _SEQUENCER_h
#define _SEQUENCER_h
#include "drumkit.h"
#include "track.h"
#include "arduino.h"

extern IntervalTimer seqTimer;

class SequencerClass
{
 protected:
	volatile TrackClass *currentTrack;
	volatile TrackClass *nextTrack;
	uint16_t bpm;
	int selector[2] = {0,0};
	volatile int currentStep;
 public:
	void init();
	void setNextTrack(TrackClass* _Track)
	{
		nextTrack = _Track;
	}
	void setCurrentTrack(TrackClass* _Track)
	{
		currentTrack = _Track;
	}
	
	//void
	void renderFull();
	void play();
	void setbpm(uint16_t newbpm);
	//void renderMinimal();
	
};
extern SequencerClass Sequencer;
void UISequenceRenderer();



#endif

