#include"config.h"
int user_nums;
USER users[MAX_USRS_NUM] = { {1001,"666","val","usr_val.txt","team_create_usr_val.txt","team_belong_usr_val.txt",0,0}};
void init_users_structarr(USER* users, int size)
{
    QFile file("USERS.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        QTextStream stream(&file);

        int index = 0;
        while (!stream.atEnd() && index < size) 
        {
            QString line = stream.readLine().trimmed();
            QStringList values = line.split(',');

            // 读取并保存到结构体数组
            //{1001,"666","val","usr_val.txt","usr_val_team_create.txt","usr_val_team_belong.txt",0,0}
            if (values.size() >= 8) {
                users[index].usr_id = values[0].toInt();
                users[index].usr_passwd = values[1];
                users[index].usr_name = values[2];
                users[index].usr_filename = values[3];
                users[index].usr_team_create_filename = values[4];
                users[index].usr_team_belong_filename = values[5];
                users[index].usr_team_create_num = values[6].toInt();
                users[index].usr_team_belong_num = values[7].toInt();
                index++;

                //打开users[index].usr_team_create_filename和users[index].usr_team_belong_filename初始化QVector<TEAM>teams_create;和QVector<TEAM>teams_belong;
                QFile file1(users[index].usr_team_create_filename);
                if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
                {
					QTextStream stream1(&file1);
					int index1 = 0;
                    while (!stream1.atEnd() && index1 < size)
                    {
						QString line1 = stream1.readLine().trimmed();
						QStringList values1 = line1.split(',');
						// 读取并保存到结构体数组
					
                        //初始化QVector<TEAM>teams_create
                        //1,2001,SCUT,1001,4,1001,1002,1003,1004,

                        //读取创建的团队总数
                        users[USR_ID_NOW - USER_ID_FORE].usr_team_create_num = values1[0].toInt();
                        for (int i = 0; i < users[USR_ID_NOW - USER_ID_FORE].usr_team_create_num; i++)
                        {
                            //循环读取创建的每个团队的id、名称、人数和创建者的id
                            //1,2001,SCUT,1,1001,
                            users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_id = values1[1 + 4 * i].toInt();
                            users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_name = values1[2 + 4 * i];
                            users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_members_nums = values1[3 + 4 * i].toInt();
                            users[USR_ID_NOW - USER_ID_FORE].teams_create[i].leader_id = values1[4 + 4 * i].toInt();
                            for (int j = 0; j < users[USR_ID_NOW - USER_ID_FORE].teams_create[i].team_members_nums; j++)
                            {
								//循环读取创建的每个团队的成员的id
                                users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members.push_back(users[values1[4 + 4 * i + j].toInt() - USER_ID_FORE]);
                            }
                        }
					}
				}
                else {
					qDebug() << "Could not open User structure array file!";
				}

                QFile file2(users[index].usr_team_belong_filename);
                if (file2.open(QIODevice::ReadOnly | QIODevice::Text))
                {
					QTextStream stream2(&file2);
					int index2 = 0;
                    while (!stream2.atEnd() && index2 < size)
                    {
						QString line2 = stream2.readLine().trimmed();
						QStringList values2 = line2.split(',');
						// 读取并保存到结构体数组
                        //1,2001,SCUT,1001,4,1001,1002,1003,1004,
                        //初始化QVector<TEAM>teams_belong;
                        //读取从属团队总数
                        users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num = values2[0].toInt();
                        for (int i = 0; i < users[USR_ID_NOW - USER_ID_FORE].usr_team_belong_num; i++)
                        {
							//循环读取从属的每个团队的id、名称、人数和所有成员的id
                            users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_id = values2[1 + 4 * i].toInt();
                            users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_name = values2[2 + 4 * i];
                            users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members_nums = values2[3 + 4 * i].toInt();
                            for (int j = 0; j < users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members_nums; j++)
                            {
                                users[USR_ID_NOW - USER_ID_FORE].teams_belong[i].team_members.push_back(users[values2[4 + 4 * i + j].toInt()-USER_ID_FORE]);
                            }
						}

					}
				}

                file1.close();
				file2.close();



            }
        }
        user_nums = index;
        file.close();

        qDebug() << "User structure array initialized successfully!";
    }
    else {
        qDebug() << "Could not open User structure array file!";
    }
}
/*
 
	void init_users()
	{
		memset(users,0, sizeof(users));
	}

*/





