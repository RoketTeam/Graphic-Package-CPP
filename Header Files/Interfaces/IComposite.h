
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "IControl.h"
#include "IListener.h"

#pragma once

using namespace std;


class IComposite : public IControl, IListener  {

	private:
		// Atrributes
		vector<IControl> _items;

	public:

		// methods
		virtual IControl* GetItem(int index) = 0;
		virtual void Add(IControl* item) = 0;

		//D'tors
		virtual ~IComposite() {};

};