#include"config.h"
#include<QInputDialog>
#include<QTextStream>
#include<qwebchannel.h>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QPainter>
#include<QRect>
//初始化当前用户id是 USER_ID_FORE(1001)，后续用户id更新的时候会同步更新
int USR_ID_NOW= USER_ID_FORE;
reg_n_login::reg_n_login(QDialog* parent)
{
	ui.setupUi(this);
	setWindowOpacity(1);//设置透明度
	//隐藏标题栏
	//setWindowFlags(Qt::CustomizeWindowHint);
	//不显示标题栏，亦无边框
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setStyleSheet("reg_n_login{background: url(:/calendar/111.jpg);}");//窗口背景设置
	//或setStyleSheet("background-image: url(:/image/profile.png);")
	ui.lineEdit->setEchoMode(QLineEdit::Password);//密文输入
	ui.lineEdit_3->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
		"color: rgb(31,31,31);"		//字体颜色
		"padding-left:10px;"       //内边距-字体缩进
		"background-color: rgb(255, 255, 255);" //背景颜色
		"border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置 
	ui.lineEdit->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
		"color: rgb(31,31,31);"		//字体颜色
		"padding-left:10px;"       //内边距-字体缩进
		"background-color: rgb(255, 255, 255);" //背景颜色
		"border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置 

	//展示图片
	QGraphicsScene* scene = new QGraphicsScene(this); // 创建 QGraphicsScen
	QPixmap pixmap("qrc:/calendar/111.jpg"); // 创建 QPixmap 并加载图像文件

	QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建 QGraphicsPixmapItem，并将 QPixmap 作为参数传递
	scene->addItem(pixmapItem); // 将 QGraphicsPixmapItem 添加到 QGraphicsScene

	//ui.graphicsView->show(); // 显示 QGraphicsView

	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &reg_n_login::reg_n_login_accepted);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

	
}

reg_n_login::~reg_n_login()
{
}



void reg_n_login::reg_n_login_accepted()
{

	//获取lineEdit和lineEdit_3的数据,如果id不是是整数，报错提示
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
		return：
		创建新账号：	1
		登陆成功：		2
		密码错误：		3
		返回登陆界面：  4
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
				//样式表
	/*			cal->setStyleSheet(R"(
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
    )");*/
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
		//向结构体数组中写入新的用户数据，并更新用户数量
		//user_nums的值根据读入文件中用户数量的多少实时更新
		users[user_nums-1].usr_id = USR_ID;
		users[user_nums-1].usr_passwd = USR_PSWD;
		//让用户输入用户名
		QString user_name = QInputDialog::getText(this, "Input", "Please input your name:", QLineEdit::Normal, "USER");

		QString filename= "usr_";
		QString file_back = ".txt";
		filename += user_name;
		filename += file_back;// 在字符串末尾添加另一个字符串
		users[user_nums - 1].usr_name = user_name;
		users[user_nums - 1].usr_filename = filename;
		users[user_nums - 1].usr_team_create_filename= "team_create_" + filename;
		users[user_nums - 1].usr_team_belong_filename = "team_belong_" + filename;
		users[user_nums - 1].usr_team_create_num=0;
		users[user_nums - 1].usr_team_belong_num=0;

		//将用户数据写入文件
		
		QFile file("USERS.txt"); //创建一个QFile对象，指定要保存的文件名
		if (file.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append)) { //以写入和文本模式打开文件
			QTextStream out(&file); //创建一个QTextStream对象，关联到文件
			//将用户信息存入txt文件
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
			out << users[user_nums - 1].usr_id<<",";
			out << users[user_nums - 1].usr_passwd<<",";
			out << users[user_nums - 1].usr_name << ",";
			out << users[user_nums - 1].usr_filename << ",";
			out << users[user_nums - 1].usr_team_create_filename << ",";
			out << users[user_nums - 1].usr_team_belong_filename << ",";
			out << users[user_nums - 1].usr_team_create_num << ",";
			out << users[user_nums - 1].usr_team_belong_num << ",";
			out << "\n";
			file.close(); //关闭文件
		}
		else {
			QMessageBox::warning(this, "Error", "Save failed!"); //保存失败则弹出警告对话框
		}

	}

int reg_n_login::checkusr(int USR_ID, QString USR_PSWD)
{
	/*
	return：
	创建新账号：	1
	登陆成功：		2
	密码错误：		3
	返回登陆界面：  4
	*/
	//id输入不合法
	if (users[USR_ID- USER_ID_FORE].usr_id==0)
	{
		//用户不存在
		//提示用户不存在，是否要注册新账号
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(nullptr, "User does not exist", "Are you sure to create a new user?",
			QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			// 用户点击了“是”按钮
			//创建新账号
			return 1;
		}
		else {
			// 用户点击了“否”按钮
			// 执行相应的操作

			return 4;
		}
		
	}
	//id输入合法且密码正确
	else if (users[USR_ID- USER_ID_FORE].usr_passwd == USR_PSWD)
	{
		//登陆成功
		QMessageBox::information(nullptr, "Successful login", "Welcome to ValCalendar!");
		return 2;
	}
	//id输入合法但是密码错误
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
	// 用于执行sql语句的对象
	QSqlQuery sqlQuery;

	// 构建创建数据库的sql语句字符串
	QString createSql = QString("CREATE TABLE usr(\
					  usr_id INT PRIMARY KEY NOT NULL,\
					  usr_pswd TEXT NOT NULL)");
	sqlQuery.prepare(createSql);
	// 执行sql语句
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
