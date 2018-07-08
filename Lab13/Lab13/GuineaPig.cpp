#include "GuineaPig.h"

GuineaPig::GuineaPig(void)
{
	cout << "GuineaPig constructor..." << endl;
}

GuineaPig::~GuineaPig(void)
{
	cout << "GuineaPig destructor..." << endl;
}

void GuineaPig::Move() const
{
	cout << "GuineaPig took a step!" << endl;
}

void GuineaPig::Speak() const
{
	cout << "Weep weep!" << endl;
}
