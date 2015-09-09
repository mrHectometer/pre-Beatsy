/*
 * UIrenderer.h
 *
 * Created: 27-7-2015 22:35:16
 *  Author: Roel
 */ 


#ifndef UIRENDERER_H_
#define UIRENDERER_H_

void (*UIrenderer)();
void (*UIrendererUpdate)();

void UISetRenderer(void (*newUIRenderFunction)())
{
	if(&UIrenderer == &newUIRenderFunction) return;
	tft.fillScreen(ILI9341_BLACK);
	UIrenderer = newUIRenderFunction;
}

volatile int rerender = 0;


#endif /* UIRENDERER_H_ */