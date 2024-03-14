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

//��ȡ�����ļ�
const char* readcfg(bool t)
{
	int temp = 0;
	string cfgset = "path=\"\"";
	string cfgtext1 = "";
	fstream cfg;
	cfg.open(".\\save\\savepath.cfg");
	if (!cfg.is_open()) {
		cout << "�����ļ�������,����save�ļ���������savepath.cfg�����ļ�,�����ļ���д��浵Ŀ¼Ȼ�����´򿪳���(ע��д��·��ʱʹ��˫��б��)" << endl;
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

//����
void save()
{
	string cfgpath = readcfg(t);
	string savepath1 = cfgpath + savefile1;
	string savepath2 = cfgpath + savefile2;
	CopyFile(savepath1.c_str(), ".\\save\\nsSGv1.sol", false);
	CopyFile(savepath2.c_str(), ".\\save\\nsTest.sol", false);
}

//��ȡ
void restore()
{
	string cfgpath = readcfg(t);
	string savepath1 = cfgpath + savefile1;
	string savepath2 = cfgpath + savefile2;
	CopyFile(".\\save\\nsSGv1.sol", savepath1.c_str(), false);
	CopyFile(".\\save\\nsTest.sol", savepath2.c_str(), false);
}

//ɾ�����ݴ浵
void delete_save()
{
	
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

//ɾ����ǰ�浵
void delete_restore()
{
	string cfgpath = readcfg(t);
	string savepath1 = cfgpath + savefile1;
	string savepath2 = cfgpath + savefile2;
	if (remove(savepath1.c_str()) != 0) { // ����ɾ���ļ�
		cout << "nsSGv1.solɾ��ʧ��." << endl;
	}
	else {
		cout << "nsSGv1.solɾ���ɹ�." << endl;

	}
	if (remove(savepath2.c_str()) != 0) { // ����ɾ���ļ�
		cout << "nsTest.solɾ��ʧ��." << endl;
	}
	else {
		cout << "nsTest.solɾ���ɹ�." << endl;

	}
}