#pragma once
#ifndef _GAME_SAVER_
#define _GAME_SAVER_

class Game_Saver {
private:
	const char* DefaultConfigPath = "path=\"\"";
	const char* DefaultSavePath = ".\\save";
	const char* SaveFile1 = "\\nsSGv1.sol";//第一个文件
	const char* SaveFile2 = "\\nsTest.sol";//第二个文件
	std::string SavePath1 ;
	std::string SavePath2 ;
	std::string SavePath3 ;
	std::string SavePath4 ;
	std::string Readcfg();//读取配置文件
	bool CheckLocalFile() const;//检测当前存档是否存在
	bool CheckBackUpFile() const;//检测备份存档是否存在
	void SetPath();//设置路径

public:
	Game_Saver();
	~Game_Saver();
	void Save();//保存存档
	void Restore();//读取存档
	void Delete_Restore();//删除备份存档
	void Delete_Save();//删除当前存档
	const void Refresh();
};

#endif