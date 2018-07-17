#include "../Panel/Panel.h"
#include "../IBorder/DoubleLine.h"

using namespace std;


Panel::Panel() {
    background_ = Color::Black;
    foreground_ = Color::White;
    set_border(new DoubleLine());
}


void Panel::draw(Graphics &g, int x, int y, size_t z) {
    Color background = g.getBackground();
    Color foreground = g.getForeground();
    if(z == 0){
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);

        CalculateHeight();
        CalculateWidth();
        border_->drawBorder(x, y, width_ + 4, g, height_ + 4);
    }
    int spacing = 0;
    for(int i = 0; i < items_.size(); i ++){
        auto current_item = items_[i];
        if(current_item->get_background() == Color::Transparent)
            current_item->set_background(get_background());
        if(current_item->get_foreground() == Color::Transparent)
            current_item->set_foreground(get_foreground());
        current_item->draw(g, x + 1 + current_item->get_margin_left(), y+spacing, z);
        spacing += current_item->get_height() + current_item->get_margin();

    }
    if(z == 0) {
        g.setBackground(background);
        g.setForeground(foreground);
    }
}

bool Panel::Add(Control *item) {
    IComposite::Add(item);
    if ((!Control::get_focus()) && item->CanGetFocus())
        Control::set_focus(*item);
}

void Panel::CalculateHeight() {
    height_ = 0;
    for(int i = 0; i < items_.size(); i ++){
        auto item = items_[i];
        if(!dynamic_cast<MyMessageBox*>(item))
            height_ += items_[i]->get_height() + items_[i]->get_margin();
    }
}

void Panel::CalculateWidth() {
    width_ = 0;
    for(int i = 0; i < items_.size(); i ++){
        int item_width = items_[i]->get_width();
        if( item_width> width_)
            width_ = item_width;
    }
}

bool Panel::MousePressed(int x, int y, bool isLeft){
    bool redraw = false;
    for(int i = 0; i < items_.size(); i ++){
        if(items_[i]->MousePressed(x, y, isLeft))
            redraw = true;
    }
    return redraw;
}

bool Panel::MouseHover(int x, int y, Graphics &g){
    bool redraw = false;
    for(int i = 0; i < items_.size(); i ++){
        if(items_[i]->MouseHover(x, y, g))
            redraw = true;
    }
    return redraw;
}

bool Panel::KeyDown(int keyCode, char character){
    return get_focus()->KeyDown(keyCode, character);
}

void Panel::get_all_controls(vector<Control*>* controls){
    for(auto control: items_){
        controls->push_back(control);
        control->get_all_controls(controls);
    }
}

void Panel::action(IObservable* observable){

}
