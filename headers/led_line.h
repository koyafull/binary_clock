#include <iostream>
#include <ctime>
#include <stdint.h>

class led_line
{
	public:
	int16_t digit;

	led_line(int);
	bool * int_to_binary();
	void print_binary(const bool *);
};
