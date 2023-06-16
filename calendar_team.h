#pragma once
#ifndef CALENDAR_TEAM_H
#define CALENDAR_TEAM_H
#include"config.h"
#include"team_mng.h"
#include"ui_calendar_team.h"
extern int user_nums;
extern int USR_ID_NOW;
class calendar_team: public QMainWindow
{
    Q_OBJECT

public:
    calendar_team(QWidget* parent = nullptr);
    ~calendar_team();
    USER user_now = users[USR_ID_NOW - 1001];
    //���ļ����뵱ǰ�û�֮ǰ�������ճ̼�¼
    void load_usr_Event();
    void updateTable();
private:
    Ui::calendar_team ui;
    QTimer* timer = new QTimer(this);
public slots:
    void handleDate(QDate date); // declare the slot function
    void team_manage();

    void updateDataToFile(int row, int column, const QString& newText);
    void on_cellselect(int row, int column);

    void on_deleteRowButtonClicked();


    void finished_cellChanged(int row, int colunmn);
};
#endif // CALENDAR_TEAM_H