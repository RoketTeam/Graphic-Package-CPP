#include "../Graphics/Graphics.h"
#include "../EventEngine/EventEngine.h"
#include "../Panel/Panel.h"


int main(int argc, char** argv)
{
	Panel p;
	Label* l = new Label("Im a Panel and I have: ");
	l -> set_margin(0);
	l ->set_margin_left(0);
	p.Add(l);

    l = new Label("NumericBox:");
    l -> set_margin(0);
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
    checkList.set_margin(1);
    p.Add(&checkList);

    p.Add(new Label("this is a TextBos:"));
    TextBox textBox;
    textBox.set_margin(0);
    textBox.set_margin_left(0);
    textBox.set_border(new OneLine);
    p.Add(&textBox);
    Button b("Submit");
    b.set_margin(-1);
    b.set_margin_left(8);
    b.add(&p);
    p.Add(&b);
    EventEngine e;
	e.run(p);
}