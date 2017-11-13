#include"CBook.h"
#include"Library.h"
#include<iostream>

using namespace std;
int main(void)
{

	CBook book("lalala", "12345634", "25", "lanxiuwen");
	CBook book2("yibenshu", "654321", "23", "lanxiuwen");

	Library lib;
	lib.AddBook(book);
	lib.ShowLibraryData();
	lib.DeleteBook("654321");
	lib.ShowLibraryData();

	return 0;
}
