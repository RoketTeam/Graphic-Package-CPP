
#include <string>
#include "../Control/Control.h"
#include "../IListener/IListener.h"
#include "../Button/Button.h"

using namespace std;

class NumericBox : public Control, public IListener
{

	public:
		// C'tors & D'tors
		NumericBox(int min_value, int max_value);
		NumericBox();
		~NumericBox() {};


		// Setters & Getters
		void set_min_value(int value);
		void set_max_value(int value);
		void set_value(int value);
		int get_value();


		// Methods
		void inc();
		void dec();
		void draw(Graphics& g, int x, int y, size_t z);

		// Event handlers
		void action(IObservable* iObservable);
		bool MousePressed(int x, int y, bool isLeft);
		bool MouseHover(int x, int y, Graphics &g);




	private:
		Button inc_;
		Button dec_;
		Label text_value_;
		int value_;
		int min_value_;
		int max_value_;

};

