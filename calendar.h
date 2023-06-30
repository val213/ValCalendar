#pragma once
#ifndef CALENDAR_H
#define CALENDAR_H
#include"TODOwidget.h"
#include"config.h"
#include"team_mng.h"
#include"tsplan.h"
#include "Mapwidget.h"
extern int user_nums;
extern int USR_ID_NOW;
class calendar : public QMainWindow
{
	Q_OBJECT

public:
	calendar(QWidget* parent = nullptr);
	~calendar();
	USER user_now = users[USR_ID_NOW - 1001];
	//从文件导入当前用户之前的所有日程记录
	void load_usr_Event();
	void updateTable();
	QPixmap pix;
	WeatherWidget* weather;
	MapWidget* map = new MapWidget;
	void onSortComboBoxIndexChanged(int);
	void sortTableByColumn(QTableWidget* tableWidget, int column);
	void showWeatherInfo();
private:
	Ui::calendarClass ui;
	QTimer* timer = new QTimer(this);
	void paintEvent(QPaintEvent* e);
	QDateTime current_time;
	void on_check_isChecked(int team_id);
	void on_check_not_checked(int team_id);
	void updateTeamTable();
	void calculateDepartureTimes(const QString& startTime, QString urgency, const QString& scheduleType, const QDateTime& currentTime);
	void update_recommend();
public slots:
	void handleDate(QDate date); // declare the slot function
	void team_manage();

	void updateDataToFile(int row, int column, const QString& newText);
	void on_cellselect(int row, int column);

	void on_deleteRowButtonClicked();

	void finished_cellChanged(int row, int colunmn);
};
#endif // CALENDAR_H