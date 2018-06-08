
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "IControl.h"
#include "IListener.h"

#pragma once

using namespace std;


class IComposite : public Control, IListener  {

	private:
		// Atrributes
		vector<Control*> items_;

	public:

		// methods
		virtual Control* GetItem(int index){};
		virtual void Add(Control* item){};

		//D'tors
		virtual ~IComposite() = 0;

};