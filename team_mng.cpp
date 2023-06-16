#include"config.h"
#include"team_mng.h"
#include"usr_mng.h"
#include"struct.h"
#include<qregularexpression.h>
#include<qmessagebox.h>
#include"calendar_team.h"
//�����Ŷӵļ���
TEAM teams[MAX_TEAM_NUM];
unsigned int team_nums;
extern USER users[MAX_USRS_NUM];
extern int USR_ID_NOW;
QVector<TEAM> myteam_create=users[USR_ID_NOW- USER_ID_FORE].teams_create;
QVector<TEAM> myteam_belong=users[USR_ID_NOW- USER_ID_FORE].teams_belong;
team_mng::team_mng(QWidget* parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Team Management");

	//�����Ŷ�
	connect(ui.pushButton, &QPushButton::clicked,this,&team_mng::create_new_team);
	//�����Ŷ�
	connect(ui.pushButton_4, &QPushButton::clicked, this, &team_mng::join_team);
	//ɾ���Ŷ�
	connect(ui.pushButton_3, &QPushButton::clicked, this, &team_mng::delete_team);
	//�˳��Ŷ�
	connect(ui.pushButton_6, &QPushButton::clicked, this, &team_mng::exit_team);

	//˫���¼�ѡ��ĳ���Ŷ�
	connect(ui.tableWidget, &QTableWidget::clicked, this, &team_mng::on_cellselect);
	updateTable_team();
	//connect(timer_team, &QTimer::timeout, this, &team_mng::updateTable_team);
	//timer_team->start(1000); // ÿ��1�봥������
	//���ڹر�֮������˳�
	setAttribute(Qt::WA_QuitOnClose, false);
}
void team_mng::on_cellselect(const QModelIndex& index) {
	connect(ui.pushButton_6, &QPushButton::clicked, this, [=]() {
		on_exit_team_ButtonClicked(index);
		});

	connect(ui.pushButton_3, &QPushButton::clicked, this, [=]() {
		on_delete_team_ButtonClicked(index);
		});
}

