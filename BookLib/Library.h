#pragma once
#include<string>
#include"CBook.h"
#include<set>


using namespace std;

struct Comp
{
	bool operator()(const CBook book1, const CBook book2)
	{
		return book1.GetLsbn() < book2.GetLsbn();
	}
};

class Library
{
public:

	Library() {}
	~Library() {}

	bool ShowLibraryData(string file_loc = "book.txt");
	bool DeleteBook(string lsbn);
	bool AddBook(CBook book);

private:
	bool WriteDataToFile(char * file_loc = "book.txt");
	bool GetDataFromFile(string file_loc = "book.txt");
	set<CBook,Comp> _library;
};