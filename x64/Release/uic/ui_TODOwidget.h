/********************************************************************************
** Form generated from reading UI file 'TODOwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODOWIDGET_H
#define UI_TODOWIDGET_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TODOwidget1
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWebEngineView *webEngineView;
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
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *comboBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QLabel *label_4;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *TODOwidget1)
    {
        if (TODOwidget1->objectName().isEmpty())
            TODOwidget1->setObjectName(QString::fromUtf8("TODOwidget1"));
        TODOwidget1->resize(516, 822);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TODOwidget1->sizePolicy().hasHeightForWidth());
        TODOwidget1->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(TODOwidget1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 503, 811));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(verticalLayoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        verticalLayout_2->addWidget(dateTimeEdit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_5);

        dateTimeEdit_2 = new QDateTimeEdit(verticalLayoutWidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        verticalLayout->addWidget(dateTimeEdit_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_3);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(lineEdit_3);

        webEngineView = new QWebEngineView(verticalLayoutWidget);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(webEngineView->sizePolicy().hasHeightForWidth());
        webEngineView->setSizePolicy(sizePolicy3);
        webEngineView->setInputMethodHints(Qt::ImhNone);
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        verticalLayout_4->addWidget(webEngineView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_8);

        startInput = new QLineEdit(verticalLayoutWidget);
        startInput->setObjectName(QString::fromUtf8("startInput"));

        horizontalLayout_2->addWidget(startInput);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_9);

        endInput = new QLineEdit(verticalLayoutWidget);
        endInput->setObjectName(QString::fromUtf8("endInput"));

        horizontalLayout_2->addWidget(endInput);

        calculateButton = new QPushButton(verticalLayoutWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_2->addWidget(calculateButton);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_6);

        distanceOutput = new QLineEdit(verticalLayoutWidget);
        distanceOutput->setObjectName(QString::fromUtf8("distanceOutput"));

        horizontalLayout_2->addWidget(distanceOutput);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_10);

        durationOutput = new QLineEdit(verticalLayoutWidget);
        durationOutput->setObjectName(QString::fromUtf8("durationOutput"));

        horizontalLayout_2->addWidget(durationOutput);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        radioButton_3 = new QRadioButton(widget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout->addWidget(radioButton_3);


        verticalLayout_3->addWidget(widget);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(label_4);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy2.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy5);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(TODOwidget1);

        QMetaObject::connectSlotsByName(TODOwidget1);
    } // setupUi

    void retranslateUi(QWidget *TODOwidget1)
    {
        TODOwidget1->setWindowTitle(QCoreApplication::translate("TODOwidget1", "Form", nullptr));
        label->setText(QCoreApplication::translate("TODOwidget1", "event title", nullptr));
        label_2->setText(QCoreApplication::translate("TODOwidget1", "start time", nullptr));
        label_5->setText(QCoreApplication::translate("TODOwidget1", "end time", nullptr));
        label_3->setText(QCoreApplication::translate("TODOwidget1", "position", nullptr));
        label_8->setText(QCoreApplication::translate("TODOwidget1", "\350\265\267\347\202\271\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("TODOwidget1", "\347\273\210\347\202\271\357\274\232", nullptr));
        calculateButton->setText(QCoreApplication::translate("TODOwidget1", "\350\256\241\347\256\227\350\267\235\347\246\273\346\227\266\351\227\264", nullptr));
        label_6->setText(QCoreApplication::translate("TODOwidget1", "\350\267\235\347\246\273\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("TODOwidget1", "\346\227\266\351\227\264", nullptr));
        label_7->setText(QCoreApplication::translate("TODOwidget1", "\344\272\213\344\273\266\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("TODOwidget1", "\350\200\203\350\257\225", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("TODOwidget1", "\350\207\252\344\271\240", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("TODOwidget1", "\344\270\212\350\257\276", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("TODOwidget1", "\345\255\246\347\224\237\345\267\245\344\275\234", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("TODOwidget1", "\350\256\262\345\272\247", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("TODOwidget1", "\345\244\226\345\207\272\345\250\261\344\271\220\346\264\273\345\212\250", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("TODOwidget1", "\350\265\264\347\272\246", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("TODOwidget1", "\346\257\224\350\265\233", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("TODOwidget1", "\345\205\266\344\273\226", nullptr));

        radioButton_2->setText(QCoreApplication::translate("TODOwidget1", "\345\215\201\345\210\206\351\207\215\350\246\201", nullptr));
        radioButton->setText(QCoreApplication::translate("TODOwidget1", "\346\234\211\347\202\271\351\207\215\350\246\201", nullptr));
        radioButton_3->setText(QCoreApplication::translate("TODOwidget1", "\344\270\215\351\207\215\350\246\201", nullptr));
        label_4->setText(QCoreApplication::translate("TODOwidget1", "\345\244\207\346\263\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TODOwidget1: public Ui_TODOwidget1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOWIDGET_H
