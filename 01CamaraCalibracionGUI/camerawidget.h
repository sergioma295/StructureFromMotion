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
#include <QProgressDialog>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QFutureWatcher>
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

 private slots:
    void actualizarVentana();
    void on_pb_Capturar_clicked();
    void apagarCamara();
    void encenderCamara();

private:
    Ui::CameraWidget *ui;
    // Variables de boton opciones.
    QMenu *mOpcionesMenu;
    QAction *mEncenderCamara;
    QAction *mApagarCamara;

    // Variables de calibrador de cámara
    CalibradorCamara *mcalibradorCamara;

    // Variables para visualizar la imagen
    QTimer *mtimer;
    cv::VideoCapture mcamera_capture;
    cv::Mat mframe;
    cv::Mat mframeOriginal;
    QImage mqt_image;

    // Progressbar
    float mProgresoCalibracion;

    // Funciones.
    void actualizarResumen();


};

#endif // CAMERAWIDGET_H
