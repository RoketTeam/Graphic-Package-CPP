#include "../IComposite/IComposite.h"
#include "../ListItem/ListItem.h"

#pragma once

using namespace std;


class RadioBox : public IComposite {

	public:

		RadioBox(){set_focus(*this);}
		~RadioBox() {};

		// Event handlers
		void MousePressed(int x, int y, bool isLeft);
		bool MouseHover(int x, int y, Graphics &g);
		void KeyDown(int keyCode, char character);
		void draw(Graphics& g, int x, int y, size_t z);
        void action(IObservable* observable){}

		void SwitchCheckedItem();


	private:
		int selected_index_;
		void DisselectOthers(int selected);
};