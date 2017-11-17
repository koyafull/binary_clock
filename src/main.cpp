#include <ctime>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>

#include "../headers/led_panel.h"

using namespace std;

int ctoi(char c)
{
	return c - '0';
}

void sigint_handler(int signum)
{
	cout << endl << endl << "          ==================== SIGINT CAUGHT ====================" << endl << "                                   exiting" << endl << endl;
	exit(signum);
}

int main() {

	signal(SIGINT, sigint_handler);

	time_t rawtime;
   	struct tm * timeinfo;
	char buffer[10];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 10, "%H:%M:%S", timeinfo);
	cout << buffer << endl;
	for(int i = 0 ; i < 10 ; i++)
	{
		cout << i << "-" << ctoi(buffer[i]) << endl;
	}
	cout << endl;

//	int test(5);
//	led_line ll = led_line(test);
//	ll.print_binary();

	led_panel current_panel = led_panel(ctoi(buffer[0]), ctoi(buffer[1]), ctoi(buffer[3]), ctoi(buffer[4]), ctoi(buffer[6]), ctoi(buffer[7]));
//	cout << "print_binary" << endl;
//	current_panel.print_binary();
	cout << endl << endl << "print_binary_clock" << endl;
	current_panel.print_binary_clock();

	char a;
	cin >> a;
}
