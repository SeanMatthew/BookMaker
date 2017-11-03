#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pagelistcontroller.h"
#include "captionlistcontroller.h"
#include "imagelistcontroller.h"
#include <QMainWindow>
#include <QHash>
#include <QSize>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void fitInsideWindow(quint32 pic_width, quint32 pic_height,
                         quint32 window_width, quint32 window_height,
                         quint32 &new_width, quint32 &new_height);

    void fitOutsideWindow(quint32 pic_width, quint32 pic_height,
                         quint32 window_width, quint32 window_height,
                         quint32 &new_width, quint32 &new_height);

public slots:


private:
    Ui::MainWindow *ui;
    PageListController *page_controller;
    CaptionListController *caption_controller;
    ImageListController *image_controller;

    void setupConnections();

};

#endif // MAINWINDOW_H
