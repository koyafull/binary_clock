#include <ctime>
#include <iostream>
#include <stdint.h>

#include "../headers/led_panel.h"
using namespace std;

int main() {
	time_t t = time(0);   // get time now
   	tm * now = localtime( & t );
//	cout << now->tm_year << endl;
	led_panel lp = led_panel(now);
	int16_t test(5);
	lp.int_to_binary(test,sizeof(test)*8);
}
