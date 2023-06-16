#pragma once
#include"config.h"
#include"USER.h"
#include"EVENT.h"
struct USER;
extern USER users[MAX_USRS_NUM];
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

	TEAM() :team_members_nums(0), team_events_nums(0), leader_id(0), team_id(0), team_name(""), team_passwd(""), team_members_filename(""), team_events_filename(""), team_members(), team_events()
	{

	}
	TEAM(QString team_name, QString team_passwd, int USR_ID_NOW)
	{
		//把创始人作为第一个成员存入团队的人员信息中
		team_members.push_back(users[USR_ID_NOW - USER_ID_FORE]);
	}
	bool operator==(const TEAM& other) const
	{
		return (team_id == other.team_id &&
			team_passwd == other.team_passwd &&
			team_name == other.team_name &&
			leader_id == other.leader_id &&
			team_members_nums == other.team_members_nums &&
			team_events_nums == other.team_events_nums &&
			team_members_filename == other.team_members_filename &&
			team_events_filename == other.team_events_filename &&
			team_members == other.team_members &&
			team_events == other.team_events);
	}

};