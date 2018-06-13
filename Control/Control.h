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
		int height_;		// bottom y
		int width_;		// bottom x



	public:
		Control();
		Control(int left, int top, IBorder*);
		static Control* getFocus() { return NULL; };
		static void setFocus(Control& control) {};
		virtual void draw(Graphics& g, int x, int y, size_t z) {}
		virtual void mousePressed(int x, int y, bool isLeft) {}
		virtual void mouseHover(int x, int y){}
		virtual void keyDown(int keyCode, char character) {}
		virtual short getLeft() { return left_; }
		virtual short getTop() { return top_; }
		virtual void setLeft(short left){left_ = left;}
		virtual void setTop(short top){top_ = top;}
		int getWidth(){ return width_;}
		int getHeight(){ return height_;}
		virtual void getAllControls(vector<Control*>* controls) {};
		virtual bool canGetFocus() { return FALSE; };
		void setBorder(IBorder* border){border_ = border;}
		virtual ~Control() = 0;
};

