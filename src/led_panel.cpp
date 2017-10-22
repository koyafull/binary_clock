#include "../headers/led_panel.h"

using namespace std;

led_panel::led_panel(int ht, int hu, int mint, int minu, int sect, int secu)
{
	this->panel.push_back(led_line(ht));
	this->panel.push_back(led_line(hu));
	this->panel.push_back(led_line(mint));
	this->panel.push_back(led_line(minu));
	this->panel.push_back(led_line(sect));
	this->panel.push_back(led_line(secu));
}

const void led_panel::print_binary()
{
	vector<led_line>::iterator it;
	for(it = this->panel.begin(); it != this->panel.end(); ++it)
	{
		(*it).print_binary();
		cout << endl;
	}
}

const void led_panel::print_binary_clock()
{
	vector<led_line>::iterator jt;
	for(int i = 0; i < 16; i++)
	{
		for(jt = this->panel.begin(); jt != this->panel.end(); ++jt)
		{
			cout << (*jt).line[i] << " ";
		}
		cout << endl;
	}
}

