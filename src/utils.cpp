#include "../headers/utils.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>

using namespace std;

int ctoi(char c)
/// converts a char <c> to an int
{
	return c - '0';		// ASCII trick to turn a single char digit to an int digit
}

const std::string get_exec_path()
{
	int pid = getpid();
	string path = "/proc/" + to_string(pid) + "/exe";
	char buf[100];
	size_t path_length = readlink(path.c_str(), buf, sizeof(buf)-1);
	buf[path_length] = 0;
	string buf_string = string(buf);
	return buf_string.substr(0, buf_string.find_last_of("\\/"));
}

void set_time_buffer(char* time_buffer)
{
	/// time management
	/// creates time structure
	time_t rawtime;
	time(&rawtime);						// gets current time
	struct tm* timeinfo;
	timeinfo = localtime(&rawtime);		// converts it to friendly object

	strftime(time_buffer, 10, "%H:%M:%S", timeinfo);	// fills buffer with specific format
	cout << time_buffer << endl;
	// cout << "time_buffer after loading: " << time_buffer << endl;
}

