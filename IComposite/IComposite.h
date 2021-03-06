
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "../Control/Control.h"
#include "../IListener/IListener.h"

#pragma once

using namespace std;


class IComposite : public Control, public IListener  {

	protected:
		// Atrributes
		vector<Control*> items_;

	public:

		// methods
		virtual Control* GetItem(int index);
		virtual bool Add(Control* item);

		//D'tors
		virtual ~IComposite() = 0;

};