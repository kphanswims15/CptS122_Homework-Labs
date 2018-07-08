#include "Simulator.h"

/*
Date Created: April 4, 2016
Description: This is a constructor and sets all the default values to zero.
*/
Simulator::Simulator(int newAccumulator, int newCounter, int newOperation, int newOperand, int newRegister)
{
	mAccumulator = newAccumulator;
	mCounter = newCounter;
	mOperation = newOperation;
	mOperand = newOperand;
	mRegister = newRegister;
}

/*
Date Created: April 4, 2016
Description: This function runs the whole program.
Precondition: Other functions are established in order for this to run.
*/
void Simulator::runApp()
{
	ifstream file;

	cout << "Please enter the file you want to read: ";
	string name;
	cin >> name;
	system("cls");

	if (name == "Example1.sml")
	{
		file.open("Example1.sml");
	}
	else if (name == "Example2.sml")
	{
		file.open("Example2.sml");
	}
	else
	{
		cout << "There is no file by that name." << endl;
	}

	loadMemory(file);
	file.close();

	while (mOperation != 43)
	{
		display();

		mRegister = fetch();
		decode(mRegister);
		exceute();

		system("pause");
		system("cls");

		mCounter++;
	}
}

/*
Date Created: April 4, 2016
Description: This function loads the instructions from the .sml file into an array.
Precondtion: There has to be an array data member that can read in the instructions and
		it has to be initialized to zero.
*/
void Simulator::loadMemory(ifstream & file)
{
	int num = 0;

	while (!file.eof())
	{
		file >> mInstruction[num];
		num++;
	}
}

/*
Date Created: April 4, 2016
Description: This gets the value at this position in the array.
Precondition: There had to be a data member that is a counter and an array that has all the
		instructions.
*/
int Simulator::fetch()
{
	return mInstruction[mCounter];
}

/*
Date Created: April 4, 2016
Description: This decodes the number that is read in from the array.
Precondition: An operation and operand variables have to be established.
*/
void Simulator::decode(int & num)
{
	mOperation = num / 1000;
	mOperand = num % 100; 
}

/*
Date Created: April 4, 2016
Date Last Modified: April 5, 2016
Description: This excutes the certain functions depending on the operation code that is passed in.
Precondition: The instruction number has to be decoded first.
*/
void Simulator::exceute()
{
	switch (mOperation)
	{
	// input/output operations
	case 10: // read-read a word from the keyboard into a specific location in memory
		read();
		break;
	case 11: // write-write a word from a specific loaction in memory to the screen
		write();
		break;
	// Load and store operations 
	case 20: // Load-load a word from a specific location in memory into the accumulator
		load();
		break;
	case 21: // Store-Store a word from the accumulator into a specific location in memory
		store();
		break;
	// Arithmetic operations
	case 30: // add-add a word from a specific location in memory tothe word in the accumulator 
			 // (leave result in accumulator)
		add();
		break;
	case 31: // subtract-subtract a word from a specific location in memory from the word in the
			 // accumlator (leave result in accumulator)
		subtract();
		break;
	case 32: // divide-divide a word from a specific location in memory into the word in the accumulator
			 // (leave the result in accumulator)
		divide();
		break;
	case 33: // multiply-multiply a word from a specific location in memory by the word in the accumulator
			 // (leave result in accumulator)
		multiply();
		break;
	case 34: // modulus-mods a word from a specific loaction in memory into the word in the accumulator
			 // (leave result in accumulator)
		modulus();
		break;
	case 35: // exponentiation-exponentiation a word from a specific loaction in memory by the word in the accumulator
			 // (leave result in accumulator)
		exponention();
		break;
	// Transfer-of-control operations
	case 40: // Branch-Branch to a specific location in memory
		branch();
		break;
	case 41: // branchneg-branch to a specific location in memory if the accumulator is negative
		branchneg();
		break;
	case 42: // branchzero-branch to a specific location in memory if the accumulator is zero
		branchzero();
		break;
	case 43: // halt-the program has completed its task
		halt();
		break;
	default: // if there is no operation for this it would stop the program
		cout << "*** Attempt to excute in valid code ***" << endl;
		cout << "*** Simpletron execution abnormally terminated ***" << endl;
		mOperation = 43;
		break;
	}
}

/*
Date Created: April 4, 2016
Description: Read a word from the keyboard into a specific location in memory
Precondition: The memory array has to be available.
*/
void Simulator::read()
{
	cout << "Enter in a number >> ";
	cin >> mMemory[mOperand];
}

/*
Date Created: April 4, 2016
Description: Write a word from a specific loaction in memory to the screen
Precondition: The memory array has to be available.
*/
void Simulator::write()
{
	cout << "Output << " << setw(6) << setfill('0') << showpos << internal << mMemory[mOperand] << endl;
}

/*
Date Created: April 4, 2016
Description: Store a word from the accumulator into a specific location in memory.
Precondition: The memory array has to be available.
*/
void Simulator::load()
{
	mAccumulator = mMemory[mOperand];
}

/*
Date Created: April 4, 2016
Description: Store a word from the accumulator into a specific location in memory.
Precondition: The memory array has to be available.
*/
void Simulator::store()
{
	mMemory[mOperand] = mAccumulator;
}

/*
Date Created: April 4, 2016
Date Last Modified: April 5, 2016
Description: add a word from a specific location in memory tothe word in the accumulator (leave result in accumulator)
Precondition: The memory array has to be available.
*/
void Simulator::add()
{
	mAccumulator += mMemory[mOperand];

	if (mAccumulator < -99999 || mAccumulator > 99999)
	{
		cout << "*** Accumulator overflowed ***" << endl;
		cout << "*** Simpletron execution abnormally terminated ***" << endl;
		mOperation = 43;
	}
}

