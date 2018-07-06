#include "../GenericList/GenericList.h"

#pragma once

using namespace std;


class RadioBox : public GenericList {

	public:

		RadioBox(){}
		~RadioBox() {};

		int select();


        void SwitchCheckedItem();


	private:
		int selected_index_;
		void DisselectOthers(int selected);
};