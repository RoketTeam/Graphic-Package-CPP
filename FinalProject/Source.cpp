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
            label->set_margin_left(4);
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
            submit.set_margin_left(9);
            submit.add(this);
            Add(&submit);
        }

        void Submit(){
            Label* numericBox_value = new Label(to_string(numericBox.get_value()));
            Label* comboBox_value = new Label(comboBox.get_value());
            vector<string> checkList_value = checkList.get_value();
            vector<string> radioBox_value = radioBox.get_value();
            Label* textBox_value = new Label(textBox.get_value());
            items_.clear();
            label = new Label("You Choose cofee cups:");
            label->set_margin(0);
            Add(label);
            Add(numericBox_value);

            label = new Label("Your favorite cofee company: ");
            label->set_margin(0);
            Add(label);
            Add(comboBox_value);

            label = new Label("Your cofee Type: ");
            label->set_margin(0);
            Add(label);

            for (auto select : checkList_value)
                Add(new Label(select));

            label = new Label("You like to drink your cofee at: ");
            label->set_margin(0);
            Add(label);

            for (auto select : radioBox_value)
                Add(new Label(select));

            label = new Label("Your free text: ");
            label->set_margin(0);
            Add(label);
            Add(textBox_value);
        }

        void action(IObservable* observable){
            Button* submit = dynamic_cast<Button*> (observable);
            MyMessageBox* messagebox = dynamic_cast<MyMessageBox*> (observable);
            if(submit && !submit->get_text().compare("Submit")){
                MyMessageBox* m = new MyMessageBox("Are you sure?");
                m->add(this);
                Add(m);
                return;
            }
            if(messagebox && !messagebox->get_value().compare("OK")){
                Submit();
            }
        }

};


int main(int argc, char** argv)
{
	Form cofee_form;
    EventEngine e;
	e.run(cofee_form);
}