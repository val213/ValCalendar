#ifndef CONFIG_H
#define CONFIG_H

#define MAX_USRS_NUM 100
#define MAX_USRS_EVENT 100
#define MAX_TEAM_NUM 100
//用户id的前缀
#define USER_ID_FORE 1001
//团队id的前缀
#define TEAM_ID_FORE 2001
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
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
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
