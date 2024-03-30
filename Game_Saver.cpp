#pragma warning( disable : 4996)
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstring>
#include "Game_Saver.h"

Game_Saver::Game_Saver() //��ʼ��
{
	Readcfg();
}

Game_Saver::~Game_Saver()
{

}

//��ȡ�����ļ�
std::string Game_Saver::Readcfg()
{
	using namespace std;
	int mark = 0;
	string path;
	fstream cfg;
	for (int i = 0; i < 5;)
	{
		cfg.open(".\\save\\savepath.cfg");//����������ɨ���ļ��Ƿ����
		if (!cfg.is_open()) {
			system("cls");
			cout << "�����ļ�������,����save�ļ���������savepath.cfg�����ļ�,�����ļ���д��浵Ŀ¼(����ֱ�ӵ����Դ������·��������ճ����,ע��Ҫд����������)" << endl;
			CreateDirectory(DefaultSavePath, NULL);
			ofstream cfgfile(".\\save\\savepath.cfg");
			cfgfile << DefaultConfigPath;
			cfgfile.close();
			Sleep(2500);
		}else i = 20;
	}
	getline(cfg, path);
	cfg.close();

	for (int j = 0; j < 5;) 
	{
		for (int i = 0; i < path.length(); i++)
		{
			cfg.open(".\\save\\savepath.cfg");//����������ɨ��·���Ƿ����
			system("cls");
			getline(cfg, path);
			cfg.close();
			if (path[i] == '"'&& path[i + 1] == '"')
			{
				cout << "·��Ϊ��,����һ�����Ƿ�������·��." << endl;
				Sleep(3500);
				break;
			}
			else if (path[i] == '"' && path[i + 1] != '"')
			{
				mark = i;
				j = 20;
				break;
			}
		}
	}
	
	path = path.substr(mark + 1, path.length() - 7);
	cfg.close();
	return path;
}
	

//��⵱ǰ�浵�Ƿ����
bool Game_Saver::CheckLocalFile() const
{
	using namespace std;
	ifstream FileExist1(SavePath1.c_str());
	ifstream FileExist2(SavePath2.c_str());
	if (!FileExist1.good())
	{
		cout << "nsSGv1.sol�ļ�������." << endl;
	}
	if (!FileExist2.good())
	{
		cout << "nsTest.sol�ļ�������." << endl;
	}
	if (!FileExist1.good() && !FileExist2.good())
	{
		return false;
	}
	return true;
}

//��ⱸ�ݴ浵�Ƿ����
bool Game_Saver::CheckBackUpFile() const
{
	using namespace std;
	ifstream FileExist1(SavePath3.c_str());
	ifstream FileExist2(SavePath4.c_str());
	if (!FileExist1.good())
	{
		cout << "nsSGv1.sol�ļ�������." << endl;
	}
	if (!FileExist2.good())
	{
		cout << "nsTest.sol�ļ�������." << endl;
	}
	if (!FileExist1.good() && !FileExist2.good())
	{
		return false;
	}
	return true;
}


//����·��
void Game_Saver::SetPath()
{
	using namespace std;

	string buff = Readcfg();

	SavePath1 = buff + (string)SaveFile1;//��ǰ�浵nsSGv1.sol
	SavePath2 = buff + (string)SaveFile2;//��ǰ�浵nsTest.sol
	SavePath3 = (string)DefaultSavePath + (string)SaveFile1;//���ݴ浵nsSGv1.sol
	SavePath4 = (string)DefaultSavePath + (string)SaveFile2;// ���ݴ浵nsTest.sol

}

//����浵
void Game_Saver::Save()
{
	using namespace std;
	SetPath();
	if (CheckLocalFile())
	{
		CopyFile(SavePath1.c_str(), ".\\save\\nsSGv1.sol", false);
		cout << "nsSGv1.sol����ɹ�." << endl;
		CopyFile(SavePath2.c_str(), ".\\save\\nsTest.sol", false);
		cout << "nsSGv1.sol����ɹ�." << endl;
	}
	else
	{
		cout << "�浵�ļ�������,�浵����ʧ��." << endl;
	}
}

//��ȡ�浵
void Game_Saver::Restore() 
{
	using namespace std;
	SetPath();
	if (CheckBackUpFile())
	{
		CopyFile(".\\save\\nsSGv1.sol", SavePath1.c_str(), false);
		cout << "nsSGv1.sol����ɹ�." << endl;
		CopyFile(".\\save\\nsTest.sol", SavePath2.c_str(), false);
		cout << "nsSGv1.sol����ɹ�." << endl;
	}
	else
	{
		cout << "�浵�ļ�������,�浵����ʧ��." << endl;
	}
}

//ɾ�����ݴ浵
void Game_Saver::Delete_Restore()
{
	using namespace std;
	if (remove(SavePath1.c_str()) != 0) { // ����ɾ���ļ�
		cout << "nsSGv1.solɾ��ʧ��." << endl;
	}
	else {
		cout << "nsSGv1.solɾ���ɹ�." << endl;

	}
	if (remove(SavePath2.c_str()) != 0) { // ����ɾ���ļ�
		cout << "nsTest.solɾ��ʧ��." << endl;
	}
	else {
		cout << "nsTest.solɾ���ɹ�." << endl;
	}
}

//ɾ����ǰ�浵
void Game_Saver::Delete_Save()
{
	using namespace std;
	if (remove(".\\save\\nsSGv1.sol") != 0) { // ����ɾ���ļ�
		cout << "nsSGv1.solɾ��ʧ��." << endl;
	}
	else {
		cout << "nsSGv1.solɾ���ɹ�." << endl;

	}
	if (remove(".\\save\\nsTest.sol") != 0) { // ����ɾ���ļ�
		cout << "nsTest.solɾ��ʧ��." << endl;
	}
	else {
		cout << "nsTest.solɾ���ɹ�." << endl;
	}
}
const void Game_Saver::Refresh()
{
	Readcfg();
}