#include <string>
#include <Windows.h>
#include "IObservable.h"
#include "Label.h"
#include "IListener.h"

using namespace std;

class Button : public IObservable, Label
{

	public:

		//C'tors
		Button();

		//D'tors
		~Button() {};

};

