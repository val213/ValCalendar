#include"config.h"
#include<QInputDialog>
#include<QTextStream>
//��ʼ����ǰ�û�id�� USER_ID_FORE(1001)�������û�id���µ�ʱ���ͬ������
int USR_ID_NOW= USER_ID_FORE;
reg_n_login::reg_n_login(QDialog* parent)
{
	ui.setupUi(this);
	setWindowOpacity(0.9);
	

	this->setStyleSheet("background: url(:/calendar/111.jpg);");//���ڱ�������
	//��setStyleSheet("background-image: url(:/image/profile.png);")
	ui.lineEdit->setEchoMode(QLineEdit::Password);//��������
	ui.lineEdit_3->setStyleSheet("font: 25 14pt '΢���ź� Light';" //����
		"color: rgb(31,31,31);"		//������ɫ
		"padding-left:10px;"       //�ڱ߾�-��������
		"background-color: rgb(255, 255, 255);" //������ɫ
		"border:2px solid rgb(20,196,188);border-radius:15px;");//�߿��ϸ-��ɫ-Բ������ 
	ui.lineEdit->setStyleSheet("font: 25 14pt '΢���ź� Light';" //����
		"color: rgb(31,31,31);"		//������ɫ
		"padding-left:10px;"       //�ڱ߾�-��������
		"background-color: rgb(255, 255, 255);" //������ɫ
		"border:2px solid rgb(20,196,188);border-radius:15px;");//�߿��ϸ-��ɫ-Բ������ 

	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &reg_n_login::reg_n_login_accepted);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

	
}

reg_n_login::~reg_n_login()
{
}

void reg_n_login::reg_n_login_accepted()
{

	//��ȡlineEdit��lineEdit_3������,���id������������������ʾ
	if (ui.lineEdit_3->text().toInt() == 0|| ui.lineEdit_3->text().toInt()< USER_ID_FORE || ui.lineEdit_3->text().toInt()>1100)
	{
		QMessageBox err;
		err.setText("Please check the ID format! (1001~1100)");
		err.exec();
		this->show();
	}
	else
	{
		USR_ID = ui.lineEdit_3->text().toInt();
		USR_PSWD = ui.lineEdit->text();
		USR_ID_NOW = USR_ID;
		/*
		return��
		�������˺ţ�	1
		��½�ɹ���		2
		�������		3
		���ص�½���棺  4
		*/
		int check_usr_result =checkusr(USR_ID, USR_PSWD);
		if (check_usr_result == 1)
			{
			save_USER();
			QMessageBox::information(nullptr, "Successful registration", "Welcome to ValCalendar!");
			this->show();
			}
		else if (check_usr_result == 2)
			{
				calendar* cal = new calendar; // create a new window object
				//��ʽ��
				cal->setStyleSheet(R"(
        QWidget {
            background-color: #E1F5FE;
            color: #000000;
        }

        QPushButton {
            background-color: #FCE4EC;
            border: 1px solid #FCE4EC;
            padding: 5px;
            border-radius: 3px;
            color: #000000;
        }

        QLineEdit {
            background-color: #FFFFFF;
            border: 1px solid #E1F5FE;
            padding: 5px;
            color: #000000;
        }

        QLabel {
            color: #000000;
        }
    )");
				cal->show(); // show the window
			}
		else if (check_usr_result == 3)
			{
				this->show();
			}
		else
			{
				this->show();
			}
	}

}
	

	
void reg_n_login::reg_n_login_rejected()
{
	this->close();
}


	void reg_n_login::save_USER()
	{
		//��ṹ��������д���µ��û����ݣ��������û�����
		//user_nums��ֵ���ݶ����ļ����û������Ķ���ʵʱ����
		users[user_nums-1].usr_id = USR_ID;
		users[user_nums-1].usr_passwd = USR_PSWD;
		//���û������û���
		QString user_name = QInputDialog::getText(this, "Input", "Please input your name:", QLineEdit::Normal, "USER");

		QString filename= "usr_";
		QString file_back = ".txt";
		filename += user_name;
		filename += file_back;// ���ַ���ĩβ�����һ���ַ���
		users[user_nums - 1].usr_name = user_name;
		users[user_nums - 1].usr_filename = filename;
		users[user_nums - 1].usr_team_create_filename= "team_create_" + filename;
		users[user_nums - 1].usr_team_belong_filename = "team_belong_" + filename;
		users[user_nums - 1].usr_team_create_num=0;
		users[user_nums - 1].usr_team_belong_num=0;

		//���û�����д���ļ�
		
		QFile file("USERS.txt"); //����һ��QFile����ָ��Ҫ������ļ���
		if (file.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append)) { //��д����ı�ģʽ���ļ�
			QTextStream out(&file); //����һ��QTextStream���󣬹������ļ�
			//���û���Ϣ����txt�ļ�
			/*
			struct USER
			{
				int usr_id;
				QString usr_passwd;
				QString usr_name;
				QString usr_filename;
				QVector<QString>teams_create;
				QVector<QString>teams_belong;
			};
			*/
			out << "-----------------------------------" << "\n";
			out << users[user_nums - 1].usr_id<<",";
			out << users[user_nums - 1].usr_passwd<<",";
			out << users[user_nums - 1].usr_name << ",";
			out << users[user_nums - 1].usr_filename << ",";
			out << users[user_nums - 1].usr_team_create_filename << ",";
			out << users[user_nums - 1].usr_team_belong_filename << ",";
			out << users[user_nums - 1].usr_team_create_num << ",";
			out << users[user_nums - 1].usr_team_belong_num << ",";
			out << "\n";
			file.close(); //�ر��ļ�
		}
		else {
			QMessageBox::warning(this, "Error", "Save failed!"); //����ʧ���򵯳�����Ի���
		}

	}

