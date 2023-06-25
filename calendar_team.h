#pragma once
#ifndef CALENDAR_TEAM_H
#define CALENDAR_TEAM_H
#include"config.h"
#include"team_mng.h"
#include"ui_calendar_team.h"
extern int user_nums;
extern int USR_ID_NOW;
//继承于calendar
class calendar_team: public  QMainWindow
{
    Q_OBJECT

public:
    calendar_team(QWidget* parent = nullptr);
    ~calendar_team();
    QString team_id;
    USER user_now = users[USR_ID_NOW - USER_ID_FORE];
    TEAM team_now;
    //从文件导入当前用户之前的所有日程记录
    void load_team_Event();
    void updateTable();
    void set_team_id(QString);
    void updateTable_calendar();
private:
    Ui::calendar_team ui;
    QTimer* timer = new QTimer(this);
public slots:
    void handleDate(QDate date); // declare the slot function
    void team_manage();

    void updateDataToFile(int row, int column, const QString& newText);
    //void on_cellselect(int row, int column);

    void on_deleteRowButtonClicked();


    void finished_cellChanged(int row, int colunmn);
};
#endif // CALENDAR_TEAM_H