/*
Date Created: April 4, 2016
Date Last Modified: April 5, 2016
Description: subtract a word from a specific location in memory from the word in theaccumlator (leave result in accumulator)
Precondition: The memory array has to be available.
*/
void Simulator::subtract()
{
	mAccumulator = mAccumulator - mMemory[mOperand];

	if (mAccumulator < -99999 || mAccumulator > 99999)
	{
		cout << "*** Accumulator overflowed ***" << endl;
		cout << "*** Simpletron execution abnormally terminated ***" << endl;
		mOperation = 43;
	}
}

/*
Date Created: April 4, 2016
Description: divide a word from a specific location in memory into the word in the accumulator (leave the result in accumulator)
Precondition: The memory array has to be available.
*/
void Simulator::divide()
{
	if (mMemory[mOperand] == 0)
	{
		cout << "*** Attempt to divide my zero ***" << endl;
		cout << "*** Simpletron excution abnormally terminated ***" << endl;
		mOperation = 43;
	}
	else
	{
		mAccumulator = mAccumulator / mMemory[mOperand];

		if (mAccumulator < -99999 || mAccumulator > 99999)
		{
			cout << "*** Accumulator overflowed ***" << endl;
			cout << "*** Simpletron execution abnormally terminated ***" << endl;
			mOperation = 43;
		}
	}
}

/*
Date Created: April 4, 2016
Description: multiply a word from a specific location location in memory by the word in the accumulator (leave result in accumulator)
Precondition: The memory array has to be available.
*/
void Simulator::multiply()
{
	mAccumulator = mAccumulator * mMemory[mOperand];

	if (mAccumulator < -99999 || mAccumulator > 99999)
	{
		cout << "*** Accumulator overflowed ***" << endl;
		cout << "*** Simpletron execution abnormally terminated ***" << endl;
		mOperation = 43;
	}
}

/*
Date Created: April 5, 2016
Description: mods a word from a specific loaction in memory into the word in the accumulator (leave result in accumulator)
Precondition: The memory array has to be available.
*/
void Simulator::modulus()
{
	if (mMemory[mOperand] == 0)
	{
		cout << "*** Attempt to divide my zero ***" << endl;
		cout << "*** Simpletron excution abnormally terminated ***" << endl;
		mOperation = 43;
	}
	else
	{
		mAccumulator = mAccumulator % mMemory[mOperand];

		if (mAccumulator < -99999 || mAccumulator > 99999)
		{
			cout << "*** Accumulator overflowed ***" << endl;
			cout << "*** Simpletron execution abnormally terminated ***" << endl;
			mOperation = 43;
		}
	}
}

/*
Date Created: April 5, 2016
Description: exponentiation a word from a specific loaction in memory by the word in the accumulator (leave result in accumulator)
Precondition: The memory array has to be available.
*/
void Simulator::exponention()
{
	mAccumulator = pow(mAccumulator, mMemory[mOperand]);

	if (mAccumulator < -99999 || mAccumulator > 99999)
	{
		cout << "*** Accumulator overflowed ***" << endl;
		cout << "*** Simpletron execution abnormally terminated ***" << endl;
		mOperation = 43;
	}
}

/*
Date Created: April 5, 2016
Description: Branch to a specific location in memory
*/
void Simulator::branch()
{
	mCounter = mOperand - 1;
}

/*
Date Created: April 5, 2016
Description: branch to a specific location in memory if the accumulator is negative
*/
void Simulator::branchneg()
{
	if (mAccumulator < 0)
	{
		mCounter = mOperand - 1;
	}
}

/*
Date Created: April 5, 2016
Description: branch to a specific location in memory if the accumulator is zero
*/
void Simulator::branchzero()
{
	if (mAccumulator == 0)
	{
		mCounter = mOperand -1;
	}
}

/*
Date Created: April 4, 2016
Description: Store a word from the accumulator into a specific location in memory.
Precondition: The memory array has to be available.
*/
void Simulator::halt()
{
	cout << "*** Simletron execution terminated ***" << endl;
}

/*
Date Created: April 4, 2016
Description: Displays the register actions.
Precondition: The memory array and other variables has to be available.
Reference: http://www.cplusplus.com/reference/ios/showpos/
		   http://www.cplusplus.com/reference/iomanip/
*/
void Simulator::display()
{
	cout << "REGISTERS: " << endl;
	cout << "accumulator";
	cout << "\t\t\t" << setw(6) << setfill('0') << showpos << internal << mAccumulator << endl;
	cout << "instructionCounter";
	cout << "\t\t" << setw(6) << setfill('0') << showpos << internal << mCounter << endl;
	cout << "instructionRegister";
	cout << "\t\t" << setw(6) << setfill('0') << showpos << internal << mRegister << endl;
	cout << "operationCode";
	cout << "\t\t\t" << setw(6) << setfill('0') << showpos << internal << mOperation << endl;
	cout << "operand";
	cout << "\t\t\t\t" << setw(6) << setfill('0') << showpos << internal << mOperand << endl << endl;

	cout << "INSTRUCTIONS:" << endl;

	int i = 0;

	// prints out instructions
	while (mInstruction[i] != 0)
	{
		cout<< showpos << mInstruction[i] << "   ";
		i++;
	}

	cout << endl << endl;

	cout << "MEMORY: " << endl;

	int j = 1, k = 0;

	// prints out the memory
	while (j <= 100)
	{
		cout << setw(6) << setfill('0') << showpos << internal << mMemory[j - 1] << "  ";
		
		// creates 10 rows and 10 colums
		if (j % 10 == 0)
		{
			cout << endl;
		}

		j++;
	}

	cout << endl;
}