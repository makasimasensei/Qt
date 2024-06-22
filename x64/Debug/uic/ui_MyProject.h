/********************************************************************************
** Form generated from reading UI file 'MyProject.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPROJECT_H
#define UI_MYPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyProjectClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyProjectClass)
    {
        if (MyProjectClass->objectName().isEmpty())
            MyProjectClass->setObjectName(QString::fromUtf8("MyProjectClass"));
        MyProjectClass->resize(600, 400);
        menuBar = new QMenuBar(MyProjectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MyProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyProjectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyProjectClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyProjectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MyProjectClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyProjectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyProjectClass->setStatusBar(statusBar);

        retranslateUi(MyProjectClass);

        QMetaObject::connectSlotsByName(MyProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyProjectClass)
    {
        MyProjectClass->setWindowTitle(QApplication::translate("MyProjectClass", "MyProject", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyProjectClass: public Ui_MyProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPROJECT_H
