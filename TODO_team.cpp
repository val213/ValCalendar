#include"config.h"
#include"calendar.h"
#include"calendar_team.h"
#include"TODOwidget.h"
#include"TODO_team.h"
#include<qwebchannel.h>
#include <QWebEngineSettings>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QWebEngineView>

TODO_team::TODO_team(QWidget* parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Add to do");
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &TODO_team::TODO_team_accepted);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &TODOwidget::close);
	todo_current_time();

	// QWebEngineProfile* profile = ui.webEngineView->page()->profile();
	// connect(ui.webEngineView, &QWebEngineView::loadFinished,this, &TODOwidget::handleWebPageLoadFinished);
}

TODO_team::~TODO_team()
{
}
void TODO_team::set_team_id(QString id)
{
	team_id = id;
	team_now = teams[team_id.toInt() - TEAM_ID_FORE];
}

void TODO_team::save_Date()
{
	qDebug() << "save team new todo!!";
	qDebug() << "team_id: " << team_id << " " << team_now.team_id;
	team_now.team_events_filename = QString::number(team_now.team_id) + "_team events.txt";
	QFile file(team_now.team_events_filename); //创建一个QFile对象，指定要保存的文件名
	if (file.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append)) { //以写入和文本模式打开文件
		QTextStream out(&file); //创建一个QTextStream对象，关联到文件
		//团队事件数量+1
		team_now.team_events_nums++;
		//将文本编辑框的内容写入文件
		//写入事件标题
		out << ui.lineEdit->text() << ",";
		//写入地点
		out << ui.lineEdit_3->text() << ",";
		//获取开始时间
		QDate start_date = ui.dateTimeEdit->date(); //获取dateTimeEdit中的日期
		QTime start_time = ui.dateTimeEdit->time();//获取dateTimeEdit中的时间
		QString start_dateString = start_date.toString("yyyy-MM-dd"); //将日期转换为字符串格式
		QString start_timeString = start_time.toString("hh:mm:ss"); //将时间转换为字符串格式
		out << start_dateString << " " << start_timeString << ","; //将日期和时间字符串写入文件

		//获取结束时间
		QDate end_date = ui.dateTimeEdit_2->date(); //获取dateTimeEdit中的日期
		QTime end_time = ui.dateTimeEdit_2->time();//获取dateTimeEdit中的时间
		QString end_dateString = end_date.toString("yyyy-MM-dd"); //将日期转换为字符串格式
		QString end_timeString = end_time.toString("hh:mm:ss"); //将时间转换为字符串格式
		out << end_dateString << " " << end_timeString << ",";//将日期和时间字符串写入文件

		//写入事件类型
		// 假设下拉框控件的名称为 comboBox
		QComboBox* comboBox = findChild<QComboBox*>("comboBox");  // 获取下拉框控件的指针

		if (comboBox) {
			QString selectedText = comboBox->currentText();  // 获取当前选中项的文本值
			out << selectedText << ",";
		}

		int urgentdegree = 0;
		if (ui.radioButton->isChecked())
		{
			urgentdegree = 1;
		}
		else if (ui.radioButton_2->isChecked())
		{
			urgentdegree = 2;
		}
		else if (ui.radioButton_3->isChecked())
		{
			urgentdegree = 3;
		}
		//写入紧急程度
		out << urgentdegree << ",";
		//备注
		out << ui.textEdit->toPlainText() << ",";

		qDebug() << "save team new todo ok!";
		file.close(); //关闭文件
	}
}

void TODO_team::TODO_team_accepted()
{
	this->save_Date();

	emit TODO_add_team();
	this->close();
	//发送信号给calendar
}

void TODO_team::todo_current_time()
{
	//将dateTimeEdit和dateTimeEdit_2的默认时间设置为当前时间
	ui.dateTimeEdit->setDateTime(QDateTime::currentDateTime());
	ui.dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
	//dateTimeEdit的时间要不早于现在的时间
	ui.dateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime());
	ui.dateTimeEdit->setCalendarPopup(true);
	ui.dateTimeEdit_2->setCalendarPopup(true);
}