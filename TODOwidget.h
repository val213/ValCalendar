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
    // ����һ���źţ�����֪ͨcalendar�µ��ճ��Ѿ�����ӣ���Ҫ�����ճ�����
    void TODO_add();

protected slots:
    // �ۺ���������ť����¼�
    void TODOwidget_accepted();
};