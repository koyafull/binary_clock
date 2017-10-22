#include <iostream>
#include <stdint.h>
#include <vector>

#include "led_line.h"

class led_panel
{
	private:
	std::vector<led_line> panel;

	public:
	led_panel(int, int, int, int, int, int);
	const void print_binary();
	const void print_binary_clock();
};

