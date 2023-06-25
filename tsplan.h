#pragma once
#ifndef TSPLAN_H
#define TSPLAN_H

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTimer>
#include <QLabel>

class WeatherWidget : public QObject
{
    Q_OBJECT
public:
    explicit WeatherWidget(QObject* parent = nullptr);
    QString weatherInfo;
    QString temp;
    QString text;

public slots:
    void requestWeatherData();
    void handleWeatherData(QNetworkReply* reply);

private:
    QLabel* weatherLabel; // 显示天气信息的标签
    QNetworkAccessManager* networkManager; // 网络管理器
    QTimer* timer; // 定时器
    QString notice;
signals:
    // 定义一个信号，用来通知另一个类数据已经准备好了
    void dataReady();
};


#endif // TSPLAN_H
