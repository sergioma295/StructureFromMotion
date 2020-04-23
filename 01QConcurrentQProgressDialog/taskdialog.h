#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/qtconcurrentmap.h>
#include <QProgressDialog>

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = 0);
    ~TaskDialog();

private slots:
    void on_pb_doTask_clicked();

private:
    Ui::TaskDialog *ui;
};

#endif // TASKDIALOG_H
