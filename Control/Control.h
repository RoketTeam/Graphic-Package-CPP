#pragma once
#include "../Graphics/Graphics.h"
#include <vector>

using namespace std;

class Control
{

	protected:
		short left_;
		short top_;
		short buttomRight_;
		IBorder* border_;



public:
		Control();
		static Control* getFocus() { return NULL; };
		static void setFocus(Control& control) {};



		virtual void draw(Graphics& g, int x, int y, size_t z) {};
		virtual void mousePressed(int x, int y, bool isLeft) {};
		virtual void keyDown(int keyCode, char character) {};
		virtual short getLeft() { return 0; };
		virtual short getTop() { return 0; };
		virtual void getAllControls(vector<Control*>* controls) {};
		virtual bool canGetFocus() { return FALSE; };
		virtual ~Control() = 0;
};

