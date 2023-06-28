#include"config.h"
int user_nums;
USER users[MAX_USRS_NUM] = { {1001,"666","val","usr_val.txt","team_create_usr_val.txt","team_belong_usr_val.txt",0,0}};
void init_users_structarr(USER* users, int size)
{
    QFile file("USERS.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        QTextStream stream(&file);
        /*
        1001,666,val,usr_val.txt,team_create_usr_val.txt,team_belong_usr_val.txt,2,2,
        1002,777,bob,usr_bob.txt,team_create_usr_bob.txt,team_belong_usr_bob.txt,0,2,
        */
        int index = 0;//用户的索引
        while (!stream.atEnd() && index < size) 
        {
            QString line = stream.readLine().trimmed();
            QStringList values = line.split(',');
            qDebug() << line;
            // 读取并保存到结构体数组
            //{1001,"666","val","usr_val.txt","usr_val_team_create.txt","usr_val_team_belong.txt",0,0}
            if (values.size() >= 8) {
                users[index].usr_id = values[0].toInt();
                users[index].usr_passwd = values[1];
                users[index].usr_name = values[2];
                users[index].usr_filename = values[3];
                users[index].usr_team_create_filename = values[4];
                qDebug() <<"users[index].usr_team_create_filename " << users[index].usr_team_create_filename;
                users[index].usr_team_belong_filename = values[5];
                qDebug() <<"users[index].usr_team_belong_filename "<<users[index].usr_team_belong_filename;
                users[index].usr_team_create_num = values[6].toInt();
                users[index].usr_team_belong_num = values[7].toInt();
                

                //打开users[index].usr_team_create_filename和users[index].usr_team_belong_filename初始化QVector<TEAM>teams_create;和QVector<TEAM>teams_belong;
                QString filename_usr_team_create_filename = users[index].usr_team_create_filename;
                QFile file1(filename_usr_team_create_filename);
                if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
                {
					QTextStream stream1(&file1);
					int index1 = 0;//该用户创建的团队的索引
                    while (!stream1.atEnd() && index1 < size)
                    {
						QString line1 = stream1.readLine().trimmed();
                        if (line1.size() < 4)
                        {
                            //读取创建的团队总数
                            QStringList values1 = line1.split(',');
                            users[index].usr_team_create_num = values1[0].toInt();
                            qDebug() << users[index].usr_team_create_num;
                        }
                        else if (line1.size() >= 4)//具体信息存储行
                        {                           
                            // 读取并保存到结构体数组
                            //初始化QVector<TEAM>teams_create          
                            QStringList values1 = line1.split(',');                          
                            //循环读取创建的每个团队的id、名称、人数和创建者的id
                            /*
                            2,
                            2001,SCUT,1001,2,1001,1002,
                            2002,SE,1001,2,1001,1002,
                            */
                            //使用过渡对象1号接受团队的数据给到用户
                            TEAM te;
                            te.team_id = values1[0].toInt();
                            te.team_name = values1[1];
                            te.leader_id= values1[2].toInt();
                            te.team_members_nums = values1[3].toInt();
                            qDebug() << "te.team_members_nums =" << te.team_members_nums;          
                            //遍历当前用户创建的团队的所有成员，将他们的id写入团队创建者的QVector中
                            for (int j = 1; j <= te.team_members_nums; j++)
                            {
                                //循环读取创建的每个团队的成员的id
                                //这里有个问题，因为用户是顺序初始化的，所以即使包含了1002，1001也无法载入1002的消息。。。
                                //那么就直接把读到的id写入吧！
                                /*qDebug() << "!" << users[values1[3+ j].toInt() - USER_ID_FORE].usr_id;
                                te.team_members.append(users[values1[3+j].toInt() - USER_ID_FORE].usr_id);*/
                                qDebug() << values1[3 + j].toInt();
                                te.team_members.append(values1[3 + j].toInt());
                            }
                            users[index].teams_create.append(te);
                            qDebug() << "users[index].teams_create.append(te);";
                            //输出检查现在的users
                            qDebug() << "users[index].teams_create.size() = " << users[index].teams_create.size();
                            
                        }
                        index1++;
					}
                    qDebug() << " User usr_team_create_filename: User structure array initialized successfully!";
				}
                else {
					qDebug() << "Could not open User usr_team_create_filename!";
				}


                QString filename_usr_team_belong_filename = users[index].usr_team_belong_filename;
                QFile file2(filename_usr_team_belong_filename);
                if (file2.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QTextStream stream2(&file2);
                    int index2 = 0;//该用户属于的团队的索引
                    while (!stream2.atEnd() && index2 < size)
                    {
                        QString line2 = stream2.readLine().trimmed();
                        if (line2.size() < 4)
                        {
                            //读取创建的团队总数
                            QStringList values2 = line2.split(',');
                            //在用户登录之前USE_ID_NOW默认是1000，存储无效，小心！！
                            users[index].usr_team_belong_num = values2[0].toInt();
                            qDebug() << users[index].usr_team_belong_num;
                        }
                        else if (line2.size() >= 4)//具体信息存储行
                        {


                            // 读取并保存到结构体数组
                            /*
                            3,
                            2001,SCUT,1001,1,1001,
                            2002,SE,1001,1,1001,
                            2003,BBQ,1001,1,1001,
                            */
                            //初始化QVector<TEAM>teams_belong;
                            //读取从属团队总数
                            QStringList values2 = line2.split(',');
                            TEAM te2;
                            te2.team_id = values2[0].toInt();
                            te2.team_name = values2[1];
                            te2.leader_id = values2[2].toInt();
                            te2.team_members_nums = values2[3].toInt();
                            qDebug() << "te2.team_members_nums =" << te2.team_members_nums;
                            for (int j = 1; j <= te2.team_members_nums; j++)
                            {
                                //循环读取创建的每个团队的成员的id
                                /*qDebug() << "!" << users[values2[3 + j].toInt() - USER_ID_FORE].usr_id;
                                te2.team_members.append(users[values2[3 + j].toInt() - USER_ID_FORE].usr_id);*/
                                qDebug() << values2[3 + j].toInt();
                                te2.team_members.append(values2[3 + j].toInt());
                            }
                            users[index].teams_belong.append(te2);
                            qDebug() << " users[index].teams_belong.append(te2);";
                            //输出检查现在的users[USR_ID_NOW - USER_ID_FORE].teams_belong
                            qDebug() << "users[index].teams_belong.size() = " << users[index].teams_belong.size();
                            index2++;
                        }
                        qDebug() << " User usr_team_belong_filename: User structure array initialized successfully!";
                    }
                }
                else qDebug() << "Could not open  User usr_team_belong_filename!";

                file1.close();
				file2.close();
				
            }
            index++;
        }
        user_nums = index;
        qDebug() << "用户数量：" << user_nums;
        file.close();

        qDebug() << "User structure array initialized successfully!";
    }
    else {
        qDebug() << "Could not open User filename!";
        
    }
}




