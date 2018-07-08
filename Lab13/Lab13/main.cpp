//#include "Task1.h"
#include "Mammal.h"
#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
#include "GuineaPig.h"

int main(void)
{
	//Base* ptr = new Base;
	//ptr->testFunction();         // prints "Base class"
	//delete ptr;
	//ptr = new Derived;
	//ptr->testFunction();         // prints "Base class" because the base class function is not virtual
	//delete ptr;

	//Mammal *pDog = new Dog;

	//pDog->Move();
	//pDog->Speak();

	/*Dog *pDog2 = new Dog;

	pDog2->Move();
	pDog2->Speak();*/

	Mammal* theArray[5];
	Mammal* ptr;

	int choice, i;

	for (i = 0; i<5; i++)
	{
		cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
		cin >> choice;

		switch (choice)
		{
		case 1: ptr = new Dog;
			break;
		case 2: ptr = new Cat;
			break;
		case 3: ptr = new Horse;
			break;
		case 4: ptr = new GuineaPig;
			break;
		default: ptr = new Mammal;
			break;
		}
		theArray[i] = ptr;
	}

	for (i = 0; i<5; i++)
		theArray[i]->Speak();

	return 0;
}