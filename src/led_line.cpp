#include "../headers/led_line.h"

using namespace std;

led_line::led_line(int _digit)
/// transforms the digit into a vector of bool. Ex: 5 -> 00000101
// params:
//  _digit: the associated digit, for example tens of seconds
{
	int8_t digit = (int8_t) _digit;

	size = sizeof(digit) * 8;
	for(int i = size - 1 ; i > -1 ; i--)
    	{
        	line.push_back((digit >> i) & 1);
    	}
}

const void led_line::print_binary()
/// prints to stdout a human readable shape
{
	vector<bool>::iterator it;
	for(it = line.begin(); it != line.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
