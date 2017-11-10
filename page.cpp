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

quint32 Page::total_items() const
{
    return m_total_items;
}

void Page::settotal_items(const quint32 &total_items)
{
    if (m_total_items != total_items)
    {
        m_total_items = total_items;
        emit total_itemsChanged();
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
