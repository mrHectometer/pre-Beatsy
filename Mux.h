// Mux.h

#ifndef _MUX_h
#define _MUX_h

#include "arduino.h"

class MuxClass
{
 protected:
	int S0, S1, S2, Z;

 public:
	MuxClass( int _S0, int _S1, int _S2, int _Z)
	{
		S0 = _S0;
		S1 = _S1;
		S2 = _S2;
		Z = _Z;
	};
	int readInputAnalog(int pin);
	int readInputDigital(int pin);
};


#endif

