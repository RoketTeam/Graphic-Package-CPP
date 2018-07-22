#include "../NumericBox/NumericBox.h"
#include "../Unitests/Test.h"
#include <assert.h>     /* assert */
#include <iostream>


using namespace std;

class TestNumericBox: public Test {

    void check_set_value(){
        NumericBox numericBox(0, 10);
        numericBox.set_value(11);
        assert (numericBox.get_value() == 10);
        numericBox.set_value(-1);
        assert (numericBox.get_value() == 0);
        numericBox.set_value(5);
        assert (numericBox.get_value() == 5);
    }

    void check_range(){
        NumericBox numericBox(0, 1);
        assert (numericBox.get_value() == 0);
        numericBox.inc();
        assert (numericBox.get_value() == 1);
        numericBox.inc();
        assert (numericBox.get_value() == 1);
        numericBox.set_value(0);
        numericBox.dec();
        assert (numericBox.get_value() == 0);
    }

    void check_value(){
        NumericBox numericBox(0, 10);
        assert (numericBox.get_value() == 0);
        assert (numericBox.get_text_value().compare("0") == 0);
    }

public:
    int run(){
        check_set_value();
        check_range();
        check_value();
    }
};



int main(int argc, char** argv)
{
    TestNumericBox testNumericBox;
    testNumericBox.run();
    int x;
    cin >> x;
}
