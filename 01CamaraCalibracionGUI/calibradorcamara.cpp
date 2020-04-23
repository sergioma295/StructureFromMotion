#include "calibradorcamara.h"

// Constructor extendido.
CalibradorCamara::CalibradorCamara(const string& userId, const string& calibrationId, int cameraIndex, int numImagenes, int nSquares[2], float sizeSquares[2], const string& comentarios)
{
    /*!
     * Constructor del objeto.
    */
    cout<<"[INFO] Construyendo el objeto CalibradorCamara."<<endl;
    // Asignación de variables de ENTRADA.
    c_userId = userId;                      // Identificador de usuario
    c_calibrationId = calibrationId;        // Identificador de calibración. Nombre de la calibración
    c_cameraIndex = cameraIndex;            // Índice de la cámara que se abrirá.
    c_imgsTotales = numImagenes;            // Número de imágenes totales de la cámara.
    c_nHorizontalSquares = nSquares[0];     // Número de Cuadros horizontales del chessboard
    c_nVerticalSquares   = nSquares[1];     // Número de Cuadros verticales del chessboard
    c_wSquares = sizeSquares[0];            // Tamaño (ancho) de los cuadros.
    c_hSquares = sizeSquares[1];            // Tamaño (alto) de los cuadros.
    c_boardSize = cv::Size(c_nHorizontalSquares, c_nVerticalSquares);   // Asignación al objeto cv::Size del tamaño del chessboard (numero de cuadros horizontales, numero de cuadros verticales).
    c_comentarios = comentarios;            // Comentarios que se introduzcan en la GUI acerca de la calibración

    // Inicialización variables SALIDA.
    std::vector<std::vector<cv::Point3f>> worldPoints;      // Vector de vectores de los puntos de control tridimensionales
    std::vector<std::vector<cv::Point2f>>imgPoints;         // Vector de vectores de ,los puntos de control en el plano de la imagen.
    // Asignación Variables salida.
    c_worldPoints = worldPoints;                            // Punto de control tridimensionales
    c_imagePoints = imgPoints;                              // Puntos de control en el plano de la imagen.

    // Inicialización y creación de la carpeta donde se almacenan los archivos de salida.
    c_saveImagePath = fs::current_path() + "/Output/ImagePoints/";
    if(!fs::exists(c_saveImagePath)){
        cout<<"[INFO] El directorio "<<c_saveImagePath<<" donde se guardan las imagenes de salida no existe y se creará."<<endl;
        fs::create_directories(c_saveImagePath);
    }else{
        cout<<"[INFO] El directorio "<<c_saveImagePath<<" existe. Compruebe su contenido cuando termine el proceso."<<endl;
    }
}

// Destructor.
CalibradorCamara::~CalibradorCamara()
{
    /*!
    Destructor de la clase CalibradorCamara.
    */
    cout<<"[INFO] Objeto Destruido"<<endl;
}


// Métodos para obtener el valor de los miembros privados de la clase.
string CalibradorCamara::getUserId(){
    /*! Obtener el ID del utilizado.*/
    cout<<"[INFO] Obtener UserId"<<endl;
    return c_userId;
}

string CalibradorCamara::getCalibrationId(){
    /*! Obtener el ID de la calibración. */
    cout<<"[INFO] Obtener CalibrationId"<<endl;
    return c_calibrationId;
}

int CalibradorCamara::getCameraIndex(){
    /*! Obtener el índice de la cámara utilizado. */
    cout<<"[INFO] Obtener CameraIndex"<<endl;
    return c_cameraIndex;
}

std::vector<int> CalibradorCamara::getNumeroCuadros(){
    /*! Obtener el número de cuadros (horizontales y verticales) del chessboard.*/
    cout<<"[INFO] Obtener Numero de Cuadros (horizontal,vertical)."<<endl;
    return {c_nHorizontalSquares, c_nVerticalSquares};
}