int reg_n_login::checkusr(int USR_ID, QString USR_PSWD)
{
	/*
	return��
	�������˺ţ�	1
	��½�ɹ���		2
	�������		3
	���ص�½���棺  4
	*/
	//id���벻�Ϸ�
	if (users[USR_ID- USER_ID_FORE].usr_id==0)
	{
		//�û�������
		//��ʾ�û������ڣ��Ƿ�Ҫע�����˺�
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(nullptr, "User does not exist", "Are you sure to create a new user?",
			QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			// �û�����ˡ��ǡ���ť
			//�������˺�
			return 1;
		}
		else {
			// �û�����ˡ��񡱰�ť
			// ִ����Ӧ�Ĳ���

			return 4;
		}
		
	}
	//id����Ϸ���������ȷ
	else if (users[USR_ID- USER_ID_FORE].usr_passwd == USR_PSWD)
	{
		//��½�ɹ�
		QMessageBox::information(nullptr, "Successful login", "Welcome to ValCalendar!");
		return 2;
	}
	//id����Ϸ������������
	QMessageBox::critical(nullptr, "Password error", "Please enter the correct password!");
	return 3;

}



/*
QString USR_ID=ui.lineEdit_3->text();
QString USR_PSWD=ui.lineEdit->text();
QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("MyDataBase.db");
db.setUserName("XingYeZhiXia");
db.setPassword("123456");

if (!db.open()) {
	qDebug() << "Error: Failed to connect database." << db.lastError();
}
else
{
	qDebug() << "successfully!";
	// ����ִ��sql���Ķ���
	QSqlQuery sqlQuery;

	// �����������ݿ��sql����ַ���
	QString createSql = QString("CREATE TABLE usr(\
					  usr_id INT PRIMARY KEY NOT NULL,\
					  usr_pswd TEXT NOT NULL)");
	sqlQuery.prepare(createSql);
	// ִ��sql���
		if (!sqlQuery.exec())
	{
		qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
	}
	else
	{
		qDebug() << "Table created!";
	}

}
db.close();
*/