#include <iostream>
#include <ctime>
#include <stdint.h>
#include <vector>

class led_panel
{
	private:
	tm* now;
	std::vector<std::vector<int> > mat;

	void time_to_mat();

	public:
	led_panel(tm*);
	bool * int_to_binary(const int16_t, const int);
};
