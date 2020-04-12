// Librerías OpenCV
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

// Librerías C++
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <experimental/filesystem>

// Incluir Librerías externas de desarrollador.
#include <calibradorcamara.h>

// Namespaces
using namespace cv;
using namespace std;
namespace fs = std::experimental::filesystem;


int main()
{
    cout << "Hello World!" << endl;
    // Creamos puntero a objeto.
    std::vector<std::vector<cv::Point3f>> worldPoints;
    std::vector<std::vector<cv::Point2f>>imgPoints;
    unsigned int nSquares[2]={9,7}; // Numero de cuadrados del CHESSBOARD. [numero_cuadrados_horizontales, numero_cuadrados_verticales].
    float sizeSquares[2]={20,20};    // Tamaño de cuadrados del CHESSBOARD. [ancho, alto].

    std::cout<<"Current path is "<<fs::current_path()<<endl;


    CalibradorCamara* ptr_calibradorCamara = new CalibradorCamara("GoPro (Carrefour)",nSquares,sizeSquares,worldPoints,imgPoints);
    // Creamos el vector de vectores de los puntos del CHESSBOARD referidos al sistema de referencia del mundo.
    std::vector<std::string> imglist;
    //ptr_calibradorCamara->addChessboardPoints(imglist);
    ptr_calibradorCamara->display();

    delete ptr_calibradorCamara;    // Eliminamos puntero a objeto

    return 0;
}

