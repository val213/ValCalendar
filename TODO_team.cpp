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




    // QWebEngineProfile* profile = ui.webEngineView->page()->profile();
    // connect(ui.webEngineView, &QWebEngineView::loadFinished,this, &TODOwidget::handleWebPageLoadFinished);

}

TODO_team::~TODO_team()
{
}
void TODO_team::set_team_id(QString id)
{
    team_id = id;
    team_now=teams[team_id.toInt() - TEAM_ID_FORE];
}

void TODO_team::save_Date()
{
    qDebug() << "save team new todo!!";
    qDebug()<<"team_id: "<< team_id<<" "<< team_now.team_id;
    team_now.team_events_filename = QString::number(team_now.team_id)+"_team events.txt";
    QFile file(team_now.team_events_filename); //����һ��QFile����ָ��Ҫ������ļ���
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append)) { //��д����ı�ģʽ���ļ�
        QTextStream out(&file); //����һ��QTextStream���󣬹������ļ�
        //�Ŷ��¼�����+1
        team_now.team_events_nums++;
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
        out << start_dateString << " " << start_timeString << ","; //�����ں�ʱ���ַ���д���ļ�

        //��ȡ����ʱ��
        QDate end_date = ui.dateTimeEdit_2->date(); //��ȡdateTimeEdit�е�����
        QTime end_time = ui.dateTimeEdit_2->time();//��ȡdateTimeEdit�е�ʱ��
        QString end_dateString = end_date.toString("yyyy-MM-dd"); //������ת��Ϊ�ַ�����ʽ
        QString end_timeString = end_time.toString("hh:mm:ss"); //��ʱ��ת��Ϊ�ַ�����ʽ
        out << end_dateString << " " << end_timeString << ",";//�����ں�ʱ���ַ���д���ļ�


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

        out << "\n";
        qDebug() << "save team new todo ok!";
        file.close(); //�ر��ļ�
    }
    
}

void TODO_team::TODO_team_accepted()
    {
        this->save_Date();
        
        emit TODO_add_team();
        this->close();
        //�����źŸ�calendar
    }