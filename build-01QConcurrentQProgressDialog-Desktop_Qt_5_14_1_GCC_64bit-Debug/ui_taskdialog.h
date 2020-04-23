/********************************************************************************
** Form generated from reading UI file 'taskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDIALOG_H
#define UI_TASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskDialog
{
public:
    QWidget *centralwidget;
    QLabel *lb_numeroIteraciones;
    QLabel *lb_tiempoConsumido;
    QSpinBox *sb_numeroIteraciones_value;
    QPushButton *pb_doTask;
    QPushButton *pb_cancelar;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TaskDialog)
    {
        if (TaskDialog->objectName().isEmpty())
            TaskDialog->setObjectName(QString::fromUtf8("TaskDialog"));
        TaskDialog->resize(529, 188);
        centralwidget = new QWidget(TaskDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lb_numeroIteraciones = new QLabel(centralwidget);
        lb_numeroIteraciones->setObjectName(QString::fromUtf8("lb_numeroIteraciones"));
        lb_numeroIteraciones->setGeometry(QRect(30, 20, 161, 17));
        lb_tiempoConsumido = new QLabel(centralwidget);
        lb_tiempoConsumido->setObjectName(QString::fromUtf8("lb_tiempoConsumido"));
        lb_tiempoConsumido->setGeometry(QRect(30, 50, 161, 17));
        sb_numeroIteraciones_value = new QSpinBox(centralwidget);
        sb_numeroIteraciones_value->setObjectName(QString::fromUtf8("sb_numeroIteraciones_value"));
        sb_numeroIteraciones_value->setGeometry(QRect(220, 20, 291, 26));
        pb_doTask = new QPushButton(centralwidget);
        pb_doTask->setObjectName(QString::fromUtf8("pb_doTask"));
        pb_doTask->setGeometry(QRect(220, 50, 291, 25));
        pb_cancelar = new QPushButton(centralwidget);
        pb_cancelar->setObjectName(QString::fromUtf8("pb_cancelar"));
        pb_cancelar->setGeometry(QRect(400, 100, 111, 25));
        TaskDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TaskDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 529, 22));
        TaskDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(TaskDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TaskDialog->setStatusBar(statusbar);
        toolBar = new QToolBar(TaskDialog);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        TaskDialog->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(TaskDialog);

        QMetaObject::connectSlotsByName(TaskDialog);
    } // setupUi

    void retranslateUi(QMainWindow *TaskDialog)
    {
        TaskDialog->setWindowTitle(QCoreApplication::translate("TaskDialog", "TaskDialog", nullptr));
        lb_numeroIteraciones->setText(QCoreApplication::translate("TaskDialog", "Numero de Iteraciones", nullptr));
        lb_tiempoConsumido->setText(QCoreApplication::translate("TaskDialog", "Tiempo Consumido ", nullptr));
        pb_doTask->setText(QCoreApplication::translate("TaskDialog", "Do Task", nullptr));
        pb_cancelar->setText(QCoreApplication::translate("TaskDialog", "Cancel", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("TaskDialog", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDialog: public Ui_TaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDIALOG_H
