#include "../Graphics/Graphics.h"
#include "../EventEngine/EventEngine.h"
#include "../Panel/Panel.h"


int main(int argc, char** argv)
{
	Panel p;
	Label* l = new Label("NumericBox:");
    l -> set_margin(0);
    p.Add(l);
    NumericBox* n = new NumericBox(0, 10);
    n->set_margin(4);
	p.Add(n);

    l = new Label("ComboBox: ");
    l -> set_margin(0);
    p.Add(l);
    ComboBox* comboBox = new ComboBox;
    comboBox->AddSelectedItem(new ListItem("avi"));
    comboBox->AddSelectedItem(new ListItem("shaked"));
    p.Add(comboBox);

    l = new Label("CheckList: ");
    l -> set_margin(0);
    p.Add(l);
    CheckList checkList;
    checkList.AddSelectedItem(new ListItem("Ligal"));
    checkList.AddSelectedItem(new ListItem("Chen"));
    checkList.AddSelectedItem(new ListItem("Lahmi"));
    checkList.AddSelectedItem(new ListItem("Shaked"));
    checkList.set_margin(1);
    p.Add(&checkList);

    l = new Label("RadioBox: ");
    l -> set_margin(0);
    p.Add(l);
    RadioBox radioBox;
    radioBox.AddSelectedItem(new ListItem("Dubi"));
    radioBox.AddSelectedItem(new ListItem("Estie"));
    radioBox.AddSelectedItem(new ListItem("Shimi"));
    radioBox.AddSelectedItem(new ListItem("Sansa"));
    radioBox.set_margin(1);
    p.Add(&radioBox);

    p.Add(new Label("this is a TextBox:"));
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