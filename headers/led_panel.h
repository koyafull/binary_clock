//////////////////////////////////////////////////////////////////////////
//									//
//	led_panel object represents the whole clock as a vector of	//
//	led_lines. It also provides the link between the computer 	//
//	reprsentation (as a vector of vector of bool) and the human	//
//	visualization through the led, controlled by the GPIOs.		//
//									//
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdint.h>
#include <unistd.h>	// usleep()
#include <vector>
#include <map>
#include <string>

#include "common.h"
#include "led_line.h"
#include "GPIO.h"

class led_panel
{
	private:
	std::vector<led_line> panel;
	std::map<pair<int, int>, int> gpio_panel;

	public:
	led_panel(map<pair<int, int>, int>, char*);
	~led_panel();
	void set_led_panel(char*);
	const void print_binary();
	const void print_binary_clock();
	const void print_gpio();
};

// TODO: use explicit function names: print_binary -> to_string, print_gpio -> switch_led like
// TODO: remove one of the useless to_string
