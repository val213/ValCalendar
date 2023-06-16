#include"config.h"
#include"team_mng.h"
#include"usr_mng.h"
#include"struct.h"
#include<qregularexpression.h>
#include<qmessagebox.h>
#include"calendar_team.h"
//所有团队的集合
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

	//创建团队
	connect(ui.pushButton, &QPushButton::clicked,this,&team_mng::create_new_team);
	//加入团队
	connect(ui.pushButton_4, &QPushButton::clicked, this, &team_mng::join_team);
	//删除团队
	connect(ui.pushButton_3, &QPushButton::clicked, this, &team_mng::delete_team);
	//退出团队
	connect(ui.pushButton_6, &QPushButton::clicked, this, &team_mng::exit_team);

	//双击事件选中某个团队
	connect(ui.tableWidget, &QTableWidget::clicked, this, &team_mng::on_cellselect);
	updateTable_team();
	//connect(timer_team, &QTimer::timeout, this, &team_mng::updateTable_team);
	//timer_team->start(1000); // 每隔1秒触发更新
	//窗口关闭之后程序不退出
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
	int selectedRow = ui.tableWidget->currentRow();  // 获取选中行号
	if (selectedRow < 0) return;

	qDebug() << "selectedRow: " << selectedRow;
	QTableWidgetItem* item = ui.tableWidget->item(selectedRow, 0);  // 获取选中行的第一列单元格对象
	QVariant data = item->data(Qt::DisplayRole);  // 获取单元格数据
	int team_id = data.toInt();  // 将数据转换为所需的类型
	qDebug() << "Selected team_id:" << team_id;
	
	
	ui.tableWidget->removeRow(selectedRow);
	//安全删除用户的从属团队文件内的对应数据行
	QFile file_usr_belong(users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename);
	if (file_usr_belong.open(QIODevice::ReadWrite | QIODevice::Text)) {
		QTextStream stream(&file_usr_belong);
		QStringList lines; // 保存文件所有数据
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
		file_usr_belong.resize(0);
		// 重新写入更新后的数据
		stream << lines.join("\n");
		file_usr_belong.close();
	}
	else {
		QMessageBox::critical(this, "error", "file open fail");
		return;
	}
	//安全删除用户所属的团队的成员文件内的对应数据
	

		QFile file_team_members(teams[team_id - TEAM_ID_FORE].team_members_filename);
		if (file_team_members.open(QIODevice::ReadWrite | QIODevice::Text)) {
			QTextStream stream(&file_team_members);
			QStringList lines; // 保存文件所有数据
			int currentRow = 0; // 当前行索引
			//文件存储的格式：4,1001,1002,1003,1004,
			//更新文件数据
			// 清空文件内容
			file_team_members.resize(0);
			//更新团队数据
			//把当前用户在团队的成员中删去
			//int index_usr = teams[team_id - TEAM_ID_FORE].team_members.indexOf(USR_ID_NOW);
			//上面这个方法不行，需要定义相等运算符：在元素类型 T 的定义中添加相等运算符（operator==）。这样，QVector 将能够正确比较元素的相等性
			//遍历teams[team_id - TEAM_ID_FORE].team_members中的每个USER结构体中的id是否和当前的用户id一致，如果一致，返回索引，执行删除指令
			//迭代器遍历
			for (auto it = teams[team_id - TEAM_ID_FORE].team_members.begin(); it != teams[team_id - TEAM_ID_FORE].team_members.end(); it++)
			{
				if (it->usr_id == USR_ID_NOW)
				{
					teams[team_id - TEAM_ID_FORE].team_members.erase(it);  //删除掉-1
				}
			}
			qDebug() << teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";
			//把当前团队的成员数量减一
			teams[team_id - TEAM_ID_FORE].team_members_nums--;
			qDebug() << teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";
			//更新该团队中所有成员在从属团队文件中存储的该团队的人员数量
			for (int i = 0; i < teams[team_id - TEAM_ID_FORE].team_members_nums; i++)
			{
				//更新数据到文件存档中
				//先清空文件
				QString filename = users[teams[team_id - TEAM_ID_FORE].team_members[i].usr_id - USER_ID_FORE].usr_team_belong_filename;
				QFile team_file(filename);
				if (!team_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
					return;
				QTextStream out(&team_file);
				team_file.resize(0);
				//4,1001,1002,1003,1004,
				//写入新的人数
				//写入剩余的成员id
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
	int selectedRow = ui.tableWidget_2->currentRow();  // 获取当前选中的行索引
	if (selectedRow >= 0) {
		QTableWidgetItem* item = ui.tableWidget_2->item(selectedRow, 0);  // 获取选中行的第一列单元格对象
		QVariant data = item->data(Qt::DisplayRole);  // 获取单元格数据
		int team_id = data.toInt();  // 将数据转换为所需的类型
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
	new_team->setFixedSize(300, 250); // 设置固定大小，避免窗口大小可调整

	QLabel* label = new QLabel(new_team);
	QLabel* label_2 = new QLabel(new_team);
	label->setText("Input the name of the new team");
	label->setAlignment(Qt::AlignCenter); // 居中对齐
	label->setGeometry(20, 20, 260, 30); // 设置位置和大小

	QLineEdit* lineEdit = new QLineEdit(new_team);
	lineEdit->setGeometry(20, 60, 260, 30); // 设置位置和大小

	label_2->setText("Input the password of the team");
	label_2->setAlignment(Qt::AlignCenter); // 居中对齐
	label_2->setGeometry(20, 100, 260, 30); // 设置位置和大小

	QLineEdit* lineEdit_2 = new QLineEdit(new_team);
	lineEdit_2->setGeometry(20, 140, 260, 30); // 设置位置和大小


	QPushButton* pushButton = new QPushButton("OK", new_team);
	pushButton->setGeometry(60, 180, 80, 30); // 设置位置和大小

	QPushButton* pushButton_2 = new QPushButton("Cancel", new_team);
	pushButton_2->setGeometry(160, 180, 80, 30); // 设置位置和大小

	new_team->show();
	

	//确认创建
	connect(pushButton, &QPushButton::clicked, this, [this, lineEdit, lineEdit_2,new_team]() {
		confirm_creat(lineEdit->text(), lineEdit_2->text());
		new_team->close();
		});
	//取消创建
	connect(pushButton_2, &QPushButton::clicked, new_team, &QWidget::close);
	


}


void team_mng::delete_team()
{
	//这个是不是能整合进team_create的下一级操作？？
	//用一个QTableView控件展示当前用户所创造的所有团队
	//先检查当前用户是否有创建团队，如果没有，则提示

	//选中对应的团队，并确定是否进行删除操作
}

void team_mng::join_team()
{
	QWidget* new_team = new QWidget;
	new_team->setWindowTitle("Join Team");
	new_team->setFixedSize(300, 250); // 设置固定大小，避免窗口大小可调整

	QLabel* label = new QLabel(new_team);
	QLabel* label_2 = new QLabel(new_team);

	label->setText("Input the id of the team");
	label->setAlignment(Qt::AlignCenter); // 居中对齐
	label->setGeometry(20, 20, 260, 30); // 设置位置和大小

	QLineEdit* lineEdit = new QLineEdit(new_team);
	lineEdit->setGeometry(20, 60, 260, 30); // 设置位置和大小

	label_2->setText("Input the password of the team");
	label_2->setAlignment(Qt::AlignCenter); // 居中对齐
	label_2->setGeometry(20, 100, 260, 30); // 设置位置和大小

	QLineEdit* lineEdit_2 = new QLineEdit(new_team);
	lineEdit_2->setGeometry(20, 140, 260, 30); // 设置位置和大小

	
	QPushButton* pushButton = new QPushButton("Join", new_team);
	pushButton->setGeometry(60, 180, 80, 30); // 设置位置和大小



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

	//初始化当前团队的文件信息读取
	QString filename = QString::number(team_id) + "_team members.txt";
	QFile team_members_file(filename);
	if (!team_members_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
	return;
	QTextStream out(&team_members_file);
	//把文件中的内容写入对应团队的成员中
	//先读取文件中的内容
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
	
	//检查用户输入
	//团队id为空
	if (teams[team_id - TEAM_ID_FORE].team_id == 0)
	{
		//提示团队不存在
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, "Error", "The team does not exist", QMessageBox::Yes);
	}
	else if (teams[team_id - TEAM_ID_FORE].team_passwd != team_password)
	{
		//团队存在但是密码错误，提示
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, "Error", "The password is wrong", QMessageBox::Yes);
	}
	else
	{
		//团队信息载入之后，判断当前用户是否已经在该团队中了
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
		//团队存在且密码正确，更新该团队的用户数据以及当前用户的团队数据
		//更新团队数据
		//把当前用户的id写入对应团队的成员中
	teams[team_id - TEAM_ID_FORE].team_members.append(users[USR_ID_NOW - USER_ID_FORE]);
	qDebug() <<"Current number of users:"<< teams[team_id - TEAM_ID_FORE].team_members_nums;
	qDebug() << "add a mumber!";
	//把当前团队的成员数量加一
	teams[team_id - TEAM_ID_FORE].team_members_nums++;
	qDebug() << "Current number of users:" << teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";


	//更新当前用户的团队数据
	
	//更新用户从属团队数量
	users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num++;

	//更新用户正在加入的团队为所属团队
	users[USR_ID_NOW - USER_ID_FORE].teams_belong.append(teams[team_id - TEAM_ID_FORE]);

	//更新该团队中所有成员在从属团队文件中存储的该团队的人员数量
	for (int i = 0; i < teams[team_id - TEAM_ID_FORE].team_members_nums; i++)
	{
		//更新数据到用户的所属团队文件存档中
		
		QString filename =users[teams[team_id - TEAM_ID_FORE].team_members[i].usr_id-USER_ID_FORE].usr_team_belong_filename;
		QFile team_file(filename);
		if (!team_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
			return;
		QTextStream out(&team_file);
		//先清空文件
		team_file.resize(0);
		//1,2001,SCUT,1001,4,1001,1002,1003,1004,
		//写入从属团队总数
		// 写入从属的每个团队的id、名称、人数和所有成员的id
		
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
		//再写入从属团队的id、名称、人数和所有成员的id
		for (int j = 0; j < teams[team_id - TEAM_ID_FORE].team_members[i].usr_team_belong_num; j++)
		{
			out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_id << ",";//崩溃了，不知道为什么越界
			out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_name << ",";
			out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members_nums << ",";
			for (int k = 0; k < teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members_nums; k++)
			{
				out << teams[team_id - TEAM_ID_FORE].team_members[i].teams_belong[j].team_members[k].usr_id << ",";
			}
		}	
		//关闭文件
		team_file.close();
	}

	//更新数据到文件存档中
	//先清空文件
	team_members_file.resize(0);
	//再写入数据
	out << teams[team_id - TEAM_ID_FORE].team_members_nums << ",";
	qDebug()<< teams[team_id - TEAM_ID_FORE].team_members_nums << "\n";
	for (int i = 0; i < teams[team_id - TEAM_ID_FORE].team_members_nums; i++)
	{
		qDebug() << teams[team_id - TEAM_ID_FORE].team_members[i].usr_id << "\n";
		out << teams[team_id - TEAM_ID_FORE].team_members[i].usr_id << ",";
	}
	//关闭文件
	team_members_file.close();

	

	//更新用户数据
	
	users[USR_ID_NOW - USER_ID_FORE].teams_belong.push_back(teams[team_id - TEAM_ID_FORE]);
	users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num++;
	//更新用户的团队文件
	//先清空文件
	QString filename_usr = users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename;
	QFile team_belong_file(filename_usr);
	if (!team_belong_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_usr(&team_belong_file);
	team_belong_file.resize(0);
	//再写入数据
	//创建的团队数量
	//团队1的id，团队1的名称，团队1创始人，团队1现有总人数，团队1的全部成员
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

	//关闭文件
	team_belong_file.close();


	//提示用户加入成功
	QMessageBox::StandardButton reply;
	reply = QMessageBox::information(this, "Success", "Join the team successfully", QMessageBox::Yes);
	//以上程序崩溃的原因已经修改好（qvector只能push_back不能用索引）
}


void team_mng::exit_team()
{
	//这个是不是能整合进team_belong的下一级操作？？
	//用一个QTableView控件展示当前用户所属于的所有团队，支持退出操作
}

void team_mng::confirm_creat(const QString& teamName, const QString& password)
{
	//创建一个新的团队
	myteam_create.push_back(TEAM(teamName, password, USR_ID_NOW));
	//将新团队的信息写入TEAMS文件和创建团队自己的文件
	//分配团队id
	new_team_id = TEAM_ID_FORE + team_nums;
	//弹出窗口提示创建团队成功并且反馈团队id
	QMessageBox::information(nullptr, "Successfully create a team!", "The id of your team is: " + QString::number(new_team_id));
	//将新团队的信息写入所有团队数组中该团队的对应信息中
	teams[team_nums].team_id = new_team_id;
	teams[team_nums].team_name = teamName;
	teams[team_nums].team_passwd = password;
	teams[team_nums].leader_id = USR_ID_NOW;
	teams[team_nums].team_members_nums = 1;
	teams[team_nums].team_members.push_back(users[USR_ID_NOW - USER_ID_FORE]);
	teams[team_nums].team_events_nums = 0;

	//为每个团队的成员信息专门创建文件并写入
	QString filename = QString::number(new_team_id) + "_team members.txt";
	QFile file(filename);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out(&file);
	out << teams[team_nums].team_members_nums << ",";
	//循环写入所有成员的id
	for (int i = 0; i < teams[team_nums].team_members_nums; i++)
	{
		out << teams[team_nums].team_members[i].usr_id << ",";
	}


	//为每个团队的事件信息专门创建文件并写入
	QString filename_2 = QString::number(new_team_id) + "_team events.txt";
	QFile file_2(filename_2);
	if (!file_2.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_2(&file_2);
	out_2 << teams[team_nums].team_events_nums << " ,";
	//循环写入所有事件的id
	for (int i = 0; i < teams[team_nums].team_events_nums; i++)
	{
		out_2 << teams[team_nums].team_events[i].event_id << ",";
	}



	//将新团队的信息写入用户的团队列表
	users[USR_ID_NOW - USER_ID_FORE].teams_create.push_back(teams[team_nums]);
	//更新用户的团队创建文件
	//先清空文件
	QString filename_usr_create = users[USR_ID_NOW - USER_ID_FORE].usr_team_create_filename;
	QFile team_create_file(filename_usr_create);
	if (!team_create_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_usr_create(&team_create_file);
	team_create_file.resize(0);
	//再写入数据
	//创建的团队数量
	//团队1的id，团队1的名称，团队1现有总人数，团队1的全部成员
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
	//关闭文件
	team_create_file.close();


	//更新用户的团队从属文件
	users[USR_ID_NOW - USER_ID_FORE].teams_belong.push_back(teams[new_team_id - TEAM_ID_FORE]);
	//更新用户的团队文件
	//先清空文件
	QString filename_usr_belong = users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename;
	QFile team_belong_file(filename_usr_belong);
	if (!team_belong_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
		return;
	QTextStream out_usr_belong(&team_belong_file);
	team_belong_file.resize(0);
	//再写入数据
	//创建的团队数量
	//团队1的id，团队1的名称，团队1创始人，团队1现有总人数，团队1的全部成员
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

	//关闭文件
	team_belong_file.close();
	

	//将新团队的信息写入TEAMS文件和创建自己的文件
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

			// 读取并保存到结构体数组
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
	//更新创建的团队
	QFile file_create(users[USR_ID_NOW - USER_ID_FORE].usr_team_create_filename);

	if (file_create.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream in(&file_create);

		// 清空原有表格内容
		ui.tableWidget_2->clearContents();
		ui.tableWidget_2->setRowCount(0);
		ui.tableWidget_2->setColumnCount(3); // 设置列数为4
		//ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<"团队ID"<<"团队名称"<<"团队创始人"<<"团队现有总人数");
		ui.tableWidget_2->setHorizontalHeaderLabels(QStringList() << "team id" << "team name" <<  "total number of the team");
		int row = 0; // 行计数器
		while (!in.atEnd()) {
			QString line = in.readLine().trimmed();
			QStringList fields = line.split(",");

			if (fields.size() >= 3) {
				QString content1 = fields[1]; // 第一个字段内容
				QString content2 = fields[2]; // 第二个字段内容
				QString content3 = fields[3]; // 第三个字段内容
				// 在表格中添加一行
				ui.tableWidget_2->insertRow(row);

				// 创建QTableWidgetItem并设置内容
				QTableWidgetItem* item1 = new QTableWidgetItem(content1);
				QTableWidgetItem* item2 = new QTableWidgetItem(content2);
				QTableWidgetItem* item3 = new QTableWidgetItem(content3);
				//自动调整每一列的长度
				ui.tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
				//允许用户自己调整
				//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
				ui.tableWidget_2->resizeColumnsToContents();
				// 将QTableWidgetItem添加到表格中的对应位置
				ui.tableWidget_2->setItem(row, 0, item1);
				ui.tableWidget_2->setItem(row, 1, item2);
				ui.tableWidget_2->setItem(row, 2, item3);
				row++; // 行计数器递增
			}

		}
		file_create.close();

	}

	//更新从属的团队
	QFile file_belong(users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_filename);
	
	if (file_belong.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream in(&file_belong);

		// 清空原有表格内容
		ui.tableWidget->clearContents();
		ui.tableWidget->setRowCount(0);
		ui.tableWidget->setColumnCount(4); // 设置列数为4
		//ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<"团队ID"<<"团队名称"<<"团队创始人"<<"团队现有总人数");
		ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "team id" << "team name" << "memner num" << "founder");
		int row = 0; // 行计数器
		while (!in.atEnd()) {
			QString line = in.readLine().trimmed();
			QStringList fields = line.split(",");

			if (fields.size() >= 4) {
				QString content1 = fields[1]; // 第一个字段内容
				QString content2 = fields[2]; // 第二个字段内容
				QString content3 = fields[3]; // 第三个字段内容
				QString content4 = fields[4]; // 第四个字段内容
				// 在表格中添加一行
				ui.tableWidget->insertRow(row);

				// 创建QTableWidgetItem并设置内容
				QTableWidgetItem* item1 = new QTableWidgetItem(content1);
				QTableWidgetItem* item2 = new QTableWidgetItem(content2);
				QTableWidgetItem* item3 = new QTableWidgetItem(content3);
				QTableWidgetItem* item4 = new QTableWidgetItem(content4);
				//自动调整每一列的长度
				ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
				//允许用户自己调整
				//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
				ui.tableWidget->resizeColumnsToContents();
				// 将QTableWidgetItem添加到表格中的对应位置
				ui.tableWidget->setItem(row, 0, item1);
				ui.tableWidget->setItem(row, 1, item2);
				ui.tableWidget->setItem(row, 2, item3);
				ui.tableWidget->setItem(row, 3, item4);
				row++; // 行计数器递增
			}

		}
		file_belong.close();

	}

	
}