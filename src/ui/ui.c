#include <stdio.h>

#include "ui.h"
#include "fonts.h"

extern PlaydateAPI* pd;
extern LCDFont* font;

static int scoreOffset = 20;
static PDStringEncoding textEncoding = TEXT_ENCODING;

void ui_updateScores(int p1Score, int p2Score) {
	char p1ScoreStr[12];
	char p2ScoreStr[12];
	sprintf(p1ScoreStr, "%02d", p1Score);
	sprintf(p2ScoreStr, "%02d", p2Score);
	
	pd->graphics->drawText(p2ScoreStr, strlen(p2ScoreStr), textEncoding, pd->display->getWidth() / 2 + scoreOffset, scoreOffset);
    int p1ScoreStrWidth = pd->graphics->getTextWidth(font, p1ScoreStr, strlen(p1ScoreStr), textEncoding, pd->graphics->getTextTracking());
	pd->graphics->drawText(p1ScoreStr, strlen(p1ScoreStr), textEncoding, pd->display->getWidth() / 2 - scoreOffset - p1ScoreStrWidth, scoreOffset);
}

void ui_createNet() {
	pd->graphics->fillRect(pd->display->getWidth()/2 - 1, 20, 2, pd->display->getHeight() - 40, kColorBlack);
}


void ui_writeText(char* text, int x, int y) {
    int textStrWidth = pd->graphics->getTextWidth(font, text, strlen(text), textEncoding, pd->graphics->getTextTracking());
	pd->graphics->drawText(text, strlen(text), textEncoding, x - textStrWidth / 2, y);
}