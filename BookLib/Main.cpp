#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<fstream>
#include"Library.h"
#include"CBook.h"

#define CMD_COLS 80
#define CMD_LINES 25

using namespace std;

void SetScreenGrid()
{
	char sysSetBuf[80];
	sprintf_s(sysSetBuf, "Mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
	system(sysSetBuf);
}

void SetSysCaption()
{
	system("title Sample");
}

void ClearScreen()
{
	system("cls");
}

void SetSysCaption(const char * pText)
{
	char sysSetBuf[80];
	sprintf_s(sysSetBuf, "title %s", pText);
	system(sysSetBuf);
}

void ShowWelcome()
{
	for (int i = 0;i < 7;i++)
		cout << endl;
	cout << setw(40);
	cout << "**************" << endl;
	cout << setw(40);
	cout << "*图书管理系统*" << endl;
	cout << setw(40);
	cout << "**************" << endl;
}

void ShowRootMenu()
{
	cout << endl;
	cout << setw(38);
	cout << "请选择功能" << endl;
	cout << endl;
	cout << setw(38);
	cout << "1  添加新书" << endl;
	cout << endl;
	cout << setw(38);
	cout << "2  浏览全部" << endl;
	cout << endl;
	cout << setw(38);
	cout << "3  删除图书" << endl;

}

void WaitUser()
{
	int iInputPage = 0;
	cout << "B 返回主菜单 Q 退出" << endl;
	char c[256];
	cin >> c;
	if (c[0] == 'q')
		system("exit");
}

int GetSelect()
{
	char buf[256];
	gets_s(buf);
	return atoi(buf);
}

void GuideInput(Library &lib)
{
	string inName;
	string inLsbn;
	string inPrice;
	string inAuthor;

	cout << "输入书名: " << endl;
	cin >> inName;
	cout << "输入ISBN： " << endl;
	cin >> inLsbn;
	cout << "输入价格： " << endl;
	cin >> inPrice;
	cout << "输入作者：" << endl;
	cin >> inAuthor;

	CBook book(inName, inLsbn, inPrice, inAuthor);
	lib.AddBook(book);
	cout << "输入成功" << endl;

	WaitUser();
}

void ViewData(Library &lib)
{
	lib.ShowLibraryData();
	WaitUser();
}

void DeleteBook(Library &lib)
{
	string lsbn;
	cout << "输入你想删除的LSBN号:" << endl;
	cin >> lsbn;
	lib.DeleteBook(lsbn);
	WaitUser();
}
void mainloop(Library &lib)
{
	ShowWelcome();
	while (1)
	{
		ClearScreen();
		ShowWelcome();
		ShowRootMenu();
		switch (GetSelect())
		{
		case 1:
			ClearScreen();
			GuideInput(lib);
			break;
		case 2:
			ClearScreen();
			ViewData(lib);
			break;
		case 3:
			ClearScreen();
			DeleteBook(lib);
			break;

		}
	}
}



int main(void)
{
	Library lib;
	mainloop(lib);
	return 0;
}