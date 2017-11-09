#include "dialogareyousure.h"
#include "ui_dialogareyousure.h"

DialogAreYouSure::DialogAreYouSure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAreYouSure)
{
    ui->setupUi(this);
}

DialogAreYouSure::~DialogAreYouSure()
{
    delete ui;
}
