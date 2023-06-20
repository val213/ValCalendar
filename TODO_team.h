#pragma once
#include"config.h"
#include"team_mng.h"
#include <QtWebEngineWidgets/QWebEngineView>
#include"bridge.h"
#include <QWebEngineProfile>
#include <QWebEnginePage>

extern int user_nums;
extern int USR_ID_NOW;

class TODO_team : public TODOwidget
{
	Q_OBJECT

public:
    TODO_team(QWidget* parent = nullptr);
    ~TODO_team();
    void set_team_id(QString);
    void save_Date();
    void TODO_team_accepted();
    QString team_id;
    USER user_now = users[USR_ID_NOW - USER_ID_FORE];
    //QWebEngineView* webEngineView_2;
    Ui::TODOwidget1 ui;
    TEAM team_now;
signals:
    // ����һ���źţ�����֪ͨcalendar_team�µ��ճ��Ѿ������ӣ���Ҫ�����ճ�����
    void TODO_add_team();


};