std::vector<float> CalibradorCamara::getSizeCuadros(){
    /*! Obtener el tamaño de los cuadros del chessboard (ancho,alto). */
    cout<<"[INFO] Obtener tamaño de cuadros (ancho,alto)."<<endl;
    return {c_wSquares, c_hSquares};
}

int CalibradorCamara::getNumberoFrame(){
    /*! Obtener el número del frame actual.*/
    cout<<"[INFO] Obtener número de frame"<<endl;
    return c_imgNum;
}

int CalibradorCamara::getNumeroTotalFrames(){
    /*! Obtener el número de frames totales utilizado.*/
    cout<<"[INFO] Obtener número total de frames para la calibración."<<endl;
    return c_imgsTotales;
}

string CalibradorCamara::getComentarios(){
    /*!  Obtener los comentarios utilizados.*/
    cout<<"[INFO] Obtener comentarios"<<endl;
    return c_comentarios;
}

string CalibradorCamara::getPath(){
    /*! Obtener el directorio de salida.*/
    cout<<"[INFO] Obtener directorio de salida"<<endl;
    return c_saveImagePath;
}

std::vector<cv::Mat> CalibradorCamara::getImageList(){
    /*! Obtener la lista de imagenes almacenadas para la calibración.*/
    cout<<"[INFO] Obtener lista de imagenes"<<endl;
    return c_imageCalibrationList;
}

std::vector<std::vector<cv::Point3f>> CalibradorCamara::getWorldPoints(){
     /*! Obtener lista de puntos de control de las vistas tomadas.*/
    cout<<"[INFO] Obtener worldPoints"<<endl;
    return c_worldPoints;
}


// Métodos para modificar las variables privadas de la clase.
void CalibradorCamara::incrementarNumeroFrame(){
    /*! Incrementar el número de Frame actaul..*/
    cout<<"[INFO] Incrementar numero de frame"<<endl;
    c_imgNum++;
}

void CalibradorCamara::setNumeroFrame(int value){
    /*! Escribir el número de frame actuals*/
    cout<<"[INFO] Set numero de frame"<<endl;
    c_imgNum = value;
}

void CalibradorCamara::addImageList(Mat view){
    /*! Añadir una imagen a la lista de imagenes utilizadas en la calibración*/
    cout<<"[INFO] Añadir vista a lista de frames."<<endl;
    c_imageCalibrationList.push_back(view);
}

void CalibradorCamara::initImageList(){
     /*! Inicializar la lista de imágenes almacenadas para la calibración.*/
    cout<<"[INFO] Inicializar la lista de imágenes almacenadas para la calibración."<<endl;
    c_imageCalibrationList.clear();
}

