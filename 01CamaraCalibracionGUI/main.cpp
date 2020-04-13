#include "paginaprincipal.h"
#include <experimental/filesystem>

// Incluir Librerías externas de desarrollador.
#include <calibradorcamara.h>

#include <QApplication>
using namespace std;

int centrarAplicacion();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaginaPrincipal paginaPrincipalWidget;

    // Centrar la aplicación en la pantalla.
    QDesktopWidget* desktop = QApplication::desktop();
    QSize windowSize;

    windowSize = paginaPrincipalWidget.size();
    int screenWidth = desktop->width(),screenHeight = desktop->height();
    int windowWidth = windowSize.width(), windowHeight = windowSize.height();

    int posX = (screenWidth-windowWidth)/2, posY = (screenHeight-windowHeight)/2-50;

    paginaPrincipalWidget.setGeometry(posX,posY,windowWidth,windowHeight);



    paginaPrincipalWidget.show();
    return a.exec();
}

