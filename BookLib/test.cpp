#include"CBook.h"
#include<iostream>

using namespace std;
int main(void)
{

	CBook book("lalala", "123456", "25", "lanxiuwen");
	CBook book2;
	book.WriteData();
	book2.GetBookFromFile();
	book2.WriteData("123.txt");

	return 0;
}
