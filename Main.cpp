#include <iostream>
#include <windows.h>
#include "Game_Saver.h"


using namespace std;

int main() 
{
	Game_Saver save;
	
	cout << "欢迎使用末日拾荒者(NEOScavenger)快速存档器" << endl;
	Sleep(3500);
	
	int choice = 0;
	for (int i = 0; i < 5;) 
	{
		save.Refresh();
		system("cls");
		cout << "请选择你想继续的操作" << endl;
		cout << "1.存档" << endl;
		cout << "2.读档" << endl;
		cout << "3.删除备份存档" << endl;
		cout << "4.删除当前存档" << endl;
		cout << "5.退出" << endl;
		cout << "后续可能会更新新功能..." << endl;

		cin >> choice;

		switch(choice)
		{
		case 1:
			system("cls");
			save.Save();
			cout << "存档操作完成" << endl;
			Sleep(2500);
			break;
		case 2:
			system("cls");
			save.Restore();
			cout << "读档操作完成" << endl;
			Sleep(2500);
			break;
		case 3:
			system("cls");
			save.Delete_Restore();
			cout << "删除备份存档操作完成" << endl;
			Sleep(2500);
			break;
		case 4:
			system("cls");
			save.Delete_Save();
			cout << "删除当前存档操作完成" << endl;
			Sleep(2500);
			break;
		case 5:
			system("cls");
			cout << "程序退出中,请稍等." << endl;
			Sleep(2500);
			i = 20;
			break;
		default:
			cout << "键入有误,请重新输入." << endl;
			Sleep(2500);
			break;
		}
	}
	
	return 0;
}
