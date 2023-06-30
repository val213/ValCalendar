#pragma once
#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QDebug>
#include <QWebEngineSettings>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class bridge : public QObject
{
	Q_OBJECT
public:
	explicit bridge(QWebEngineView* webEngineView, QObject* parent);

signals:
	void distanceAndTimeCalculated(const QString& duration, const QString& distance);

private:
	QString m_start;
	QString m_end;
	QWebEngineView* m_webEngineView;
public slots:
	void setStartAndEnd(const QString& start, const QString& end);

	void calculateDistanceAndTime(const QString& start, const QString& end);
};

#endif // BRIDGE_H
