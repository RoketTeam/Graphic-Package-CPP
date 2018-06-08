#include "../Graphics/Graphics.h"
#include "../Label/Label.h"
#include "../EventEngine/EventEngine.h"

int main(int argc, char** argv)
{

	Label l("Hello World");
	Control& l2 = l;
	EventEngine e;
	e.run(l);

}