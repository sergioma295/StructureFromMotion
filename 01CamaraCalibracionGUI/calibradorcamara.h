#ifndef CALIBRADORCAMARA_H
#define CALIBRADORCAMARA_H

// Librerías.
#include <iostream>
#include <string>
#include <vector>
#include <QString>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <experimental/filesystem>
#include <QDebug>
#include <QObject>
#include <QProgressDialog>
#include <QTimer>
#include <unistd.h>
#include <iostream>
#include <cstdlib>

// Namespaces
using namespace std;
using namespace cv;
namespace fs = std::experimental::filesystem;


// Clase para calibrar la cámara. Contiene los métodos y variables necesario para realizar la calibración
class CalibradorCamara
{
public:

    CalibradorCamara();
    CalibradorCamara(const string&,const string&,int, int, int[2], float[2], const string&);
    ~CalibradorCamara();

    // // Métodos para devolver variables privadas de la clase.
    string getUserId();                     // USUARIO.
    string getCalibrationId();              // USUARIO.
    int getCameraIndex();                   // USUARIO.
    std::vector<int> getNumeroCuadros();    // USUARIO.
    std::vector<float> getSizeCuadros();    // USUARIO.
    int getNumberoFrame();                  // SISTEMA.
    int getNumeroTotalFrames();             // USUARIO.
    string getComentarios();                // USUARIO.
    string getPath();                       // SISTEMA.
    std::vector<cv::Mat> getImageList();    // SISTEMA.
    std::vector<std::vector<cv::Point3f>> getWorldPoints();    // SISTEMA.

    // Métodos para modificar las variables privadas de la clase.
    void incrementarNumeroFrame();                  // SISTEMA.
    void setNumeroFrame(int);                       // SISTEMA.
    void addImageList(Mat);                         // SISTEMA.
    void initImageList();                           // SISTEMA.
    int createWorldPoints();                        // SISTEMA.
    void addImagePoints();                          // SISTEMA.

    // Métodos de la calibración.
    cv::Mat searchImagePoints(cv::Mat);                               // SISTEMA.
    void calibrar(int);                                               // SISTEMA.


private:
    // INPUTS.
    string c_userId;                // Identificador de la calibración realizada por una cámara determinada.
    string c_calibrationId;         // Identificador de la calibración para una cámara determianda.
    int c_cameraIndex;              // Índice utilizado para abrir la cámara.
    int c_nHorizontalSquares;       // Número de Cuadrados Horizontales.
    int c_nVerticalSquares;         // Número de Cuadradados Verticales.
    cv::Size c_boardSize;           // Número total de cuadrados de calibración en el pattern.
    float c_wSquares;               // Ancho de los cuadrados del CHESSBOARD.
    float c_hSquares;               // Alto de los cuadrados del CHESSBOARD.
    int c_imgNum;                   // Identificador del número de frame analizado (de 0 a c_framesTotales).
    int c_imgsTotales;              // Número imágenes totales.
    string c_comentarios;           // Comentarios en la calibración.

    // Variables internas
    std::vector<std::vector<cv::Point3f>> c_worldPoints;    // Vector de vectores. Cada elemento es un vector de los puntos tridimensionales del CHESSBOARD referenciados al SoC_world
    std::vector<std::vector<cv::Point2f>> c_imagePoints;    // Vector de vectores. Cada elemento es un vector de los puntos bidimensionales del CHESSBOARD en el plano de la imagen.
    std::vector<cv::Mat> c_imageCalibrationList;            // Lista de imágenes que se utilizarán en la calibración.

    // OUTPUTS..
    cv::Mat c_mInstrs;              // Matriz parámetros extrínsecos
    cv::Mat c_coeffDist;            // Vector de coeficientes de distorsión.
    std::string c_saveImagePath;    // Directorio donde se almacena la salida del algoritmo de calibración en distintos tipos de ficheros (.jpg, .csv).

};

#endif // CALIBRADORCAMARA_H
