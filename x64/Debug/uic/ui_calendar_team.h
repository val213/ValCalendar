/********************************************************************************
** Form generated from reading UI file 'calendar_team.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_TEAM_H
#define UI_CALENDAR_TEAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calendar_team
{
public:
    QCalendarWidget *calendarWidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QLabel *label_2;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QTextEdit *textEdit_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;

    void setupUi(QWidget *calendar_team)
    {
        if (calendar_team->objectName().isEmpty())
            calendar_team->setObjectName(QString::fromUtf8("calendar_team"));
        calendar_team->resize(824, 472);
        calendarWidget = new QCalendarWidget(calendar_team);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 20, 411, 261));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\275\256\345\255\227\347\244\276\345\233\275\351\243\216\347\235\277\346\245\267\347\256\200\347\271\201-\351\227\252")});
        font.setPointSize(12);
        calendarWidget->setFont(font);
        tableWidget = new QTableWidget(calendar_team);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 290, 771, 161));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        pushButton_4 = new QPushButton(calendar_team);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(660, 220, 121, 24));
        pushButton_4->setFont(font);
        horizontalLayoutWidget = new QWidget(calendar_team);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(430, 50, 191, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_14);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200")});
        font1.setPointSize(14);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(calendar_team);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 20, 221, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200")});
        font2.setPointSize(16);
        label->setFont(font2);
        tabWidget = new QTabWidget(calendar_team);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(430, 110, 351, 111));
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(-20, 0, 371, 81));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(-10, 0, 361, 81));
        tabWidget->addTab(tab_2, QString());
        layoutWidget = new QWidget(calendar_team);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(429, 250, 351, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout_2->addWidget(pushButton_3);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);

        horizontalLayout_2->addWidget(comboBox);


        retranslateUi(calendar_team);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(calendar_team);
    } // setupUi

    void retranslateUi(QWidget *calendar_team)
    {
        calendar_team->setWindowTitle(QCoreApplication::translate("calendar_team", "Form", nullptr));
        pushButton_4->setText(QCoreApplication::translate("calendar_team", "\346\233\264\346\226\260\345\205\254\345\221\212\346\240\217", nullptr));
        label_14->setText(QCoreApplication::translate("calendar_team", "Current team:", nullptr));
        label_2->setText(QCoreApplication::translate("calendar_team", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("calendar_team", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("calendar_team", "\345\205\254\345\221\212\346\240\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("calendar_team", "\345\205\266\344\273\226\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("calendar_team", "\347\241\256\345\256\232\344\277\256\346\224\271\346\227\245\347\250\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("calendar_team", "\345\210\240\351\231\244\351\200\211\344\270\255\346\227\245\347\250\213", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("calendar_team", "\351\273\230\350\256\244\346\267\273\345\212\240\351\241\272\345\272\217", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("calendar_team", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("calendar_team", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("calendar_team", "\347\264\247\346\200\245\347\250\213\345\272\246", nullptr));

    } // retranslateUi

};

namespace Ui {
    class calendar_team: public Ui_calendar_team {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_TEAM_H
