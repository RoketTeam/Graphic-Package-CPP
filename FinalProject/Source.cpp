#include "../Graphics/Graphics.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../NumericBox/NumericBox.h"
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"
#include "../EventEngine/EventEngine.h"
#include "../MyMessageBox/MyMessageBox.h"
#include "../Panel/Panel.h"


int main(int argc, char** argv)
{
	Panel p;
	Label* l = new Label("Im a Panel and I have: ");
	l -> setMargin(0);
	p.Add(l);

    l = new Label("NumericBox:");
    l -> setMargin(-1);
    p.Add(l);
    NumericBox* n = new NumericBox(0, 10);
    n->setMargin(4);
	p.Add(n);

    l = new Label("MessageBox: ");
    l -> setMargin(0);
    p.Add(l);
    p.Add(new MyMessageBox("I hope dsfsfsdfdsf"));
	MyMessageBox m("lalala");
	EventEngine e;
	e.run(p);
}