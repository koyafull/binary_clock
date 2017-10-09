#include <iostream>
#include <stdint.h>

class led_line
{
	private:
	int16_t digit;

	public:
	led_line(int);
	bool * int_to_binary();
	void print_binary(const bool *);
};
