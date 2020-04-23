#ifndef PAGINAPRINCIPAL_H
#define PAGINAPRINCIPAL_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMessageBox>
#include "camerawidget.h"
#include <QCameraInfo>
#include <calibradorcamara.h>

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
    CameraWidget *mcameraWidget;
    CalibradorCamara *calibrador;

};
#endif // PAGINAPRINCIPAL_H
