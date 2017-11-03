#ifndef IMAGELISTCONTROLLER_H
#define IMAGELISTCONTROLLER_H

#include "imagelist.h"
#include <QObject>

class ImageListController : public QObject
{
    Q_OBJECT
public:
    explicit ImageListController(
            ImageList *image_list, QObject *parent = 0);

    ImageModel *addImage();
    bool deleteImage(ImageModel *image);

signals:

public slots:

private:
    ImageList *m_images;
};

#endif // IMAGELISTCONTROLLER_H
