#include <iostream>
#include <windows.h>
#include "Game_Saver.h"


using namespace std;

int main() 
{
	Game_Saver save;
	
	cout << "��ӭʹ��ĩ��ʰ����(NEOScavenger)���ٴ浵��" << endl;
	Sleep(3500);
	
	int choice = 0;
	for (int i = 0; i < 5;) 
	{
		save.Refresh();
		system("cls");
		cout << "��ѡ����������Ĳ���" << endl;
		cout << "1.�浵" << endl;
		cout << "2.����" << endl;
		cout << "3.ɾ�����ݴ浵" << endl;
		cout << "4.ɾ����ǰ�浵" << endl;
		cout << "5.�˳�" << endl;
		cout << "�������ܻ�����¹���..." << endl;

		cin >> choice;

		switch(choice)
		{
		case 1:
			system("cls");
			save.Save();
			cout << "�浵�������" << endl;
			Sleep(2500);
			break;
		case 2:
			system("cls");
			save.Restore();
			cout << "�����������" << endl;
			Sleep(2500);
			break;
		case 3:
			system("cls");
			save.Delete_Restore();
			cout << "ɾ�����ݴ浵�������" << endl;
			Sleep(2500);
			break;
		case 4:
			system("cls");
			save.Delete_Save();
			cout << "ɾ����ǰ�浵�������" << endl;
			Sleep(2500);
			break;
		case 5:
			system("cls");
			cout << "�����˳���,���Ե�." << endl;
			Sleep(2500);
			i = 20;
			break;
		default:
			cout << "��������,����������." << endl;
			Sleep(2500);
			break;
		}
	}
	
	return 0;
}
