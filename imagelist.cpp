#include "imagelist.h"

ImageList::ImageList(QObject *parent) : QObject(parent)
{

}

ImageList::Images ImageList::images() const
{
    return m_images;
}

ImageModel *ImageList::addImage()
{
    auto result = new ImageModel(this);
    if (result != nullptr)
    {
        m_images.append(result);
        emit imageAdded(result);
    }
    return result;
}

bool ImageList::deleteImage(ImageModel *image)
{
    if (m_images.contains(image))
    {
        emit imageRemoved(image);
        m_images.removeOne(image);
        delete image;
        return true;
    }
    return false;
}

quint32 ImageList::total_images() const
{
    return m_total_images;
}

void ImageList::settotal_images(const quint32 &total_images)
{
    if (m_total_images != total_images)
    {
        m_total_images = total_images;
        emit total_imagesChanged();
    }
}
