#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Administrator/Desktop/SvnRoot/Sean/Qt Stuff/BookMaker/images/babylon.png");

    QSize label_size = ui->label_MainPicture->size(), pic_size(1, 1);
    quint32 p_w = pix.size().width(), p_h = pix.size().height(),
                  l_w = label_size.width(), l_h = label_size.height();
        QRect pic_window(0, 0, l_w, l_h);
    double ratio_w = (double) l_w / (double) p_w,
           ratio_h = (double) l_h / (double) p_h;
    if (ratio_w > ratio_h)
    {
        pic_size += QSize(l_w - 1, ratio_w*p_h - 1);
        pic_window.setY((ratio_w*p_h - l_h) / 2);
        pic_window.setHeight(pic_window.height() + pic_window.y());
    }
    else
    {
        pic_size += QSize(ratio_h*p_w - 1, l_h - 1);
        pic_window.setX((ratio_h*p_w - l_w) / 2);
        pic_window.setWidth(pic_window.width() + pic_window.x());
    }

    pix = pix.scaled(pic_size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPixmap pix2 = pix.copy(pic_window);
    ui->label_MainPicture->setPixmap(pix2);
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{

}
