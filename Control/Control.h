#pragma once
#include "../Graphics/Graphics.h"
#include <vector>

using namespace std;
class IBorder;

class Control
{

	protected:
		short left_;	 	// top y
		short top_; 		// top x
		IBorder* border_;
		short height_;		// bottom y
		short width_;		// bottom x



	public:
		Control();
		Control(int left, int top, IBorder*);
		static Control* getFocus() { return NULL; };
		static void setFocus(Control& control) {};
		virtual void draw(Graphics& g, int x, int y, size_t z) {};
		virtual void mousePressed(int x, int y, bool isLeft) {};
		virtual void keyDown(int keyCode, char character) {};
		virtual short getLeft() { return left_; };
		virtual short getTop() { return top_; };
		virtual void getAllControls(vector<Control*>* controls) {};
		virtual bool canGetFocus() { return FALSE; };
		void setBorder(IBorder* border){border_ = border;}
		virtual ~Control() = 0;
};

