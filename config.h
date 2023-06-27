#ifndef CONFIG_H
#define CONFIG_H

#define MAX_USRS_NUM 100
#define MAX_USRS_EVENT 100
#define MAX_TEAM_NUM 100
//用户id的前缀
#define USER_ID_FORE 1001
//团队id的前缀
#define TEAM_ID_FORE 2001
#define EVENT_ID_FORE 3001
#define MAX_EVENT_NUM 100
#define MAX_TEAM_EVENT 100
#define MAX_TEAM_USR 100

#define FILED_USR 8//用户id，用户密码，用户名称，用户创建团队文件名，用户归属团队文件名，用户创建团队数量，用户归属团队数量，
#define FILED_USR_EVENT 7//事件标题，地点，开始时间，结束时间，事件类型，紧急程度，备注，
#define FILED_TEAM 8//团队id，团队名称，团队密码，团队创建者id，团队成员数量，团队事件数量，团队成员文件名，团队事件文件名，
#define FILED_USR_CREATE_TEAM 0//用户归属的团队数量，【团队id,团队名称，团队创建者id，团队成员数量，【所有用户成员id】】
#define FILES_USR_BELONG_TEAM 0//用户归属的团队数量，【团队id,团队名称，团队创建者id，团队成员数量，【所有用户成员id】】
#define FILED_TEAM_NUM 0//用户成员数量，【所有用户成员id】
#define FILED_TEAM_EVENT 7//事件标题，地点，开始时间，结束时间，事件类型，紧急程度，备注，


#include <iostream>  // C++ 标准库头文件应放在其他头文件之前
#include <QString>  // Qt 核心头文件应放在其他 Qt 相关头文件之前
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

#include "struct.h"  // 自定义头文件
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
