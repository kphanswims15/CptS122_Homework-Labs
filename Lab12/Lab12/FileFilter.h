#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

class FileFilter
{
public:
	FileFilter();
	~FileFilter();

	virtual char transfrom(char ch) = 0;
	void doFilter(void);

private:
	ifstream mInfile;
	ofstream mOutfile;
};
