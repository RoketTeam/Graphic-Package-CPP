#pragma once
#include "../Graphics/Graphics.h"
#include <vector>

using namespace std;
class IBorder;

class Control
{

	public:

        // Static methods
        static Control* get_focus() { return focused_control; }
        static void set_focus(Control& control) {focused_control = &control;}

        // C'tors & D'tors
        Control();
		Control(int left, int top, IBorder*);
        virtual ~Control() = 0;

        // Setters & Getters
        void set_background(Color color){background_ = color; }
        void set_foreground(Color color){ foreground_ = color; }
        void set_border(IBorder* border);
        Control* set_margin(int margin);
        virtual void set_left(short left){left_ = left;}
        virtual void set_top(short top){top_ = top;}

        int get_margin(){return margin_;}
        virtual int get_left() { return left_; }
        virtual short get_top() { return top_; }
        virtual int get_width(){ return width_;}
        virtual int get_height(){ return height_;}
        virtual void get_all_controls(vector<Control*>* controls) {};

        // Methods
        virtual void draw(Graphics& g, int x, int y, size_t z){}
        virtual bool CanGetFocus() { return FALSE; };
        void FillBackground(short x, short y, int height, Graphics & g);

        // Event handlers
        virtual void MousePressed(int x, int y, bool isLeft) {}
		virtual bool MouseHover(int x, int y, Graphics &g){ return false;}
		virtual void KeyDown(int keyCode, char character) {}

    protected:
        static Control* focused_control;

        short left_;	 	// top x
        short top_; 		// top y
        IBorder* border_;
        int height_;		// bottom y
        int width_;		    // bottom x
        Color background_;
        Color foreground_;
        int margin_;
};

