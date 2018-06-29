#pragma once
#include "../Graphics/Graphics.h"
#include <vector>

using namespace std;
class IBorder;

class Control
{

	protected:
		short left_;	 	// top x
		short top_; 		// top y
		IBorder* border_;
		int height_;		// bottom y
		int width_;		// bottom x
        Color background_;
        Color foreground_;
		static Control* focused_control;
		int margin_;


	public:
		Control();
		Control(int left, int top, IBorder*);
		static Control* getFocus() { return focused_control; };
		static void setFocus(Control& control) {focused_control = &control;}
		virtual void draw(Graphics& g, int x, int y, size_t z){}
		virtual void mousePressed(int x, int y, bool isLeft) {}
		virtual bool mouseHover(int x, int y, Graphics &g){ return false;}
		virtual void keyDown(int keyCode, char character) {}

		void setBackground(Color color){background_ = color; }
		void setForeground(Color color){ foreground_ = color; }

		void fillBackground(short x, short y, int height, Graphics & g);

		virtual int getLeft() { return left_; }
		virtual short getTop() { return top_; }
		virtual void setLeft(short left){left_ = left;}
		virtual void setTop(short top){top_ = top;}
		virtual int getWidth(){ return width_;}
		virtual int getHeight(){ return height_;}
		virtual void getAllControls(vector<Control*>* controls) {};
		virtual bool canGetFocus() { return FALSE; };
		void setBorder(IBorder* border){border_ = border;}
		virtual ~Control() = 0;
		Control* setMargin(int margin){margin_ = margin;}
		int getMargin(){return margin_;}
};

