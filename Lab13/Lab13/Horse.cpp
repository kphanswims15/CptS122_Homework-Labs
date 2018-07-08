#include "Horse.h"

Horse::Horse(void):itsAge(1)
{
	cout << "Horse constructor..." << endl;
}

Horse::~Horse(void)
{
	cout << "Horse destructor..." << endl;
}

void Horse::Move() const
{
	cout << "Horse took a step!" << endl;
}

void Horse::Speak() const
{
	cout << "Neigh!" << endl;
}
