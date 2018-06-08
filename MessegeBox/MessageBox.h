
#include <string>
#include <Windows.h>
#include <iostream>
#include <string>
#include "IControl.h"
#include "Button.h"

using namespace std;

class MessageBox : public Control
{
	private:
		Button ok_;
		Button cancel_;
		Label message_;

	public:
		//C'tors
		MessageBox() {};

		MessageBox(Button ok, Button cancel, Label message)
			: ok_(ok), cancel_(cancel), message_(message) {
		};

		// methods
		void SetMessage(string message);
		string getMessage();

		//D'tors
		~MessageBox() {};


};

