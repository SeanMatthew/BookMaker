#ifndef IMAGELISTCONTROLLER_H
#define IMAGELISTCONTROLLER_H

#include "imagelist.h"
#include <QObject>

class ImageListController : public QObject
{
    Q_OBJECT
public:
    explicit ImageListController(
            ImageList *images, QObject *parent = 0);

    ImageList *addImage();
    bool deleteImage(ImageModel *image);

signals:

public slots:

private:
    ImageList *m_images;
};

#endif // IMAGELISTCONTROLLER_H
