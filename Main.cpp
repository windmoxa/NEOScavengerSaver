#include "Main_Function.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() 
{
	cout << "��ӭʹ��ĩ��ʰ����(NEOScavenger)���ٴ浵��" << endl;
	Sleep(3500);
	int choice = 0;
	for (int i = 0; i < 5;) 
	{
		
		system("cls");
		cout << "��ѡ����������Ĳ���" << endl;
		cout << "1.�浵" << endl;
		cout << "2.����" << endl;
		cout << "3.ɾ�����ݴ浵" << endl;
		cout << "4.ɾ����ǰ�浵" << endl;
		cout << "5�˳�" << endl;
		cout << "�������ܻ�����¹���..." << endl;

		cin >> choice;

		switch (choice) 
		{
		case 1:
			system("cls");
			save();
			cout << "�浵�ɹ�" << endl;
			Sleep(2500);
			break;
		case 2:
			system("cls");
			restore();
			cout << "�����ɹ�" << endl;
			Sleep(2500);
			break;
		case 3:
			system("cls");
			delete_restore();
			cout << "ɾ�����ݴ浵�ɹ�" << endl;
			Sleep(2500);
			break;
		case 4:
			system("cls");
			delete_save();
			cout << "ɾ����ǰ�浵�ɹ�" << endl;
			Sleep(2500);
			break;
		case 5:
			system("cls");
			save();
			cout << "�˳�������" << endl;
			Sleep(2500);
			i = 20;
			break;
		}
	}

	return 0;
}
