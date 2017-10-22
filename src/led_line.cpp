#include "../headers/led_line.h"

using namespace std;

led_line::led_line(int _digit)
{
	// cast to int16_t to reduce storage size
	int16_t digit = (int16_t) _digit;

	size = sizeof(digit) * 8;
	for(int i = size - 1 ; i > -1 ; i--)
    	{
        	line.push_back((digit >> i) & 1);
    	}
}

const void led_line::print_binary()
{
	vector<bool>::iterator it;
	for(it = line.begin(); it != line.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
