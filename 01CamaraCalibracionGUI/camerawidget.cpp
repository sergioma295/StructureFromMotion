#include "camerawidget.h"
#include "ui_camerawidget.h"

CameraWidget::CameraWidget(CalibradorCamara &calibradorCamera, QWidget *parent):QWidget(parent), ui(new Ui::CameraWidget)
{
    /*!
    * \brief Constructor de CamaraWidget. QWidget que permite realizar la calibración y visualizarla.
    */

    cout<<"[INFO] Iniciando Camera Widget"<<endl;
    ui->setupUi(this);
    this->setWindowTitle("GUI Calibracion SMA");

    // Asignación
    mcalibradorCamara = &calibradorCamera;

    // Diseño del botón de opciones.
    mOpcionesMenu = new QMenu("Opciones",this);
    mApagarCamara = new QAction("Apagar",this);
    mEncenderCamara = new QAction("Encender",this);
    mOpcionesMenu->addActions({mEncenderCamara,mApagarCamara});
    ui->pb_Opciones->setMenu(mOpcionesMenu);

    // SLOTS del botón opciones.
    connect(mApagarCamara,SIGNAL(triggered()),this,SLOT(apagarCamara()));
    connect(mEncenderCamara,SIGNAL(triggered()),this,SLOT(encenderCamara()));

    // Definición del timer.
    mtimerActualizarVentana = new QTimer(this);

    // Inicializamos el numero de imagen a 0.
    mcalibradorCamara->setNumeroFrame(0);

    // Mostramos los datos introducidos en el frame de resumen.
    cout<<"[INFO] Actualizar resumen de datos introducidos"<<endl;
    actualizarResumen();

    // Creación de la variable worldPoints (puntos de control).
    cout<<"[INFO] Creando WorldPoints"<<endl;
    mcalibradorCamara->createWorldPoints();

    cout<<"[INFO] Abriendo Cámara"<<endl;
    //Apertura de la cámara.
    int cameraIndex = mcalibradorCamara->getCameraIndex();
    mcamera_capture.open(cameraIndex);
    if(!mcamera_capture.isOpened()){
        this->close();
        QMessageBox::information(this,"Error cámara","No se ha podido abrir la cámara elegida. Se cerrará el programa");
        cout<<"[INFO] La cámara no ha podido abrirse"<<endl;
    }else{
        connect(mtimerActualizarVentana, SIGNAL(timeout()),this, SLOT(actualizarVentana()));
        mtimerActualizarVentana->start(20);
        cout<<"[INFO] Cámara abierta"<<endl;
    }


}

CameraWidget::~CameraWidget()
{
    /*!
     * \brief Destructor del Widget
    */
    delete ui;
    cout<<"[INFO] CamaraWidget ha sido destruido"<<endl;
}

void CameraWidget::actualizarResumen(){
    /*!
     * \brief Actualiza el resumen del widget con la información que ha introducido el usuario en la pestaña principal.
    */

    ui->value_lb_UsuarioId->setText(mcalibradorCamara->getUserId().c_str());
    ui->value_lb_CalibrationId->setText((QString)mcalibradorCamara->getCalibrationId().c_str());
    ui->value_lb_CamaraId->setText(QString::number(mcalibradorCamara->getCameraIndex()));

    std::vector<int> numeroCuadros = mcalibradorCamara->getNumeroCuadros();
    ui->value_lb_NumeroCuadros->setText(QString::number(numeroCuadros[0]) + "x" + QString::number(numeroCuadros[1]));

    std::vector<float> sizeCuadros = mcalibradorCamara->getSizeCuadros();
    ui->value_lb_SizeCuadros->setText(QString::number(sizeCuadros[0]) + "x" + QString::number(sizeCuadros[1]));

    ui->value_lb_NumeroImagenes->setText(QString::number(mcalibradorCamara->getNumeroTotalFrames()));
    ui->value_lb_NumeroVista->setText(QString::number(mcalibradorCamara->getNumberoFrame()));
    cout<<"[INFO] Resumen actualizado"<<endl;


}


void CameraWidget::apagarCamara(){
    /*!
     * \brief SLOT para desconectar cámara cuando se activa la señal triggered de mApagarCamara.
     */
    cout<<"[INFO] Apagando cámara"<<endl;
    disconnect(mtimerActualizarVentana, SIGNAL(timeout()), this, SLOT(actualizarVentana()));
    mcamera_capture.release();
    cv::Mat imageDiscconect = cv::Mat::zeros(mframe.size(), CV_8UC3);
    mqt_image = QImage((const unsigned char*)(imageDiscconect.data),imageDiscconect.cols,imageDiscconect.rows,QImage::Format_RGB888);
    ui->lb_imageCamera->setPixmap(QPixmap::fromImage(mqt_image));
    ui->lb_imageCamera->resize(ui->lb_imageCamera->pixmap()->size());
}

