#ifndef PAGINAPRINCIPAL_H
#define PAGINAPRINCIPAL_H

#include <QMainWindow>
#include <QDesktopWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PaginaPrincipal; }
QT_END_NAMESPACE

class PaginaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    PaginaPrincipal(QWidget *parent = nullptr);
    ~PaginaPrincipal();

private slots:
    void on_pb_Run_clicked();

private:
    Ui::PaginaPrincipal *ui;
};
#endif // PAGINAPRINCIPAL_H
