#pragma once
#ifndef _GAME_SAVER_
#define _GAME_SAVER_

class Game_Saver {
private:
	const char* DefaultConfigPath = "path=\"\"";
	const char* DefaultSavePath = ".\\save";
	const char* SaveFile1 = "\\nsSGv1.sol";//��һ���ļ�
	const char* SaveFile2 = "\\nsTest.sol";//�ڶ����ļ�
	std::string SavePath1 ;
	std::string SavePath2 ;
	std::string SavePath3 ;
	std::string SavePath4 ;
	std::string Readcfg();//��ȡ�����ļ�
	bool CheckLocalFile() const;//��⵱ǰ�浵�Ƿ����
	bool CheckBackUpFile() const;//��ⱸ�ݴ浵�Ƿ����
	void SetPath();//����·��

public:
	Game_Saver();
	~Game_Saver();
	void Save();//����浵
	void Restore();//��ȡ�浵
	void Delete_Restore();//ɾ�����ݴ浵
	void Delete_Save();//ɾ����ǰ�浵
	const void Refresh();
};

#endif