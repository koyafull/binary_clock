#include "../headers/led_panel.h"

using namespace std;

led_panel::led_panel(map<pair<int, int>, int> _gpio_panel, int ht, int hu, int mint, int minu, int sect, int secu)
{
	this->set_led_panel(ht, hu, mint, minu, sect, secu);
	this->gpio_panel = _gpio_panel;

	map<pair<int, int>, int>::iterator it;
	for(it = gpio_panel.begin(); it != gpio_panel.end(); it++)
	{
		GPIO g(to_string(it->second));
		cout << "exporting " << it->second << endl;
		g.export_gpio();
		usleep(100000);		// otherwise folders are not created before next step
		g.setdir_gpio("out");
	}
}

led_panel::~led_panel()
{
	map<pair<int, int>, int>::iterator it;
	for(it = gpio_panel.begin(); it != gpio_panel.end(); it++)
	{
		if(it->second != 0)
		{
			GPIO g(to_string(it->second));
			cout << "unexporting " << it->second << endl;
			g.setval_gpio("0");
			usleep(100000);		// make sure the value has had the time to be written
			g.unexport_gpio();
		}
	}
}

void led_panel::set_led_panel(int ht, int hu, int mint, int minu, int sect, int secu)
{
	this->panel.clear();

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
{
//	cout << endl << "PRINT GPIO" << endl;

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			try
			{
//				cout << this->panel.at(j).line.at(i) << " ";
//				cout << gpio_panel[make_pair(i,j)] << " ";
				int gpio_nb = gpio_panel[make_pair(i,j)];

				if(gpio_nb != 0)
				{
					string current_value = "";
					string& current_value_ref = current_value;

					GPIO g(to_string(gpio_nb));

					g.getval_gpio(current_value_ref);
					string new_value = to_string(panel.at(j).line.at(i));

					if(current_value != new_value)
					g.setval_gpio(new_value);
				}
//				cout << this->panel.at(j).line.at(i) << " ";
			}
			catch(int e)
			{
				continue;
			}
		}
//		cout << endl;
	}
}
