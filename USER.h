#pragma once
#include"config.h"
#include"TEAM.h"
//TEAM结构体的前向声明，让用户结构体能够把TEAM作为成员
struct TEAM;
struct USER
{
	int usr_id;
	QString usr_passwd;
	QString usr_name;
	QString usr_filename;
	//存放用户创建的团队信息的文件
	QString usr_team_create_filename;
	//存放用户所属的团队信息的文件
	QString usr_team_belong_filename;
	int usr_team_create_num;
	int usr_team_belong_num;
	QVector<TEAM>teams_create;
	QVector<TEAM>teams_belong;
	//在内部重载运算符==，便于在用户退出团队的时候按照id检索成员删除
	bool operator==(const USER& other) const
	{
		return (usr_id == other.usr_id &&
			usr_passwd == other.usr_passwd &&
			usr_name == other.usr_name &&
			usr_filename == other.usr_filename &&
			usr_team_create_filename == other.usr_team_create_filename &&
			usr_team_belong_filename == other.usr_team_belong_filename &&
			usr_team_create_num == other.usr_team_create_num &&
			usr_team_belong_num == other.usr_team_belong_num &&
			teams_create == other.teams_create &&
			teams_belong == other.teams_belong);
	}

};
//这个外部变量声明也必须在USER结构体声明之后才有意义
extern USER users[MAX_USRS_NUM];