#pragma once

#include <iostream>

#include "Mammal.h"

using std::cout;
using std::endl;

class GuineaPig : public Mammal
{
public:
	GuineaPig(void);
	~GuineaPig(void);
	void Move() const;
	void Speak() const;

protected:
	int itsAge;
};