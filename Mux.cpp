// 
// 
// 

#include "Mux.h"

int MuxClass::readInputAnalog(int pin)
{
	int r0,r1,r2;
	r0 = pin & 0x01;
	r1 = (pin >> 1) & 0x01;
	r2 = (pin >> 2) & 0x01;
	digitalWriteFast(S0,r0);
	digitalWriteFast(S1,r1);
	digitalWriteFast(S2,r2);
	delayMicroseconds(20);//experiment with value
	return analogRead(Z);
}
int MuxClass::readInputDigital(int pin)
{
	int r0,r1,r2;
	r0 = pin & 0x01;
	r1 = (pin >> 1) & 0x01;
	r2 = (pin >> 2) & 0x01;
	digitalWriteFast(S0,r0);
	digitalWriteFast(S1,r1);
	digitalWriteFast(S2,r2);
	delayMicroseconds(20);//experiment with value
	return digitalRead(Z);
}

