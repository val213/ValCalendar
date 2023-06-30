#include "config.h"
#include "calendar.h"
#include "TODOwidget.h"
#include "usr_mng.h"
#include "event_mng.h"
#include "ui_calendar.h"
#include "ui_TODOwidget.h"
#include "ui_REG_N_LOGIN.h"
#include "REG_N_LOGIN.h"
#include <QMessageBox>
#include"calendar_team.h"
#include"TODO_team.h"
using namespace std;
calendar_team::calendar_team(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setStyleSheet("calendar_team{background: url(:/calendar/SCUT.jpg); background-size: 50% auto;}");//窗口背景设置
	connect(ui.calendarWidget, &QCalendarWidget::activated, this, &calendar_team::handleDate);
	//设置时间显示的字体
	QPalette palette;
	palette.setColor(QPalette::WindowText, Qt::red);
	ui.label->setPalette(palette);

	//定时器
	QTimer* CurrentTime = new QTimer(this);
	CurrentTime->start(0);
	//使用定时器信号槽，尽快更新时间的显示
	init_teams_structarr(teams, MAX_TEAM_NUM);
	connect(CurrentTime, &QTimer::timeout, this, [=]() {
		QDateTime current_time = QDateTime::currentDateTime();
		//显示时间，格式为：年-月-日 时：分：秒 周几
		QString StrCurrentTime = current_time.toString("yyyy-MM-dd hh:mm:ss ddd");
		//时间显示格式可自由设定，如hh:mm ddd 显示 时：分 周几
		//具体格式见函数QString QDateTime::​toString(const QString & format) const
		ui.label->setText(StrCurrentTime);
		ui.textEdit_2->setText("团队创建者：" + users[team_now->leader_id - USER_ID_FORE].usr_name + "\n" + "现有总人数：" + QString::number(teams[team_now->team_id - TEAM_ID_FORE].team_members_nums));
		//更新公告栏
		});

	//设置当前团队的团队名称
	//ui.label_2->setText(user_now.usr_name);
	//users[user_nums - 1].usr_filename

	//双击选中团队
	//connect(ui.tableWidget, &QTableWidget::cellDoubleClicked, this, &calendar_team::on_cellselect);
	//connect(timer, &QTimer::timeout, this, &calendar_team::updateTable);
	//timer->start(1000); // 每隔1秒触发更新
	//关闭窗口后程序不退出
	setAttribute(Qt::WA_QuitOnClose, false);
}
// 读取文件内容并解析为表格数据并更新
void calendar_team::updateTable()
{
	team_now->team_id = team_id.toInt();
	team_now->team_events_filename = QString::number(team_now->team_id) + "_team events.txt";
	//team_now->team_id = team_id_from_TODOsignals.toInt();
	qDebug() << team_now->team_id << " calendar " << team_now->team_events_filename;
	QFile file(team_now->team_events_filename);
	//qDebug() <<"hey there!" << users[USR_ID_NOW - USER_ID_FORE].usr_filename;
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream in(&file);
		// 清空原有表格内容
		ui.tableWidget->clearContents();
		ui.tableWidget->setRowCount(0);
		ui.tableWidget->setColumnCount(7); // 设置列数为7
		// 设置表头为自定义的字符串列表
		ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "日程名称"
			<< "地点" << "开始时间" << "结束时间" << "事件类型" << "紧急程度" << "备注");

		int row = 0; // 行计数器
		while (!in.atEnd()) {
			QString line = in.readLine().trimmed();
			QStringList fields = line.split(",");

			if (fields.size() >= 7) {
				QString content1 = fields[0]; // 第一个字段内容
				QString content2 = fields[1]; // 第二个字段内容
				QString content3 = fields[2]; // 第三个字段内容
				QString content4 = fields[3];
				QString content5 = fields[4];
				QString content6 = fields[5];
				QString content7 = fields[6];
				// 在表格中添加一行
				ui.tableWidget->insertRow(row);

				// 创建QTableWidgetItem并设置内容
				QTableWidgetItem* item1 = new QTableWidgetItem(content1);
				QTableWidgetItem* item2 = new QTableWidgetItem(content2);
				QTableWidgetItem* item3 = new QTableWidgetItem(content3);
				QTableWidgetItem* item4 = new QTableWidgetItem(content4);
				QTableWidgetItem* item5 = new QTableWidgetItem(content5);
				QTableWidgetItem* item6 = new QTableWidgetItem(content6);
				QTableWidgetItem* item7 = new QTableWidgetItem(content7);
				//自动调整每一列的长度
				ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
				//允许用户自己调整
				//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

				// 将QTableWidgetItem添加到表格中的对应位置
				ui.tableWidget->setItem(row, 0, item1);
				ui.tableWidget->setItem(row, 1, item2);
				ui.tableWidget->setItem(row, 2, item3);
				ui.tableWidget->setItem(row, 3, item4);
				ui.tableWidget->setItem(row, 4, item5);
				ui.tableWidget->setItem(row, 5, item6);
				ui.tableWidget->setItem(row, 6, item7);

				row++; // 行计数器递增
			}
		}
		file.close();

		//更新公告栏
		QString ADFilename = QString::number(team_now->team_id) + "_AD.txt";

		//如果用户修改textEdit的内容并按下回车，更新对应的文件内容
		connect(ui.pushButton_4, &QPushButton::clicked, this, [=]() {
			QFile file(ADFilename);
			if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
				return;
			QTextStream out_ad(&file);
			out_ad << ui.textEdit->toPlainText();
			file.close();
			});
		//创建一个文件，存放不同团队的公告栏文本信息，允许团队创始人修改并更新
		//文件名为团队id+"公告.txt"
		//文件内容为团队公告栏的文本信息
		QFile file(ADFilename);
		//读取文件内容并显示在公告栏
		if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
		{
			qDebug() << "打开公告文件失败！";
			return;
		}
		QTextStream in_ad(&file);
		QString line = in_ad.readAll();
		ui.textEdit->setText(line);
		file.close();
	}
}

