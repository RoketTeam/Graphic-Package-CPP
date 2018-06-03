
#include <string>
#include <Windows.h>
#include "IControl.h"
#include "Button.h"

using namespace std;

class NumericBox : public IControl
{
	private:
		Button _inc;
		Button _dec;
		int _value;

	public:
		//C'tors
		NumericBox() {
		};

		NumericBox(Button inc, Button dec, int value)
			: _inc(inc), _dec(dec), _value(value) {
		};

		// methods
		void Inc();
		void Dec();
		void SetMinValue(int value);
		void SetMaxValue(int value);
		void SetValue(int value);

		//D'tors
		~NumericBox() {};


};

