#ifndef CALIBRADORCAMARA_H
#define CALIBRADORCAMARA_H


#include <iostream>
#include <string>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <experimental/filesystem>

using namespace std;
using namespace cv;
namespace fs = std::experimental::filesystem;

class CalibradorCamara
{
public:                 // Miembros públicos no protegidos. Se trata de la interfaz de la clase.
    CalibradorCamara(); // Constuctor
    CalibradorCamara(const string&, unsigned int[2], float[2], std::vector<std::vector<cv::Point3f>>,std::vector<std::vector<cv::Point2f>>);   // Constructor extendido.
    ~CalibradorCamara();    // Destructor

    // Métodos públicos.
    void display();
    int addChessboardPoints(const std::vector<std::string>&);

private:                // Miembros protegidos. Implementacion de la clases, es decir, de sus atributos.

    // INPUTs. Miembros de cámara (borrar este comentario cuando se finalice).
    string c_camaraId;  // Identificador de la calibración realizada por una cámara determinada.
    unsigned int c_frame;   // Identificador del número de frame analizado (de 0 a c_framesTotales).
    unsigned int c_framesTotales;
    std::vector<std::vector<cv::Point3f>> c_worldPoints; // Vector de vectores. Cada elemento es un vector de los puntos tridimensionales del CHESSBOARD referenciados al SoC_world
    std::vector<std::vector<cv::Point2f>> c_imagePoints; // Vector de vectores. Cada elemento es un vector de los puntos bidimensionales del CHESSBOARD en el plano de la imagen.

    unsigned int c_nHorizontalSquares;  // Número de Cuadrados Horizontales.
    unsigned int c_nVerticalSquares;    // Número de Cuadradados Verticales.
    cv::Size c_boardSize = cv::Size(c_nHorizontalSquares, c_nVerticalSquares); // Número total de cuadrados de calibración en el pattern.

    float c_wSquares;   // Ancho de los cuadrados del CHESSBOARD.
    float c_hSquares;   // Alto de los cuadrados del CHESSBOARD.

    // OUTPUTS. Miembros de cámara (borrar este comentario cuando se finalice).
    cv::Mat c_pInstrs;        // Matriz parámetros extrínsecos
    cv::Mat c_coeffDist;        // Vector de coeficientes de distorsión.
};

#endif // CALIBRADORCAMARA_H
