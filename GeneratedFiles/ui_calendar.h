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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QVBoxLayout *verticalLayout_6;
    QCalendarWidget *Calendar1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *label_13;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QTextBrowser *textBrowser_7;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QTextBrowser *textBrowser_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QTextBrowser *textBrowser_8;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
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
    QFrame *line_3;
    QTableWidget *tableWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QLabel *label_16;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *calendarClass)
    {
        if (calendarClass->objectName().isEmpty())
            calendarClass->setObjectName(QString::fromUtf8("calendarClass"));
        calendarClass->resize(956, 637);
        centralWidget = new QWidget(calendarClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 20, 921, 332));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(verticalLayoutWidget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setBold(true);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        checkBox_3 = new QCheckBox(verticalLayoutWidget_5);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(verticalLayoutWidget_5);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox = new QCheckBox(verticalLayoutWidget_5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        label_2->setWordWrap(false);
        label_2->setMargin(-1);
        label_2->setIndent(-1);
        label_2->setOpenExternalLinks(false);

        verticalLayout_3->addWidget(label_2);

        checkBox_4 = new QCheckBox(verticalLayoutWidget_5);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        verticalLayout_3->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(verticalLayoutWidget_5);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        verticalLayout_3->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(verticalLayoutWidget_5);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        verticalLayout_3->addWidget(checkBox_6);


        verticalLayout->addLayout(verticalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));

        horizontalLayout_6->addLayout(verticalLayout_6);

        Calendar1 = new QCalendarWidget(verticalLayoutWidget_5);
        Calendar1->setObjectName(QString::fromUtf8("Calendar1"));
        Calendar1->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Calendar1->sizePolicy().hasHeightForWidth());
        Calendar1->setSizePolicy(sizePolicy1);
        Calendar1->setMouseTracking(true);
        Calendar1->setTabletTracking(true);
        Calendar1->setAcceptDrops(true);
        Calendar1->setAutoFillBackground(true);
        Calendar1->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        Calendar1->setGridVisible(true);
        Calendar1->setNavigationBarVisible(true);
        Calendar1->setDateEditEnabled(true);

        horizontalLayout_6->addWidget(Calendar1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAcceptDrops(false);

        horizontalLayout_3->addWidget(label);

        label_12 = new QLabel(verticalLayoutWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_11 = new QLabel(verticalLayoutWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setAcceptDrops(false);

        horizontalLayout_5->addWidget(label_11);

        label_13 = new QLabel(verticalLayoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_5->addWidget(label_13);


        verticalLayout_5->addLayout(horizontalLayout_5);

        stackedWidget = new QStackedWidget(verticalLayoutWidget_5);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 371, 170));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        textBrowser_7 = new QTextBrowser(verticalLayoutWidget);
        textBrowser_7->setObjectName(QString::fromUtf8("textBrowser_7"));
        textBrowser_7->setMaximumSize(QSize(16777215, 50));
        textBrowser_7->setAcceptDrops(false);
        textBrowser_7->setTabChangesFocus(false);
        textBrowser_7->setUndoRedoEnabled(false);
        textBrowser_7->setReadOnly(true);
        textBrowser_7->setAcceptRichText(true);
        textBrowser_7->setOpenLinks(false);

        horizontalLayout_9->addWidget(textBrowser_7, 0, Qt::AlignHCenter);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);


        verticalLayout_8->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(label_6);

        textBrowser_6 = new QTextBrowser(verticalLayoutWidget);
        textBrowser_6->setObjectName(QString::fromUtf8("textBrowser_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
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

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(label_7);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy4);
        label_10->setSizeIncrement(QSize(0, 0));

        horizontalLayout_10->addWidget(label_10);

        textBrowser_8 = new QTextBrowser(verticalLayoutWidget);
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


        verticalLayout_8->addLayout(horizontalLayout_10);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_5->addWidget(stackedWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        verticalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_6);

        widget = new QWidget(verticalLayoutWidget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_7->addWidget(pushButton);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_7->addWidget(label_15);

        view = new QComboBox(widget);
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->addItem(QString());
        view->setObjectName(QString::fromUtf8("view"));

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

        horizontalLayout_7->addWidget(label_5);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_3);


        verticalLayout_7->addWidget(widget);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(25, 370, 911, 211));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy5);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 0, 191, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_14);

        label_16 = new QLabel(horizontalLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy5.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy5);

        horizontalLayout->addWidget(label_16);

        calendarClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(calendarClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 956, 22));
        calendarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(calendarClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        calendarClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(calendarClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        calendarClass->setStatusBar(statusBar);

        retranslateUi(calendarClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(calendarClass);
    } // setupUi

    void retranslateUi(QMainWindow *calendarClass)
    {
        calendarClass->setWindowTitle(QCoreApplication::translate("calendarClass", "calendar", nullptr));
        label_3->setText(QCoreApplication::translate("calendarClass", "MyCalendar", nullptr));
        checkBox_3->setText(QCoreApplication::translate("calendarClass", "Important Events", nullptr));
        checkBox_2->setText(QCoreApplication::translate("calendarClass", "Holiday", nullptr));
        checkBox->setText(QCoreApplication::translate("calendarClass", "Tasks", nullptr));
        label_2->setText(QCoreApplication::translate("calendarClass", "Other Calendars", nullptr));
        checkBox_4->setText(QCoreApplication::translate("calendarClass", "Individual", nullptr));
        checkBox_5->setText(QCoreApplication::translate("calendarClass", "Group 1", nullptr));
        checkBox_6->setText(QCoreApplication::translate("calendarClass", "Group 2", nullptr));
        label->setText(QCoreApplication::translate("calendarClass", "Time now", nullptr));
        label_12->setText(QString());
        label_11->setText(QCoreApplication::translate("calendarClass", "The time of the next event ", nullptr));
        label_13->setText(QString());
        label_8->setText(QCoreApplication::translate("calendarClass", "\346\234\200\346\231\232", nullptr));
        label_9->setText(QCoreApplication::translate("calendarClass", "\345\220\216\345\207\272\345\217\221", nullptr));
        label_6->setText(QCoreApplication::translate("calendarClass", "\345\273\272\350\256\256", nullptr));
        label_7->setText(QCoreApplication::translate("calendarClass", "\345\220\216\345\207\272\345\217\221", nullptr));
        label_10->setText(QCoreApplication::translate("calendarClass", "\345\244\251\346\260\224\345\273\272\350\256\256", nullptr));
        pushButton->setText(QCoreApplication::translate("calendarClass", "Team manage", nullptr));
        label_15->setText(QCoreApplication::translate("calendarClass", "  View\357\274\232", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class calendarClass: public Ui_calendarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
