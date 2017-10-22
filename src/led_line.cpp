#include "../headers/led_line.h"

using namespace std;

led_line::led_line(int _digit)
{
	// cast to int16_t to reduce storage size
	int16_t digit = (int16_t) _digit;

	size = sizeof(digit) * 8;
	line = new bool[size];

	for(int i = size - 1 ; i > -1 ; i--)
    	{
        	*(line + size - 1 - i) = ((digit >> i) & 1);
    	}
}

const void led_line::print_binary()
{

	for(int i = 0 ; i < size ; i++)
	{
		cout << *(line + i) << " ";
	}
	cout << endl;
}
