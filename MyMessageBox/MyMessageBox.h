//#pragma once
#include <iostream>
#include <string>
#include "../Control/Control.h"
#include "../Button/Button.h"

#define DEFAULT_HEIGHT 300
#define DEFAULT_WIDTH 300

using namespace std;



class MyMessageBox : public Control
{
	private:
		Button ok_;
		Button cancel_;
		Label message_;

	public:
		//C'tors
        MyMessageBox(string message);


		// methods
		void mousePressed(int x, int y, bool isLeft){};
		void draw(Graphics& g, int x, int y, size_t z);

		void SetMessage(string message){}
		string getMessage(){ return message_.getText();}

		//D'tors
		~MyMessageBox() {}
};

