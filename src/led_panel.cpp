#include "../headers/led_panel.h"
#include "../headers/common.h"
#include "../headers/utils.h"

using namespace std;

led_panel::led_panel(map<pair<int, int>, int> _gpio_panel, char* _time_buffer)
/// instanciates the object and decalres the GPIO on the Raspberry Pi
// params:
//  _gpio_panel: mapping between led position on the clock and GPIO number for wiring
//  ht: tens of hours
//  hu: units of hours
//  mint: tens of minutes
//  minu: units of minutes
//  sect: tens of seconds
//  secu: units of seconds
{
	/// instanciates led_lines
	this->set_led_panel(_time_buffer);
	this->gpio_panel = _gpio_panel;

	/// declares GPIO on the Raspberry Pi
	map<pair<int, int>, int>::iterator it;
	for(it = gpio_panel.begin(); it != gpio_panel.end(); it++)
	{
		meta_GPIO* g;
		if(!_DEBUG){
			g = new GPIO(to_string(it->second));
		}
		else {
			g = new debug_GPIO(to_string(it->second));
		}
		cout << "exporting " << it->second << endl;
		g->export_gpio();
		usleep(100000);		// waits for folders to be created before using it
		g->setdir_gpio("out");
	}
}

led_panel::~led_panel()
/// destructs the led_panel gracefully by freeing GPIO from the Raspberry Pi
{
	cout << "IAM THE DESTRUCTOR OF WORLD" << endl;
	map<pair<int, int>, int>::iterator it;
	for(it = gpio_panel.begin(); it != gpio_panel.end(); it++)
	{
		if(it->second != 0)
		{
			meta_GPIO* g;
			if(!_DEBUG){
				g = new GPIO(to_string(it->second));
			}
			else {
				g = new debug_GPIO(to_string(it->second));
			}
			cout << "unexporting " << it->second << endl;
			g->setval_gpio("0");
			usleep(100000);		// makes sure the value has had the time to be written
			g->unexport_gpio();
		}
	}
}

void led_panel::set_led_panel(char* time_buffer)
/// declares let_line one by one
// params:
//  ht: tens of hours
//  hu: units of hours
//  mint: tens of minutes
//  minu: units of minutes
//  sect: tens of seconds
//  secu: units of seconds
{
	this->panel.clear();

	this->panel.push_back(led_line(ctoi(time_buffer[0])));
	this->panel.push_back(led_line(ctoi(time_buffer[1])));
	this->panel.push_back(led_line(ctoi(time_buffer[3])));
	this->panel.push_back(led_line(ctoi(time_buffer[4])));
	this->panel.push_back(led_line(ctoi(time_buffer[6])));
	this->panel.push_back(led_line(ctoi(time_buffer[7])));

	this->print_binary_clock();
	this->print_gpio();
}

const void led_panel::print_binary()
/// prints to stdout using led_line::print_binary()
{
	vector<led_line>::iterator it;
	for(it = this->panel.begin(); it != this->panel.end(); ++it)
	{
		(*it).print_binary();
		cout << endl;
	}
}

const void led_panel::print_binary_clock()
/// prints to stdout same as led_panel::print_binary(), explicit version
{
	vector<led_line>::iterator jt;
	for(int i = 0; i < 8; i++)
	{
		for(jt = this->panel.begin(); jt != this->panel.end(); ++jt)
		{
			cout << (*jt).line[i] << " ";
		}
		cout << endl;
	}
}

const void led_panel::print_gpio()
/// prints to the GPIO, meaning makes leds turn on and off
// TODO: makes browsing coherent with structure (currently using bare browsing)
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			try
			{
				int gpio_nb = gpio_panel[make_pair(i,j)];

				if(gpio_nb != 0)
				{
					string current_value = "";
					string& current_value_ref = current_value;

					meta_GPIO* g;
					if(!_DEBUG){
						g = new GPIO(to_string(gpio_nb));
					}
					else {
						g = new debug_GPIO(to_string(gpio_nb));
					}

					g->getval_gpio(current_value_ref);
					string new_value = to_string(panel.at(j).line.at(i));

					if(current_value != new_value)	// avoids blinking
					g->setval_gpio(new_value);
				}
			}
			catch(int e)
			{
				continue;
			}
		}
	}
}
