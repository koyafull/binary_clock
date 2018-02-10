#include <ctime>
#include <iostream>
#include <unistd.h>	// for usleep()
#include <stdlib.h>
#include <signal.h>
#include <utility>	// pair
#include <map>

#include "../headers/led_panel.h"

using namespace std;

int ctoi(char c)
{
	return c - '0';		// ASCII trick to turn a single char digit to an int digit
}

void sigint_handler(int signum)
{
	cout << endl << endl << "          ==================== SIGINT CAUGHT ====================" << endl << "                                   exiting" << endl << endl;
	throw 20;		// to call destructor and close properly, we need to exit from main(), so we forward
}

int main() {
	try
	{

		map<pair<int, int>, int> gpio_panel;
		gpio_panel[make_pair(6,0)] = 4;
		gpio_panel[make_pair(7,0)] = 17;
		gpio_panel[make_pair(4,1)] = 14;
		gpio_panel[make_pair(5,1)] = 15;
		gpio_panel[make_pair(6,1)] = 27;
		gpio_panel[make_pair(7,1)] = 22;
		gpio_panel[make_pair(5,2)] = 18;
		gpio_panel[make_pair(6,2)] = 10;
		gpio_panel[make_pair(7,2)] = 9;
		gpio_panel[make_pair(4,3)] = 25;
		gpio_panel[make_pair(5,3)] = 8;
		gpio_panel[make_pair(6,3)] = 11;
		gpio_panel[make_pair(7,3)] = 5;
		gpio_panel[make_pair(5,4)] = 1;
		gpio_panel[make_pair(6,4)] = 6;
		gpio_panel[make_pair(7,4)] = 13;
		gpio_panel[make_pair(4,5)] = 16;
		gpio_panel[make_pair(5,5)] = 21;
		gpio_panel[make_pair(6,5)] = 19;
		gpio_panel[make_pair(7,5)] = 26;

		signal(SIGINT, sigint_handler);

		time_t rawtime;
		struct tm * timeinfo;
		char buffer[10];
		time(&rawtime);
		timeinfo= localtime(&rawtime);

		led_panel current_panel = led_panel(gpio_panel, ctoi(buffer[0]), ctoi(buffer[1]), ctoi(buffer[3]), ctoi(buffer[4]), ctoi(buffer[6]), ctoi(buffer[7]));

		while(1)
		{
			time(&rawtime);
			timeinfo = localtime(&rawtime);

			strftime(buffer, 10, "%H:%M:%S", timeinfo);
			cout << buffer << endl;
	//		for(int i = 0 ; i < 10 ; i++)
	//		{
	//			cout << i << "-" << ctoi(buffer[i]) << endl;
	//		}
	//		cout << endl;

			current_panel.set_led_panel(ctoi(buffer[0]), ctoi(buffer[1]), ctoi(buffer[3]), ctoi(buffer[4]), ctoi(buffer[6]), ctoi(buffer[7]));
//			current_panel.set_led_panel(0,0,0,4,0,0);
			current_panel.print_binary_clock();
			current_panel.print_gpio();
			usleep(1000000);
		}
	}
	catch(int e)
	{
		if(e == 20)
		{
			exit(0);
		}
	}
}
