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

    JSBridge = new bridge(ui.webEngineView, this); 
    QWebChannel* channel = new QWebChannel(this);
    channel->registerObject("bridge", JSBridge); // ���������Ƹ�Ϊ"bridge"


    ui.webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    ui.webEngineView->settings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);
    // �� QWebChannel ����󶨵� view �� profile ��
    ui.webEngineView->page()->setWebChannel(channel);


    //ui.webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    //ui.webEngineView->setGeometry(QRect(10, 30, 581, 341));// ����ê�����С
    //ui.webEngineView->load(QUrl("C:\\Users\\yangluwei\\source\\repos\\calendar\\calendar\\Baidu_JS\\BDmap.html"));
    //QString path = QApplication::applicationDirPath() + "/BDmap.html";  //��html�ļ�����debugĿ¼��
    //qDebug() << __FUNCTION__ << path;
    ui.webEngineView->load(QUrl("qrc:/calendar/Baidu_JS/BDmap.html"));
    //ui.webEngineView->load(QUrl::fromLocalFile(path));

    //ui.webEngineView->load(QUrl(u8"https://www.ditu6.com/walk/"));  // ����Ŀ����ҳ

    connect(ui.webEngineView, &QWebEngineView::loadFinished, [](bool ok) {
        if (ok) {
            // ҳ�������ɺ�ִ�еĲ���
            qDebug() << "Page loaded successfully";
  
           
        }
        else {
            // ҳ�����ʧ��ʱִ�еĲ���
            qDebug() << "Page failed to load";
        }
        });
    connect(ui.calculateButton, &QPushButton::clicked, this, &TODOwidget::onCalculateButtonClicked);
    connect(JSBridge, &bridge::distanceAndTimeCalculated, this, &TODOwidget::onDistanceAndTimeCalculated);

    ui.webEngineView->show();

       
    //ui.webEngineView->setZoomFactor(1.2);  // ����������������Ӧҳ���С

    
   // ui.webEngineView->page()->setWebChannel(channel);
    
    /*
    QString htmlPath = QCoreApplication::applicationDirPath() + "Baidu_JS/BDmap.html";//�Ӵ�html�ļ��ж�ȡ���ݺ�д��webview
    QUrl baseUrl = QCoreApplication::applicationDirPath() + "/Baidu_JS/";//�ⲿ���󣬰�������CSS��js�ļ�
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
}



void TODOwidget::onCalculateButtonClicked()
{
    // ��ȡ�����յ��������ı�
    QString start = ui.startInput->text();
    QString end = ui.endInput->text();

    // ����JSBridge�Ĳۺ������������յ㴫�ݸ�JS�ļ�
    JSBridge->setStartAndEnd(start, end);
}

// �ۺ��������ڽ��ռ�����������QT�е��ı���
void TODOwidget::onDistanceAndTimeCalculated(const QString& duration, const QString& distance)
{
    // �����ı�����ʾ������
    ui.distanceOutput->setText(duration);
    ui.durationOutput->setText(distance);
}

TODOwidget::~TODOwidget()
{
}
void TODOwidget::save_Date()
{

    QFile file(user_now.usr_filename); //����һ��QFile����ָ��Ҫ������ļ���
    if (file.open(QIODevice::WriteOnly | QIODevice::Text| QFile::Append)) { //��д����ı�ģʽ���ļ�
        QTextStream out(&file); //����һ��QTextStream���󣬹������ļ�
        //����һ��
        out << "\n";
        //���ı��༭�������д���ļ�
        //д���¼�����
        out << ui.lineEdit->text() << ",";
        //д��ص�
       out << ui.lineEdit_3->text() << ",";
        //��ȡ��ʼʱ��
        QDate start_date = ui.dateTimeEdit->date(); //��ȡdateTimeEdit�е�����
        QTime start_time = ui.dateTimeEdit->time();//��ȡdateTimeEdit�е�ʱ��
        QString start_dateString = start_date.toString("yyyy-MM-dd"); //������ת��Ϊ�ַ�����ʽ
        QString start_timeString = start_time.toString("hh:mm:ss"); //��ʱ��ת��Ϊ�ַ�����ʽ
        out << start_dateString<<" "<<start_timeString << ","; //�����ں�ʱ���ַ���д���ļ�

        //��ȡ����ʱ��
        QDate end_date = ui.dateTimeEdit_2->date(); //��ȡdateTimeEdit�е�����
        QTime end_time = ui.dateTimeEdit_2->time();//��ȡdateTimeEdit�е�ʱ��
        QString end_dateString = end_date.toString("yyyy-MM-dd"); //������ת��Ϊ�ַ�����ʽ
        QString end_timeString = end_time.toString("hh:mm:ss"); //��ʱ��ת��Ϊ�ַ�����ʽ
        out << end_dateString <<" "<<  end_timeString << ",";//�����ں�ʱ���ַ���д���ļ�


        //д���¼�����
        // ����������ؼ�������Ϊ comboBox
        QComboBox* comboBox = findChild<QComboBox*>("comboBox");  // ��ȡ������ؼ���ָ��

        if (comboBox) {
            QString selectedText = comboBox->currentText();  // ��ȡ��ǰѡ������ı�ֵ
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
        //д������̶�
        out << urgentdegree << ",";
        //��ע
        out << ui.textEdit->toPlainText() << ",";

        out <<"\n";
        file.close(); //�ر��ļ�
    }

}

void TODOwidget::TODOwidget_accepted()
{
	this->save_Date();
	this->close();
    //�����źŸ�calendar
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
