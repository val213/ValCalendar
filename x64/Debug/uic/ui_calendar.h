/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calendarClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QCalendarWidget *Calendar1;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QTextBrowser *textBrowser_7;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QTextBrowser *textBrowser_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QTextBrowser *textBrowser_8;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *label_13;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QLabel *label_15;
    QComboBox *view;
    QTextBrowser *textBrowser_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *label_5;
    QTableWidget *tableWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QLabel *label_16;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *calendarClass)
    {
        if (calendarClass->objectName().isEmpty())
            calendarClass->setObjectName(QString::fromUtf8("calendarClass"));
        calendarClass->resize(925, 616);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calendarClass->sizePolicy().hasHeightForWidth());
        calendarClass->setSizePolicy(sizePolicy);
        calendarClass->setStyleSheet(QString::fromUtf8("calendar{background-image: url(:/calendar/SCUT.jpg);}"));
        centralWidget = new QWidget(calendarClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 20, 902, 286));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));

        horizontalLayout_6->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_5 = new QPushButton(verticalLayoutWidget_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\275\256\345\255\227\347\244\276\345\233\275\351\243\216\347\235\277\346\245\267\347\256\200\347\271\201-\351\227\252")});
        font.setPointSize(12);
        pushButton_5->setFont(font);
        pushButton_5->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(pushButton_5);

        label_3 = new QLabel(verticalLayoutWidget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(14);
        font1.setBold(false);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);


        horizontalLayout_6->addLayout(verticalLayout);

        Calendar1 = new QCalendarWidget(verticalLayoutWidget_5);
        Calendar1->setObjectName(QString::fromUtf8("Calendar1"));
        Calendar1->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Calendar1->sizePolicy().hasHeightForWidth());
        Calendar1->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\275\256\345\255\227\347\244\276\345\233\275\351\243\216\347\235\277\346\245\267\347\256\200\347\271\201-\351\227\252")});
        font2.setPointSize(16);
        Calendar1->setFont(font2);
        Calendar1->setMouseTracking(true);
        Calendar1->setTabletTracking(true);
        Calendar1->setAcceptDrops(true);
        Calendar1->setAutoFillBackground(true);
        Calendar1->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        Calendar1->setGridVisible(true);
        Calendar1->setNavigationBarVisible(true);
        Calendar1->setDateEditEnabled(true);

        horizontalLayout_6->addWidget(Calendar1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(verticalLayoutWidget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_8);

        textBrowser_7 = new QTextBrowser(verticalLayoutWidget_5);
        textBrowser_7->setObjectName(QString::fromUtf8("textBrowser_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textBrowser_7->sizePolicy().hasHeightForWidth());
        textBrowser_7->setSizePolicy(sizePolicy3);
        textBrowser_7->setMaximumSize(QSize(16777215, 50));
        textBrowser_7->setAcceptDrops(false);
        textBrowser_7->setTabChangesFocus(false);
        textBrowser_7->setUndoRedoEnabled(false);
        textBrowser_7->setReadOnly(true);
        textBrowser_7->setAcceptRichText(true);
        textBrowser_7->setOpenLinks(false);

        horizontalLayout_9->addWidget(textBrowser_7, 0, Qt::AlignHCenter);

        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout_9->addWidget(label_9);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        label_6 = new QLabel(verticalLayoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_6);

        textBrowser_6 = new QTextBrowser(verticalLayoutWidget_5);
        textBrowser_6->setObjectName(QString::fromUtf8("textBrowser_6"));
        sizePolicy3.setHeightForWidth(textBrowser_6->sizePolicy().hasHeightForWidth());
        textBrowser_6->setSizePolicy(sizePolicy3);
        textBrowser_6->setMaximumSize(QSize(16777215, 50));
        textBrowser_6->setAcceptDrops(false);
        textBrowser_6->setTabChangesFocus(false);
        textBrowser_6->setUndoRedoEnabled(false);
        textBrowser_6->setReadOnly(true);
        textBrowser_6->setAcceptRichText(true);
        textBrowser_6->setOpenLinks(false);

        horizontalLayout_8->addWidget(textBrowser_6, 0, Qt::AlignHCenter);

        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setFont(font);

        horizontalLayout_8->addWidget(label_7);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_2 = new QLabel(verticalLayoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_2);

        textBrowser_8 = new QTextBrowser(verticalLayoutWidget_5);
        textBrowser_8->setObjectName(QString::fromUtf8("textBrowser_8"));
        sizePolicy3.setHeightForWidth(textBrowser_8->sizePolicy().hasHeightForWidth());
        textBrowser_8->setSizePolicy(sizePolicy3);
        textBrowser_8->setMaximumSize(QSize(16777215, 50));
        textBrowser_8->setAcceptDrops(false);
        textBrowser_8->setTabChangesFocus(false);
        textBrowser_8->setUndoRedoEnabled(false);
        textBrowser_8->setReadOnly(true);
        textBrowser_8->setAcceptRichText(true);
        textBrowser_8->setOpenLinks(false);

        horizontalLayout_10->addWidget(textBrowser_8);

        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy4.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy4);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_10);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_2->addLayout(verticalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget_5);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(16);
        label->setFont(font3);
        label->setAcceptDrops(false);

        horizontalLayout_3->addWidget(label);

        label_12 = new QLabel(verticalLayoutWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200")});
        font4.setPointSize(12);
        label_12->setFont(font4);

        horizontalLayout_3->addWidget(label_12);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_11 = new QLabel(verticalLayoutWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy5);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Times New Roman")});
        font5.setPointSize(12);
        label_11->setFont(font5);
        label_11->setAcceptDrops(false);

        horizontalLayout_5->addWidget(label_11);

        label_13 = new QLabel(verticalLayoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font4);

        horizontalLayout_5->addWidget(label_13);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout);


        verticalLayout_7->addLayout(horizontalLayout_6);

        widget = new QWidget(verticalLayoutWidget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setFont(font5);

        horizontalLayout_7->addWidget(pushButton);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy6);
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_15);

        view = new QComboBox(widget);
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->setObjectName(QString::fromUtf8("view"));
        view->setFont(font5);
        view->setAutoFillBackground(false);
        view->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        view->setMinimumContentsLength(0);

        horizontalLayout_7->addWidget(view);

        textBrowser_3 = new QTextBrowser(widget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setMaximumSize(QSize(200, 20));
        textBrowser_3->setAcceptDrops(false);
        textBrowser_3->setTabChangesFocus(false);
        textBrowser_3->setUndoRedoEnabled(false);
        textBrowser_3->setReadOnly(true);
        textBrowser_3->setAcceptRichText(true);
        textBrowser_3->setOpenLinks(false);

        horizontalLayout_7->addWidget(textBrowser_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy6.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy6);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_4);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setMaximumSize(QSize(200, 20));
        textBrowser->setAcceptDrops(false);
        textBrowser->setTabChangesFocus(false);
        textBrowser->setUndoRedoEnabled(false);
        textBrowser->setReadOnly(true);
        textBrowser->setAcceptRichText(true);
        textBrowser->setOpenLinks(false);

        horizontalLayout_7->addWidget(textBrowser);

        textBrowser_2 = new QTextBrowser(widget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setMaximumSize(QSize(200, 20));
        textBrowser_2->setAcceptDrops(false);
        textBrowser_2->setTabChangesFocus(false);
        textBrowser_2->setUndoRedoEnabled(false);
        textBrowser_2->setReadOnly(true);
        textBrowser_2->setAcceptRichText(true);
        textBrowser_2->setOpenLinks(false);

        horizontalLayout_7->addWidget(textBrowser_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy6.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy6);
        label_5->setFont(font);
        label_5->setAutoFillBackground(false);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_5);


        verticalLayout_7->addWidget(widget);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 350, 901, 211));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy7);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 310, 191, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy5.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy5);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Rockwell Condensed")});
        font6.setPointSize(12);
        label_14->setFont(font6);
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_14);

        label_16 = new QLabel(horizontalLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy4.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy4);
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Monotype Corsiva")});
        font7.setPointSize(20);
        font7.setItalic(true);
        label_16->setFont(font7);
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_16);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(580, 310, 345, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout_2->addWidget(pushButton_3);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);

        horizontalLayout_4->addWidget(comboBox);

        calendarClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(calendarClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 22));
        calendarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(calendarClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        calendarClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(calendarClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        calendarClass->setStatusBar(statusBar);

        retranslateUi(calendarClass);

        QMetaObject::connectSlotsByName(calendarClass);
    } // setupUi

    void retranslateUi(QMainWindow *calendarClass)
    {
        calendarClass->setWindowTitle(QCoreApplication::translate("calendarClass", "calendar", nullptr));
        pushButton_5->setText(QCoreApplication::translate("calendarClass", "\346\233\264\346\226\260\345\233\242\351\230\237\346\227\245\345\216\206\346\241\206", nullptr));
        label_3->setText(QCoreApplication::translate("calendarClass", "MyCalendar", nullptr));
        label_8->setText(QCoreApplication::translate("calendarClass", "\346\234\200\346\231\232", nullptr));
        label_9->setText(QCoreApplication::translate("calendarClass", "\345\220\216\345\207\272\345\217\221", nullptr));
        label_6->setText(QCoreApplication::translate("calendarClass", "\345\273\272\350\256\256", nullptr));
        label_7->setText(QCoreApplication::translate("calendarClass", "\345\220\216\345\207\272\345\217\221", nullptr));
        label_2->setText(QCoreApplication::translate("calendarClass", "\345\244\251\346\260\224", nullptr));
        label_10->setText(QCoreApplication::translate("calendarClass", "\345\233\276\346\240\207", nullptr));
        label->setText(QCoreApplication::translate("calendarClass", "Time now", nullptr));
        label_12->setText(QString());
        label_11->setText(QCoreApplication::translate("calendarClass", "The time of the next event ", nullptr));
        label_13->setText(QString());
        pushButton->setText(QCoreApplication::translate("calendarClass", "Team manage", nullptr));
        label_15->setText(QCoreApplication::translate("calendarClass", "\346\212\245\345\221\212\357\274\232", nullptr));
        view->setItemText(0, QCoreApplication::translate("calendarClass", "Day", nullptr));
        view->setItemText(1, QCoreApplication::translate("calendarClass", "Week", nullptr));
        view->setItemText(2, QCoreApplication::translate("calendarClass", "Month", nullptr));
        view->setItemText(3, QCoreApplication::translate("calendarClass", "Year", nullptr));
        view->setItemText(4, QCoreApplication::translate("calendarClass", "Schedule", nullptr));
        view->setItemText(5, QCoreApplication::translate("calendarClass", "4 days", nullptr));

        label_4->setText(QCoreApplication::translate("calendarClass", "\350\267\235\347\246\273", nullptr));
        label_5->setText(QCoreApplication::translate("calendarClass", "\345\244\251", nullptr));
        label_14->setText(QCoreApplication::translate("calendarClass", "Current user:", nullptr));
        label_16->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("calendarClass", "\347\241\256\345\256\232\344\277\256\346\224\271\346\227\245\347\250\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("calendarClass", "\345\210\240\351\231\244\351\200\211\344\270\255\346\227\245\347\250\213", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("calendarClass", "\351\273\230\350\256\244\346\267\273\345\212\240\351\241\272\345\272\217", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("calendarClass", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("calendarClass", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("calendarClass", "\347\264\247\346\200\245\347\250\213\345\272\246", nullptr));

    } // retranslateUi

};

namespace Ui {
    class calendarClass: public Ui_calendarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
