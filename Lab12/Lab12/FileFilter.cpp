#include "FileFilter.h"

FileFilter::FileFilter()
{
	mInfile.open("infile.txt");
	mOutfile.open("outfile.txt");
}

FileFilter::~FileFilter()
{
	if (mInfile.is_open())
	{
		mInfile.close();
	}

	if (mOutfile.is_open)
	{
		mOutfile.close();
	}
}

void FileFilter::doFilter(void)
{
	while (mInfile.eof())
	{
		char ch;
		mInfile >> ch;

		if (ch != '\n')
		{
			mOutfile << ch;
		}
	}
}
