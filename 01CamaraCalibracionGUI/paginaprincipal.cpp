#include "paginaprincipal.h"
#include "ui_paginaprincipal.h"

// Prototipos de función.
QStringList ListarCamaras();


PaginaPrincipal::PaginaPrincipal(QWidget *parent):QMainWindow(parent), ui(new Ui::PaginaPrincipal)
{

    ui->setupUi(this);
    this->setWindowTitle("GUI Calibracion SMA");

    // Establecer logos de la interfaz.
    QPixmap pixUserIcon("/home/sergio/QtCreator/QtProjects/StructureFromMotion/01CamaraCalibracionGUI/Media/user-icon2p.png");
    QPixmap pixCamaraIcon("/home/sergio/QtCreator/QtProjects/StructureFromMotion/01CamaraCalibracionGUI/Media/camera-icon2p.jpeg");
    QPixmap pixChessboardPatternIcon("/home/sergio/QtCreator/QtProjects/StructureFromMotion/01CamaraCalibracionGUI/Media/chessboard-icon2p.jpeg");
    ui->lb_UsuarioIcon->setPixmap(pixUserIcon);
    ui->lb_CamaraIcon->setPixmap(pixCamaraIcon);
    ui->lb_ChessboardPatternIcon->setPixmap(pixChessboardPatternIcon);
    // Establecer valor por defecto de los values.
    ui->value_le_UsuarioId->setText("Sergio");
    ui->value_le_CalibracionId->setText("Cam");
    ui->value_sb_NumeroImagenes->setValue(5);
    ui->value_sb_NumeroCuadrosHorizontales->setValue(9);
    ui->value_sb_NumeroCuadrosVerticales->setValue(7);
    ui->value_sb_SizeAnchoCuadros->setValue(20);
    ui->value_sb_SizeAltoCuadros->setValue(20);
    ui->value_lb_Comentarios->setText("Test I");

    // Listar camaras conectadas.
    QStringList listCameras = ListarCamaras();
    ui->value_cb_CamaraId->addItems(listCameras);
}

PaginaPrincipal::~PaginaPrincipal()
{
    delete ui;
}


QStringList ListarCamaras(){
    /*
     *
     * Listar cámaras conectadas.
     *
     * @return: QStringList listCameras.
    */

    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    QStringList listCameras;
    for (const QCameraInfo &cameraInfo : cameras) {
        QString cameraName = cameraInfo.deviceName();
        listCameras.append(cameraInfo.deviceName());
        //listCameras.insert(cameraInfo.position(),cameraInfo.deviceName());
    }
    return listCameras;
}

void PaginaPrincipal::on_pb_Run_clicked()
{
    /*
     *
     * SLOT botón Run clicked.
     *
     * Al pulsar el botón RUN el programa recoge la información introducida por el usuario, comprueba que ha introducido todo lo necesario,
     * crea un objeto del tipo CalibradorCamara, destruye la PaginaPrincipal y abre un nuevo Widget ("CamaraWidget") en el cuál se
     * realizará la calibración.
    */

    // Obtenemos el valor que el usuario ha introducido en la interfaz.
    QString userId = ui->value_le_UsuarioId->text();    // Nombre del usuario.
    QString calibrationId = ui->value_le_CalibracionId->text(); // Nombre del archivo de calibración.
    int cameraIndex = ui->value_cb_CamaraId->currentIndex();    // Índice de la cámara conectada.
    int numeroImagenes =ui->value_sb_NumeroImagenes->value();   // Número total de imágenes que se realizarán en la calibración.
    int numeroCuadrosHorizontales =ui->value_sb_NumeroCuadrosHorizontales->value(); // Número total de cuadros horizontales del chessboard.
    int numeroCuadrosVerticales =ui->value_sb_NumeroCuadrosVerticales->value(); // Número total de cuadros verticales del chessboard.
    float widthCuadros = ui->value_sb_SizeAnchoCuadros->value();  // Ancho de los cuadros del chessboard.
    float heightCuadros =ui->value_sb_SizeAltoCuadros->value();   // Alto de los cuadros del chessboard.
    QString comentarios =ui->value_lb_Comentarios->toPlainText();   // Comentarios en la calibración.

    // Comprobación que se han insertado todos los elementos.
    if(userId.isEmpty() or calibrationId.isEmpty() or numeroImagenes == 0 or numeroCuadrosHorizontales == 0 or numeroCuadrosVerticales ==0 or widthCuadros== 0 or heightCuadros == 0 or comentarios.isEmpty())
    {
        QMessageBox::information(this,"Información no completada","Existen campos que aún no ha rellenado. Por favor, complete la información que se le está pidiendo");
    }else{

        QMessageBox::information(this,"Información completada","Preparado para abrir cámara.");
        // Abrimos la nueva ventana donde aparecen los frames que capta la cámara.
        this->close();

        // Almacenamos la información recogida en variables para incializar un objeto CalibradorCamara.
        int nSquares[2]={numeroCuadrosHorizontales,numeroCuadrosVerticales}; // Numero de cuadrados del CHESSBOARD. [numero_cuadrados_horizontales, numero_cuadrados_verticales].
        float sizeSquares[2]={widthCuadros,heightCuadros};    // Tamaño de cuadrados del CHESSBOARD. [ancho, alto].

        // const string&,const string&,int, int, unsigned int[2], float[2], const string&
        CalibradorCamara* ptr_calibradorCamara = new CalibradorCamara(userId.toStdString(),calibrationId.toStdString(),cameraIndex,numeroImagenes,nSquares,sizeSquares,comentarios.toStdString());

        // Inicialización de la nueva ventana, cerrar la actual y mostrar la nueva.
        this->close();
        mcameraWidget = new CameraWidget(*ptr_calibradorCamara);
        mcameraWidget->show();
    }



}

