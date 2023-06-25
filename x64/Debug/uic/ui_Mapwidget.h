/********************************************************************************
** Form generated from reading UI file 'Mapwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWIDGET_H
#define UI_MAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mapwidget
{
public:
    QWebEngineView *webEngineView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *startInput;
    QLabel *label_9;
    QLineEdit *endInput;
    QPushButton *calculateButton;
    QLabel *label_6;
    QLineEdit *distanceOutput;
    QLabel *label_10;
    QLineEdit *durationOutput;

    void setupUi(QWidget *Mapwidget)
    {
        if (Mapwidget->objectName().isEmpty())
            Mapwidget->setObjectName(QString::fromUtf8("Mapwidget"));
        Mapwidget->setWindowModality(Qt::WindowModal);
        Mapwidget->resize(1004, 858);
        webEngineView = new QWebEngineView(Mapwidget);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setGeometry(QRect(9, 9, 991, 781));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));
        layoutWidget = new QWidget(Mapwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 810, 790, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_8);

        startInput = new QLineEdit(layoutWidget);
        startInput->setObjectName(QString::fromUtf8("startInput"));

        horizontalLayout_2->addWidget(startInput);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_9);

        endInput = new QLineEdit(layoutWidget);
        endInput->setObjectName(QString::fromUtf8("endInput"));

        horizontalLayout_2->addWidget(endInput);

        calculateButton = new QPushButton(layoutWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_2->addWidget(calculateButton);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_6);

        distanceOutput = new QLineEdit(layoutWidget);
        distanceOutput->setObjectName(QString::fromUtf8("distanceOutput"));

        horizontalLayout_2->addWidget(distanceOutput);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_10);

        durationOutput = new QLineEdit(layoutWidget);
        durationOutput->setObjectName(QString::fromUtf8("durationOutput"));

        horizontalLayout_2->addWidget(durationOutput);


        retranslateUi(Mapwidget);

        QMetaObject::connectSlotsByName(Mapwidget);
    } // setupUi

    void retranslateUi(QWidget *Mapwidget)
    {
        Mapwidget->setWindowTitle(QCoreApplication::translate("Mapwidget", "Form", nullptr));
        label_8->setText(QCoreApplication::translate("Mapwidget", "\350\265\267\347\202\271\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Mapwidget", "\347\273\210\347\202\271\357\274\232", nullptr));
        calculateButton->setText(QCoreApplication::translate("Mapwidget", "\350\256\241\347\256\227\350\267\235\347\246\273\346\227\266\351\227\264", nullptr));
        label_6->setText(QCoreApplication::translate("Mapwidget", "\350\267\235\347\246\273\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("Mapwidget", "\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mapwidget: public Ui_Mapwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWIDGET_H
