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

public:
    TODOwidget(QWidget* parent = nullptr);
    void DisplaySlot(QString lng, QString lat);
    void on_pushButton_clicked();
    ~TODOwidget();
    void save_Date();

    void handleWebPageLoadFinished(bool success);

    void handleJavaScriptConsoleMessage(const QString& message);

    USER user_now = users[USR_ID_NOW - USER_ID_FORE];
    //QWebEngineView* webEngineView_2;
    Ui::TODOwidget1 ui;

protected:
    bridge* JSBridge;
signals:
    // 声明一个信号，用于通知calendar新的日程已经被添加，需要更新日程数据
    void TODO_add();

protected slots:
    // 槽函数，处理按钮点击事件
    void TODOwidget_accepted();
};