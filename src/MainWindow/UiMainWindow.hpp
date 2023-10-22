/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTableWidget *bufferTable;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QTableWidget *devicesTable;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QTableWidget *eventsTable;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *succededLine;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLineEdit *canceledLine;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *stepBtn;
    QPushButton *autoBtn;
    QPushButton *resultsBtn;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1390, 695);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        bufferTable = new QTableWidget(verticalLayoutWidget);
        if (bufferTable->columnCount() < 4)
            bufferTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        bufferTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        bufferTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        bufferTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        bufferTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        bufferTable->setObjectName(QString::fromUtf8("bufferTable"));
        bufferTable->setMinimumSize(QSize(10, 0));

        verticalLayout_3->addWidget(bufferTable);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        devicesTable = new QTableWidget(verticalLayoutWidget_2);
        if (devicesTable->columnCount() < 2)
            devicesTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        devicesTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        devicesTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        devicesTable->setObjectName(QString::fromUtf8("devicesTable"));
        devicesTable->setMinimumSize(QSize(10, 0));

        verticalLayout_4->addWidget(devicesTable);

        splitter->addWidget(verticalLayoutWidget_2);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        eventsTable = new QTableWidget(layoutWidget);
        if (eventsTable->columnCount() < 3)
            eventsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        eventsTable->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        eventsTable->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        eventsTable->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        eventsTable->setObjectName(QString::fromUtf8("eventsTable"));
        eventsTable->setMinimumSize(QSize(10, 0));

        verticalLayout->addWidget(eventsTable);

        splitter->addWidget(layoutWidget);

        horizontalLayout_2->addWidget(splitter);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        succededLine = new QLineEdit(centralwidget);
        succededLine->setObjectName(QString::fromUtf8("succededLine"));
        succededLine->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(succededLine->sizePolicy().hasHeightForWidth());
        succededLine->setSizePolicy(sizePolicy);
        succededLine->setMinimumSize(QSize(0, 0));
        succededLine->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(succededLine);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        canceledLine = new QLineEdit(centralwidget);
        canceledLine->setObjectName(QString::fromUtf8("canceledLine"));
        sizePolicy.setHeightForWidth(canceledLine->sizePolicy().hasHeightForWidth());
        canceledLine->setSizePolicy(sizePolicy);
        canceledLine->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_7->addWidget(canceledLine);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stepBtn = new QPushButton(centralwidget);
        stepBtn->setObjectName(QString::fromUtf8("stepBtn"));

        horizontalLayout->addWidget(stepBtn);

        autoBtn = new QPushButton(centralwidget);
        autoBtn->setObjectName(QString::fromUtf8("autoBtn"));

        horizontalLayout->addWidget(autoBtn);

        resultsBtn = new QPushButton(centralwidget);
        resultsBtn->setObjectName(QString::fromUtf8("resultsBtn"));

        horizontalLayout->addWidget(resultsBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_7);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1390, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<b>Buffer</b>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = bufferTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = bufferTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = bufferTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\217\320\262\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = bufferTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<b>Devices</b>", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = devicesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = devicesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\217\320\262\320\272\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<b>\320\241\320\276\320\261\321\213\321\202\320\270\321\217</b>", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = eventsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = eventsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = eventsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Success:", nullptr));
        succededLine->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Canceled:", nullptr));
        canceledLine->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        stepBtn->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        autoBtn->setText(QCoreApplication::translate("MainWindow", "Auto", nullptr));
        resultsBtn->setText(QCoreApplication::translate("MainWindow", "Results", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
