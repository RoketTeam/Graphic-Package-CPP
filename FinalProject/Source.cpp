#include "../Graphics/Graphics.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../EventEngine/EventEngine.h"

int main(int argc, char** argv)
{

//	Label l("Hello World");
//	Control& l2 = l;
	Button b("whyyy");
	EventEngine e;
	e.run(b);

}