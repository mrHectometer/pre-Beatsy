#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H

#include <WProgram.h>
#define DEBBIE

#ifdef DEBBIE
//Source: http://bitstream24.com/debugging-arduino-code-using-c-preprocessor-macros/
#define DEBUG_INIT() char sDebug[128];
#define DEBUG_PRINTHEX(T, v) Serial.print(T); sprintf(sDebug, “%x\n\r”, v); Serial.print(sDebug);
#define DEBUG_PRINTDEC(T, v) Serial.print(T); sprintf(sDebug, “%d\n\r”, v); Serial.print(sDebug);
#define DEBUG_PRINTARRAYHEX(T, a, l) Serial.print(T); if(l == 0) Serial.print(“Empty.\n\r”); else {for(int x=0; x<l; x++){sprintf(sDebug, “%x “, a[x]); Serial.print(sDebug);} Serial.print(“\n\r”);}
#define DEBUG_PRINTARRAYDEC(T, a, l) Serial.print(T); if(l == 0) Serial.print(“Empty.\n\r”); else {for(int x=0; x<l; x++){sprintf(sDebug, “%d “, a[x]); Serial.print(sDebug);} Serial.print(“\n\r”);}
#define DEBUG_HALT() while(Serial.available() == 0); Serial.setTimeout(1); Serial.readBytes(sDebug, 1);

#define DEBUG_PRINT(...)  \
        Serial.print(millis());     \
        Serial.print(": ");    \
        Serial.print(__PRETTY_FUNCTION__); \
        Serial.print(' ');      \
        Serial.print(__LINE__);     \
        Serial.print(' ');      \
        Serial.println(__VA_ARGS__)
    
#else
#define DEBUG_INIT()
#define DEBUG_PRINTHEX(T, v)
#define DEBUG_PRINTDEC(T, v)
#define DEBUG_PRINTARRAYHEX(T, a, l)
#define DEBUG_PRINTARRAYDEC(T, a, l)
#define DEBUG_HALT()
#define DEBUG_PRINT(...)
#endif

#endif

