#include "../headers/GPIO.h"

using namespace std;

const string DEBUG_SUFFIX = "DEBUG: [GPIO]";

debug_GPIO::debug_GPIO()
{
    this->gpionum = "4";
}

debug_GPIO::debug_GPIO(string gnum)
{
    this->gpionum = gnum;
}

void debug_GPIO::setup(string gnum)
{
    this->gpionum = gnum;
}

int debug_GPIO::export_gpio()
{
    cout << DEBUG_SUFFIX << this->gpionum << " - Exporting" << endl;
    return 0;
}

int debug_GPIO::unexport_gpio()
{
    cout << DEBUG_SUFFIX << this->gpionum << " - Unexporting" << endl;
    return 0;
}

int debug_GPIO::setdir_gpio(string dir)
{
    cout << DEBUG_SUFFIX << this->gpionum << " - Setting direction " << dir << endl;
    return 0;
}

int debug_GPIO::setval_gpio(string val)
{
    cout << DEBUG_SUFFIX << this->gpionum << " - Setting val " << val << endl;
    return 0;
}

int debug_GPIO::getval_gpio(string& val)
{
    cout << DEBUG_SUFFIX << this->gpionum << " - Reading val" <<  endl;
    return 0;
}

string debug_GPIO::get_gpionum(){

return this->gpionum;

}
