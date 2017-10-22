#include <ctime>
#include <iostream>
#include <stdint.h>

#include "../headers/led_line.h"
using namespace std;

int main() {
	time_t t = time(0);   // get time now
   	tm * now = localtime( & t );
//	cout << now->tm_year << endl;
	int test(5);
	led_line ll = led_line(test);
	ll.print_binary();
}
