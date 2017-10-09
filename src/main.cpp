#include <ctime>
#include <iostream>
#include <stdint.h>

#include "../headers/led_line.h"
using namespace std;

int main() {
	time_t t = time(0);   // get time now
   	tm * now = localtime( & t );
//	cout << now->tm_year << endl;
	led_line lp = led_line(now);
	int16_t test(5);
	int test_size = sizeof(test) * 8;
	lp.print_binary(lp.int_to_binary(test,test_size), test_size);
}
