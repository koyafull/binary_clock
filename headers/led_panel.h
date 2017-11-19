#include <iostream>
#include <stdint.h>
#include <vector>
#include <map>
#include <string>

#include "led_line.h"
#include "GPIO.h"

class led_panel
{
	private:
	std::vector<led_line> panel;
	std::map<pair<int, int>, int> gpio_panel;

	public:
	led_panel(int, int, int, int, int, int);
	~led_panel();
	const void print_binary();
	const void print_binary_clock();
	const void print_gpio();
};

