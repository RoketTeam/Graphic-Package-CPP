#include "../Graphics/Graphics.h"
#include "../EventEngine/EventEngine.h"
#include "../Panel/Panel.h"


class Form: public Panel {
    private:
        Label* label;
        NumericBox numericBox;
        ComboBox comboBox;
        CheckList checkList;
        RadioBox radioBox;
        TextBox textBox;
        Button submit;

    public:
        Form(){
            label = new Label("~~~~~~ THIS IS AN AWESOME FORM! ~~~~~~");
            label->set_margin(0);
            Add(label);

            label = new Label("How many cofee cups are you drinking in a day?");
            label->set_margin(0);
            Add(label);
            numericBox.set_margin(3);
            Add(&numericBox);

            label = new Label("Choose your favorite cofee company: ");
            label->set_margin(0);
            Add(label);

            comboBox.AddSelectedItem(new ListItem("Elite"));
            comboBox.AddSelectedItem(new ListItem("Jacobs"));
            comboBox.AddSelectedItem(new ListItem("TesterChoice"));
            comboBox.set_margin(3);
            Add(&comboBox);

            label = new Label("Choose your cofee Type: ");
            label->set_margin(0);
            Add(label);

            checkList.AddSelectedItem(new ListItem("Black"));
            checkList.AddSelectedItem(new ListItem("Espresso"));
            checkList.AddSelectedItem(new ListItem("Espresso with milk"));
            checkList.AddSelectedItem(new ListItem("Americano"));
            checkList.set_margin(3);
            Add(&checkList);

            label = new Label("When do you like to drink your cofee? ");
            label->set_margin(0);
            Add(label);

            radioBox.AddSelectedItem(new ListItem("8AM"));
            radioBox.AddSelectedItem(new ListItem("10AM"));
            radioBox.AddSelectedItem(new ListItem("4PM"));
            radioBox.AddSelectedItem(new ListItem("All answers is right"));
            radioBox.set_margin(3);
            Add(&radioBox);

            label = new Label("Anything else? ");
            label->set_margin(0);
            Add(label);
            textBox.set_border(new OneLine);
            textBox.set_margin(2);
            Add(&textBox);

            submit.set_text("Submit");
            submit.set_margin_left(6);
            submit.add(this);
            Add(&submit);
        }

        void action(IObservable* observable){
            MyMessageBox* m = new MyMessageBox("Are you sure?");
            Add(m);
        }

};


int main(int argc, char** argv)
{
	Form cofee_form;
    EventEngine e;
	e.run(cofee_form);
}