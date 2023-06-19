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
#include<QPainter>
#include<QBitmap>
#include<QMap>
using namespace std;
calendar::calendar(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint); //隐藏标题栏
    //this->setAttribute(Qt::WA_TranslucentBackground);   //让窗体实现透明
   // pix.load("微信图片_20230505230404.png");  //加载图片
    //this->resize(pix.size());  //让窗口的大小跟你的图片大小一样
    setWindowOpacity(0.9);
    

    //唤起团队管理界面
    connect(ui.pushButton, &QPushButton::clicked, this, &calendar::team_manage);
    //唤起添加日程界面
    connect(ui.Calendar1, &QCalendarWidget::activated,this , &calendar::handleDate);
    //设置时间显示的字体
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::red);
    ui.label_12->setPalette(palette);
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
        ui.label_12->setText(StrCurrentTime);
        });
    //设置当前用户的用户名
    ui.label_16->setText(user_now.usr_name);
    //users[user_nums - 1].usr_filename

    
  //双击事件选中用户的某个日程
    connect(ui.tableWidget, &QTableWidget::cellDoubleClicked, this, &calendar::on_cellselect);
    //定时更新用户日程
   // connect(timer, &QTimer::timeout, this, &calendar::updateTable);
    //选择不同排序方式展示QTableWidget的内容
    QObject::connect(ui.comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &calendar::onSortComboBoxIndexChanged);


    updateTable();




    //timer->start(500); // 每隔0.5秒触发更新

   
    }
// 读取文件内容并解析为表格数据并更新
void calendar::updateTable()
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
            << "地点" << "开始时间" << "结束时间" << "事件类型" << "紧急程度"  << "备注");

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
//combobox连接的槽函数，根据index调用排序函数
void calendar::onSortComboBoxIndexChanged(int index)
{
    if (index == 1)
    {
        //按照开始时间排序
        sortTableByColumn(ui.tableWidget, 2);
    }
    else if (index == 2)
    {
        // 按照结束时间排序
        sortTableByColumn(ui.tableWidget, 3);
    }
    else if (index == 3)
    {
        //按照紧急程度排序
        sortTableByColumn(ui.tableWidget, 5);
    }
    else updateTable();
    
}
void calendar::sortTableByColumn(QTableWidget* tableWidget, int column)
{
    // 获取行数和列数
    int rowCount = tableWidget->rowCount();

    // 创建一个存储行索引和对应单元格数据的映射
    QMap<int, QList<QTableWidgetItem*>> rowDataMap;

    // 遍历每一行，获取指定列的数据并保存到映射中
    for (int row = 0; row < rowCount; ++row)
    {
        QTableWidgetItem* item = tableWidget->item(row, column);
        if (item)
        {
            QVariant data = item->data(Qt::DisplayRole);
            rowDataMap[row].append(item);
        }
        else
        {
            rowDataMap[row].append(nullptr);
        }
    }

    // 根据数据对行索引进行排序
    QVector<int> sortedRowIndices;
    for (const auto& key : rowDataMap.keys())
    {
        sortedRowIndices.append(key);
    }
    std::sort(sortedRowIndices.begin(), sortedRowIndices.end(), [&rowDataMap](int row1, int row2) {
        QList<QTableWidgetItem*> items1 = rowDataMap.value(row1);
        QList<QTableWidgetItem*> items2 = rowDataMap.value(row2);

        // 根据首个单元格数据进行比较和排序
        QVariant data1 = items1.first() ? items1.first()->data(Qt::DisplayRole) : QVariant();
        QVariant data2 = items2.first() ? items2.first()->data(Qt::DisplayRole) : QVariant();

        if (data1.type() == QVariant::String && data2.type() == QVariant::String && data1.toString().length() > 5 && data2.toString().length() > 5) {
            QString dateString1 = data1.toString();
            QString dateString2 = data2.toString();

            // 解析日期字符串为 QDateTime 对象进行比较
            QDateTime dateTime1 = QDateTime::fromString(dateString1, "yyyy-MM-dd hh:mm:ss");
            QDateTime dateTime2 = QDateTime::fromString(dateString2, "yyyy-MM-dd hh:mm:ss");

            // 根据日期时间进行比较和排序
            return dateTime1 < dateTime2;
        }
        else {
            // 其他情况，根据字符串进行比较和排序
            QString string1 = data1.toString();
            QString string2 = data2.toString();
            return string1 < string2;
        }
        });

    // 根据排序结果重新设置行的顺序
// 创建一个临时列表存储每行的单元格数据
    QList<QList<QTableWidgetItem*>> tempDataList;
    for (int row = 0; row < rowCount; ++row)
    {
        QList<QTableWidgetItem*> rowData;
        for (int column = 0; column < tableWidget->columnCount(); ++column)
        {
            QTableWidgetItem* item = tableWidget->takeItem(row, column);
            rowData.append(item);
        }
        tempDataList.append(rowData);
    }

    // 根据排序结果重新设置行的顺序
    for (int newRow = 0; newRow < rowCount; ++newRow)
    {
        int oldRow = sortedRowIndices[newRow];

        // 从临时列表获取单元格数据
        QList<QTableWidgetItem*> rowData = tempDataList[oldRow];

        // 移动行对应的单元格数据
        for (int column = 0; column < tableWidget->columnCount(); ++column)
        {
            QTableWidgetItem* item = rowData[column]->clone();
            tableWidget->setItem(newRow, column, item);
        }

        // 更新表格的行标签
        tableWidget->verticalHeader()->moveSection(oldRow, newRow);
    }

    // 释放临时列表中的内存
    for (int row = 0; row < rowCount; ++row)
    {
        QList<QTableWidgetItem*> rowData = tempDataList[row];
        for (QTableWidgetItem* item : rowData)
        {
            delete item;
        }
        rowData.clear();
    }
    tempDataList.clear();



}



