#include "../Graphics/Graphics.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../NumericBox/NumericBox.h"
#include "../EventEngine/EventEngine.h"

int main(int argc, char** argv)
{

//	Label l("Hello World");
//	Control& l2 = l;
	NumericBox b(2, 10);
	EventEngine e;
	e.run(b);

}