int CalibradorCamara::createWorldPoints()
{
    /*! Crea un vector de vectores con los puntos de control de cada frame (elementos de la lista) que se utilizarán en la calibración.
     * Contiene tantos elementos como número de imágenes indique el usuario.*/
    cout<<"[INFO] Crear vector worldpoints"<<endl;

    // Comprobamos que está vacío. Si no lo está, devuelve error.
    if(!c_worldPoints.size()==0)
        return -1;

    // 1) Creamos un vector de vectores con el valor de las coordenadas de los puntos de control y un numero total igual al numero de vistas.
    for(int nf = 0; nf<=c_imgsTotales;nf++)
    {
        // Definición de un vector de puntos tanto para SoC_W
        vector<cv::Point3f> pts_socW;          // Punto tridimensional (Xw, Yw, Zw).
        for(int i = 0;  i<c_nVerticalSquares;i++)
        {
            for(int j = 0; j<c_nHorizontalSquares;j++)
            {
                // Obtenemos el valor del punto y se lo añadimos como elemento del vector.
                int x_w = j * c_hSquares;
                int y_w = i * c_wSquares;
                int z_w = 0.0f;
                cv::Point3f pt = cv::Point3f(x_w, y_w, z_w);   // En mm  --> i/nSquaresH: Apunta a las x, i%nSquaresH. Apunta a las y. Primero recorre todas las x con y distintas y luego cambia el valor de x y hace lo mismo. Multipilicamos por ancho de cuadrado.
                pts_socW.push_back(pt);
            }
        }
        c_worldPoints.push_back(pts_socW);
    }

/*
    // 2) Creamos un vector de vectores con el valor de las coordenadas de los puntos de control en el plano de la imagen y un numero total igual al número de vistas.
    for(int nf=0; nf<=c_imgsTotales;nf++)
    {
        cv::Mat imgView, imgView_GRAY;                         // Imagen donde se buscarán los puntos de control bidimensionales

        // Definición de un vector de puntos tanto para SoC_C
        vector<cv::Point2f> pts_socC;        // Puntos en el sistema de coordenada de la camara (Xc, Yc, Zc). (Vector de puntos porque son varios).

        // 2.1) Calculamos las coordenadas de forma aproximada (si existen). Si existen se calculan de forma más exacta utilizando después cornerSubPix.
        bool foundFlag = cv::findChessboardCorners(imgView,c_boardSize,pts_socC,CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE | CALIB_CB_FILTER_QUADS);

        // 2.2) Si se han encontrado puntos aproximados, entonces calculamos los puntos exactos.
        if(foundFlag)
        {
            // 2.2.1) Convertimos la imagen de color a escala de grises
            cv::cvtColor(imgView,imgView_GRAY,CV_BGR2GRAY);

            cv::Size sizeVentanaBusqueda = cv::Size(11,11); // Definición del tamaño de la ventana de búsqueda.
            int maxCount = 50;
            double accuray = 0.1;
            cv::cornerSubPix(imgView_GRAY,
                             pts_socC,
                             sizeVentanaBusqueda,
                             cv::Size(-1,-1),
                             cv::TermCriteria(cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS, maxCount, accuray));

            // 2.2.2) Pintamos los píxeles en la imagen.
            cv::drawChessboardCorners(imgView,
                                      c_boardSize,
                                      pts_socC,
                                      foundFlag);

            // 2.2.3) Guardamos en el vector de vectores.
            c_imagePoints.push_back(pts_socC);

            // 2.2.4) Guardamos la imagen en la carpeta de salida
            String saveImageName = c_saveImagePath + "cornersSoC" + to_string(nf+1) + ".jpg";
            cv::imwrite(saveImageName,imgView);
        }
    }
*/
    return 0;
}

void CalibradorCamara::addImagePoints(){
    /*! Añadir los puntos de control encontrados en el plano de la imagen. */
    cout<<"[INFO] Añadir imagePoints."<<endl;

}


// Métodos de la calibración.
cv::Mat CalibradorCamara::searchImagePoints(cv::Mat imgView){
    /*! Añadir los puntos de control encontrados en el plano de la imagen.
    /* Esta función se utiliza para previsualizar en pantalla si se han encontrado los puntos de control en el plano de la imagen y posteriormente
       capturar dicha vista.
    */
    cout<<"[INFO] Buscar puntos de control en el plano de la imagen (aproximado)."<<endl;

    // Definición de una matriz para almacenar la imagen en escala de grises.
    cv::Mat imgView_gray;
    cv::cvtColor(imgView,imgView_gray, CV_BGR2GRAY);

    // Definición de un vector de puntos tanto para SoC_C
    vector<cv::Point2f> pts_socC;        // Puntos en el sistema de coordenada de la camara (Xc, Yc, Zc). (Vector de puntos porque son varios).

    // Calculamos las coordenadas de forma aproximada (si existen).
    bool foundFlag = cv::findChessboardCorners(imgView_gray,c_boardSize,pts_socC, CALIB_CB_FAST_CHECK);
    cv::drawChessboardCorners(imgView, c_boardSize, pts_socC, foundFlag);

    // Cambiamos la imagen al color de salida de qt.
    cvtColor(imgView,imgView,CV_BGR2RGB);
    return imgView;
}

void CalibradorCamara::calibrar(int nframe){
    /*!
     * \brief Calibra la cámara con la lista de imagenes de control almacenadas.
    */
    cv::Mat view = c_imageCalibrationList[nframe];
    sleep(1);

}
