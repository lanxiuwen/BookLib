#include"CBook.h"
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;
CBook::CBook(string Name, string lsbn, string Price, string Author)
	:_name(Name), _lsbn(lsbn), _price(Price), _author(Author) {}

string  CBook::GetName() const
{
	return _name;
}

void CBook::SetName(string &Name)
{
	_name = Name;
}

string CBook::GetLsbn() const
{
	return _lsbn;
}

void CBook::SetLsbn(string &lsbn)
{
	_lsbn = lsbn;
}

string CBook::GetPrice() const
{
	return _price;
}

void CBook::SetPrice(string &price)
{
	_price = price;
}
string CBook::GetAuthor() const
{
	return _author;
}
void CBook::SetAuthor(string &Author)
{
	_author = Author;
}


