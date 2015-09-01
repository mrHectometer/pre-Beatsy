/*
 * IncFile1.h
 *
 * Created: 27-7-2015 22:25:50
 *  Author: Roel
 */ 


#ifndef INPUT_H
#define INPUT_H

// For using with the Teensy Audio board
#define TFT_DC 8
#define TFT_CS 9
#define TFT_RST 255 // Set to 255 when reset is not used
#define TFT_MOSI 7
#define TFT_SCLK 14
#define TFT_MISO 12

ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);

//chip select for SD
int SDCS = 10;
//buttons
const int button0 = 0;
const int button1 = 1;
const int button2 = 2;
const int button3 = 3;
const int button4 = 4;
const int Volumeknob = A3;
Bounce bUp = Bounce(button0, 3);
Bounce bDown = Bounce(button1, 3);
Bounce bLeft = Bounce(button2, 3);
Bounce bRight = Bounce(button3, 3);
Bounce bEnter = Bounce(button4, 3);

void init_buttons()
{
	pinMode(button0,INPUT);
	pinMode(button1,INPUT);
	pinMode(button2,INPUT);
	pinMode(button3,INPUT);
	pinMode(button4,INPUT);
	pinMode(Volumeknob,INPUT);
	analogReadResolution(8);
}
void init_SD()
{
	if (!SD.begin(SDCS)) 
	{
		Serial.println("SD initialization failed!");
	}
	else
	{
		Serial.println("SD initialized succesfully");
	}
}
void init_tft()
{
	tft.begin();
	tft.setRotation(1);
	tft.invertDisplay(0);
	tft.fillScreen(ILI9341_BLACK);
}
#endif /* INPUT_H */