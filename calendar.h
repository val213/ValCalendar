#pragma once
#ifndef CALENDAR_H
#define CALENDAR_H
#include"config.h"
#include"team_mng.h"
extern int user_nums;
extern int USR_ID_NOW;
class calendar : public QMainWindow
{
    Q_OBJECT

public:
    calendar(QWidget *parent = nullptr);
    ~calendar();
    USER user_now = users[USR_ID_NOW -1001];
    //从文件导入当前用户之前的所有日程记录
    void load_usr_Event();
    void updateTable();
    QPixmap pix;
    void onSortComboBoxIndexChanged(int);
    void sortTableByColumn(QTableWidget* tableWidget, int column);
private:
    Ui::calendarClass ui;
    QTimer* timer = new QTimer(this);
    void paintEvent(QPaintEvent* e);
    
public slots:
    void handleDate(QDate date); // declare the slot function
    void team_manage();

    void updateDataToFile(int row, int column, const QString& newText);
    void on_cellselect(int row, int column);

    void on_deleteRowButtonClicked();

  
    void finished_cellChanged(int row,int colunmn);

};
#endif // CALENDAR_H