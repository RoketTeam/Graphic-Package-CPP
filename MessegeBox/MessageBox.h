
#include <string>
#include <Windows.h>
#include <iostream>
#include <string>
#include "IControl.h"
#include "Button.h"

using namespace std;

class MessageBox : public IControl
{
	private:
		Button _ok;
		Button _cancel;
		Label _message;

	public:
		//C'tors
		MessageBox() {};

		MessageBox(Button ok, Button cancel, Label message)
			: _ok(ok), _cancel(cancel), _message(message) {
		};

		// methods
		void SetMessage(string message);
		string getMessage();

		//D'tors
		~MessageBox() {};


};

