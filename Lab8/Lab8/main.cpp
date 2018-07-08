#include "BST.h"

int main(void)
{
	BST tree;

	string cow = "cow";
	string cat = "cat";
	string dog = "dog";
	string moo = "moo";

	tree.insert(cow);
	tree.insert(dog);
	tree.insert(cat);
	tree.insert(moo);

	tree.inOrderTraversal();
	tree.preOrderTraversal();

	return 0;
}