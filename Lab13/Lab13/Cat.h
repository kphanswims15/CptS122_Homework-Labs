#pragma once

#include <iostream>

#include "Mammal.h"

using std::cout;
using std::endl;

class Cat : public Mammal
{
public:
	Cat(void);
	~Cat(void);
	void Move() const;
	void Speak() const;

protected:
	int itsAge;
};
