#pragma once
#include "../Button/Button.h"
#include "../RadioBox/RadioBox.h"
#include "../IBorder/OneLine.h"
#include "../IListener/IListener.h"
#include "../GenericList/GenericList.h"

using namespace std;


class ComboBox : public RadioBox, public IListener {


public:
	//C'tors
	ComboBox();

	// methods
	bool is_open(){ return is_open_;}
	void open(){is_open_ = true;}
	void close(){is_open_ = false;}
	void draw(Graphics& g, int x, int y, size_t z);
	void action(IObservable* observable);
	void CalculateWidth();
	void CalculateHeight();
	string get_value();

	//Handlers
	bool KeyDown(int keyCode, char character);
	bool MousePressed(int x, int y, bool isLeft);

	//D'tors
	~ComboBox() {};

private:
	bool is_open_;
	Button toggle_list_;

};