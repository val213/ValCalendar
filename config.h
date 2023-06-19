#ifndef CONFIG_H
#define CONFIG_H

#define MAX_USRS_NUM 100
#define MAX_USRS_EVENT 100
#define MAX_TEAM_NUM 100
//�û�id��ǰ׺
#define USER_ID_FORE 1001
//�Ŷ�id��ǰ׺
#define TEAM_ID_FORE 2001
#include <iostream>  // C++ ��׼��ͷ�ļ�Ӧ��������ͷ�ļ�֮ǰ

#include <QString>  // Qt ����ͷ�ļ�Ӧ�������� Qt ���ͷ�ļ�֮ǰ
#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QCalendarWidget>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTimer>
#include <QVector>

#include "struct.h"  // �Զ���ͷ�ļ�
#include "usr_mng.h"
#include "team_mng.h"
#include "ui_calendar.h"
#include "ui_TODOwidget.h"
#include "ui_REG_N_LOGIN.h"

#include "REG_N_LOGIN.h"

#include "calendar.h"

#include "TODOwidget.h"
#include "event_mng.h"
#include "team_mng.h"
#endif
