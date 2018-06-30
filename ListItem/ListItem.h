
# pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "../Control/Control.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

using namespace std;


class ListItem : public Control {

	private:
		// Atrributes
		Button check_;
		Label descriptionLabel_;
		short lineLengh_;
		bool isChecked_;
		//bool isFocused_;
		bool isHover_;


	// Methods
		void MarkAsChoose(Graphics &g);
		void MarkAsUnchoose(Graphics &g);
		bool SetColor(DWORD color);

	public:
		// C'tors
		ListItem(string description);
		ListItem(short left, short top, string description);
		ListItem(short left, short top, int length, string description);

		// methods
		void setLeft(short left);
		void setTop(short top);
		short getLineLengh() { return lineLengh_; }
		void draw(Graphics &g, int x, int y, size_t z);

		//bool focus();
		//bool unfocus();
		//bool isFocus() { return isFocused_; }

		void mousePressed(int x, int y, Graphics &g);
		bool isChecked() { return isChecked_; }
		
		bool mouseHover(int x, int y, Graphics &g);
		bool isHover() { return isHover_; }
		void hover() { isHover_ = true; }
		void unHover() { isHover_ = false; }

		//D'tors
		~ListItem();

};