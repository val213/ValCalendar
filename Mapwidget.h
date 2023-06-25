#pragma once
#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#include <QMainWindow>
#include<qwidget.h>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QWebEnginePage>
#include<qwebchannel.h>
#include <QWebEngineSettings>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include"bridge.h"
#include"ui_Mapwidget.h"
class  MapWidget : public QMainWindow
{
	Q_OBJECT
protected:
	bridge* JSBridge;
public:
	MapWidget(QWidget* parent = nullptr);

	void onCalculateButtonClicked();
	void onDistanceAndTimeCalculated(const QString& duration, const QString& distance);
	~MapWidget();
	void handleWebPageLoadFinished(bool success);

	void handleJavaScriptConsoleMessage(const QString& message);


	Ui::Mapwidget ui;
};
#endif // !MAPWIDGET_H 
