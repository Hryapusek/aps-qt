/********************************************************************************
** Form generated from reading UI file 'startupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUPDIALOG_H
#define UI_STARTUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StartupDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpinBox *devicesSpin;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpinBox *clientsSpin;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QSpinBox *timeSpin;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QSpinBox *bufferSpin;
    QSlider *bufferSlider;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QDoubleSpinBox *minDeviceTimeSpin;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QDoubleSpinBox *maxDeviceTimeSpin;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_7;
    QDoubleSpinBox *lambdaSpin;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *startBtn;
    QPushButton *exitBtn;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QDialog *StartupDialog)
    {
        if (StartupDialog->objectName().isEmpty())
            StartupDialog->setObjectName(QString::fromUtf8("StartupDialog"));
        StartupDialog->resize(227, 285);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartupDialog->sizePolicy().hasHeightForWidth());
        StartupDialog->setSizePolicy(sizePolicy);
        StartupDialog->setMinimumSize(QSize(227, 285));
        StartupDialog->setMaximumSize(QSize(227, 287));
        verticalLayout_3 = new QVBoxLayout(StartupDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(StartupDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        devicesSpin = new QSpinBox(StartupDialog);
        devicesSpin->setObjectName(QString::fromUtf8("devicesSpin"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(devicesSpin->sizePolicy().hasHeightForWidth());
        devicesSpin->setSizePolicy(sizePolicy1);
        devicesSpin->setMinimumSize(QSize(60, 0));
        devicesSpin->setBaseSize(QSize(0, 0));
        devicesSpin->setMinimum(1);
        devicesSpin->setMaximum(90);
        devicesSpin->setValue(10);

        horizontalLayout->addWidget(devicesSpin);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(StartupDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        clientsSpin = new QSpinBox(StartupDialog);
        clientsSpin->setObjectName(QString::fromUtf8("clientsSpin"));
        sizePolicy1.setHeightForWidth(clientsSpin->sizePolicy().hasHeightForWidth());
        clientsSpin->setSizePolicy(sizePolicy1);
        clientsSpin->setMinimumSize(QSize(60, 0));
        clientsSpin->setBaseSize(QSize(0, 0));
        clientsSpin->setMinimum(1);
        clientsSpin->setMaximum(90);
        clientsSpin->setValue(20);

        horizontalLayout_2->addWidget(clientsSpin);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_3 = new QLabel(StartupDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        timeSpin = new QSpinBox(StartupDialog);
        timeSpin->setObjectName(QString::fromUtf8("timeSpin"));
        sizePolicy1.setHeightForWidth(timeSpin->sizePolicy().hasHeightForWidth());
        timeSpin->setSizePolicy(sizePolicy1);
        timeSpin->setMinimumSize(QSize(60, 0));
        timeSpin->setBaseSize(QSize(0, 0));
        timeSpin->setMinimum(1);
        timeSpin->setMaximum(100000);
        timeSpin->setValue(43200);

        horizontalLayout_3->addWidget(timeSpin);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_4 = new QLabel(StartupDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        bufferSpin = new QSpinBox(StartupDialog);
        bufferSpin->setObjectName(QString::fromUtf8("bufferSpin"));
        bufferSpin->setMinimum(1);
        bufferSpin->setMaximum(1000);
        bufferSpin->setValue(5);

        horizontalLayout_4->addWidget(bufferSpin);

        bufferSlider = new QSlider(StartupDialog);
        bufferSlider->setObjectName(QString::fromUtf8("bufferSlider"));
        bufferSlider->setMinimum(1);
        bufferSlider->setMaximum(1000);
        bufferSlider->setValue(5);
        bufferSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(bufferSlider);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_5 = new QLabel(StartupDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        minDeviceTimeSpin = new QDoubleSpinBox(StartupDialog);
        minDeviceTimeSpin->setObjectName(QString::fromUtf8("minDeviceTimeSpin"));
        minDeviceTimeSpin->setMinimum(0.010000000000000);
        minDeviceTimeSpin->setMaximum(200.000000000000000);
        minDeviceTimeSpin->setSingleStep(0.300000000000000);
        minDeviceTimeSpin->setValue(20.000000000000000);

        horizontalLayout_5->addWidget(minDeviceTimeSpin);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        label_6 = new QLabel(StartupDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        maxDeviceTimeSpin = new QDoubleSpinBox(StartupDialog);
        maxDeviceTimeSpin->setObjectName(QString::fromUtf8("maxDeviceTimeSpin"));
        maxDeviceTimeSpin->setMinimum(0.010000000000000);
        maxDeviceTimeSpin->setMaximum(200.000000000000000);
        maxDeviceTimeSpin->setSingleStep(0.300000000000000);
        maxDeviceTimeSpin->setValue(30.000000000000000);

        horizontalLayout_6->addWidget(maxDeviceTimeSpin);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        label_7 = new QLabel(StartupDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lambdaSpin = new QDoubleSpinBox(StartupDialog);
        lambdaSpin->setObjectName(QString::fromUtf8("lambdaSpin"));
        lambdaSpin->setMinimum(0.100000000000000);
        lambdaSpin->setMaximum(100.000000000000000);
        lambdaSpin->setSingleStep(0.100000000000000);

        horizontalLayout_7->addWidget(lambdaSpin);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_8 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        startBtn = new QPushButton(StartupDialog);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));

        horizontalLayout_8->addWidget(startBtn);

        exitBtn = new QPushButton(StartupDialog);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout_8->addWidget(exitBtn);

        horizontalSpacer_9 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(StartupDialog);
        QObject::connect(bufferSlider, SIGNAL(valueChanged(int)), bufferSpin, SLOT(setValue(int)));
        QObject::connect(bufferSpin, SIGNAL(valueChanged(int)), bufferSlider, SLOT(setValue(int)));
        QObject::connect(startBtn, SIGNAL(clicked()), StartupDialog, SLOT(accept()));
        QObject::connect(exitBtn, SIGNAL(clicked()), StartupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StartupDialog);
    } // setupUi

    void retranslateUi(QDialog *StartupDialog)
    {
        StartupDialog->setWindowTitle(QCoreApplication::translate("StartupDialog", "APS", nullptr));
        label->setText(QCoreApplication::translate("StartupDialog", "Devices", nullptr));
        label_2->setText(QCoreApplication::translate("StartupDialog", "Clients", nullptr));
        label_3->setText(QCoreApplication::translate("StartupDialog", "Time", nullptr));
        label_4->setText(QCoreApplication::translate("StartupDialog", "Buffer size", nullptr));
        label_5->setText(QCoreApplication::translate("StartupDialog", "Min device time", nullptr));
        label_6->setText(QCoreApplication::translate("StartupDialog", "Max device time", nullptr));
        label_7->setText(QCoreApplication::translate("StartupDialog", "Lambda", nullptr));
        startBtn->setText(QCoreApplication::translate("StartupDialog", "Start", nullptr));
        exitBtn->setText(QCoreApplication::translate("StartupDialog", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartupDialog: public Ui_StartupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUPDIALOG_H
