#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QCameraInfo>
#include <calibradorcamara.h>
#include <QTimer>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QMessageBox>
#include <QDialog>
#include <QProgressBar>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QFutureWatcher>
#include <QDebug>

using namespace cv;

namespace Ui {
class CameraWidget;
}

// Declaración de clases
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class CameraWidget : public QWidget
{
    Q_OBJECT

public:

    explicit CameraWidget(CalibradorCamara&, QWidget *parent = nullptr);
    ~CameraWidget();

    void Calibrar();        // Tarea de calibración.

 private slots:
    void actualizarVentana();
    void on_pb_Capturar_clicked();
    void apagarCamara();
    void encenderCamara();
    void performCalibrar();
    void cancelCalibrar();

private:
    Ui::CameraWidget *ui;
    // Variables de boton opciones.
    QMenu *mOpcionesMenu;
    QAction *mEncenderCamara;
    QAction *mApagarCamara;

    // Variables de calibrador de cámara
    CalibradorCamara *mcalibradorCamara;

    // Variables para visualizar la imagen
    QTimer *mtimerActualizarVentana;
    cv::VideoCapture mcamera_capture;
    cv::Mat mframe;
    cv::Mat mframeOriginal;
    QImage mqt_image;

    // ProgressDialog
    float mProgresoCalibracion;

    // Funciones.
    void actualizarResumen();

    // Variables para la tarea de calibración.
    int mstep;
    QProgressDialog *mprogressDialog;
    QTimer *mtimerProgressDialog;


};

#endif // CAMERAWIDGET_H
