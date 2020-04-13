/********************************************************************************
** Form generated from reading UI file 'paginaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGINAPRINCIPAL_H
#define UI_PAGINAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaginaPrincipal
{
public:
    QWidget *centralwidget;
    QPushButton *pb_Run;
    QLabel *lb_Titulo;
    QFrame *F1_Usuario;
    QLabel *lb_UsuarioId;
    QLineEdit *value_le_UsuarioId;
    QLineEdit *value_le_CalibracionId;
    QLabel *lb_CalibracionId;
    QLabel *lb_UsuarioIcon;
    QFrame *F2_Camara;
    QLabel *lb_CamaraIcon;
    QLabel *lb_CamaraId;
    QComboBox *value_cb_CamaraId;
    QFrame *F4_Comentarios;
    QLabel *lb_Comentarios;
    QTextEdit *value_lb_Comentarios;
    QFrame *F3_Chessboard;
    QLabel *lb_NumeroCuadros;
    QSpinBox *value_sb_NumeroCuadrosHorizontales;
    QLabel *lb_NumeroCuadrosHorizontales;
    QSpinBox *value_sb_NumeroCuadrosVerticales;
    QLabel *lb_NumeroCuadrosVerticales;
    QLabel *lb_SizeCuadros;
    QSpinBox *value_sb_SizeAltoCuadros;
    QLabel *lb_SizeAltoCuadros;
    QSpinBox *value_sb_SizeAnchoCuadros;
    QLabel *lb_SizeAnchoCuadros;
    QLabel *lb_NumeroImagenes;
    QSpinBox *value_sb_NumeroImagenes;
    QLabel *lb_ChessboardPatternIcon;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PaginaPrincipal)
    {
        if (PaginaPrincipal->objectName().isEmpty())
            PaginaPrincipal->setObjectName(QString::fromUtf8("PaginaPrincipal"));
        PaginaPrincipal->resize(588, 660);
        PaginaPrincipal->setWindowOpacity(1.000000000000000);
        PaginaPrincipal->setAutoFillBackground(false);
        PaginaPrincipal->setStyleSheet(QString::fromUtf8(""));
        PaginaPrincipal->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(PaginaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pb_Run = new QPushButton(centralwidget);
        pb_Run->setObjectName(QString::fromUtf8("pb_Run"));
        pb_Run->setGeometry(QRect(490, 590, 89, 25));
        lb_Titulo = new QLabel(centralwidget);
        lb_Titulo->setObjectName(QString::fromUtf8("lb_Titulo"));
        lb_Titulo->setGeometry(QRect(150, 10, 341, 26));
        QFont font;
        font.setFamily(QString::fromUtf8("Bitstream Charter"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lb_Titulo->setFont(font);
        lb_Titulo->setStyleSheet(QString::fromUtf8("color: rgb(52, 38, 38)\n"
""));
        F1_Usuario = new QFrame(centralwidget);
        F1_Usuario->setObjectName(QString::fromUtf8("F1_Usuario"));
        F1_Usuario->setGeometry(QRect(10, 50, 571, 71));
        F1_Usuario->setLayoutDirection(Qt::LeftToRight);
        F1_Usuario->setAutoFillBackground(false);
        F1_Usuario->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236)"));
        F1_Usuario->setFrameShape(QFrame::WinPanel);
        F1_Usuario->setFrameShadow(QFrame::Raised);
        lb_UsuarioId = new QLabel(F1_Usuario);
        lb_UsuarioId->setObjectName(QString::fromUtf8("lb_UsuarioId"));
        lb_UsuarioId->setGeometry(QRect(20, 10, 72, 21));
        value_le_UsuarioId = new QLineEdit(F1_Usuario);
        value_le_UsuarioId->setObjectName(QString::fromUtf8("value_le_UsuarioId"));
        value_le_UsuarioId->setGeometry(QRect(110, 10, 142, 21));
        value_le_UsuarioId->setAutoFillBackground(false);
        value_le_UsuarioId->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        value_le_CalibracionId = new QLineEdit(F1_Usuario);
        value_le_CalibracionId->setObjectName(QString::fromUtf8("value_le_CalibracionId"));
        value_le_CalibracionId->setGeometry(QRect(110, 40, 142, 21));
        value_le_CalibracionId->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        lb_CalibracionId = new QLabel(F1_Usuario);
        lb_CalibracionId->setObjectName(QString::fromUtf8("lb_CalibracionId"));
        lb_CalibracionId->setGeometry(QRect(10, 40, 96, 17));
        lb_UsuarioIcon = new QLabel(F1_Usuario);
        lb_UsuarioIcon->setObjectName(QString::fromUtf8("lb_UsuarioIcon"));
        lb_UsuarioIcon->setGeometry(QRect(510, 10, 51, 51));
        lb_UsuarioIcon->setPixmap(QPixmap(QString::fromUtf8("Media/user-icon2p.png")));
        F2_Camara = new QFrame(centralwidget);
        F2_Camara->setObjectName(QString::fromUtf8("F2_Camara"));
        F2_Camara->setGeometry(QRect(10, 130, 571, 71));
        F2_Camara->setLayoutDirection(Qt::LeftToRight);
        F2_Camara->setAutoFillBackground(false);
        F2_Camara->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236)"));
        F2_Camara->setFrameShape(QFrame::WinPanel);
        F2_Camara->setFrameShadow(QFrame::Raised);
        lb_CamaraIcon = new QLabel(F2_Camara);
        lb_CamaraIcon->setObjectName(QString::fromUtf8("lb_CamaraIcon"));
        lb_CamaraIcon->setGeometry(QRect(510, 10, 51, 51));
        lb_CamaraIcon->setPixmap(QPixmap(QString::fromUtf8("Media/camera-icon2p.jpeg")));
        lb_CamaraId = new QLabel(F2_Camara);
        lb_CamaraId->setObjectName(QString::fromUtf8("lb_CamaraId"));
        lb_CamaraId->setGeometry(QRect(30, 10, 71, 25));
        value_cb_CamaraId = new QComboBox(F2_Camara);
        value_cb_CamaraId->setObjectName(QString::fromUtf8("value_cb_CamaraId"));
        value_cb_CamaraId->setGeometry(QRect(110, 10, 141, 25));
        value_cb_CamaraId->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)\n"
""));
        F4_Comentarios = new QFrame(centralwidget);
        F4_Comentarios->setObjectName(QString::fromUtf8("F4_Comentarios"));
        F4_Comentarios->setGeometry(QRect(10, 350, 571, 221));
        F4_Comentarios->setLayoutDirection(Qt::LeftToRight);
        F4_Comentarios->setAutoFillBackground(false);
        F4_Comentarios->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236)"));
        F4_Comentarios->setFrameShape(QFrame::WinPanel);
        F4_Comentarios->setFrameShadow(QFrame::Raised);
        lb_Comentarios = new QLabel(F4_Comentarios);
        lb_Comentarios->setObjectName(QString::fromUtf8("lb_Comentarios"));
        lb_Comentarios->setGeometry(QRect(10, 10, 91, 20));
        value_lb_Comentarios = new QTextEdit(F4_Comentarios);
        value_lb_Comentarios->setObjectName(QString::fromUtf8("value_lb_Comentarios"));
        value_lb_Comentarios->setGeometry(QRect(110, 10, 451, 191));
        value_lb_Comentarios->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        F3_Chessboard = new QFrame(centralwidget);
        F3_Chessboard->setObjectName(QString::fromUtf8("F3_Chessboard"));
        F3_Chessboard->setGeometry(QRect(10, 210, 571, 131));
        F3_Chessboard->setLayoutDirection(Qt::LeftToRight);
        F3_Chessboard->setAutoFillBackground(false);
        F3_Chessboard->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236)"));
        F3_Chessboard->setFrameShape(QFrame::WinPanel);
        F3_Chessboard->setFrameShadow(QFrame::Raised);
        lb_NumeroCuadros = new QLabel(F3_Chessboard);
        lb_NumeroCuadros->setObjectName(QString::fromUtf8("lb_NumeroCuadros"));
        lb_NumeroCuadros->setGeometry(QRect(20, 60, 81, 26));
        value_sb_NumeroCuadrosHorizontales = new QSpinBox(F3_Chessboard);
        value_sb_NumeroCuadrosHorizontales->setObjectName(QString::fromUtf8("value_sb_NumeroCuadrosHorizontales"));
        value_sb_NumeroCuadrosHorizontales->setGeometry(QRect(110, 60, 141, 26));
        value_sb_NumeroCuadrosHorizontales->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lb_NumeroCuadrosHorizontales = new QLabel(F3_Chessboard);
        lb_NumeroCuadrosHorizontales->setObjectName(QString::fromUtf8("lb_NumeroCuadrosHorizontales"));
        lb_NumeroCuadrosHorizontales->setGeometry(QRect(250, 60, 82, 26));
        QFont font1;
        font1.setPointSize(10);
        font1.setItalic(true);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        lb_NumeroCuadrosHorizontales->setFont(font1);
        value_sb_NumeroCuadrosVerticales = new QSpinBox(F3_Chessboard);
        value_sb_NumeroCuadrosVerticales->setObjectName(QString::fromUtf8("value_sb_NumeroCuadrosVerticales"));
        value_sb_NumeroCuadrosVerticales->setGeometry(QRect(350, 60, 141, 26));
        value_sb_NumeroCuadrosVerticales->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lb_NumeroCuadrosVerticales = new QLabel(F3_Chessboard);
        lb_NumeroCuadrosVerticales->setObjectName(QString::fromUtf8("lb_NumeroCuadrosVerticales"));
        lb_NumeroCuadrosVerticales->setGeometry(QRect(490, 60, 66, 26));
        lb_NumeroCuadrosVerticales->setFont(font1);
        lb_SizeCuadros = new QLabel(F3_Chessboard);
        lb_SizeCuadros->setObjectName(QString::fromUtf8("lb_SizeCuadros"));
        lb_SizeCuadros->setGeometry(QRect(30, 90, 71, 26));
        value_sb_SizeAltoCuadros = new QSpinBox(F3_Chessboard);
        value_sb_SizeAltoCuadros->setObjectName(QString::fromUtf8("value_sb_SizeAltoCuadros"));
        value_sb_SizeAltoCuadros->setGeometry(QRect(350, 90, 141, 26));
        value_sb_SizeAltoCuadros->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lb_SizeAltoCuadros = new QLabel(F3_Chessboard);
        lb_SizeAltoCuadros->setObjectName(QString::fromUtf8("lb_SizeAltoCuadros"));
        lb_SizeAltoCuadros->setGeometry(QRect(490, 90, 66, 26));
        lb_SizeAltoCuadros->setFont(font1);
        value_sb_SizeAnchoCuadros = new QSpinBox(F3_Chessboard);
        value_sb_SizeAnchoCuadros->setObjectName(QString::fromUtf8("value_sb_SizeAnchoCuadros"));
        value_sb_SizeAnchoCuadros->setGeometry(QRect(110, 90, 141, 26));
        value_sb_SizeAnchoCuadros->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lb_SizeAnchoCuadros = new QLabel(F3_Chessboard);
        lb_SizeAnchoCuadros->setObjectName(QString::fromUtf8("lb_SizeAnchoCuadros"));
        lb_SizeAnchoCuadros->setGeometry(QRect(250, 90, 82, 26));
        lb_SizeAnchoCuadros->setFont(font1);
        lb_NumeroImagenes = new QLabel(F3_Chessboard);
        lb_NumeroImagenes->setObjectName(QString::fromUtf8("lb_NumeroImagenes"));
        lb_NumeroImagenes->setGeometry(QRect(10, 10, 91, 20));
        value_sb_NumeroImagenes = new QSpinBox(F3_Chessboard);
        value_sb_NumeroImagenes->setObjectName(QString::fromUtf8("value_sb_NumeroImagenes"));
        value_sb_NumeroImagenes->setGeometry(QRect(110, 10, 141, 26));
        value_sb_NumeroImagenes->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lb_ChessboardPatternIcon = new QLabel(F3_Chessboard);
        lb_ChessboardPatternIcon->setObjectName(QString::fromUtf8("lb_ChessboardPatternIcon"));
        lb_ChessboardPatternIcon->setGeometry(QRect(510, 10, 51, 41));
        lb_ChessboardPatternIcon->setPixmap(QPixmap(QString::fromUtf8("Media/chessboard-icon2p.jpeg")));
        PaginaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PaginaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 588, 22));
        PaginaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(PaginaPrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PaginaPrincipal->setStatusBar(statusbar);

        retranslateUi(PaginaPrincipal);

        QMetaObject::connectSlotsByName(PaginaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *PaginaPrincipal)
    {
        PaginaPrincipal->setWindowTitle(QCoreApplication::translate("PaginaPrincipal", "Calibracion App", nullptr));
        pb_Run->setText(QCoreApplication::translate("PaginaPrincipal", "Run", nullptr));
        lb_Titulo->setText(QCoreApplication::translate("PaginaPrincipal", "PROGRAMA DE CALIBRACI\303\223N", nullptr));
        lb_UsuarioId->setText(QCoreApplication::translate("PaginaPrincipal", "Usuario Id:", nullptr));
        value_le_UsuarioId->setText(QString());
        lb_CalibracionId->setText(QCoreApplication::translate("PaginaPrincipal", "Calibraci\303\263n Id:", nullptr));
        lb_UsuarioIcon->setText(QString());
        lb_CamaraIcon->setText(QString());
        lb_CamaraId->setText(QCoreApplication::translate("PaginaPrincipal", "C\303\241mara Id:", nullptr));
        lb_Comentarios->setText(QCoreApplication::translate("PaginaPrincipal", "Comentarios: ", nullptr));
        lb_NumeroCuadros->setText(QCoreApplication::translate("PaginaPrincipal", "N\302\272 Cuadros: ", nullptr));
        lb_NumeroCuadrosHorizontales->setText(QCoreApplication::translate("PaginaPrincipal", "(Horizontales)", nullptr));
        lb_NumeroCuadrosVerticales->setText(QCoreApplication::translate("PaginaPrincipal", "(Verticales)", nullptr));
        lb_SizeCuadros->setText(QCoreApplication::translate("PaginaPrincipal", "T Cuadros:", nullptr));
        lb_SizeAltoCuadros->setText(QCoreApplication::translate("PaginaPrincipal", "(Alto, mm)", nullptr));
        lb_SizeAnchoCuadros->setText(QCoreApplication::translate("PaginaPrincipal", "(Ancho, mm)", nullptr));
        lb_NumeroImagenes->setText(QCoreApplication::translate("PaginaPrincipal", "N\302\272 Im\303\241genes: ", nullptr));
        lb_ChessboardPatternIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PaginaPrincipal: public Ui_PaginaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGINAPRINCIPAL_H
