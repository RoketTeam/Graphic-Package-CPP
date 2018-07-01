#pragma once

#include <string>
#include "../Control/Control.h"
#include "../IListener/IListener.h"
#include "../Label/Label.h"
#include "../IObserver/IObservable.h"

using namespace std;

class TextBox : public Control, public IListener
{
private:
	int length_;
	Label value_;

public:
	//C'tors
	TextBox();
	TextBox(short left, short top, int length);
	TextBox(short left, short top, int length, string value);

	// methods
	void setLeft(short left);
	void setTop(short top);
	void setFrameSize(int Length);
	void addChar(int x, Graphics &g, char ch);
	void deleteChar();
	void deleteAllText();


	//Handler
	void draw(Graphics& g);
	void action(IObservable* iObservable);
	void keyPressed(CHAR AsciiChar, Graphics& g);
	//void mousePressed(int x, int y, bool isLeft);
	//bool mouseHover(int x, int y, Graphics &g);

	//D'tors
	~TextBox() {};



};

