#include "../Graphics/Graphics.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../NumericBox/NumericBox.h"
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"
#include "../EventEngine/EventEngine.h"
#include "../MyMessageBox/MyMessageBox.h"
#include "../Panel/Panel.h"
#include "../ListItem/ListItem.h"
#include "../RadioBox/RadioBox.h"
#include "../GenericList/GenericList.h"
#include "../CheckList/CheckList.h"

int main(int argc, char** argv)
{
	Panel p;
	Label* l = new Label("Im a Panel and I have: ");
	l -> set_margin(0);
	p.Add(l);

    l = new Label("NumericBox:");
    l -> set_margin(-1);
    p.Add(l);
    NumericBox* n = new NumericBox(0, 10);
    n->set_margin(4);
	p.Add(n);

    l = new Label("CheckList: ");
    l -> set_margin(-2);
    p.Add(l);
    CheckList checkList;
    checkList.AddSelectedItem(new ListItem("Ligal"));
    checkList.AddSelectedItem(new ListItem("Chen"));
    checkList.AddSelectedItem(new ListItem("Lahmi"));
    checkList.AddSelectedItem(new ListItem("Shaked"));
    p.Add(&checkList);
    EventEngine e;
	e.run(p);
}