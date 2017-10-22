#include <ctime>
#include <iostream>
#include <stdint.h>

//#include "../headers/led_line.h"
#include "../headers/led_panel.h"

using namespace std;

int main() {
	time_t t = time(0);   // get time now
   	tm * now = localtime( & t );
//	cout << now->tm_year << endl;
//	int test(5);
//	led_line ll = led_line(test);
//	ll.print_binary();

	led_panel current_panel = led_panel(1, 2, 5, 1, 7, 4);
	cout << "print_binary" << endl;
	current_panel.print_binary();
	cout << endl << endl << "print_binary_clock" << endl;
	current_panel.print_binary_clock();
}
