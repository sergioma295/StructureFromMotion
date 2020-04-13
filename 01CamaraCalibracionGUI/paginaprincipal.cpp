#include "paginaprincipal.h"
#include "ui_paginaprincipal.h"

PaginaPrincipal::PaginaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PaginaPrincipal)
{
    ui->setupUi(this);



}

PaginaPrincipal::~PaginaPrincipal()
{
    delete ui;
}


void PaginaPrincipal::on_pb_Run_clicked()
{

    QString a = ui->value_le_UsuarioId->text();
    QString b = ui->value_le_CalibracionId->text();

    QString c =ui->value_cb_CamaraId->currentText();
    int d =ui->value_sb_NumeroImagenes->value();

    int e =ui->value_sb_NumeroCuadrosHorizontales->value();
    int f =ui->value_sb_NumeroCuadrosVerticales->value();
    int g =ui->value_sb_SizeAnchoCuadros->value();
    int h =ui->value_sb_SizeAltoCuadros->value();

    QString i =ui->lb_Comentarios->text();
}