void team_mng::on_exit_team_ButtonClicked(const QModelIndex& index)
{
	int selectedRow = ui.tableWidget->currentRow();  // ��ȡѡ���к�
	if (selectedRow < 0) return;

	qDebug() << "selectedRow: " << selectedRow;
	QTableWidgetItem* item = ui.tableWidget->item(selectedRow, 0);  // ��ȡѡ���еĵ�һ�е�Ԫ�����
	QVariant data = item->data(Qt::DisplayRole);  // ��ȡ��Ԫ������
	int team_id = data.toInt();  // ������ת��Ϊ���������
	qDebug() << "Selected team_id:" << team_id;
	
	
	ui.tableWidget->removeRow(selectedRow);
	//��ȫɾ���û��Ĵ����Ŷ��ļ��ڵĶ�Ӧ������
	QFile file_usr_belong(users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename);
	if (file_usr_belong.open(QIODevice::ReadWrite | QIODevice::Text)) {
		QTextStream stream(&file_usr_belong);
		QStringList lines; // �����ļ���������
		int currentRow = 0; // ��ǰ������
		while (!stream.atEnd()) {
			QString line = stream.readLine().trimmed();
			QStringList items = line.split(",");
			if (currentRow == selectedRow) {
				// ɾ����Ӧλ�õ��ı�
				items.clear();
			}
			line = items.join(",");
			lines.append(line);
			currentRow++;
		}
		// ����ļ�����
		file_usr_belong.resize(0);
		// ����д����º������
		stream << lines.join("\n");
		file_usr_belong.close();
	}
	else {
		QMessageBox::critical(this, "error", "file open fail");
		return;
	}
	//��ȫɾ���û��������Ŷӵĳ�Ա�ļ��ڵĶ�Ӧ����
	

		QFile file_team_members(teams[team_id - TEAM_ID_FORE].team_members_filename);
		if (file_team_members.open(QIODevice::ReadWrite | QIODevice::Text)) {
			QTextStream stream(&file_team_members);
			QStringList lines; // �����ļ���������
			int currentRow = 0; // ��ǰ������
			//�ļ��洢�ĸ�ʽ��4,1001,1002,1003,1004,
			//�����ļ�����
			// ����ļ�����
			file_team_members.resize(0);
			//�����Ŷ�����
			//�ѵ�ǰ�û����Ŷӵĳ�Ա��ɾȥ
			//int index_usr = teams[team_id - TEAM_ID_FORE].team_members.indexOf(USR_ID_NOW);
			//��������������У���Ҫ����������������Ԫ������ T �Ķ������������������operator==����������QVector ���ܹ���ȷ�Ƚ�Ԫ�ص������
			//����teams[team_id - TEAM_ID_FORE].team_members�е�ÿ��USER�ṹ���е�id�Ƿ�͵�ǰ���û�idһ�£����һ�£�����������ִ��ɾ��ָ��
			//����������
			for (auto it = teams[team_id - TEAM_ID_FORE].team_members.begin(); it != teams[team_id - TEAM_ID_FORE].team_members.end(); it++)
			{
				if (it->usr_id == USR_ID_NOW)
				{
					teams[team_id - TEAM_ID_FORE].team_members.erase(it);  //ɾ����-1
				}
			}
			qDebug() << teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";
			//�ѵ�ǰ�Ŷӵĳ�Ա������һ
			teams[team_id - TEAM_ID_FORE].team_members_nums--;
			qDebug() << teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";
			//���¸��Ŷ������г�Ա�ڴ����Ŷ��ļ��д洢�ĸ��Ŷӵ���Ա����
			for (int i = 0; i < teams[team_id - TEAM_ID_FORE].team_members_nums; i++)
			{
				//�������ݵ��ļ��浵��
				//������ļ�
				QString filename = users[teams[team_id - TEAM_ID_FORE].team_members[i].usr_id - USER_ID_FORE].usr_team_belong_filename;
				QFile team_file(filename);
				if (!team_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
					return;
				QTextStream out(&team_file);
				team_file.resize(0);
				//4,1001,1002,1003,1004,
				//д���µ�����
				//д��ʣ��ĳ�Աid
				out << teams[team_id - TEAM_ID_FORE].team_members[i].usr_team_belong_num << ",";
				qDebug() << teams[team_id - TEAM_ID_FORE].team_members[i].usr_team_belong_num;


				file_team_members.close();
			}

		}
		else {
			QMessageBox::critical(this, "error", "file open fail");
			return;
		}
	
}
void team_mng::on_delete_team_ButtonClicked(const QModelIndex& index)
{
	int selectedRow = ui.tableWidget_2->currentRow();  // ��ȡ��ǰѡ�е�������
	if (selectedRow >= 0) {
		QTableWidgetItem* item = ui.tableWidget_2->item(selectedRow, 0);  // ��ȡѡ���еĵ�һ�е�Ԫ�����
		QVariant data = item->data(Qt::DisplayRole);  // ��ȡ��Ԫ������
		int team_id = data.toInt();  // ������ת��Ϊ���������
		qDebug() << "Selected team_id:" << team_id;
	}

}
team_mng::~team_mng()
{

}

void team_mng::create_new_team()
{
	
	QWidget* new_team = new QWidget;
	new_team->setWindowTitle("Create New Team");
	new_team->setFixedSize(300, 250); // ���ù̶���С�����ⴰ�ڴ�С�ɵ���

	QLabel* label = new QLabel(new_team);
	QLabel* label_2 = new QLabel(new_team);
	label->setText("Input the name of the new team");
	label->setAlignment(Qt::AlignCenter); // ���ж���
	label->setGeometry(20, 20, 260, 30); // ����λ�úʹ�С

	QLineEdit* lineEdit = new QLineEdit(new_team);
	lineEdit->setGeometry(20, 60, 260, 30); // ����λ�úʹ�С

	label_2->setText("Input the password of the team");
	label_2->setAlignment(Qt::AlignCenter); // ���ж���
	label_2->setGeometry(20, 100, 260, 30); // ����λ�úʹ�С

	QLineEdit* lineEdit_2 = new QLineEdit(new_team);
	lineEdit_2->setGeometry(20, 140, 260, 30); // ����λ�úʹ�С


	QPushButton* pushButton = new QPushButton("OK", new_team);
	pushButton->setGeometry(60, 180, 80, 30); // ����λ�úʹ�С

	QPushButton* pushButton_2 = new QPushButton("Cancel", new_team);
	pushButton_2->setGeometry(160, 180, 80, 30); // ����λ�úʹ�С

	new_team->show();
	

	//ȷ�ϴ���
	connect(pushButton, &QPushButton::clicked, this, [this, lineEdit, lineEdit_2,new_team]() {
		confirm_creat(lineEdit->text(), lineEdit_2->text());
		new_team->close();
		});
	//ȡ������
	connect(pushButton_2, &QPushButton::clicked, new_team, &QWidget::close);
	


}


void team_mng::delete_team()
{
	//����ǲ��������Ͻ�team_create����һ����������
	//��һ��QTableView�ؼ�չʾ��ǰ�û�������������Ŷ�
	//�ȼ�鵱ǰ�û��Ƿ��д����Ŷӣ����û�У�����ʾ

	//ѡ�ж�Ӧ���Ŷӣ���ȷ���Ƿ����ɾ������
}

void team_mng::join_team()
{
	QWidget* new_team = new QWidget;
	new_team->setWindowTitle("Join Team");
	new_team->setFixedSize(300, 250); // ���ù̶���С�����ⴰ�ڴ�С�ɵ���

	QLabel* label = new QLabel(new_team);
	QLabel* label_2 = new QLabel(new_team);

	label->setText("Input the id of the team");
	label->setAlignment(Qt::AlignCenter); // ���ж���
	label->setGeometry(20, 20, 260, 30); // ����λ�úʹ�С

	QLineEdit* lineEdit = new QLineEdit(new_team);
	lineEdit->setGeometry(20, 60, 260, 30); // ����λ�úʹ�С

	label_2->setText("Input the password of the team");
	label_2->setAlignment(Qt::AlignCenter); // ���ж���
	label_2->setGeometry(20, 100, 260, 30); // ����λ�úʹ�С

	QLineEdit* lineEdit_2 = new QLineEdit(new_team);
	lineEdit_2->setGeometry(20, 140, 260, 30); // ����λ�úʹ�С

	
	QPushButton* pushButton = new QPushButton("Join", new_team);
	pushButton->setGeometry(60, 180, 80, 30); // ����λ�úʹ�С



	new_team->show();

	connect(pushButton, &QPushButton::clicked, this, [this, lineEdit, lineEdit_2, new_team]() {
		confirm_join(lineEdit->text().toInt(), lineEdit_2->text());
		new_team->close();
		});

}

void team_mng::confirm_join(const int& team_id, const QString& team_password)
{
	//qDebug() << "confirm_join" << "\n";
	// Check if team_id - TEAM_ID_FORE is within range
	if (team_id - TEAM_ID_FORE >= 0 && team_id - TEAM_ID_FORE < MAX_TEAM_NUM)
	{
		// Access teams[team_id - TEAM_ID_FORE]
		qDebug() << "team_join index ok" << "\n";
	}
	else
	{
		// Handle out of range error
		qDebug() << team_id - TEAM_ID_FORE << " " << team_id << "\n";
	}	
	if (USR_ID_NOW - USER_ID_FORE >= 0 && USR_ID_NOW - USER_ID_FORE < MAX_USRS_NUM)
	{
		qDebug() << "usr_join index ok" << "\n";
	}
	else
	{
		// Handle out of range error
		qDebug() << USR_ID_NOW - USER_ID_FORE << " " << USR_ID_NOW << "\n";
	}

	//��ʼ����ǰ�Ŷӵ��ļ���Ϣ��ȡ
	QString filename = QString::number(team_id) + "_team members.txt";
	QFile team_members_file(filename);
	if (!team_members_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
	return;
	QTextStream out(&team_members_file);
	//���ļ��е�����д���Ӧ�Ŷӵĳ�Ա��
	//�ȶ�ȡ�ļ��е�����
	out.seek(0);
	QString line;
	QTextStream in(&team_members_file);
	QRegularExpression re(",$");

	line = in.readLine().trimmed().replace(re, "");
	QStringList list = line.split(",");
	qDebug() << line << " "<<list;
	qDebug() << list.size();
	//1,1001"   QList("1", "1001")
	//2
	
	//����û�����
	//�Ŷ�idΪ��
	if (teams[team_id - TEAM_ID_FORE].team_id == 0)
	{
		//��ʾ�ŶӲ�����
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, "Error", "The team does not exist", QMessageBox::Yes);
	}
	else if (teams[team_id - TEAM_ID_FORE].team_passwd != team_password)
	{
		//�ŶӴ��ڵ������������ʾ
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, "Error", "The password is wrong", QMessageBox::Yes);
	}
	else
	{
		//�Ŷ���Ϣ����֮���жϵ�ǰ�û��Ƿ��Ѿ��ڸ��Ŷ�����
		teams[team_id - TEAM_ID_FORE].team_members_nums = list[0].toInt();
		qDebug() << teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";
		//1
		for (int i = 1; i < teams[team_id - TEAM_ID_FORE].team_members_nums+1; i++)
		{
			teams[team_id - TEAM_ID_FORE].team_members.push_back(users[list[i].toInt() - USER_ID_FORE]);
		}
		for (int i = 0; i < teams[team_id - TEAM_ID_FORE].team_members_nums; i++)
		{
			qDebug() << teams[team_id - TEAM_ID_FORE].team_members[i].usr_id <<" " << USR_ID_NOW << "\n";
			if (teams[team_id - TEAM_ID_FORE].team_members[i].usr_id == USR_ID_NOW)
			{
				QMessageBox::warning(this, "Warning", "You have already joined this team!");
				return;
			}
		}
	}
		//�ŶӴ�����������ȷ�����¸��Ŷӵ��û������Լ���ǰ�û����Ŷ�����
		//�����Ŷ�����
		//�ѵ�ǰ�û���idд���Ӧ�Ŷӵĳ�Ա��
	teams[team_id - TEAM_ID_FORE].team_members.append(users[USR_ID_NOW - USER_ID_FORE]);
	qDebug() <<"Current number of users:"<< teams[team_id - TEAM_ID_FORE].team_members_nums;
	qDebug() << "add a mumber!";
	//�ѵ�ǰ�Ŷӵĳ�Ա������һ
	teams[team_id - TEAM_ID_FORE].team_members_nums++;
	qDebug() << "Current number of users:" << teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";


	//���µ�ǰ�û����Ŷ�����
	
	//�����û������Ŷ�����
	users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num++;

	//�����û����ڼ�����Ŷ�Ϊ�����Ŷ�
	users[USR_ID_NOW - USER_ID_FORE].teams_belong.append(teams[team_id - TEAM_ID_FORE]);

	//���¸��Ŷ������г�Ա�ڴ����Ŷ��ļ��д洢�ĸ��Ŷӵ���Ա����
	for (int i = 0; i < teams[team_id - TEAM_ID_FORE].team_members_nums; i++)
	{
		//�������ݵ��û��������Ŷ��ļ��浵��
		
		QString filename =users[teams[team_id - TEAM_ID_FORE].team_members[i].usr_id-USER_ID_FORE].usr_team_belong_filename;
		QFile team_file(filename);
		if (!team_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
			return;
		QTextStream out(&team_file);
		//������ļ�
		team_file.resize(0);
		//1,2001,SCUT,1001,4,1001,1002,1003,1004,
		//д������Ŷ�����
		// д�������ÿ���Ŷӵ�id�����ơ����������г�Ա��id
		
		out << teams[team_id - TEAM_ID_FORE].team_members[i].usr_team_belong_num << ",";
		qDebug() << "The number of teams each current user belongs to:" << teams[team_id - TEAM_ID_FORE].team_members[i].usr_team_belong_num;
		qDebug() << "teams_belong size: " << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong.size();
		for (int j = 0; j < teams[team_id - TEAM_ID_FORE].team_members[i].usr_team_belong_num; j++)
		{
			qDebug() << "teams_belong[" << j << "] - team_id: " << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_id;
			qDebug() << "teams_belong[" << j << "] - team_name: " << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_name;
			qDebug() << "teams_belong[" << j << "] - team_members_nums: " << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members_nums;

			for (int k = 0; k < teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members_nums; k++)
			{
				qDebug() << "teams_belong[" << j << "] - team_members[" << k << "] - usr_id: " << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members[k].usr_id;
			}
		}
		//��д������Ŷӵ�id�����ơ����������г�Ա��id
		for (int j = 0; j < teams[team_id - TEAM_ID_FORE].team_members[i].usr_team_belong_num; j++)
		{
			out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_id << ",";//�����ˣ���֪��ΪʲôԽ��
			out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_name << ",";
			out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members_nums << ",";
			for (int k = 0; k < teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members_nums; k++)
			{
				out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members[k].usr_id << ",";
			}
		}	
		//�ر��ļ�
		team_file.close();
	}

	//�������ݵ��ļ��浵��
	//������ļ�
	team_members_file.resize(0);
	//��д������
	out << teams[team_id - TEAM_ID_FORE].team_members_nums << ",";
	qDebug()<< teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";
	for (int i = 0; i < teams[team_id - TEAM_ID_FORE].team_members_nums; i++)
	{
		qDebug() << teams[team_id - TEAM_ID_FORE].team_members[i].usr_id << "\n";
		out << teams[team_id - TEAM_ID_FORE].team_members[i].usr_id << ",";
	}
	//�ر��ļ�
	team_members_file.close();

	

	//�����û�����
	
	users[USR_ID_NOW - USER_ID_FORE].teams_belong.push_back(teams[team_id - TEAM_ID_FORE]);
	users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num++;
	//�����û����Ŷ��ļ�
	//������ļ�
	QString filename_usr = users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename;
	QFile team_belong_file(filename_usr);
	if (!team_belong_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_usr(&team_belong_file);
	team_belong_file.resize(0);
	//��д������
	//�������Ŷ�����
	//�Ŷ�1��id���Ŷ�1�����ƣ��Ŷ�1��ʼ�ˣ��Ŷ�1�������������Ŷ�1��ȫ����Ա
	out_usr << users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num << ",";
	for (int i = 0; i < users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num; i++)
	{
		out_usr << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_id << ",";
		out_usr << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_name << ",";
		out_usr << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members[0].usr_id << ",";
		out_usr << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members_nums << ",";
		for (int j = 0; j < users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members_nums; j++)
		{
			out_usr << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members[j].usr_id << ",";
		}
	}

	//�ر��ļ�
	team_belong_file.close();


	//��ʾ�û�����ɹ�
	QMessageBox::StandardButton reply;
	reply = QMessageBox::information(this, "Success", "Join the team successfully", QMessageBox::Yes);
	//���ϳ��������ԭ���Ѿ��޸ĺã�qvectorֻ��push_back������������
}


void team_mng::exit_team()
{
	//����ǲ��������Ͻ�team_belong����һ����������
	//��һ��QTableView�ؼ�չʾ��ǰ�û������ڵ������Ŷӣ�֧���˳�����
}

void team_mng::confirm_creat(const QString& teamName, const QString& password)
{
	//����һ���µ��Ŷ�
	myteam_create.push_back(TEAM(teamName, password, USR_ID_NOW));
	//�����Ŷӵ���Ϣд��TEAMS�ļ��ʹ����Ŷ��Լ����ļ�
	//�����Ŷ�id
	new_team_id = TEAM_ID_FORE + team_nums;
	//����������ʾ�����Ŷӳɹ����ҷ����Ŷ�id
	QMessageBox::information(nullptr, "Successfully create a team!", "The id of your team is: " + QString::number(new_team_id));
	//�����Ŷӵ���Ϣд�������Ŷ������и��ŶӵĶ�Ӧ��Ϣ��
	teams[team_nums].team_id = new_team_id;
	teams[team_nums].team_name = teamName;
	teams[team_nums].team_passwd = password;
	teams[team_nums].leader_id = USR_ID_NOW;
	teams[team_nums].team_members_nums = 1;
	teams[team_nums].team_members.push_back(users[USR_ID_NOW - USER_ID_FORE]);
	teams[team_nums].team_events_nums = 0;

	//Ϊÿ���Ŷӵĳ�Ա��Ϣר�Ŵ����ļ���д��
	QString filename = QString::number(new_team_id) + "_team members.txt";
	QFile file(filename);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out(&file);
	out << teams[team_nums].team_members_nums << ",";
	//ѭ��д�����г�Ա��id
	for (int i = 0; i < teams[team_nums].team_members_nums; i++)
	{
		out << teams[team_nums].team_members[i].usr_id << ",";
	}


	//Ϊÿ���Ŷӵ��¼���Ϣר�Ŵ����ļ���д��
	QString filename_2 = QString::number(new_team_id) + "_team events.txt";
	QFile file_2(filename_2);
	if (!file_2.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_2(&file_2);
	out_2 << teams[team_nums].team_events_nums << " ,";
	//ѭ��д�������¼���id
	for (int i = 0; i < teams[team_nums].team_events_nums; i++)
	{
		out_2 << teams[team_nums].team_events[i].event_id << ",";
	}



	//�����Ŷӵ���Ϣд���û����Ŷ��б�
	users[USR_ID_NOW - USER_ID_FORE].teams_create.push_back(teams[team_nums]);
	//�����û����ŶӴ����ļ�
	//������ļ�
	QString filename_usr_create = users[USR_ID_NOW - USER_ID_FORE].usr_team_create_filename;
	QFile team_create_file(filename_usr_create);
	if (!team_create_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_usr_create(&team_create_file);
	team_create_file.resize(0);
	//��д������
	//�������Ŷ�����
	//�Ŷ�1��id���Ŷ�1�����ƣ��Ŷ�1�������������Ŷ�1��ȫ����Ա
	out_usr_create << users[USR_ID_NOW - USER_ID_FORE].usr_team_create_num<< ",";
	for (int i = 0; i < users[USR_ID_NOW - USER_ID_FORE].usr_team_create_num; i++)
	{
		out_usr_create << users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_id << ",";
		out_usr_create << users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_name << ",";
		out_usr_create << users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_members_nums << ",";
		for (int j = 0; j < users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_members_nums; j++)
		{
			out_usr_create << users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_members[j].usr_id << ",";
		}
	}
	//�ر��ļ�
	team_create_file.close();


	//�����û����ŶӴ����ļ�
	users[USR_ID_NOW - USER_ID_FORE].teams_belong.push_back(teams[new_team_id - TEAM_ID_FORE]);
	//�����û����Ŷ��ļ�
	//������ļ�
	QString filename_usr_belong = users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename;
	QFile team_belong_file(filename_usr_belong);
	if (!team_belong_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_usr_belong(&team_belong_file);
	team_belong_file.resize(0);
	//��д������
	//�������Ŷ�����
	//�Ŷ�1��id���Ŷ�1�����ƣ��Ŷ�1��ʼ�ˣ��Ŷ�1�������������Ŷ�1��ȫ����Ա
	out_usr_belong << users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num << ",";
	qDebug()<< users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num;
	for (int i = 0; i < users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num; i++)
	{
		out_usr_belong << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_id << ",";
		out_usr_belong << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_name << ",";
		out_usr_belong << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members[0].usr_id << ",";
		out_usr_belong << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members_nums << ",";
		for (int j = 0; j < users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members_nums; j++)
		{
			out_usr_belong << users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members[j].usr_id << ",";
		}
	}

	//�ر��ļ�
	team_belong_file.close();
	

	//�����Ŷӵ���Ϣд��TEAMS�ļ��ʹ����Լ����ļ�
	QFile team_file("TEAMS.txt");
	if (!team_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream team_file_out(&team_file);
	team_file_out << teams[team_nums].team_id << "," << teamName << "," << password << "," << USR_ID_NOW << "," << 1 << "," << 0 << "," << filename << "," << filename_2;
	team_file_out << "\n";
	team_file.close();
	
	
	
}



void init_teams_structarr(TEAM* teams, int size)
{
	QFile file("TEAMS.txt");

	if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream stream(&file);

		int index = 0;
		while (!stream.atEnd() && index < size)
		{
			QRegularExpression re(",$");

			QString line = stream.readLine().replace(re, "");
			;
			QStringList values = line.split(',');

			// ��ȡ�����浽�ṹ������
			if (values.size() >= 8) {

				teams[index].team_id = values[0].toInt();
				teams[index].team_name = values[1];
				teams[index].team_passwd = values[2];
				teams[index].leader_id = values[3].toInt();
				teams[index].team_members_nums = values[4].toInt();
				teams[index].team_events_nums = values[5].toInt();
				teams[index].team_members_filename = values[6];
				teams[index].team_events_filename = values[7];

				index++;
			}
		}
		team_nums = index;
		file.close();

		qDebug() << "The team structure array is initialized successfully!";
	}
	else {
		qDebug() << "Could not open The team structure array file!";
	}

}

void team_mng::updateTable_team()
{
	//���´������Ŷ�
	QFile file_create(users[USR_ID_NOW - USER_ID_FORE].usr_team_create_filename);

	if (file_create.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream in(&file_create);

		// ���ԭ�б������
		ui.tableWidget_2->clearContents();
		ui.tableWidget_2->setRowCount(0);
		ui.tableWidget_2->setColumnCount(3); // ��������Ϊ4
		//ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<"�Ŷ�ID"<<"�Ŷ�����"<<"�ŶӴ�ʼ��"<<"�Ŷ�����������");
		ui.tableWidget_2->setHorizontalHeaderLabels(QStringList() << "team id" << "team name" <<  "total number of the team");
		int row = 0; // �м�����
		while (!in.atEnd()) {
			QString line = in.readLine().trimmed();
			QStringList fields = line.split(",");

			if (fields.size() >= 3) {
				QString content1 = fields[1]; // ��һ���ֶ�����
				QString content2 = fields[2]; // �ڶ����ֶ�����
				QString content3 = fields[3]; // �������ֶ�����
				// �ڱ�������һ��
				ui.tableWidget_2->insertRow(row);

				// ����QTableWidgetItem����������
				QTableWidgetItem* item1 = new QTableWidgetItem(content1);
				QTableWidgetItem* item2 = new QTableWidgetItem(content2);
				QTableWidgetItem* item3 = new QTableWidgetItem(content3);
				//�Զ�����ÿһ�еĳ���
				ui.tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
				//�����û��Լ�����
				//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
				ui.tableWidget_2->resizeColumnsToContents();
				// ��QTableWidgetItem��ӵ�����еĶ�Ӧλ��
				ui.tableWidget_2->setItem(row, 0, item1);
				ui.tableWidget_2->setItem(row, 1, item2);
				ui.tableWidget_2->setItem(row, 2, item3);
				row++; // �м���������
			}

		}
		file_create.close();

	}

	//���´������Ŷ�
	QFile file_belong(users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename);
	
	if (file_belong.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream in(&file_belong);

		// ���ԭ�б������
		ui.tableWidget->clearContents();
		ui.tableWidget->setRowCount(0);
		ui.tableWidget->setColumnCount(4); // ��������Ϊ4
		//ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<"�Ŷ�ID"<<"�Ŷ�����"<<"�ŶӴ�ʼ��"<<"�Ŷ�����������");
		ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "team id" << "team name" << "memner num" << "founder");
		int row = 0; // �м�����
		while (!in.atEnd()) {
			QString line = in.readLine().trimmed();
			QStringList fields = line.split(",");

			if (fields.size() >= 4) {
				QString content1 = fields[1]; // ��һ���ֶ�����
				QString content2 = fields[2]; // �ڶ����ֶ�����
				QString content3 = fields[3]; // �������ֶ�����
				QString content4 = fields[4]; // ���ĸ��ֶ�����
				// �ڱ�������һ��
				ui.tableWidget->insertRow(row);

				// ����QTableWidgetItem����������
				QTableWidgetItem* item1 = new QTableWidgetItem(content1);
				QTableWidgetItem* item2 = new QTableWidgetItem(content2);
				QTableWidgetItem* item3 = new QTableWidgetItem(content3);
				QTableWidgetItem* item4 = new QTableWidgetItem(content4);
				//�Զ�����ÿһ�еĳ���
				ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
				//�����û��Լ�����
				//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
				ui.tableWidget->resizeColumnsToContents();
				// ��QTableWidgetItem��ӵ�����еĶ�Ӧλ��
				ui.tableWidget->setItem(row, 0, item1);
				ui.tableWidget->setItem(row, 1, item2);
				ui.tableWidget->setItem(row, 2, item3);
				ui.tableWidget->setItem(row, 3, item4);
				row++; // �м���������
			}

		}
		file_belong.close();

	}

	
}