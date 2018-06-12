#pragma once

#include <string>
#include <Windows.h>
#include "../IObserver/IObservable.h"
#include "../Label/Label.h"
#include "../IListener/IListener.h"

using namespace std;

class Button : public IObservable, public Label
{

	public:
		Button(string text);
		void mousePressed(int x, int y, bool isLeft);
		string getText();
		void draw(Graphics &g, int x, int y, size_t z);

		//D'tors
		~Button();

};

