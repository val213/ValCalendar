#include"config.h"
#include<qwebchannel.h>
#include <QWebEngineSettings>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineView>
TODOwidget::TODOwidget(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    this->setWindowTitle("Add to do");
	connect(ui.buttonBox,&QDialogButtonBox::accepted,this,&TODOwidget::TODOwidget_accepted);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &TODOwidget::close);
    /*
    * 地图加载功能已经转移到MapWidget
    ui.webEngineView->show();
    
    JSBridge = new bridge(ui.webEngineView, this); 
    QWebChannel* channel = new QWebChannel(this);
    channel->registerObject("bridge", JSBridge); // 将对象名称改为"bridge"


    ui.webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    ui.webEngineView->settings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);
    // 将 QWebChannel 对象绑定到 view 的 profile 中
    ui.webEngineView->page()->setWebChannel(channel);
    ui.webEngineView->load(QUrl("qrc:/calendar/Baidu_JS/BDmap.html"));

    connect(ui.webEngineView, &QWebEngineView::loadFinished, [](bool ok) {
        if (ok) {
            // 页面加载完成后执行的操作
            qDebug() << "Page loaded successfully";


        }
        else {
            // 页面加载失败时执行的操作
            qDebug() << "Page failed to load";
        }
        });
    
    connect(JSBridge, &bridge::distanceAndTimeCalculated, this, &TODOwidget::onDistanceAndTimeCalculated);

    ui.webEngineView->page()->setDevToolsPage(ui.webEngineView->page());

    
    connect(ui.calculateButton, &QPushButton::clicked, this, &TODOwidget::onCalculateButtonClicked);
    */
}





TODOwidget::~TODOwidget()
{
}
void TODOwidget::save_Date()
{

    QFile file(user_now.usr_filename); //创建一个QFile对象，指定要保存的文件名
    if (file.open(QIODevice::WriteOnly | QIODevice::Text| QFile::Append)) { //以写入和文本模式打开文件
        QTextStream out(&file); //创建一个QTextStream对象，关联到文件
        //另起一行
        out << "\n";
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
       

        //获取结束时间
        QDate end_date = ui.dateTimeEdit_2->date(); //获取dateTimeEdit中的日期
        QTime end_time = ui.dateTimeEdit_2->time();//获取dateTimeEdit中的时间
        QString end_dateString = end_date.toString("yyyy-MM-dd"); //将日期转换为字符串格式
        QString end_timeString = end_time.toString("hh:mm:ss"); //将时间转换为字符串格式
       

         out << start_dateString<<" "<<start_timeString << ","; //将日期和时间字符串写入文件
         out << end_dateString <<" "<<  end_timeString << ",";//将日期和时间字符串写入文件
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

        out <<"\n";
        file.close(); //关闭文件
    }
    emit TODO_Add_Correct();
}

int TODOwidget::check_todo()
{
    QDate start_date = ui.dateTimeEdit->date(); //获取dateTimeEdit中的日期
    QTime start_time = ui.dateTimeEdit->time();//获取dateTimeEdit中的时间
    QString start_dateString = start_date.toString("yyyy-MM-dd"); //将日期转换为字符串格式
    QString start_timeString = start_time.toString("hh:mm:ss"); //将时间转换为字符串格式


    //获取结束时间
    QDate end_date = ui.dateTimeEdit_2->date(); //获取dateTimeEdit中的日期
    QTime end_time = ui.dateTimeEdit_2->time();//获取dateTimeEdit中的时间
    QString end_dateString = end_date.toString("yyyy-MM-dd"); //将日期转换为字符串格式
    QString end_timeString = end_time.toString("hh:mm:ss"); //将时间转换为字符串格式

    //判断起始时间是否合理，开始时间必须不晚于结束时间
    if (start_date > end_date)
    {
        QMessageBox::warning(this, "警告", "开始时间不能晚于结束时间");

        //关闭提示框
        return 0;

    }
    return 1;
}

void TODOwidget::TODOwidget_accepted()
{
    //如果日程添加合法
    if (this->check_todo())
    {
    this->save_Date();
    //关闭窗口
    this->close();
    //发送信号给calendar
    emit TODO_add();
    }
	
    
    
	
}