void CameraWidget::encenderCamara(){
    /*!
     * \brief SLOT para conectar la cámara cuando se activa la señal triggered de mEncenderCamara.
     */
    cout<<"[INFO] Encendiendo cámara"<<endl;
    // Conectar de nuevo la cámara.
    int cameraIndex = mcalibradorCamara->getCameraIndex();
    mcamera_capture.open(cameraIndex);
    if(!mcamera_capture.isOpened()){
        QMessageBox::information(this,"Error cámara","No se ha podido abrir la cámara elegida. Se cerrará el programa");
        this->close();
    }else{
        connect(mtimerActualizarVentana, SIGNAL(timeout()),this, SLOT(actualizarVentana()));
        mtimerActualizarVentana->start(20);
        QMessageBox::information(this,"Cámara","Se abrió la cámara de forma existosa.");
    }
}

void CameraWidget::on_pb_Capturar_clicked()
{
    /*!
    * \brief Slot que se activa al clickar el botón capturar. Almacena dicha imagen en la carpeta de salida y la añade a la lista de imagenes que se utilizarán
    * para realizar la calbiración.
    */
    cout<<"[INFO] Capturando imagen"<<endl;
    // Meter la imagen en una lista.
    //mImageList.push_back(mframeOriginal.clone());
    mcalibradorCamara->addImageList(mframeOriginal.clone());
    string relativePath = mcalibradorCamara->getPath() + "img" + std::to_string(mcalibradorCamara->getNumberoFrame()+1)+".jpg";
    cvtColor(mframe,mframe,CV_RGB2BGR);
    cv::imwrite(relativePath,mframe);
    std::vector<cv::Mat> b = mcalibradorCamara->getImageList();
    mcalibradorCamara->incrementarNumeroFrame();
    actualizarResumen();

    // Liberar memoria.
    mframe.release();
    mframeOriginal.release();

}


void CameraWidget::actualizarVentana(){
    /*!
     * \brief Actualización de la ventana para cambiar el frame recogido por la cámara en función del timer definido anteriormente.
    */

    mcamera_capture >> mframeOriginal;
    mframeOriginal.copyTo(mframe);

    // Buscar corners en la imagen.
    if(mcalibradorCamara->getNumberoFrame() < mcalibradorCamara->getNumeroTotalFrames()){
       mframe = mcalibradorCamara->searchImagePoints(mframe);

    }else{
        cout<<"[INFO] Calibrando"<<endl;
        mstep = 0;
        Calibrar();
        // Reinicializamos lista
        mcalibradorCamara->setNumeroFrame(0);
        mcalibradorCamara->initImageList();
        actualizarResumen();

    }

    // Redimensionar el frame para ajustarlo al label de salida.
    cv::resize(mframe,mframe,cv::Size(ui->lb_imageCamera->size().width(),ui->lb_imageCamera->size().height()));
    // Enviar a label la imagen.
    mqt_image = QImage((const unsigned char*)(mframe.data),mframe.cols,mframe.rows,QImage::Format_RGB888);
    ui->lb_imageCamera->setPixmap(QPixmap::fromImage(mqt_image));
    ui->lb_imageCamera->resize(ui->lb_imageCamera->pixmap()->size());

}

void CameraWidget::Calibrar()
{
    /*!
     * Tarea Calibrar. Actualiza el valor del progress bar en función del número de imagen procesada en la calibración.
     */
    cout<<"[INFO] Calibrar cámara."<<endl;
    // Variables para realizar la calibración de la cámara con un progressDialog tipo modeless.
    int numTasks = mcalibradorCamara->getImageList().size() - 1 ;

    // Creando ProgressDialog.
    mprogressDialog = new QProgressDialog("Realizando calibración. Espere...","Cancel",0,numTasks);
    mprogressDialog->show();
    connect(mprogressDialog,SIGNAL(canceled()),this,SLOT(cancelCalibrar()));

    // Timer para realizar la calibración.
    mtimerProgressDialog = new QTimer(this);
    connect(mtimerProgressDialog,SIGNAL(timeout()),this,SLOT(performCalibrar()));
    mtimerProgressDialog->start(0);

}

void CameraWidget::performCalibrar(){
    /*!
     * \brief Slot para llevar a cabo la tarea de calibrar la cámara. Permite mostrar el ProgressDialog sin bloquear
     * el programa.
     */
    cout<<"[INFO] Calibrando. Vista Nº"<<mstep<<endl;

    // Realizando la tarea costosa.
    mcalibradorCamara->calibrar(mstep);

    // Actualizando progressDialog.
    mprogressDialog->setValue(mstep);
    mstep++;

    // Condición de parada.
    if(mstep>mprogressDialog->maximum()){
        mtimerProgressDialog->stop();
    }
}

void CameraWidget::cancelCalibrar(){
    /*!
    * \brief Slot para cancelar la calibración en curso.
    */
    cout<<"[INFO] Cancelando tarea de calibrar"<<endl;
    mtimerProgressDialog->stop();
}
