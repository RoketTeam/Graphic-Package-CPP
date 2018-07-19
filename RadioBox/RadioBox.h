#include "../GenericList/GenericList.h"

#pragma once

using namespace std;


class RadioBox : public GenericList {

	public:
		RadioBox(){}
		
		int select();
        int switch_checked_item();


	protected:
		int selected_index_;
		void unselec_others(int selected);
};