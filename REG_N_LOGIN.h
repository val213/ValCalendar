#ifndef REG_N_LOGIN_H
#define REG_N_LOGIN_H
#include"config.h"
class reg_n_login:public QDialog
{
	Q_OBJECT
public:
	reg_n_login(QDialog* parent = nullptr);
	~reg_n_login();
	int USR_ID=0;
	QString USR_PSWD;
private:
	QPixmap m_imgTitle, m_back;



private:
	Ui::REG_N_LOGIN ui;
public slots:
	void reg_n_login_accepted();
	void reg_n_login_rejected();
	int checkusr(int USR_ID, QString USR_PSWD);
	void save_USER();
};



#endif // !REG_N_LOGIN_H



