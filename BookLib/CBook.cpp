#include"CBook.h"
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;
CBook::CBook(string Name, string lsbn, string Price, string Author)
	:_name(Name), _lsbn(lsbn), _price(Price), _author(Author) {}

string  CBook::GetName()
{
	return _name;
}

void CBook::SetName(string &Name)
{
	_name = Name;
}

string CBook::GetLsbn()
{
	return _lsbn;
}

void CBook::SetLsbn(string &lsbn)
{
	_lsbn = lsbn;
}

string CBook::GetPrice()
{
	return _price;
}

void CBook::SetPrice(string &price)
{
	_price = price;
}
string CBook::GetAuthor()
{
	return _author;
}
void CBook::SetAuthor(string &Author)
{
	_author = Author;
}
void CBook::WriteData(char * file_loc)
{
	ofstream ofile;
	ofile.open(file_loc,ios::app);
	try
	{
		ofile << _name<<' ';
		ofile << _lsbn<<' ';
		ofile << _price<<' ';
		ofile << _author << endl;

		/*ofile.write(_name.c_str(),_name.length());
		ofile.write("|||",3);
		ofile.write(_lsbn.c_str(), _lsbn.length());
		ofile.write("|||", 3);
		ofile.write(_price.c_str(), _price.length());
		ofile.write("|||", 3);
		ofile.write(_author.c_str(), _author.length());
		ofile.write("||!", 3);*/
	}
	catch (...)
	{
		throw"file erro";
		ofile.close();
	}
}

//void CBook::DeleteData(int iCount);

void CBook::GetBookFromFile(char * file_loc)
{
	string name;
	string lsbn;
	string price;
	string author;
	int partFlag=0;
	int nextBook = 0;
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
		}

	}
	catch (...)
	{
		throw"file erro";
		ifile.close();
	}

	_name = name;
	_lsbn = lsbn;
	_price = price;
	_author = author;
}