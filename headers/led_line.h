#include <iostream>
#include <ctime>
#include <stdint.h>
#include <vector>

class led_line
{
	private:
	tm* now;
	std::vector<std::vector<int> > mat;

	void time_to_mat();

	public:
	led_line(tm*);
	bool * int_to_binary(const int16_t, const int);
	void print_binary(const bool *, const int);
};