void calendar_team::set_team_id(QString id)
{
	//team_now是从team_mng传递进来的点击的那个团队
	this->team_id = id;
	team_now = &teams[team_id.toInt() - TEAM_ID_FORE];
	qDebug() << "team_id set_team_id: " << team_id;
	updateTable();
	//设置当前团队的团队名称
	ui.label_2->setText(team_id);
	ui.label_3->setText(QString::number(USR_ID_NOW));
	//增加对当前用户是否是团队创始人的判断，如果不是，pushButton_4变无法点击
	if (team_now->leader_id != USR_ID_NOW) {
		ui.pushButton_4->setEnabled(false);
	}
	else {
		ui.pushButton_4->setEnabled(true);
	}
}

void calendar_team::updateTable_calendar()
{
}

calendar_team::~calendar_team()
{}

//这个函数被迭代掉了
void calendar_team::load_team_Event()
{
	//从当前团队对应的.txt文件中读取事件记录
	QFile team_event_file(team_now->team_events_filename);
	if (!team_event_file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::critical(this, "错误", "文件打开失败");
		return;
	}
}
void calendar_team::team_manage()
{
	team_mng* team_mng1 = new team_mng(this); // create a new window object
	team_mng1->show(); // show the window
}
void calendar_team::handleDate(QDate date) // define the slot function
{
	if (USR_ID_NOW == team_now->leader_id)
	{
		TODO_team* window = new TODO_team(this); // create a new window object
		window->set_team_id(team_id);
		window->show(); // show the window
		connect(window, &TODO_team::TODO_add_team, this, &calendar_team::updateTable);
	}
	else
	{
		//提示用户权限不够
		QMessageBox::information(this, "错误", "您不是团队创始人，没有权限添加事件");
	}
}

// 处理行删除的槽函数
void calendar_team::on_deleteRowButtonClicked() {
	int selectedRow = ui.tableWidget->currentRow();
	ui.tableWidget->removeRow(selectedRow);
	// 更新数据到文件存档中
	updateDataToFile(selectedRow, -1, "");
}

// 更新数据到文件存档中
void calendar_team::updateDataToFile(int row, int column, const QString& newText) {
	QFile file(team_now->team_events_filename);
	if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		QTextStream stream(&file);
		QStringList lines;
		int currentRow = 0; // 当前行索引
		while (!stream.atEnd()) {
			QString line = stream.readLine().trimmed();
			QStringList items = line.split(",");
			if (currentRow == row) {
				if (items.size() > column) {
					// 更新对应位置的文本
					items[column] = newText;
				}
			}
			line = items.join(",");
			lines.append(line);
			currentRow++;
		}
		// 清空文件内容
		file.resize(0);
		// 重新写入更新后的数据
		stream << lines.join("\n");
		file.close();
	}
}

void calendar_team::finished_cellChanged(int row, int column)
{
	QTableWidgetItem* item = ui.tableWidget->item(row, column);
	QString newText = item->text();
	//qDebug() << newText;
	// 更新数据到文件存档中
	updateDataToFile(row, column, newText);
}