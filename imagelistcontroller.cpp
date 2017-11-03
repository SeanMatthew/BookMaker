#include "imagelistcontroller.h"

ImageListController::ImageListController(
        ImageList *image_list, QObject *parent) :
    QObject(parent), m_images(image_list)
{
    Q_ASSERT(image_list != nullptr);
}

ImageModel *ImageListController::addImage()
{
    auto result = m_images->addImage();
    if (result != nullptr)
    {
        m_images->settotal_images(m_images->total_images() + 1);
        result->setobject_number(m_images->total_images());
        result->setdescription(tr("New description..."));
        result->settitle(tr("New title..."));
        //use default image?
    }
    return result;
}

bool ImageListController::deleteImage(ImageModel *image)
{
    return m_images->deleteImage(image);
}
