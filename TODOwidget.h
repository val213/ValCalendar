#pragma once
#include"config.h"
#include<qwidget.h>
#include <QtWebEngineWidgets/QWebEngineView>
#include"bridge.h"
#include <QWebEngineProfile>
#include <QWebEnginePage>


extern int user_nums;
extern int USR_ID_NOW;

class TODOwidget : public QMainWindow
{
    Q_OBJECT
protected:
    bridge* JSBridge;
public:
    TODOwidget(QWidget* parent = nullptr);

    void onCalculateButtonClicked();
    void on_pushButton_clicked();
    void onDistanceAndTimeCalculated(const QString& duration, const QString& distance);
    ~TODOwidget();
    void save_Date();
    int check_todo();
    void handleWebPageLoadFinished(bool success);

    void handleJavaScriptConsoleMessage(const QString& message);

    USER user_now = users[USR_ID_NOW - USER_ID_FORE];
    //QWebEngineView* webEngineView_2;
    Ui::TODOwidget1 ui;


signals:
    // 声明一个信号，用于通知calendar新的日程已经被添加，需要更新日程数据
    void TODO_add();
    void TODO_Add_Correct();
protected slots:
    // 槽函数，处理按钮点击事件
    void TODOwidget_accepted();
};