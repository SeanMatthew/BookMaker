#ifndef DIALOGAREYOUSURE_H
#define DIALOGAREYOUSURE_H

#include <QDialog>

namespace Ui {
class DialogAreYouSure;
}

class DialogAreYouSure : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAreYouSure(QWidget *parent = 0);
    ~DialogAreYouSure();

private:
    Ui::DialogAreYouSure *ui;
};

#endif // DIALOGAREYOUSURE_H
