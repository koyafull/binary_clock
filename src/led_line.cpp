#include "../headers/led_line.h"

using namespace std;

led_line::led_line(struct tm* _now)
{
	now = _now;
	time_to_mat();
}

bool * led_line::int_to_binary(const int16_t n, const int size)
{
	bool * res = new bool[size];
	for(int i = size - 1 ; i > -1 ; i--)
    	{
        	*(res + size - 1 - i) = ((n>>i) & 1);
    	}
	return res;
}

void led_line::print_binary(const bool * b, const int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		cout << *(b + i) << " ";
	}
	cout << endl;
}

void led_line::time_to_mat()
{
	
}
