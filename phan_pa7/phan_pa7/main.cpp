/*
Programmer: Kimi Phan

Class: Cpts 122, Spring 2016, Lab Section: 05

Programming Assignment: PA 7: Building Your Own Computer

Date: April 4, 2016

Date Last Modified: April 5, 2016

Description: In this assignment you will change the requirements of the “Build Your Own Computer” discussion to create a class 
		that will be the Simpletron. This class will encapsulate all of the operations of the Simpletron microcontroller. You 
		may also want to include some code for the Fatal Errors. This program will interpret instructions (called Simpletron 
		Machine Language (SML) instructions) and carry out the corresponding operation. For this program you must place your 
		SML instructions into a file and read each instruction from the file, instead of typing each instruction into the
		program every time the program starts up.
*/

#include "Simulator.h"

int main(void)
{
	Simulator myComp;

	myComp.runApp();

	return 0;
}