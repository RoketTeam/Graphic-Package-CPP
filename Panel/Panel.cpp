#include "../Panel/Panel.h"
#include "../IBorder/DoubleLine.h"

using namespace std;


Panel::Panel() {
    background_ = Color::Cyan;
    setBorder(new DoubleLine());
}


void Panel::draw(Graphics &g, int x, int y, size_t z) {
    Color background = g.getBackground();
    Color foreground = g.getForeground();
    if(z == 0){
        if(background_ != Color::Transparent)
            g.setBackground(background_);
        if(foreground_ != Color::Transparent)
            g.setForeground(foreground_);
        if(border_){
            calculateHeight();
            calculateWidth();
            border_->drawBorder(x, y, width_ + 4, g, height_ + 4);
        }
    }
    int spacing = 0;
    for(int i = 0; i < items_.size(); i ++){
        items_[i]->draw(g, x + 1, y+spacing, z);
        spacing += items_[i]->getHeight() + items_[i]->getMargin();
    }
    if(z == 0) {
        g.setBackground(background);
        g.setForeground(foreground);
    }
}

void Panel::calculateHeight() {
    height_ = 0;
    for(int i = 0; i < items_.size(); i ++){
        height_ += items_[i]->getHeight() + items_[i]->getMargin();
    }
}

void Panel::calculateWidth() {
    width_ = 0;
    for(int i = 0; i < items_.size(); i ++){
        int itemWidth = items_[i]->getWidth();
        if( itemWidth> width_)
            width_ = itemWidth;
    }
}

void Panel::mousePressed(int x, int y, bool isLeft){
    for(int i = 0; i < items_.size(); i ++){
        items_[i]->mousePressed(x, y, isLeft);
    }
}
bool Panel::mouseHover(int x, int y, Graphics &g){
    bool redraw = false;
    for(int i = 0; i < items_.size(); i ++){
        if(items_[i]->mouseHover(x, y, g))
            redraw = true;
    }
    return redraw;
}
void Panel::keyDown(int keyCode, char character){}
void Panel::getAllControls(vector<Control*>* controls){}

