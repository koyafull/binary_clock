#include <iostream>
#include <stdint.h>
#include <vector>

class led_line
{
	private:
	std::vector<bool> line;
	int size;

	public:
	led_line(int);
	const void print_binary();

	friend class led_panel;
};
