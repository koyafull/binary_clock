#include "../headers/led_panel.h"

using namespace std;

led_panel::led_panel(struct tm* _now)
{
	now = _now;
	time_to_mat();
}

bool * led_panel::int_to_binary(const int16_t n, const int size)
{
	bool * res = new bool[size];
	for(int i = size - 1 ; i > -1 ; i--)
    	{
        	*(res + size - 1 - i) = ((n>>i) & 1);
//		cout << ((n>>i) & 1) << " ";
    	}
	cout << endl;
	for(int i = 0 ; i < size ; i++)
	{
		cout << *(res + i) << " ";
	}

	return res;
}

void led_panel::time_to_mat()
{
	
}
