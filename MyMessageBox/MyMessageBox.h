//#pragma once
#include <iostream>
#include <string>
#include "../Control/Control.h"
#include "../Button/Button.h"


class MyMessageBox : public Control, public IListener
{

	public:

		// C'tors & D'tors
        MyMessageBox(string message);
		~MyMessageBox() {}


		// Setters & Getters
		void set_message(string message){message_.set_text(message);}
		string get_message(){ return message_.get_text();}
		void set_visibility(bool visibility){is_visible_ = visibility;}
		bool is_visible(){ return is_visible_;}
		void set_ok_text(string ok){ok_ = ok;}
		void set_cancel_text(string ok){cancel_ = ok;}

		// Methods
		void draw(Graphics& g, int x, int y, size_t z);

		// Event handler
		void MousePressed(int x, int y, bool isLeft);
        bool MouseHover(int x, int y, Graphics &g);
        void action(IObservable* observable);


	private:
		Button ok_;
		Button cancel_;
		Label message_;
		bool is_visible_;
};

