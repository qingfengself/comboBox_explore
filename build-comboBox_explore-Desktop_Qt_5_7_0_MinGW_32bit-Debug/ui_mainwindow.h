/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *cBBox_1;
    QPushButton *pB_clear;
    QTreeWidget *treeW_CmdList;
    QPushButton *pushBtn_add;
    QPushButton *pushBtn_delete;
    QPushButton *pushBtn_addRoot;
    QPushButton *pushBtn_save;
    QPushButton *pushBtn_load;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(502, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cBBox_1 = new QComboBox(centralWidget);
        cBBox_1->setObjectName(QStringLiteral("cBBox_1"));
        cBBox_1->setGeometry(QRect(8, 10, 71, 22));
        cBBox_1->setContextMenuPolicy(Qt::CustomContextMenu);
        pB_clear = new QPushButton(centralWidget);
        pB_clear->setObjectName(QStringLiteral("pB_clear"));
        pB_clear->setGeometry(QRect(90, 10, 75, 23));
        treeW_CmdList = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeW_CmdList->setHeaderItem(__qtreewidgetitem);
        treeW_CmdList->setObjectName(QStringLiteral("treeW_CmdList"));
        treeW_CmdList->setGeometry(QRect(10, 40, 381, 191));
        pushBtn_add = new QPushButton(centralWidget);
        pushBtn_add->setObjectName(QStringLiteral("pushBtn_add"));
        pushBtn_add->setGeometry(QRect(400, 100, 75, 23));
        pushBtn_delete = new QPushButton(centralWidget);
        pushBtn_delete->setObjectName(QStringLiteral("pushBtn_delete"));
        pushBtn_delete->setGeometry(QRect(400, 130, 75, 23));
        pushBtn_addRoot = new QPushButton(centralWidget);
        pushBtn_addRoot->setObjectName(QStringLiteral("pushBtn_addRoot"));
        pushBtn_addRoot->setGeometry(QRect(400, 70, 75, 23));
        pushBtn_save = new QPushButton(centralWidget);
        pushBtn_save->setObjectName(QStringLiteral("pushBtn_save"));
        pushBtn_save->setGeometry(QRect(400, 180, 75, 23));
        pushBtn_load = new QPushButton(centralWidget);
        pushBtn_load->setObjectName(QStringLiteral("pushBtn_load"));
        pushBtn_load->setGeometry(QRect(400, 210, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 502, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pB_clear->setText(QApplication::translate("MainWindow", "clear", 0));
        pushBtn_add->setText(QApplication::translate("MainWindow", "add node", 0));
        pushBtn_delete->setText(QApplication::translate("MainWindow", "delete", 0));
        pushBtn_addRoot->setText(QApplication::translate("MainWindow", "add root", 0));
        pushBtn_save->setText(QApplication::translate("MainWindow", "save", 0));
        pushBtn_load->setText(QApplication::translate("MainWindow", "load", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
