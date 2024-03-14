#include "Main_Function.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() 
{
	cout << "欢迎使用末日拾荒者(NEOScavenger)快速存档器" << endl;
	Sleep(3500);
	int choice = 0;
	for (int i = 0; i < 5;) 
	{
		
		system("cls");
		cout << "请选择你想继续的操作" << endl;
		cout << "1.存档" << endl;
		cout << "2.读档" << endl;
		cout << "3.删除备份存档" << endl;
		cout << "4.删除当前存档" << endl;
		cout << "5退出" << endl;
		cout << "后续可能会更新新功能..." << endl;

		cin >> choice;

		switch (choice) 
		{
		case 1:
			system("cls");
			save();
			cout << "存档成功" << endl;
			Sleep(2500);
			break;
		case 2:
			system("cls");
			restore();
			cout << "读档成功" << endl;
			Sleep(2500);
			break;
		case 3:
			system("cls");
			delete_restore();
			cout << "删除备份存档成功" << endl;
			Sleep(2500);
			break;
		case 4:
			system("cls");
			delete_save();
			cout << "删除当前存档成功" << endl;
			Sleep(2500);
			break;
		case 5:
			system("cls");
			save();
			cout << "退出程序中" << endl;
			Sleep(2500);
			i = 20;
			break;
		}
	}

	return 0;
}
