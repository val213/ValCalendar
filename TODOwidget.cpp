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
    channel->registerObject("bridge", JSBridge); // ���������Ƹ�Ϊ"bridge"
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
        qDebug() << "wrong input format";        //�����ʽ ����+γ�ȣ��м���Ӣ�Ķ��š�,������
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
