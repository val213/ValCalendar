﻿#include "config.h"
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
using namespace std;
calendar_team::calendar_team(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   
    connect(ui.calendarWidget, &QCalendarWidget::activated, this, &calendar_team::handleDate);
    //设置时间显示的字体
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::red);
    ui.label->setPalette(palette);
    //定时器
    QTimer* CurrentTime = new QTimer(this);
    CurrentTime->start(0);
    //使用定时器信号槽，尽快更新时间的显示
    connect(CurrentTime, &QTimer::timeout, [=]() {
        QDateTime current_time = QDateTime::currentDateTime();
        //显示时间，格式为：年-月-日 时：分：秒 周几
        QString StrCurrentTime = current_time.toString("yyyy-MM-dd hh:mm:ss ddd");
        //时间显示格式可自由设定，如hh:mm ddd 显示 时：分 周几 
        //具体格式见函数QString QDateTime::​toString(const QString & format) const
        ui.label->setText(StrCurrentTime);
        });
    //设置当前团队的团队名称
    ui.label_2->setText(user_now.usr_name);
    //users[user_nums - 1].usr_filename


    //双击选中团队
    connect(ui.tableWidget, &QTableWidget::cellDoubleClicked, this, &calendar_team::on_cellselect);
    //connect(timer, &QTimer::timeout, this, &calendar_team::updateTable);
    //timer->start(1000); // 每隔1秒触发更新
    //关闭窗口后程序不退出
    setAttribute(Qt::WA_QuitOnClose, false);

}
// 读取文件内容并解析为表格数据并更新
void calendar_team::updateTable()
{
    QFile file(users[USR_ID_NOW - USER_ID_FORE].usr_filename);
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

    }

}

calendar_team::~calendar_team()
{}
void calendar_team::load_usr_Event()
{
    //从当前用户对应的.txt文件中读取事件记录
    QFile usr_event_file(user_now.usr_filename);
    if (!usr_event_file.open(QIODevice::ReadOnly | QIODevice::Text))
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

    TODOwidget* window = new TODOwidget(this); // create a new window object
    window->show(); // show the window
}



// 处理单元格文本修改的槽函数
void calendar_team::on_cellselect(int row, int column) {
    timer->stop(); // 停止定时器
    /*
    * 错误语法
    connect(ui.pushButton_2, &QPushButton::clicked, [this](int row, int column) { &calendar_team::finished_cellChanged; });
    */
    connect(ui.pushButton_2, &QPushButton::clicked, [this, row, column]() { finished_cellChanged(row, column); });
    connect(ui.pushButton_3, &QPushButton::clicked, this, &calendar_team::on_deleteRowButtonClicked);
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
    QFile file(users[USR_ID_NOW - USER_ID_FORE].usr_filename);
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
    timer->start(1000);
}