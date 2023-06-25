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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mapwidget
{
public:
    QFrame *frame;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWebEngineView *webEngineView;
    QLabel *label;
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
        Mapwidget->resize(497, 567);
        frame = new QFrame(Mapwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 9, 491, 561));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        webEngineView = new QWebEngineView(frame);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(webEngineView->sizePolicy().hasHeightForWidth());
        webEngineView->setSizePolicy(sizePolicy);
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        verticalLayout->addWidget(webEngineView);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_8);

        startInput = new QLineEdit(frame);
        startInput->setObjectName(QString::fromUtf8("startInput"));

        horizontalLayout_2->addWidget(startInput);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_9);

        endInput = new QLineEdit(frame);
        endInput->setObjectName(QString::fromUtf8("endInput"));

        horizontalLayout_2->addWidget(endInput);

        calculateButton = new QPushButton(frame);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_2->addWidget(calculateButton);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_6);

        distanceOutput = new QLineEdit(frame);
        distanceOutput->setObjectName(QString::fromUtf8("distanceOutput"));

        horizontalLayout_2->addWidget(distanceOutput);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_10);

        durationOutput = new QLineEdit(frame);
        durationOutput->setObjectName(QString::fromUtf8("durationOutput"));

        horizontalLayout_2->addWidget(durationOutput);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Mapwidget);

        QMetaObject::connectSlotsByName(Mapwidget);
    } // setupUi

    void retranslateUi(QWidget *Mapwidget)
    {
        Mapwidget->setWindowTitle(QCoreApplication::translate("Mapwidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("Mapwidget", "\347\254\254\344\270\200\346\254\241\345\212\240\350\275\275\347\224\250\346\227\266\350\276\203\351\225\277\357\274\214\346\225\254\350\257\267\350\200\220\345\277\203\347\255\211\345\276\205\357\274\214\347\254\254\344\272\214\346\254\241\344\271\213\345\220\216\345\260\261\345\217\257\344\273\245\347\247\222\345\274\200\344\272\206\357\274\201", nullptr));
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
