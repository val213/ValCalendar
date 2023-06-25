/********************************************************************************
** Form generated from reading UI file 'Team_mng.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAM_MNG_H
#define UI_TEAM_MNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_team_mng
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *team_mng)
    {
        if (team_mng->objectName().isEmpty())
            team_mng->setObjectName(QString::fromUtf8("team_mng"));
        team_mng->resize(362, 354);
        horizontalLayoutWidget = new QWidget(team_mng);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 324, 88));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4, 0, Qt::AlignHCenter);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(horizontalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout_3->addWidget(pushButton_6);


        horizontalLayout->addLayout(verticalLayout_3);

        tableWidget = new QTableWidget(team_mng);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 260, 321, 86));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget_2 = new QTableWidget(team_mng);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(20, 140, 321, 86));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        label_2 = new QLabel(team_mng);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 230, 111, 16));
        label_3 = new QLabel(team_mng);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 101, 16));

        retranslateUi(team_mng);

        QMetaObject::connectSlotsByName(team_mng);
    } // setupUi

    void retranslateUi(QWidget *team_mng)
    {
        team_mng->setWindowTitle(QCoreApplication::translate("team_mng", "Form", nullptr));
        label->setText(QCoreApplication::translate("team_mng", "\345\210\233\345\273\272/\345\212\240\345\205\245\345\233\242\351\230\237", nullptr));
        pushButton->setText(QCoreApplication::translate("team_mng", "Create New Team", nullptr));
        pushButton_4->setText(QCoreApplication::translate("team_mng", "Join Team", nullptr));
        label_4->setText(QCoreApplication::translate("team_mng", "\345\210\240\351\231\244/\351\200\200\345\207\272\345\233\242\351\230\237", nullptr));
        pushButton_3->setText(QCoreApplication::translate("team_mng", "Delete Team", nullptr));
        pushButton_6->setText(QCoreApplication::translate("team_mng", "Exit Team", nullptr));
        label_2->setText(QCoreApplication::translate("team_mng", "team_you_belong", nullptr));
        label_3->setText(QCoreApplication::translate("team_mng", "team_you_create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class team_mng: public Ui_team_mng {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAM_MNG_H
