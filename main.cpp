#include "mainwindow.h"
#include <QApplication>
#include <QPalette>
#include <QStyleFactory>
#define WIDTH_MAIN 800
#define HEIGHT_MAIN 600
#define WIDTH_NEW 500
#define HEIGHT_NEW 300
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PageList pageList;
    PageListController p_c(&pageList);

    MainWindow w(&p_c);

    w.setFixedSize(QSize(WIDTH_MAIN, HEIGHT_MAIN));

    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    qApp->setPalette(darkPalette);
    //qApp->setStyleSheet("QListWidget::item { border-bottom: 1px solid black; }");
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    w.show();

    return a.exec();
}
