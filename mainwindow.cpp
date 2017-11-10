#include "mainwindow.h"
#include "ui_mainwindow.h"
#define SCROLL_BAR_SIZE 20

MainWindow::MainWindow(PageListController *p_c,
                       //CaptionListController *c_c,
                       //ImageListController *i_c,
                       QWidget *parent) :
    QMainWindow(parent),
    ui_m(new Ui::MainWindow),
    page_controller(p_c)//,
   // caption_controller(c_c),
    //image_controller(i_c)
{
    ui_m->setupUi(this);

    //QPixmap main_screen_pix("C:/Users/Administrator/Desktop/SvnRoot/Sean/Qt Stuff/BookMaker/images/babylon.png");
    //QPixmap main_screen_pix2("C:/Users/Administrator/Desktop/SvnRoot/Sean/Qt Stuff/BookMaker/images/book.png");

  //  QTransform main_screen = \
    //        fitWindowFullscreenDefault(, main_screen_pix);

    //p->scale(300,300);
        //delete p;
    //ui->graphicsView_Main->scene()->addPixmap(main_screen_pix2);

    //QGraphicsPixmapItem *i = ui->graphicsView_Main->scene()->addPixmap(main_screen_pix2);
    //QGraphicsPixmapItem *item = ui->graphicsView_Main->scene()->addPixmap(main_screen_pix2);

    //i->setPixmap(i->pixmap().scaled(QSize(300,300),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    //i->setPixmap()

    //fitWindow(ui->label_MainPicture, main_screen_pix, 0, 0, 200);
    ui_m->stackedWidget->setCurrentWidget(ui_m->page_Main);
    removeGrid();
    setupConnections();

    /*
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
    */
}

MainWindow::~MainWindow()
{
    delete ui_m;
}

void MainWindow::quitToMain()
{
    ui_m->stackedWidget->setCurrentWidget(ui_m->page_Main);
}

void MainWindow::editStory()
{
    NewStoryDialog bookdialog(page_controller);
    bookdialog.setModal(true);
    int dcode = bookdialog.exec();

    if (dcode == QDialog::Accepted)
    {
        ui_m->stackedWidget->setCurrentWidget(ui_m->page_StoryBook);
        MainWindow::setWindowTitle(
        page_controller->title() + tr(" by ") +
           page_controller->author());
    }
}

void MainWindow::newStory()
{
    NewStoryDialog bookdialog(page_controller);
    bookdialog.setModal(true);
    int dcode = bookdialog.exec();

    if (dcode == QDialog::Accepted)
    {
        auto page = page_controller->createPage();
        if (page)
            page->setpage_number(1);
        ui_m->label_PageNumber->setText(tr("Page #1"));
        ui_m->stackedWidget->setCurrentWidget(ui_m->page_StoryBook);
        MainWindow::setWindowTitle(
        page_controller->title() + tr(" by ") +
           page_controller->author());
    }
}

void MainWindow::loadStory()
{

}

void MainWindow::saveStory()
{

}

void MainWindow::deleteStory()
{

}

void MainWindow::aboutStory()
{
    QMessageBox::about(this, tr("About BookMaker!"),
    tr("<p><b>BookMaker</b> is a program which (you guessed) creates books! "
       "You create pages, which you can add text or images to your page. "
       "Putting the pages together creates you the book. Be creative! "
       "The editing tools are limited. Use PhotoShop or something else "
       "for detailed editing. Thank you for using my program! "
       "Have fun! ^.^</p>"));
}

void MainWindow::quitStory()
{
    QCoreApplication::exit();
}

void MainWindow::insertImage()
{

}

void MainWindow::insertCaption()
{

}

void MainWindow::showGrid()
{
    if (!m_grid)
    {
        ui_m->line_X100_Grid->show();
        ui_m->line_X200_Grid->show();
        ui_m->line_X300_Grid->show();
        ui_m->line_X400_Grid->show();
        ui_m->line_X500_Grid->show();
        ui_m->line_X600_Grid->show();
        ui_m->line_Y100_Grid->show();
        ui_m->line_Y200_Grid->show();
        ui_m->line_Y300_Grid->show();
        ui_m->line_Y400_Grid->show();
    }
    m_grid = true;
}

