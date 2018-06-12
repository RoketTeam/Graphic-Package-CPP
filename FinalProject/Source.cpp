#include "../Graphics/Graphics.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../NumericBox/NumericBox.h"
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"
#include "../EventEngine/EventEngine.h"

int main(int argc, char** argv)
{

	Label l(" I Hate C++ Very Much ");
	DoubleLine* OLborder = new DoubleLine();
	l.setBorder(OLborder);
	Control& l2 = l;
	NumericBox b(2, 10);
	EventEngine e;
	e.run(l);

}