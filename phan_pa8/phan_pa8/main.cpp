/*
Programmer: Kimi Phan

Class: Cpts 122, Spring 2016, Lab Section: 05

Programming Assignment: PA 6: Morse Code Lookup BST

Date: April 22, 2016

Date Last Modified: April 23, 2016

Description: For this assignment you are implementing a system for detecting trends in consumer products over a 48 hour period. 
		We are interested in knowing which products are purchased and sold, the least and most, by various retail stores throughout 
		the United States. When a product is tagged as purchased it indicates that a certain retail store bought units of the product 
		from a supplier. When a product is tagged as sold it indicates that a certain retail store sold that many units of a product. 
		Your system must read product data from a .csv file, and store the data in a way that inserts data in better than linear time 
		(O(n)) in most cases. Since, a binary search tree (BST) is a reasonably efficient data structure for inserting and searching 
		data (O (log n) for balanced trees), you must create two BSTs; one tree represents the products that were sold and the other 
		tree represents the products that were bought. The system must leverage the organization of the trees to display, which products 
		were least bought and sold, and which were most bought and sold for that 48 hour period. Your system is only required to output 
		the following to the screen:

		-The contents of the two BSTs, which will be printed in order
		-The product that type and number of units that sold the most
		-The product that type and number of units that sold the least
		-The product that type and number of units that were purchased the most
		-The product that type and number of units that were purchased the least
*/

#include "DataAnalysis.h"

int main(void)
{
	DataAnalysis obj;

	obj.runAnalysis();

	return 0;
}