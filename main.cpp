#include"config.h"
int main(int argc, char *argv[])
{
   
    //从文件中读取并初始化用户结构体数组
    init_users_structarr(users, MAX_USRS_NUM);
    //从文件中读取并初始化团队结构体数组
    init_teams_structarr(teams,MAX_TEAM_NUM);
    QApplication a(argc, argv);
    reg_n_login w1;
    //设置窗口标题
    w1.setWindowTitle("Regist or Login");
    w1.show();
    return a.exec();
}
