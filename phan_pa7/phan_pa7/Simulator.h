#pragma once

#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
#include <math.h>

#include "Simulator.h"

using std::cin;
using std::cout;
using std::endl;
using std::showpos;
using std::right;
using std::setfill;
using std::setw;
using std::internal;
using std::setiosflags;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

/*
Date Created: April 4, 2016
Date Last Modified: April 5, 2016
Description: This is a simulator class that runs and excutes the functions of a simulator
		for a computer.
*/
class Simulator
{
public:
	// constructor
	Simulator(int newAccumulator = 0, int newCounter = 0, int newOperation = 0, int newOperand = 0, int newRegister = 0);
	
	// functions
	void runApp();
	void loadMemory(ifstream & file);
	int fetch();
	void decode(int & num);
	void exceute();
	void read();
	void write();
	void load();
	void store();
	void add();
	void subtract();
	void divide();
	void multiply();
	void modulus();
	void exponention();
	void branch();
	void branchneg();
	void branchzero();
	void halt();
	void display();

private:
	int mAccumulator;
	int mCounter;
	int mOperation;
	int mOperand;
	int mRegister;
	int mInstruction[100] = { 0 };
	int mMemory[100] = { 0 };
};