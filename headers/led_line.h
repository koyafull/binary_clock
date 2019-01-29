//////////////////////////////////////////////////////////////////////////
//									//
//	led_line obecjt represents one digit among the 6 that are 	//
//	needed to form a standard hour format: HH:MM:SS. This digit is 	//
//	in its bit shape and is align vertically on the final binary 	//
//	clock. The number of maximum bits that you need to represent a  //
// 	digit is variable: for the tens of hours, the max is 2, so 2	//
//	leds are enough, for unit of seconds, the max is 9, so 4 leds 	//
//	are needed. Whatever, a led_line is considered as 8 bits long.	//
//									//
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdint.h>
#include <vector>

class led_line
{
	private:
	std::vector<bool> line;
	int size;

	public:

	/// constructor
	led_line(int);

	/// print to stdout a formal representation of the line. 
	/// Ex: 00000101
	const void print_binary();

	friend class led_panel;
};
