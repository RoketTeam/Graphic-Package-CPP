#include "../Graphics/Graphics.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../NumericBox/NumericBox.h"
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"
#include "../EventEngine/EventEngine.h"

int main(int argc, char** argv)
{
	NumericBox b(0, 10);
	EventEngine e;
	e.run(b);
}