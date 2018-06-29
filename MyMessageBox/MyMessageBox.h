//#pragma once
#include <iostream>
#include <string>
#include "../Control/Control.h"
#include "../Button/Button.h"

#define DEFAULT_HEIGHT 5
#define DEFAULT_WIDTH 5

using namespace std;



class MyMessageBox : public Control, public IListener
{
	private:
		Button ok_;
		Button cancel_;
		Label message_;
		bool is_visible;

	public:
		//C'tors
        MyMessageBox(string message);


		// methods
		void mousePressed(int x, int y, bool isLeft);
        bool mouseHover(int x, int y, Graphics &g);

        void draw(Graphics& g, int x, int y, size_t z);

		void setMessage(string message){message_.setText(message);}
		string getMessage(){ return message_.getText();}
        virtual void action(IObservable* observable);

		//D'tors
		~MyMessageBox() {}
};

