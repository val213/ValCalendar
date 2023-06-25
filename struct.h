#pragma once
#include"config.h"
//#include"USER.h"
//#include"TEAM.h"
//#include"EVENT.h"

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
	
	
};
//这个外部变量声明也必须在USER结构体声明之后才有意义
extern USER users[MAX_USRS_NUM];
struct EVENT
{
	int event_id;
	QString event_name;
	QString event_position;
	QString event_starttime;
	QString event_endtime;
	QString event_content;
	QString event_type;
	int urgentdegree;
};

struct TEAM
{
	int team_id;
	QString team_passwd;
	QString team_name;
	
	int leader_id;
	int team_members_nums;
	int team_events_nums;
	//存放团队成员信息的文件
	QString team_members_filename;
	//存放团队事件信息的文件
	QString team_events_filename;
	QVector<USER> team_members;
	QVector<EVENT> team_events;

	TEAM():team_members_nums(0),team_events_nums(0),leader_id(0),team_id(0),team_name(""),team_passwd(""),team_members_filename(""),team_events_filename(""),team_members(),team_events()
	{
		
	}
	TEAM(QString team_name,QString team_passwd,int USR_ID_NOW)
	{
		//把创始人作为第一个成员存入团队的人员信息中
		team_members.push_back(users[USR_ID_NOW- USER_ID_FORE]);
	}

};

