#include"config.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    reg_n_login w1;
    //���ô��ڱ���
    w1.setWindowTitle("Regist or Login");
    //���ļ��ж�ȡ����ʼ���û��ṹ������
    init_users_structarr(users, MAX_USRS_NUM);
    //���ļ��ж�ȡ����ʼ���Ŷӽṹ������
    init_teams_structarr(teams,MAX_TEAM_NUM);

    w1.show();
    return a.exec();
}
