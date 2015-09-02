// Sequencer.h

#ifndef _SEQUENCER_h
#define _SEQUENCER_h
#include "drumkit.h"
#include "track.h"
#include "arduino.h"

extern volatile int renderenable;
extern IntervalTimer seqTimer;

class SequencerClass
{
 protected:
	volatile TrackClass *currentTrack;
	volatile TrackClass *nextTrack;
	uint16_t bpm = 120;
	int selector[2] = {0,0};
	volatile int currentTick;
 public:
	void init();
	void setNextTrack(TrackClass* _Track)
	{
		_Track->set_measure_ticks();
		nextTrack = _Track;
	}
	void setCurrentTrack(TrackClass* _Track)
	{
		_Track->set_measure_ticks();
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
void sequencePlay();


#endif

