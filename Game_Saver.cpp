#pragma warning( disable : 4996)
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstring>
#include "Game_Saver.h"

Game_Saver::Game_Saver() //初始化
{
	Readcfg();
}

Game_Saver::~Game_Saver()
{

}

//读取配置文件
std::string Game_Saver::Readcfg()
{
	using namespace std;
	int mark = 0;
	string path;
	fstream cfg;
	for (int i = 0; i < 5;)
	{
		cfg.open(".\\save\\savepath.cfg");//反复打开做到扫描文件是否存在
		if (!cfg.is_open()) {
			system("cls");
			cout << "配置文件不存在,已在save文件夹下生成savepath.cfg配置文件,配置文件中写入存档目录(可以直接点击资源管理器路径栏复制粘贴了,注意要写在引号里面)" << endl;
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
			cfg.open(".\\save\\savepath.cfg");//反复打开做到扫描路径是否存在
			system("cls");
			getline(cfg, path);
			cfg.close();
			if (path[i] == '"'&& path[i + 1] == '"')
			{
				cout << "路径为空,请检查一下你是否配置了路径." << endl;
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
	

//检测当前存档是否存在
bool Game_Saver::CheckLocalFile() const
{
	using namespace std;
	ifstream FileExist1(SavePath1.c_str());
	ifstream FileExist2(SavePath2.c_str());
	if (!FileExist1.good())
	{
		cout << "nsSGv1.sol文件不存在." << endl;
	}
	if (!FileExist2.good())
	{
		cout << "nsTest.sol文件不存在." << endl;
	}
	if (!FileExist1.good() && !FileExist2.good())
	{
		return false;
	}
	return true;
}

//检测备份存档是否存在
bool Game_Saver::CheckBackUpFile() const
{
	using namespace std;
	ifstream FileExist1(SavePath3.c_str());
	ifstream FileExist2(SavePath4.c_str());
	if (!FileExist1.good())
	{
		cout << "nsSGv1.sol文件不存在." << endl;
	}
	if (!FileExist2.good())
	{
		cout << "nsTest.sol文件不存在." << endl;
	}
	if (!FileExist1.good() && !FileExist2.good())
	{
		return false;
	}
	return true;
}


//设置路径
void Game_Saver::SetPath()
{
	using namespace std;

	string buff = Readcfg();

	SavePath1 = buff + (string)SaveFile1;//当前存档nsSGv1.sol
	SavePath2 = buff + (string)SaveFile2;//当前存档nsTest.sol
	SavePath3 = (string)DefaultSavePath + (string)SaveFile1;//备份存档nsSGv1.sol
	SavePath4 = (string)DefaultSavePath + (string)SaveFile2;// 备份存档nsTest.sol

}

//保存存档
void Game_Saver::Save()
{
	using namespace std;
	SetPath();
	if (CheckLocalFile())
	{
		CopyFile(SavePath1.c_str(), ".\\save\\nsSGv1.sol", false);
		cout << "nsSGv1.sol保存成功." << endl;
		CopyFile(SavePath2.c_str(), ".\\save\\nsTest.sol", false);
		cout << "nsSGv1.sol保存成功." << endl;
	}
	else
	{
		cout << "存档文件不存在,存档保存失败." << endl;
	}
}

//读取存档
void Game_Saver::Restore() 
{
	using namespace std;
	SetPath();
	if (CheckBackUpFile())
	{
		CopyFile(".\\save\\nsSGv1.sol", SavePath1.c_str(), false);
		cout << "nsSGv1.sol保存成功." << endl;
		CopyFile(".\\save\\nsTest.sol", SavePath2.c_str(), false);
		cout << "nsSGv1.sol保存成功." << endl;
	}
	else
	{
		cout << "存档文件不存在,存档读档失败." << endl;
	}
}

//删除备份存档
void Game_Saver::Delete_Restore()
{
	using namespace std;
	if (remove(SavePath1.c_str()) != 0) { // 尝试删除文件
		cout << "nsSGv1.sol删除失败." << endl;
	}
	else {
		cout << "nsSGv1.sol删除成功." << endl;

	}
	if (remove(SavePath2.c_str()) != 0) { // 尝试删除文件
		cout << "nsTest.sol删除失败." << endl;
	}
	else {
		cout << "nsTest.sol删除成功." << endl;
	}
}

//删除当前存档
void Game_Saver::Delete_Save()
{
	using namespace std;
	if (remove(".\\save\\nsSGv1.sol") != 0) { // 尝试删除文件
		cout << "nsSGv1.sol删除失败." << endl;
	}
	else {
		cout << "nsSGv1.sol删除成功." << endl;

	}
	if (remove(".\\save\\nsTest.sol") != 0) { // 尝试删除文件
		cout << "nsTest.sol删除失败." << endl;
	}
	else {
		cout << "nsTest.sol删除成功." << endl;
	}
}
const void Game_Saver::Refresh()
{
	Readcfg();
}