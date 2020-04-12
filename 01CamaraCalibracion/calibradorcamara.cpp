#include "calibradorcamara.h"

// Constructor extendido.
CalibradorCamara::CalibradorCamara(const string& name,unsigned int nSquares[2], float sizeSquares[2], std::vector<std::vector<cv::Point3f>> worldPoints,std::vector<std::vector<cv::Point2f>>imgPoints)
{
    c_camaraId = name;
    c_worldPoints = worldPoints;
    c_imagePoints = imgPoints;


    // Inicializamos el valor del resto. TEMPORAL, DEBEN LEEERSE DESDE UN ARCHIVO.
    c_nHorizontalSquares = nSquares[0];
    c_nVerticalSquares   = nSquares[1];
    c_wSquares = sizeSquares[0];
    c_hSquares = sizeSquares[1];


}

// Destructor.
CalibradorCamara::~CalibradorCamara()
{
    cout<<"Objeto Destruido"<<endl;
}


// Métodos público que puede acceder a atributos privados de la clase.
// Inicializa el vector de vectores que almacena los puntos del CHESSBOARD referidos al sistema de referencias del mundo de cada vista en una variable (vector de vectores).
int CalibradorCamara::addChessboardPoints(const std::vector<std::string>& imglist)
{
    // Definición de un vector de puntos tanto para SoC_W como para SoC_C (3D y 2D respectivamente).

    // Comprobamos que está vacío. Si no lo está, devuelve error.
    if(!c_worldPoints.size()==0)
        return -1;

    c_framesTotales = imglist.size();
    // 1) Creamos un vector de vectores con el valor de las coordenadas de los puntos de control y un numero total igual al numero de vistas.
    for(int nf = 0; nf<=c_framesTotales;nf++)
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


    // 2) Creamos un vector de vectores con el valor de las coordenadas de los puntos de control en el plano de la imagen y un numero total igual al número de vistas.
    for(int nf=0; nf<=c_framesTotales;nf++)
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
        }
    }

    return 0;
}

// Muestra la información del objeto
void CalibradorCamara::display(){
    cout<<"Calibrador Camara con las siguientes especificaciones:\n(1)-Id: "<<c_camaraId<<
          ".\n(2)-Numero Total de vistas tomadas: "<<c_framesTotales<<
          ".\n(3)-Tamaño de worldPoints: "<<c_worldPoints.size()<<endl<<
          "---------------------------------------------------------------"<<endl<<endl;
}
