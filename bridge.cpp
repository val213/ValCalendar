#include"bridge.h"
#include<qwebchannel.h>
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
#include <QJsonArray>
#include <QNetworkReply>


bridge::bridge(QWebEngineView* webEngineView, QObject* parent):m_webEngineView(webEngineView)
{

}



void bridge::setStartAndEnd(const QString& start, const QString& end)
{
	m_start = start;
	m_end = end;
	qDebug() << "start:" << m_start << "end:" << m_end;
    // ִ�о����ʱ�����
    calculateDistanceAndTime(m_start, m_end);
}



void bridge::calculateDistanceAndTime(const QString& start, const QString& end)
{
    // ������ִ���뾭γ����صĲ������������� JavaScript ����
    QString script = QString("var startlatitude = '%1'; var startlongitude = '%2'; ")
        .arg(start).arg(end);

    m_webEngineView->page()->runJavaScript(script);

}
