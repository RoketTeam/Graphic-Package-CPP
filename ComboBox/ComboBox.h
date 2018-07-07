#pragma once
#include "../Button/Button.h"
#include "../RadioBox/RadioBox.h"
#include "../IBorder/OneLine.h"
#include "../IListener/IListener.h"

using namespace std;


class ComboBox : public RadioBox, public IListener {


public:

	// methods
	bool is_open(){ return is_open_;}
	void open(){is_open_ = true;}
	void close(){is_open_ = false;}
	void draw(Graphics& g, int x, int y, size_t z);
	void action(IObservable* observable);
	void MousePressed(int x, int y, bool isLeft);
	void CalculateWidth();
	void CalculateHeight();
	//D'tors
	ComboBox();
	~ComboBox() {};

private:
	bool is_open_;
	Button toggle_list_;

};