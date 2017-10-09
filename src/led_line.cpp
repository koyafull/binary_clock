#include "../headers/led_line.h"

using namespace std;

led_line::led_line(int _digit)
{
	digit = (int16_t) _digit;
}

bool * led_line::int_to_binary()
{
	int size = sizeof(digit) * 8;
	bool * res = new bool[size];
	for(int i = size - 1 ; i > -1 ; i--)
    	{
        	*(res + size - 1 - i) = ((digit >> i) & 1);
    	}
	return res;
}

void led_line::print_binary(const bool * b)
{
	int size = sizeof(digit) * 8;
	for(int i = 0 ; i < size ; i++)
	{
		cout << *(b + i) << " ";
	}
	cout << endl;
}
