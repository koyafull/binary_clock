//////////////////////////////////////////////////////////////////////////
//									//
//	main method that basically:					//
//		* instanciates the program environment, such as signal	//
//		interpretation, environment variables and GPIO settings	//
//		* runs a infinite loop that transform uptime syscall to	//
//		shinning leds						//
//									//
//	Handles the SINGINT (15) signal to exit gracefully.		//
//									//
//////////////////////////////////////////////////////////////////////////
//#define DEBUG
#include <ctime>
#include <iostream>
#include <unistd.h>	// usleep()
#include <stdlib.h>
#include <signal.h>
#include <utility>	// pair<T, T>
#include <map>
#include <unistd.h>
#include <string.h>
#include <regex>

#include "./utils.cpp"
#include "../headers/common.h"
#include "../headers/led_panel.h"


using namespace std;

#ifdef DEBUG_MODE
	const bool _DEBUG = true;
#else
	const bool _DEBUG = false;
#endif

const char* USAGE_STRING = 
	"Usage:	binary_clock COMMAND\
	\n\nwhere COMMAND is either of the following:\
	\nshutup\t\tturn off every led\
	\nwakeup\t\tturn on every led\
	\nTIME\t\trespecting HH:MM:SS format";

int arg_parser(int argc, char* argv[]) 
{
	int i = 0;
	cout << "READING " << argc << " ARGUMENTS" << endl;
	for(i = 0 ; i < argc ; i++)
	{
		cout << i << ": " << argv[i] << endl;
	}

	if(argc == 1) return 0;

	if(argc == 2)
	{
		int response(0);
		if(strcmp(argv[1], "shutup") == 0) return 1;
		else if(strcmp(argv[1], "wakeup") == 0) return 2;
		else if(regex_match(argv[1], regex("^(?:[01]\\d|2[0123]):(?:[012345]\\d):(?:[012345]\\d)$"))) return 3;
	}

	cout << USAGE_STRING << endl;
	exit(1);
}

void sigint_handler(int signum)
/// signal handler: defines the beavior of signal <sigmun> catching
// param:
//  signum: number of signal to have behavior redefined
{
	cout << endl << endl << "          ==================== SIGINT CAUGHT ====================" << endl << "                                   exiting" << endl << endl;
	throw 20;		// to call led_panel destructor and close properly, we need to exit from main(), so we forward
}

void update_gpio(led_panel* led_panel, char* time_buffer)
{
		/// led_panel management
	led_panel->set_led_panel(
		ctoi(time_buffer[0]), 
		ctoi(time_buffer[1]), 
		ctoi(time_buffer[3]), 
		ctoi(time_buffer[4]), 
		ctoi(time_buffer[6]), 
		ctoi(time_buffer[7])
	);
	led_panel->print_binary_clock();
	led_panel->print_gpio();
}

int main(int argc, char* argv[])
{
	const string EXEC_PATH = get_exec_path();
	cout << "EXEC PATH = " << EXEC_PATH << endl;
	int mode = arg_parser(argc, argv);
	int response(0);

	if(_DEBUG)
	{
		cout << "DEBUG MODE" << endl;
	}

	/// signal handling: redirects signal SINGINT (15) to sigint_handler. See signal for more information about signal and signal handling.
	signal(SIGINT, sigint_handler);

	try
	{
		/// environment variable creation
		map<pair<int, int>, int> gpio_panel;
		gpio_panel[make_pair(6,0)] = 14;
		gpio_panel[make_pair(7,0)] = 4;
		gpio_panel[make_pair(4,1)] = 15;
		gpio_panel[make_pair(5,1)] = 18;
		gpio_panel[make_pair(6,1)] = 17;
		gpio_panel[make_pair(7,1)] = 27;
		gpio_panel[make_pair(5,2)] = 24;
		gpio_panel[make_pair(6,2)] = 23;
		gpio_panel[make_pair(7,2)] = 22;
		gpio_panel[make_pair(4,3)] = 8;
		gpio_panel[make_pair(5,3)] = 25;
		gpio_panel[make_pair(6,3)] = 9;
		gpio_panel[make_pair(7,3)] = 10;
		gpio_panel[make_pair(5,4)] = 1;
		gpio_panel[make_pair(6,4)] = 7;
		gpio_panel[make_pair(7,4)] = 11;
		gpio_panel[make_pair(4,5)] = 16;
		gpio_panel[make_pair(5,5)] = 12;
		gpio_panel[make_pair(6,5)] = 6;
		gpio_panel[make_pair(7,5)] = 5;
		
		char time_buffer[10];
		set_time_buffer(time_buffer);

		led_panel current_panel = led_panel(
			gpio_panel, 
			ctoi(time_buffer[0]), 
			ctoi(time_buffer[1]), 
			ctoi(time_buffer[3]), 
			ctoi(time_buffer[4]), 
			ctoi(time_buffer[6]), 
			ctoi(time_buffer[7])
		);
	
		switch (mode)
		{
			case 0:
				while(1)
				{
					/// infinite loop
					set_time_buffer(time_buffer);
					update_gpio(&current_panel, time_buffer);
					usleep(1000000);
				}
				break;

			case 1:
				cout << "SHUTUP" << endl;
				response = system((EXEC_PATH + "/shutup.sh").c_str());
				cout << "RESPONSE: " << response << endl;
				exit(0);

			case 2:
				cout << "WAKEUP" << endl;
				response = system((EXEC_PATH + "/wakeup.sh").c_str());
				cout << "RESPONSE: " << response << endl;
				exit(0);

			case 3:
				cout << "FIXED TIME: " << argv[1] << endl;
				update_gpio(&current_panel, argv[1]);
				exit(0);
			
			default:
				exit(1);
		}

	}
	/// sigint graceful exiting
	catch(int e)
	{
		if(e == 20)
		{
			exit(0);
		}
	}
}
