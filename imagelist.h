#ifndef IMAGELIST_H
#define IMAGELIST_H

#include "imagemodel.h"
#include <QObject>
#include <QList>

class ImageList : public QObject
{
    Q_OBJECT
public:
    typedef QList<ImageModel*> Images;
    explicit ImageList(QObject *parent = 0);

    Images images() const;
    ImageModel *addImage();
    bool deleteImage(ImageModel *image);
    quint32 total_images() const;
    void settotal_images(const quint32 &total_images);

signals:
    void imageAdded(ImageModel *image);
    void imageRemoved(ImageModel *image);
    void total_imagesChanged();

public slots:

private:
    Images m_images;
    quint32 m_total_images = 0;
};

#endif // IMAGELIST_H
