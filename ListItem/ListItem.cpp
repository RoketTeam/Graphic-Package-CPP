#include "ListItem.h"
#include "../Label/Label.h"
#include "../IListener/IListener.h"
#include "../IBorder/OneLine.h"
#include "../IBorder/DoubleLine.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>

using namespace std;


ListItem::ListItem(string description) : Control(),// IListener(),
lineLengh_(description.length()),
descriptionLabel_(description),
check_(" ") {};

ListItem::ListItem(short left, short top, string description) : Control(),// IListener(),
lineLengh_(description.length()),
descriptionLabel_(description),
check_(" ")
{
	setLeft(left);
	setTop(top);
};

ListItem::ListItem(short left, short top, int length, string description) : Control(), //IListener(),
lineLengh_(length),
descriptionLabel_(description),
check_(" ")
{
	setLeft(left);
	setTop(top);
};


void ListItem::setLeft(short left) {
	if (left < 0) { left = 0; }
	left_ = left;
}

void ListItem::setTop(short top) {
	if (top < 0) { top = 0; }
	top_ = top;
}

bool ListItem::SetColor(DWORD color)
{
	return false;
}

void ListItem::draw(Graphics &g, int x, int y, size_t z) {
	if (!z) {
		Color background = g.getBackground();
		Color foreground = g.getForeground();
		descriptionLabel_.setLeft(check_.getWidth());
		
		if (background_ != Color::Transparent)
			g.setBackground(background_);
		if (foreground_ != Color::Transparent)
			g.setForeground(foreground_);
		width_ = lineLengh_;
		this->fillBackground(x, y, width_, g);
		check_.draw(g, x, y, 0);
		descriptionLabel_.draw(g, x+ descriptionLabel_.getLeft(), y, 0);
		g.setBackground(background);
		g.setForeground(foreground);
	}
}

void ListItem::mousePressed(int x, int y, Graphics &g)
{
	//if (isInside(x, y, left_, top_, width_, height_)) {
		if (isChecked()) {
			MarkAsUnchoose(g);
		}
		else {
			MarkAsChoose(g);
		}
	//}
}

void ChangeMark(Button btn, Graphics &g)
{
	g.write(btn.getLeft()+1, btn.getTop()+1, btn.getText());
}


void ListItem::MarkAsChoose(Graphics &g)
{
	isChecked_ = true;
	check_.setText("V");
	ChangeMark(check_, g);
}

void ListItem::MarkAsUnchoose(Graphics &g)
{
	isChecked_ = false;
	check_.setText(" ");
	ChangeMark(check_, g);
}


bool ListItem::mouseHover(int x, int y, Graphics & g)
{
	return check_.mouseHover(x, y, g);
}


ListItem::~ListItem() {
	delete this->border_;
}