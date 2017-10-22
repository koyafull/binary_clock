#include <iostream>
#include <stdint.h>

class led_line
{
	private:
	bool * line;
	int size;

	public:
	led_line(int);
	const void print_binary();

	friend class led_panel;
};
