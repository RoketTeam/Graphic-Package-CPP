#pragma once

#include <string>
#include <Windows.h>
#include "../IObserver/IObservable.h"
#include "../Label/Label.h"
#include "../IListener/IListener.h"

using namespace std;

class Button : public IObservable, public Label
{
    protected:
        bool isHover_;
        bool clickable_;

	public:
		Button(string text);
		void mousePressed(int x, int y, bool isLeft);
		string getText();
		void draw(Graphics &g, int x, int y, size_t z);
		bool mouseHover(int x, int y, Graphics &g);
		bool isHover(){ return isHover_;}
		void hover(){isHover_ = true;}
		void unHover(){isHover_ = false;}
		void setClickable(bool clickable){clickable_ = clickable;}
		bool isClickable(){ return clickable_;}
		//D'tors
		~Button();

};

