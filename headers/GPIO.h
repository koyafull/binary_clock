#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class meta_GPIO {
	public:
	    virtual void setup(string x) = 0;
	    virtual int export_gpio() = 0;
	    virtual int unexport_gpio() = 0;
	    virtual int setdir_gpio(string dir) = 0;
	    virtual int setval_gpio(string val) = 0;
	    virtual int getval_gpio(string& val) = 0;
	    virtual string get_gpionum() = 0;
	private:
	    string gpionum;
};

class GPIO : public meta_GPIO {
	public:
	    GPIO();
	    GPIO(string x);
	    void setup(string x) override;
	    int export_gpio() override;
	    int unexport_gpio() override;
	    int setdir_gpio(string dir) override;
	    int setval_gpio(string val) override;
	    int getval_gpio(string& val) override;
	    string get_gpionum() override;
	private:
	    string gpionum;
};

class debug_GPIO : public meta_GPIO {
	public:
	    debug_GPIO();
	    debug_GPIO(string x);
	    void setup(string x) override;
	    int export_gpio() override;
	    int unexport_gpio() override;
	    int setdir_gpio(string dir) override;
	    int setval_gpio(string val) override;
	    int getval_gpio(string& val) override;
	    string get_gpionum() override;
	private:
	    string gpionum;
};
