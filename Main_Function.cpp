#pragma warning( disable : 4996)
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
bool t = true;

string savefile1 = "\\\\nsSGv1.sol";
string savefile2 = "\\\\nsTest.sol";
string savepath = ".\\save";

//读取配置文件
const char* readcfg(bool t)
{
	int temp = 0;
	string cfgset = "path=\"\"";
	string cfgtext1 = "";
	fstream cfg;
	cfg.open(".\\save\\savepath.cfg");
	if (!cfg.is_open()) {
		cout << "配置文件不存在,已在save文件夹下生成savepath.cfg配置文件,配置文件中写入存档目录然后重新打开程序(注意写入路径时使用双反斜杠)" << endl;
		CreateDirectory(savepath.c_str(), NULL);
		ofstream cfgfile(".\\save\\savepath.cfg");
		cfgfile << cfgset;
		cfgfile.close();
		return 0;
	}
	getline(cfg, cfgtext1);
	cfg.close();
	for (int i = 0;; i++)
	{
		if (cfgtext1[i] == '"')
		{
			temp = i;
			break;
		}
	}
	string cfgtext2 = cfgtext1.substr(temp +1, cfgtext1.length() - 7 );
	const char* out = cfgtext2.data();
	return out;
}

//保存
void save()
{
	string cfgpath = readcfg(t);
	string savepath1 = cfgpath + savefile1;
	string savepath2 = cfgpath + savefile2;
	CopyFile(savepath1.c_str(), ".\\save\\nsSGv1.sol", false);
	CopyFile(savepath2.c_str(), ".\\save\\nsTest.sol", false);
}

//读取
void restore()
{
	string cfgpath = readcfg(t);
	string savepath1 = cfgpath + savefile1;
	string savepath2 = cfgpath + savefile2;
	CopyFile(".\\save\\nsSGv1.sol", savepath1.c_str(), false);
	CopyFile(".\\save\\nsTest.sol", savepath2.c_str(), false);
}

//删除备份存档
void delete_save()
{
	
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

//删除当前存档
void delete_restore()
{
	string cfgpath = readcfg(t);
	string savepath1 = cfgpath + savefile1;
	string savepath2 = cfgpath + savefile2;
	if (remove(savepath1.c_str()) != 0) { // 尝试删除文件
		cout << "nsSGv1.sol删除失败." << endl;
	}
	else {
		cout << "nsSGv1.sol删除成功." << endl;

	}
	if (remove(savepath2.c_str()) != 0) { // 尝试删除文件
		cout << "nsTest.sol删除失败." << endl;
	}
	else {
		cout << "nsTest.sol删除成功." << endl;

	}
}