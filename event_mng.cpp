#include"config.h"
extern int user_nums;
extern int USR_ID_NOW;
int events_nums;
EVENT events[MAX_USRS_EVENT];
void init_usr_event_structarr(EVENT* events, int size)
{
	QFile file(users[USR_ID_NOW - 1001].usr_filename);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream(&file);

		int index = 0;
		while (!stream.atEnd() && index < size) 
		{
			QString line = stream.readLine().trimmed();
			QStringList values = line.split(',');

			//读取并保存到event结构体数组中
			if(values.size()>=5)
			{
				events[index].event_name = values[0];
				events[index].event_date = values[1];
				events[index].event_starttime = values[2];
				events[index].event_endtime = values[3];
				events[index].event_content = values[4];
				events[index].urgentdegree = values[5].toInt();

				index++;
			}
		}
		events_nums = index;
		file.close();

		qDebug() << "结构体数组初始化成功！";
	}
	else {
		qDebug() << "无法打开文件！";
	}
}