#include "BSTApp.h"

/*
Date Created: March 21, 2016
Date Last Modified: March 22, 2016
Description: This is a constructor that opens up the MorseTable.txt and the Convert.txt
*/
BSTApp::BSTApp()
{
	mInputStream.open("MorseTable.txt", ios::in);
	mReadConvert.open("Convert.txt", ios::in);
}

/*
Date Created: March 21, 2016
Date Last Modified: March 22, 2016
Description: This is the destructor and it closes the files.
*/
BSTApp::~BSTApp()
{
	if (mInputStream.is_open())
	{
		mInputStream.close();
	}

	if (mReadConvert.is_open())
	{
		mReadConvert.close();
	}
}

/*
Date Created: March 21, 2016
Date Last Modified: March 22, 2016
Description: This runs the whole app.
*/
void BSTApp::runApp(void)
{
	if (mInputStream.is_open())
	{
		// reads info into the tree and it builds the tree
		mInputStream >> mTree;
		mTree.print();
	}

	if (mReadConvert.is_open())
	{
		char string[100];
		int i = 0;

		// This converts the message into morse code
		cout << "Message:" << endl;
		while(!mReadConvert.eof())
		{ 
			mReadConvert.getline(string, 100);

			while (string[i] != '\0')
			{
				if (string[i] == ' ')
				{
					cout << "  ";
					i++;
				}
				else
				{
					string[i] = toupper(string[i]);
					mTree.search(string[i]);
					i++;
				}
			}

			i = 0;
			cout << endl;
		}
	}
}