void MainWindow::removeGrid()
{
    if (m_grid)
    {
        ui_m->line_X100_Grid->hide();
        ui_m->line_X200_Grid->hide();
        ui_m->line_X300_Grid->hide();
        ui_m->line_X400_Grid->hide();
        ui_m->line_X500_Grid->hide();
        ui_m->line_X600_Grid->hide();
        ui_m->line_Y100_Grid->hide();
        ui_m->line_Y200_Grid->hide();
        ui_m->line_Y300_Grid->hide();
        ui_m->line_Y400_Grid->hide();
    }
    m_grid = false;
}



/*void MainWindow::newStory()
{

}*/

//void MainWindow::fitWindow(QGraphicsView *gView, QPixmap pix, QTransform &tform,
 //   qreal scale_x, qreal scale_y, qreal offset_x, qreal offset_y, qreal rotate_ccw)
//{
    /*QSize label_size = gView->size();
    quint32 p_w = pix.size().width(),
            p_h = pix.size().height(),
            l_w = label_size.width() - SCROLL_BAR_SIZE,
            l_h = label_size.height() - SCROLL_BAR_SIZE;
    qreal ratio_w = (qreal) l_w / (qreal) p_w,
          ratio_h = (qreal) l_h / (qreal) p_h;

    if (ratio_w > ratio_h)
        tform.scale(ratio_w, ratio_h);
    else
        tform.scale(ratio_h, ratio_h);

    gView->scene()->addPixmap(pix.transformed(tform, Qt::SmoothTransformation));
    ui->graphicsView_Main->centerOn(gView->scene()->width() / 2,
                                    gView->scene()->height() / 2);

    return tform;*/
//}

//! Displays centered full screen fixed aspect ratio fit
//! @param label - The label for the pixmap
//! @param pix - the pixmap for the label
//! @return scale of the window relative to the original pixmap
//QTransform MainWindow::fitWindowFullscreenDefault(QLabel *label, QPixmap pix)
//{
    //QTransform tform;
  /*  QSize label_size = gView->size();
    quint32 p_w = pix.size().width(),
            p_h = pix.size().height(),
            l_w = label_size.width();// - SCROLL_BAR_SIZE,
            l_h = label_size.height(); //- SCROLL_BAR_SIZE;
    qreal ratio_w = (qreal) l_w  / (qreal) p_w,
          ratio_h = (qreal) l_h  / (qreal) p_h;

    if (ratio_w > ratio_h)
        tform.scale(ratio_w, ratio_h);
    else
        tform.scale(ratio_h, ratio_h);

*/
    //gView->scene()->addPixmap(pix.transformed(tform, Qt::SmoothTransformation));
   // gView->setSceneRect(200,200,200,200);
    //ui->graphicsView_Main->centerOn(gView->scene()->width() / 2,
      //                              gView->scene()->height() / 2);

  //  return tform;

//}

void MainWindow::setupConnections()
{
    /* Main Menu buttons */

    connect(ui_m->pushButton_MainAbout,
            &QPushButton::clicked,
            this, &MainWindow::aboutStory);

    connect(ui_m->pushButton_MainQuit,
            &QPushButton::clicked,
            this, &MainWindow::quitStory);

    connect(ui_m->pushButton_MainNew,
            &QPushButton::clicked,
            this, &MainWindow::newStory);

    connect(ui_m->pushButton_MainLoad,
            &QPushButton::clicked,
            this, &MainWindow::loadStory);

    connect(ui_m->pushButton_MainSave,
            &QPushButton::clicked,
            this, &MainWindow::saveStory);

    connect(ui_m->pushButton_MainDelete,
            &QPushButton::clicked,
            this, &MainWindow::deleteStory);

    /* 'Book' drop down menu */

    connect(ui_m->actionAbout,
            &QAction::triggered,
            this, &MainWindow::aboutStory);

    connect(ui_m->actionQuit,
            &QAction::triggered,
            this, &MainWindow::quitToMain);

    /* 'Window' drop down menu */

    connect(ui_m->actionAdd_Gridlines,
            &QAction::triggered,
            this, &MainWindow::showGrid);

    connect(ui_m->actionRemove_Gridlines,
            &QAction::triggered,
            this, &MainWindow::removeGrid);

}
