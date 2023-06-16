#include"config.h"
#include<qwebchannel.h>
#include <QWebEngineSettings>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QWebEngineView>

TODOwidget::TODOwidget(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    this->setWindowTitle("Add to do");
	connect(ui.buttonBox,&QDialogButtonBox::accepted,this,&TODOwidget::TODOwidget_accepted);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &TODOwidget::close);



    JSBridge = new bridge(this);
    QWebChannel* channel = new QWebChannel(this);
    channel->registerObject("bridge", JSBridge); // 将对象名称改为"bridge"
    ui.webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);


    ui.webEngineView->page()->setWebChannel(channel);
    ui.webEngineView->page()->load(QUrl("./Baidu_JS/BDmap.html"));

    connect(JSBridge, &bridge::DisplayPoint, this, &TODOwidget::DisplaySlot);
   // QWebEngineProfile* profile = ui.webEngineView->page()->profile();
   // connect(ui.webEngineView, &QWebEngineView::loadFinished,this, &TODOwidget::handleWebPageLoadFinished);


}
void TODOwidget::DisplaySlot(QString lng, QString lat)
{
	qDebug() << lng << "," << lat;
	ui.lineEdit_3->setText(lng);
	ui.lineEdit_4->setText(lat);
}

void  TODOwidget::on_pushButton_clicked()
{
    QString context = ui.lineEdit_4->text();
    if (!context.contains(','))
    {
        qDebug() << "wrong input format";        //输入格式 经度+纬度，中间以英文逗号‘,’隔开
        return;
    }
    QString lng = context.split(',').at(0);
    QString lat = context.split(',').at(1);

    ui.webEngineView->page()->runJavaScript(QString("SetPoint(%1,%2)").arg(lng).arg(lat));
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
        out << start_dateString<<" "<<start_timeString << ","; //将日期和时间字符串写入文件

        //获取结束时间
        QDate end_date = ui.dateTimeEdit_2->date(); //获取dateTimeEdit中的日期
        QTime end_time = ui.dateTimeEdit_2->time();//获取dateTimeEdit中的时间
        QString end_dateString = end_date.toString("yyyy-MM-dd"); //将日期转换为字符串格式
        QString end_timeString = end_time.toString("hh:mm:ss"); //将时间转换为字符串格式
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

}

void TODOwidget::TODOwidget_accepted()
{
	this->save_Date();
	this->close();
    //发送信号给calendar
    emit TODO_add();
}

void TODOwidget::handleWebPageLoadFinished(bool success)
{
    if (success) {
        ui.webEngineView->page()->runJavaScript("console.log = function(message) {"
            "    window.qwebchannel.javascriptConsoleMessage(message);"
            "};");
    }
    else {
		qDebug() << "Web page load failed!";
    }
}

void TODOwidget::handleJavaScriptConsoleMessage(const QString& message)
{
    qDebug() << "JavaScript Console Message:" << message;
}
