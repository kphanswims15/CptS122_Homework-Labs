#pragma once

#include <iostream>

#include "Mammal.h"

using std::cout;
using std::endl;

class Dog : public Mammal
{
public:
	Dog(void);
	~Dog(void);
	void Move() const;
	void Speak() const;

protected:
	int itsAge;
};
