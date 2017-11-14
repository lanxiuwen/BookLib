#include"Library.h"
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

bool Library::AddBook(CBook book)
{
	try
	{
		GetDataFromFile();
		_library.insert(book);
		WriteDataToFile();
	}
	catch (...)
	{
		throw"Add Book Failed";
		return false;
	}
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
	try
	{
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
	}
	catch (...)
	{
		throw"file erro";
		return false;
	}
	
	return true;
}
bool Library::ShowLibraryData(string file_loc) 
{
	GetDataFromFile(file_loc);
	cout << setw(20) << "书名" << setw(20) << "LSBN" << setw(20) << "价格" << setw(20) << "作者" << endl;
	cout << endl;

	for (set<CBook,Comp>::const_iterator it = _library.begin();it != _library.end();it++)
	{
		cout <<setw(20)<< (*it).GetName() << ' ';
		cout << setw(20) << (*it).GetLsbn() << ' ';
		cout << setw(20) << (*it).GetPrice() << ' ';
		cout << setw(20) <<(*it).GetAuthor() << endl;
	}

	return true;

}



bool Library::WriteDataToFile(char * file_loc)
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
	try
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
		WriteDataToFile();
	}
	catch (...)
	{
		throw"Delete Book Failed";
		return false;
	}
	return true;
}