#pragma once

#include <string>
#include "../Control/Control.h"
#include "../Label/Label.h"
#include "../IObserver/IObservable.h"

using namespace std;

class TextBox : public Control
{
private:
	int length_;
	Label value_;
	Graphics* graphic_;

public:
	// C'tors & D'tors
	TextBox(Graphics &);
	TextBox(short left, short top, int length, Graphics &);
	TextBox(short left, short top, int length, string value, Graphics &);
	~TextBox() {};

	// Setters & Getters
	void set_left(short left);
	void set_top(short top);
	void set_frame_size(int length);

	// methods
	void addChar(int x, char ch);
	void deleteChar();
	void deleteAllText();
	void draw(Graphics& g, int x, int y, size_t z);

	//Handler
	void KeyDown(int keyCode, char character);
	void MousePressed(int x, int y, bool isLeft);
	bool MouseHover(int x, int y, Graphics &g);



};

