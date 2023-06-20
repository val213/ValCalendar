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
    QLabel* weatherLabel; // ��ʾ������Ϣ�ı�ǩ
    QNetworkAccessManager* networkManager; // ���������
    QTimer* timer; // ��ʱ��

signals:
    // ����һ���źţ�����֪ͨ��һ���������Ѿ�׼������
    void dataReady();
};


#endif // TSPLAN_H
