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
		// C'tors & D'tors
		Button(string text);
		Button();
		~Button();

		// Setters & Getters
		void set_clickable(bool clickable){clickable_ = clickable;}
		string get_text();


		// Methods
		void draw(Graphics &g, int x, int y, size_t z);


	// Event handlers
		bool MousePressed(int x, int y, bool isLeft);
		bool MouseHover(int x, int y, Graphics &g);

		bool is_hover(){ return is_hover_;}
		bool is_clickable(){ return clickable_;}

		void hover(){is_hover_ = true;}
		void unhover(){is_hover_ = false;}



	protected:
		bool is_hover_;
		bool clickable_;

};

