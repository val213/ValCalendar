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



    //JSBridge = new bridge(this);
    //QWebChannel* channel = new QWebChannel(this);
    //channel->registerObject("bridge", JSBridge); // 将对象名称改为"bridge"
   // ui.webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    //ui.webEngineView->setGeometry(QRect(10, 30, 581, 341));// 设置锚点与大小
    //ui.webEngineView->load(QUrl("C:\\Users\\yangluwei\\source\\repos\\calendar\\calendar\\Baidu_JS\\BDmap.html"));
    QString path = QApplication::applicationDirPath() + "/BDmap.html";  //将html文件放入debug目录下
    //qDebug() << __FUNCTION__ << path;
    //ui.webEngineView->load(QUrl(u8"file:///C:/Users/yangluwei/source/repos/calendar/calendar/Baidu_JS/BDmap.html"));
    //ui.webEngineView->load(QUrl::fromLocalFile(path));

    ui.webEngineView->load(QUrl("https://map.baidu.com/search/%E5%8D%8E%E5%8D%97%E7%90%86%E5%B7%A5%E5%A4%A7%E5%AD%A6%E7%94%9F%E6%B4%BB%E5%8C%BA-c10%E6%A0%8B%E5%AD%A6%E7%94%9F%E5%85%AC%E5%AF%93/@12624641.275,2622040.17,19z?querytype=s&da_src=shareurl&wd=%E5%8D%8E%E5%8D%97%E7%90%86%E5%B7%A5%E5%A4%A7%E5%AD%A6%E7%94%9F%E6%B4%BB%E5%8C%BA-C10%E6%A0%8B%E5%AD%A6%E7%94%9F%E5%85%AC%E5%AF%93&c=25&src=0&wd2=%E5%B9%BF%E5%B7%9E%E5%B8%82%E7%95%AA%E7%A6%BA%E5%8C%BA&pn=0&sug=1&l=10&b=(12829376.05403883,4629568.744784641;13188689.18733266,4841930.870945831)&from=webmap&biz_forward=%7B%22scaler%22:2,%22styles%22:%22pl%22%7D&sug_forward=7496367a5f075bf0b9df8fd2&device_ratio=2"));  // 加载目标网页

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

    //ui.webEngineView->setZoomFactor(1.2);  // 调整缩放因子以适应页面大小

    ui.webEngineView->show();
   // ui.webEngineView->page()->setWebChannel(channel);
    
    /*
    QString htmlPath = QCoreApplication::applicationDirPath() + "Baidu_JS/BDmap.html";//从此html文件中读取内容后写入webview
    QUrl baseUrl = QCoreApplication::applicationDirPath() + "/Baidu_JS/";//外部对象，包括以下CSS和js文件
    QFile file(htmlPath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QString htmlData = file.readAll().constData();
    file.close();
    ui.webEngineView->setHtml(htmlData, baseUrl);
    */

    //ui.webEngineView->show();
   
   // connect(ui.webEngineView, &QWebEngineView::loadFinished,this, &TODOwidget::handleWebPageLoadFinished);
   // connect(JSBridge, &bridge::DisplayPoint, this, &TODOwidget::DisplaySlot);
    ui.webEngineView->show();

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
