#include "StudentList.h"

/*
Date Created: March 6, 2016
Description: This is the default constructor and it will always set mpHead to NULL
or nullptr.
*/
StudentList::StudentList()
{
	mpHead = nullptr;
}

/*
Date Created: March 6, 2016
Description: This is the copy constructor. It is invoked copying a List object during construction of
another List object, or when a List object is passed-by-value. It preforms a deep copy which
means it creates new memory for each copied node.
*/
StudentList::StudentList(const StudentList &copyList)
{
	this->mpHead = copyList.mpHead;
}

/*
Date Created: March 6, 2016
Description: This is a destructor and it is invoked when the object leaves scope.
*/
StudentList::~StudentList()
{
	destroyStudentList();
}

/*
Date Created: March 6, 2016
Description: This is a getter and it returns a copy of the address stored in mpHead
*/
StudentNode * StudentList::getHeadPtr() const
{
	return mpHead;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it modifies mpHead.
*/
void StudentList::setHeadPtr(StudentNode * const pNewHead)
{
	mpHead = pNewHead;
}

/*
Date Created: March 6, 2016
Description: This will insert each node at the front.
*/
bool StudentList::insertAtFront(const int newRecordNumber, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel, const int newNumberOfDates, const vector<string> newAbsenceDates)
{
	bool success = false;

	StudentNode *insertMe = new StudentNode(newRecordNumber, newID, newName, newEmail, newUnits, newProgram, newLevel, newNumberOfDates, newAbsenceDates);
	StudentNode *pCur = mpHead;

	if (insertMe != nullptr)
	{
		success = true; // allocated memory successfully
						// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		insertMe->setNextPtr(mpHead);
		mpHead = insertMe;
		success = true;
	}
	return success;
}

/*
Date Created: March 6, 2016
Description: Determines if the list is empty and it returns true if the list is empty and
false otherwise.
*/
bool StudentList::isEmpty()
{
	return (mpHead == nullptr);
}

/*
Date Created: March 28, 2016
Description: Takes attendance for each student.
*/
void StudentList::takeAttendance()
{
	if (!isEmpty())
	{
		time_t now = time(0);
		tm *local = localtime(&now);

		StudentNode *pCur = mpHead;
		char input = '\0';
		string date = to_string(1 + local->tm_mon) + "-" + to_string(local->tm_mday) + "-" + to_string(1900 + local->tm_year);
		
		cout << "Date: " << date << endl << endl;

		//goes through the list 
		while (pCur != nullptr)
		{
			do
			{
				cout << "Is " << pCur->getName() << " absent? (y/n) ";
				cin >> input;

				if (input == 'y')
				{
					// add number of absences
					pCur->setNumberOfAbsences(pCur->getNumberOfAbsences() + 1);
					// add date
					pCur->setAbsenceDates(date, -1);
				}
			} while (input != 'y' && input != 'n');

			pCur = pCur->getNextPtr();
		}
	}
	else
	{
		cout << "The list is empty." << endl;
	}
}

//////////Private functions//////////

/*
Date Created: March 6, 2016
Description: allocates memory for a Listnode and it initializes the memory with the new data.
*/
StudentNode * StudentList::makeNode(const int newRecordNumber, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel)
{
	StudentNode *pMem = new StudentNode(newRecordNumber, newID, newName, newEmail, newUnits, newProgram, newLevel);

	return pMem;
}

/*
Date Created: March 6, 2016
Description: This is created so that we can use recursion to delete the nodes.
*/
void StudentList::destroyStudentListHelper(StudentNode * const pMem)
{
	if (pMem != nullptr)
	{
		destroyStudentListHelper(pMem->getNextPtr());
		delete pMem; //delete from the back of list to the front
	}
}

/*
Date Created: March 6, 2016
Description: Deletes each node to free memory.
*/
void StudentList::destroyStudentList()
{
	destroyStudentListHelper(mpHead);
}

