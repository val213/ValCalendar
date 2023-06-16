#pragma once
#include"ui_Team_mng.h"
#include"config.h"
extern TEAM teams[MAX_TEAM_NUM];
class team_mng:public QWidget
{
	Q_OBJECT
public:
	int new_team_id;
	team_mng(QWidget *parent = Q_NULLPTR);
	~team_mng();
	Ui::team_mng ui;//��һ��Ҫ����ǰ��
	QTimer* timer_team = new QTimer(this);
	void create_new_team();
	void confirm_creat(const QString& teamName, const QString& password);
	void delete_team();
	void join_team();
	void exit_team();
	void confirm_join(const int& teamName, const QString& password);
	void updateTable_team();
	void on_cellselect(const QModelIndex& index);
	void on_exit_team_ButtonClicked(const QModelIndex& index);
	void on_delete_team_ButtonClicked(const QModelIndex& index);
private:

public slots:


};
void init_teams_structarr(TEAM* teams, int size);

