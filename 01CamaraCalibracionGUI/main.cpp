#include "paginaprincipal.h"
#include <experimental/filesystem>

// Incluir Librerías externas de desarrollador.
#include <calibradorcamara.h>
#include <QApplication>

using namespace std;

int centrarAplicacion(PaginaPrincipal &pp);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaginaPrincipal paginaPrincipalWidget;


    // Centrar la aplicación en la pantalla.
    int errorCode = centrarAplicacion(paginaPrincipalWidget);

    paginaPrincipalWidget.show();
    return a.exec();
}

int centrarAplicacion(PaginaPrincipal &pp){
    QDesktopWidget* desktop = QApplication::desktop();  // Objeto desktop
    QSize windowSize = pp.size();   // Variable almacenamiento del tamaño de la ventana.
    // Obtener tamaño
    int screenWidth = desktop->width(),screenHeight = desktop->height();    // Ancho y alto de la pantalla.
    int windowWidth = windowSize.width(), windowHeight = windowSize.height();   // Ancho y alto de la ventana.
    // Posicionar esquina superior izquierda.
    int posX = (screenWidth-windowWidth)/2, posY = (screenHeight-windowHeight)/2;
    // Mover la ventana.
    pp.setGeometry(posX,posY,windowWidth,windowHeight);

    return 0;
}
