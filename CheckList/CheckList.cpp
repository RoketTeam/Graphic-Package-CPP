#include "CheckList.h"
#include "../IComposite/IComposite.h"
#include "../ListItem/ListItem.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>

using namespace std;

bool CheckList::CheckMousePosition(COORD mousePosition)
{
	return false;
}

CheckList::CheckList(int numberOfOptions, string options[], short positionX=0, short positionY=0) : IComposite(),
_listSize(numberOfOptions)
{
	_position.X = positionX;
	_position.Y = positionY;

	int currTop = positionY;
	for (size_t i = 0; i < numberOfOptions; i++)
	{
		ListItem* li = new ListItem(positionX, currTop, options[i]);
		_items.push_back(*li);

		currTop += li->getHeight();
		_listSize++;
	}

}
void CheckList::HandleInputRecord(INPUT_RECORD inputRecord)
{
}
void CheckList::KeyEventProc(KEY_EVENT_RECORD keyEventRecord)
{
}
void CheckList::MouseEventProc(MOUSE_EVENT_RECORD mouseEventRecord)
{
}
;


CheckList::~CheckList() {
	_items.clear();
}