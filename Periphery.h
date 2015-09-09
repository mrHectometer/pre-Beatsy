/*
 * IncFile1.h
 *
 * Created: 27-7-2015 22:25:50
 *  Author: Roel
 */ 


#ifndef INPUT_H
#define INPUT_H

// For using with the Teensy Audio board
#define TFT_DC 21
#define TFT_CS 20
#define TFT_RST 255 // Set to 255 when reset is not used
#define TFT_MOSI 7
#define TFT_SCLK 14
#define TFT_MISO 12

ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);

//chip select for SD
int SDCS = 10;
//buttons
Adafruit_Trellis matrix0 = Adafruit_Trellis();

Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);
// or use the below to select 4, up to 8 can be passed in
//Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0, &matrix1, &matrix2, &matrix3);

// set to however many you're working with here, up to 8
#define NUMTRELLIS 1

#define numKeys (NUMTRELLIS * 16)

// Connect Trellis Vin to 5V and Ground to ground.
// Connect the INT wire to pin #A2 (can change later!)
#define INTPIN 0


void init_buttons()
{

	//pinMode(Volumeknob,INPUT);
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
void init_trellis()
{
	trellis.begin(0x70);  // only one
}
#endif /* INPUT_H */