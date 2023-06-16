#pragma once
#include"config.h"
//#include"USER.h"
//#include"TEAM.h"
//#include"EVENT.h"

//TEAM�ṹ���ǰ�����������û��ṹ���ܹ���TEAM��Ϊ��Ա
struct TEAM;

struct USER
{
	int usr_id;
	QString usr_passwd;
	QString usr_name;
	QString usr_filename;
	//����û��������Ŷ���Ϣ���ļ�
	QString usr_team_create_filename;
	//����û��������Ŷ���Ϣ���ļ�
	QString usr_team_belong_filename;
	int usr_team_create_num;
	int usr_team_belong_num;
	QVector<TEAM>teams_create;
	QVector<TEAM>teams_belong;
	
	
};
//����ⲿ��������Ҳ������USER�ṹ������֮���������
extern USER users[MAX_USRS_NUM];
struct EVENT
{
	int event_id;
	QString event_name;
	QString event_date;
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
	//����Ŷӳ�Ա��Ϣ���ļ�
	QString team_members_filename;
	//����Ŷ��¼���Ϣ���ļ�
	QString team_events_filename;
	QVector<USER> team_members;
	QVector<EVENT> team_events;

	TEAM():team_members_nums(0),team_events_nums(0),leader_id(0),team_id(0),team_name(""),team_passwd(""),team_members_filename(""),team_events_filename(""),team_members(),team_events()
	{
		
	}
	TEAM(QString team_name,QString team_passwd,int USR_ID_NOW)
	{
		//�Ѵ�ʼ����Ϊ��һ����Ա�����Ŷӵ���Ա��Ϣ��
		team_members.push_back(users[USR_ID_NOW- USER_ID_FORE]);
	}

};

