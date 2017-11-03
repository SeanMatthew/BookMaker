#include "page.h"

Page::Page(QObject *parent) : QObject(parent)
{

}

Page::~Page()
{

}

Page::Images Page::images() const
{
    return m_images;
}

ImageModel *Page::addImage()
{
    auto result = new ImageModel(this);
    if (result != nullptr)
    {
        m_images.append(result);
        emit imageAdded(result);
    }
    return result;
}

bool Page::deleteImage(ImageModel *image)
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

quint32 Page::total_images() const
{
    return m_total_images;
}

void Page::settotal_images(const quint32 &total_images)
{
    if (m_total_images != total_images)
    {
        m_total_images = total_images;
        emit total_imagesChanged();
    }
}

Page::Captions Page::captions() const
{
    return m_captions;
}

Caption *Page::addCaption()
{
    auto result = new Caption(this);
    if (result != nullptr)
    {
        m_captions.append(result);
        emit captionAdded(result);
    }
    return result;
}

bool Page::deleteCaption(Caption *caption)
{
    if (m_captions.contains(caption))
    {
        emit captionRemoved(caption);
        m_captions.removeOne(caption);
        delete caption;
        return true;
    }
    return false;
}

quint32 Page::total_captions() const
{
    return m_total_captions;
}

void Page::settotal_captions(const quint32 &total_captions)
{
    if (m_total_captions != total_captions)
    {
        m_total_captions = total_captions;
        emit total_captionsChanged();
    }
}

quint32 Page::page_number() const
{
    return m_page_number;
}

void Page::setpage_number(const quint32 &page_number)
{
    if (m_page_number != page_number)
    {
        m_page_number = page_number;
        emit page_numberChanged();
    }
}
