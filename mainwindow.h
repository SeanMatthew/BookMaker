#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pagelistcontroller.h"
#include "captionlistcontroller.h"
#include "imagelistcontroller.h"
#include "newstorydialog.h"

#include <QMainWindow>
#include <QHash>
#include <QSize>
#include <QPixmap>
#include <QLabel>
#include <QTransform>
#include <QMatrix>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QPainter>
#include <QImage>
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtWidgets>
#define ORIGIN_X 20
#define ORIGIN_y 20

namespace Ui {
class MainWindow;
}

class QTableWidgetItem;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(PageListController *p_c,
                      //  CaptionListController *c_c,
                      //  ImageListController *i_c,
                        QWidget *parent = 0);
    ~MainWindow();

    //void fitWindow(QGraphicsView *gView, QPixmap pix, QTransform &tform,
      //  qreal scale_x, qreal scale_y, qreal offset_x, qreal offset_y, qreal rotate_ccw);
   // QTransform fitWindowFullscreenDefault(QLabel *label, QPixmap pix);

public slots:
    void newStory();
    void quitToMain();
    void editStory();
    void loadStory();
    void saveStory();
    void deleteStory();
    void aboutStory();
    void quitStory();

    void insertImage();
    void insertCaption();

    void showGrid();
    void removeGrid();

private:
    Ui::MainWindow *ui_m;
    //Ui::NewStoryDialog *ui_n;
    PageListController *page_controller;
 //   CaptionListController *caption_controller;
  //  ImageListController *image_controller;
    QHash<quint32, Page*> m_pageMap;
    QHash<QTableWidgetItem*, ImageModel*> m_image_widgetMap;
    QHash<QTableWidgetItem*, Caption*> m_caption_widgetMap;
    QHash<ImageModel*, QLabel*> m_image_labelmap;
    QHash<Caption*, QLabel*> m_caption_labelMap;

    bool m_grid = true;

    void setupConnections();
};

#endif // MAINWINDOW_H
