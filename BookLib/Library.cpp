#include"Library.h"
#include<fstream>
#include<iostream>
using namespace std;

bool Library::AddBook(CBook book)
{
	GetDataFromFile();
	_library.insert(book);
	WriteBookToData();
	return true;
}
bool Library::GetDataFromFile(string file_loc)
{
	CBook book;
	string name;
	string lsbn;
	string price;
	string author;

	ifstream ifile;
	ifile.open(file_loc);
	while (!ifile.eof())
	{
		ifile >> name;
		ifile >> lsbn;
		ifile >> price;
		ifile >> author;

		book.SetName(name);
		book.SetLsbn(lsbn);
		book.SetPrice(price);
		book.SetAuthor(author);

		_library.insert(book);
	}
	ifile.close();
	return true;
}
bool Library::ShowLibraryData(string file_loc) 
{
	GetDataFromFile(file_loc);
	for (set<CBook,Comp>::const_iterator it = _library.begin();it != _library.end();it++)
	{
		cout << (*it).GetName() << ' ';
		cout << (*it).GetLsbn() << ' ';
		cout << (*it).GetPrice() << ' ';
		cout << (*it).GetAuthor() << endl;
	}

	return true;

}



bool Library::WriteBookToData(char * file_loc)
{
	ofstream ofile;
	ofile.open(file_loc);
	try
	{
		for (set<CBook,Comp>::const_iterator it = _library.begin();it != _library.end();it++)
		{
			ofile << (*it).GetName()  << ' ';
			ofile << (*it).GetLsbn()  << ' ';
			ofile << (*it).GetPrice() << ' ';
			ofile << (*it).GetAuthor() << endl;
		}


	}
	catch (...)
	{
		throw"file erro";
		ofile.close();
	}

	return true;
}

bool Library::DeleteBook(string lsbn)
{
	GetDataFromFile();

	for (set<CBook, Comp>::const_iterator it = _library.begin();it != _library.end();it++)
	{
		if ((*it).GetLsbn() == lsbn)
		{
			_library.erase(it);//这里不能用*it
			break;//erase之后之前的iterator就不适用与新set了
		}


	}
	WriteBookToData();
	return true;
}