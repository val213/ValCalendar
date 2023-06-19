#pragma once
#include"config.h"
#include"TEAM.h"
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
	//���ڲ����������==���������û��˳��Ŷӵ�ʱ����id������Աɾ��
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
//����ⲿ��������Ҳ������USER�ṹ������֮���������
extern USER users[MAX_USRS_NUM];