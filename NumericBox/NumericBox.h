
#include <string>
#include <Windows.h>
#include "IControl.h"
#include "Button.h"

using namespace std;

class NumericBox : public Control, public IListener
{
	private:
		Button inc_;
		Button dec_;
		Label textValue_;
		int value_;

	public:
		//C'tors
		NumericBox(int minValue, int MaxValue) {
		};


		// methods
		void inc();
		void dec();
		void setMinValue(int value);
		void setMaxValue(int value);
		void setValue(int value);
		int getValue();

		//D'tors
		~NumericBox() {};


};

