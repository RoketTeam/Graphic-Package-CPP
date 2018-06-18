#pragma once

#include <string>
#include <Windows.h>
#include "../Control/Control.h"

using namespace std;

class Label : public Control
{
	private:
		string text_;

	public:
		Label(string text);
		void setText(string text);
		string getText();
		void draw(Graphics& g, int x, int y, size_t z);
		void setLeft(short left);
		void setTop(short top);
		~Label();

};

