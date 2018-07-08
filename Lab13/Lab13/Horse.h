#pragma once

#include <iostream>

#include "Mammal.h"

using std::cout;
using std::endl;

class Horse : public Mammal
{
public:
	Horse(void);
	~Horse(void);
	void Move() const;
	void Speak() const;

protected:
	int itsAge;
};
