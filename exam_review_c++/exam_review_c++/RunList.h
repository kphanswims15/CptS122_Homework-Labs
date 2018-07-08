#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "List.h"

using std::cin;
using std::cout;
using std::ostream;
using std::fstream;

class RunList
{
public:
	void runApp();

private:
	List mList;
};

ostream & operator<< (ostream & output, const List & rhs);