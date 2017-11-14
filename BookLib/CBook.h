
#pragma once

#include<string>

using namespace std;

class CBook
{
public:
	CBook() {}
	CBook(string Name, string lsbn, string Price, string Author);
	~CBook() {}

	string GetName() const;
	void SetName(string &Name);
	string GetLsbn() const;
	void SetLsbn(string &lsbn);
	string GetPrice() const;
	void SetPrice(string &price);
	string GetAuthor() const;
	void SetAuthor(string &Author);


protected:
	string _name;
	string _lsbn;
	string _price;
	string _author;

};