calendar::~calendar()
{}

//这个函数好像没用上，被另一个函数迭代掉了
void calendar::load_usr_Event()
{
    //从当前用户对应的.txt文件中读取事件记录
    QFile usr_event_file(user_now.usr_filename);
    if (!usr_event_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
		QMessageBox::critical(this, "错误", "文件打开失败");
		return;
	}




}
void calendar::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix);
}
void calendar::team_manage()
{
    team_mng* team_mng1 = new team_mng(this); // create a new window object
    team_mng1->show(); // show the window
   
}
void calendar::handleDate(QDate date) // define the slot function
{

    TODOwidget* addtodo = new TODOwidget(this); // create a new window object
    addtodo->show(); // show the window
    connect(addtodo, &TODOwidget::TODO_add, this, &calendar::updateTable);
}



// 处理单元格文本修改的槽函数
void calendar::on_cellselect(int row, int column) {
   // timer->stop(); // 停止定时器
    /*
    * 错误语法
    connect(ui.pushButton_2, &QPushButton::clicked, [this](int row, int column) { &calendar::finished_cellChanged; });
    */
    connect(ui.pushButton_2, &QPushButton::clicked, [this,row,column]() { finished_cellChanged(row,column); });
    connect(ui.pushButton_3, &QPushButton::clicked, this, &calendar::on_deleteRowButtonClicked);
}

// 处理行删除的槽函数
void calendar::on_deleteRowButtonClicked() {
    int selectedRow = ui.tableWidget->currentRow();
    ui.tableWidget->removeRow(selectedRow);
    //安全删除文件内对应数据行
    QFile file(users[USR_ID_NOW - USER_ID_FORE].usr_filename);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		QTextStream stream(&file);
		QStringList lines;
		int currentRow = 0; // 当前行索引
        while (!stream.atEnd()) {
			QString line = stream.readLine().trimmed();
			QStringList items = line.split(",");
            if (currentRow == selectedRow) {
				// 删除对应位置的文本
				items.clear();
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
    else {
		QMessageBox::critical(this, "错误", "文件打开失败");
		return;
	}
}

// 更新数据到文件存档中
    void calendar::updateDataToFile(int row, int column, const QString & newText) {
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

void calendar::finished_cellChanged(int row,int column)
{
    QTableWidgetItem* item = ui.tableWidget->item(row, column);
    QString newText = item->text();
    //qDebug() << newText;
    // 更新数据到文件存档中
    updateDataToFile(row, column, newText);
    //timer->start(1000);
    updateTable();
}
