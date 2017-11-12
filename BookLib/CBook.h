#define NUM1 128
#define NUM2 50
#include<string>

using namespace std;

class CBook
{
public:
	CBook() {}
	CBook(string Name, string lsbn, string Price, string Author);
	~CBook() {}

	string GetName();
	void SetName(string &Name);
	string GetLsbn();
	void SetLsbn(string &lsbn);
	string GetPrice();
	void SetPrice(string &price);
	string GetAuthor();
	void SetAuthor(string &Author);
	void WriteData(char * file_loc = "book.txt");
	//void DeleteData(int iCount);
	void GetBookFromFile(char * file_loc="book.txt");
	//
protected:
	string _name;
	string _lsbn;
	string _price;
	string _author;

};
