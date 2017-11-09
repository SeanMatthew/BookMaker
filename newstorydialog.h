#ifndef NEWSTORYDIALOG_H
#define NEWSTORYDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <pagelistcontroller.h>

namespace Ui {
class NewStoryDialog;
}

class NewStoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStoryDialog(PageListController *p_c,
                            QWidget *parent = 0);
    ~NewStoryDialog();

public slots:
    void cancelNew();
    void okayNew();

private:
    Ui::NewStoryDialog *ui_n;
    PageListController *page_controller;
    bool newbook = true;

    void setupConnections();
};

#endif // NEWSTORYDIALOG_H
