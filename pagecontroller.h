#ifndef PAGECONTROLLER_H
#define PAGECONTROLLER_H

#include "page.h"
#include <QObject>
#include <QFont>

class QLabel;

class PageController : public QObject
{
    Q_OBJECT
public:
    explicit PageController(Page *page,
                            QObject *parent = nullptr);

    ImageModel *addImage();
    bool deleteImage(ImageModel *image);
    void editTransforms();

    Caption *createCaption();
    bool deleteCaption(Caption *caption);

    bool objectReplace(quint32 object_from, quint32 object_target);

signals:

public slots:
    Page *m_page;
};

#endif // PAGECONTROLLER_H
