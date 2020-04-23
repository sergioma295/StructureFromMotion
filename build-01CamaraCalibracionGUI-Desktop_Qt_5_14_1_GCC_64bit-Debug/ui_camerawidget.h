/********************************************************************************
** Form generated from reading UI file 'camerawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWIDGET_H
#define UI_CAMERAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraWidget
{
public:
    QPushButton *pb_Opciones;
    QFrame *frame;
    QLabel *label;
    QLabel *lb_NumeroCuadros;
    QLabel *lb_UsuarioId;
    QLabel *lb_NumeroImagenes;
    QLabel *lb_CamaraId;
    QLabel *lb_CalibracionId;
    QLabel *lb_SizeCuadros;
    QLabel *value_lb_UsuarioId;
    QLabel *value_lb_CalibrationId;
    QLabel *value_lb_CamaraId;
    QLabel *value_lb_NumeroCuadros;
    QLabel *value_lb_SizeCuadros;
    QLabel *value_lb_NumeroImagenes;
    QLabel *value_lb_NumeroVista;
    QLabel *lb_NumeroVista;
    QLabel *lb_Titulo;
    QPushButton *pb_Capturar;
    QLabel *lb_imageCamera;

    void setupUi(QWidget *CameraWidget)
    {
        if (CameraWidget->objectName().isEmpty())
            CameraWidget->setObjectName(QString::fromUtf8("CameraWidget"));
        CameraWidget->resize(920, 580);
        CameraWidget->setMinimumSize(QSize(920, 580));
        CameraWidget->setMaximumSize(QSize(920, 580));
        pb_Opciones = new QPushButton(CameraWidget);
        pb_Opciones->setObjectName(QString::fromUtf8("pb_Opciones"));
        pb_Opciones->setGeometry(QRect(670, 50, 241, 25));
        frame = new QFrame(CameraWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(670, 80, 241, 451));
        frame->setMinimumSize(QSize(241, 451));
        frame->setMaximumSize(QSize(241, 451));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 67, 17));
        lb_NumeroCuadros = new QLabel(frame);
        lb_NumeroCuadros->setObjectName(QString::fromUtf8("lb_NumeroCuadros"));
        lb_NumeroCuadros->setGeometry(QRect(10, 130, 101, 26));
        lb_UsuarioId = new QLabel(frame);
        lb_UsuarioId->setObjectName(QString::fromUtf8("lb_UsuarioId"));
        lb_UsuarioId->setGeometry(QRect(10, 40, 101, 21));
        lb_NumeroImagenes = new QLabel(frame);
        lb_NumeroImagenes->setObjectName(QString::fromUtf8("lb_NumeroImagenes"));
        lb_NumeroImagenes->setGeometry(QRect(10, 220, 101, 20));
        lb_CamaraId = new QLabel(frame);
        lb_CamaraId->setObjectName(QString::fromUtf8("lb_CamaraId"));
        lb_CamaraId->setGeometry(QRect(10, 100, 101, 25));
        lb_CalibracionId = new QLabel(frame);
        lb_CalibracionId->setObjectName(QString::fromUtf8("lb_CalibracionId"));
        lb_CalibracionId->setGeometry(QRect(10, 70, 101, 17));
        lb_SizeCuadros = new QLabel(frame);
        lb_SizeCuadros->setObjectName(QString::fromUtf8("lb_SizeCuadros"));
        lb_SizeCuadros->setGeometry(QRect(10, 160, 101, 26));
        value_lb_UsuarioId = new QLabel(frame);
        value_lb_UsuarioId->setObjectName(QString::fromUtf8("value_lb_UsuarioId"));
        value_lb_UsuarioId->setGeometry(QRect(130, 40, 101, 21));
        value_lb_CalibrationId = new QLabel(frame);
        value_lb_CalibrationId->setObjectName(QString::fromUtf8("value_lb_CalibrationId"));
        value_lb_CalibrationId->setGeometry(QRect(130, 70, 101, 21));
        value_lb_CamaraId = new QLabel(frame);
        value_lb_CamaraId->setObjectName(QString::fromUtf8("value_lb_CamaraId"));
        value_lb_CamaraId->setGeometry(QRect(130, 100, 101, 21));
        value_lb_NumeroCuadros = new QLabel(frame);
        value_lb_NumeroCuadros->setObjectName(QString::fromUtf8("value_lb_NumeroCuadros"));
        value_lb_NumeroCuadros->setGeometry(QRect(130, 130, 101, 21));
        value_lb_SizeCuadros = new QLabel(frame);
        value_lb_SizeCuadros->setObjectName(QString::fromUtf8("value_lb_SizeCuadros"));
        value_lb_SizeCuadros->setGeometry(QRect(130, 160, 101, 21));
        value_lb_NumeroImagenes = new QLabel(frame);
        value_lb_NumeroImagenes->setObjectName(QString::fromUtf8("value_lb_NumeroImagenes"));
        value_lb_NumeroImagenes->setGeometry(QRect(130, 220, 101, 21));
        value_lb_NumeroVista = new QLabel(frame);
        value_lb_NumeroVista->setObjectName(QString::fromUtf8("value_lb_NumeroVista"));
        value_lb_NumeroVista->setGeometry(QRect(130, 190, 101, 21));
        lb_NumeroVista = new QLabel(frame);
        lb_NumeroVista->setObjectName(QString::fromUtf8("lb_NumeroVista"));
        lb_NumeroVista->setGeometry(QRect(10, 190, 101, 20));
        lb_Titulo = new QLabel(CameraWidget);
        lb_Titulo->setObjectName(QString::fromUtf8("lb_Titulo"));
        lb_Titulo->setGeometry(QRect(390, 10, 331, 26));
        QFont font;
        font.setFamily(QString::fromUtf8("Bitstream Charter"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lb_Titulo->setFont(font);
        lb_Titulo->setStyleSheet(QString::fromUtf8("color: rgb(52, 38, 38)\n"
""));
        pb_Capturar = new QPushButton(CameraWidget);
        pb_Capturar->setObjectName(QString::fromUtf8("pb_Capturar"));
        pb_Capturar->setGeometry(QRect(820, 540, 89, 25));
        lb_imageCamera = new QLabel(CameraWidget);
        lb_imageCamera->setObjectName(QString::fromUtf8("lb_imageCamera"));
        lb_imageCamera->setGeometry(QRect(20, 50, 640, 480));
        lb_imageCamera->setMinimumSize(QSize(640, 480));
        lb_imageCamera->setMaximumSize(QSize(640, 480));
        lb_imageCamera->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1.2px;\n"
"border-style:inset;"));

        retranslateUi(CameraWidget);

        QMetaObject::connectSlotsByName(CameraWidget);
    } // setupUi

    void retranslateUi(QWidget *CameraWidget)
    {
        CameraWidget->setWindowTitle(QCoreApplication::translate("CameraWidget", "Form", nullptr));
        pb_Opciones->setText(QCoreApplication::translate("CameraWidget", "Opciones", nullptr));
        label->setText(QCoreApplication::translate("CameraWidget", "Resumen", nullptr));
        lb_NumeroCuadros->setText(QCoreApplication::translate("CameraWidget", "N\302\272 Cuadros: ", nullptr));
        lb_UsuarioId->setText(QCoreApplication::translate("CameraWidget", "Usuario Id:", nullptr));
        lb_NumeroImagenes->setText(QCoreApplication::translate("CameraWidget", "N\302\272 Im\303\241genes: ", nullptr));
        lb_CamaraId->setText(QCoreApplication::translate("CameraWidget", "C\303\241mara Id:", nullptr));
        lb_CalibracionId->setText(QCoreApplication::translate("CameraWidget", "Calibraci\303\263n Id:", nullptr));
        lb_SizeCuadros->setText(QCoreApplication::translate("CameraWidget", "T Cuadros:", nullptr));
        value_lb_UsuarioId->setText(QCoreApplication::translate("CameraWidget", "VALUE", nullptr));
        value_lb_CalibrationId->setText(QCoreApplication::translate("CameraWidget", "VALUE", nullptr));
        value_lb_CamaraId->setText(QCoreApplication::translate("CameraWidget", "VALUE", nullptr));
        value_lb_NumeroCuadros->setText(QCoreApplication::translate("CameraWidget", "VALUE", nullptr));
        value_lb_SizeCuadros->setText(QCoreApplication::translate("CameraWidget", "VALUE", nullptr));
        value_lb_NumeroImagenes->setText(QCoreApplication::translate("CameraWidget", "VALUE", nullptr));
        value_lb_NumeroVista->setText(QCoreApplication::translate("CameraWidget", "VALUE", nullptr));
        lb_NumeroVista->setText(QCoreApplication::translate("CameraWidget", "Vista N\302\272: ", nullptr));
        lb_Titulo->setText(QCoreApplication::translate("CameraWidget", "C\303\201MARA - Obtenci\303\263n de vistas", nullptr));
        pb_Capturar->setText(QCoreApplication::translate("CameraWidget", "Capturar", nullptr));
        lb_imageCamera->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CameraWidget: public Ui_CameraWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWIDGET_H
