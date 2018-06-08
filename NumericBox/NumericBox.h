
#include <string>
#include <Windows.h>
#include "IControl.h"
#include "Button.h"

using namespace std;

class NumericBox : public IControl
{
	private:
		Button inc_;
		Button dec_;
		int value_;

	public:
		//C'tors
		NumericBox() {
		};

		NumericBox(Button inc, Button dec, int value)
			: inc_(inc), dec_(dec), value_(value) {
		};

		// methods
		void inc();
		void dec();
		void setMinValue(int value);
		void setMaxValue(int value);
		void setValue(int value);

		//D'tors
		~NumericBox() {};


};

