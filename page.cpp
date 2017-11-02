#include "page.h"

Page::Page(QObject *parent) : QObject(parent)
{

}

Page::~Page()
{

}

ImageList Page::images() const
{
    return m_images;
}

void Page::setimages(const ImageList &images)
{ // Probably not right
    if (m_images != images)
    {
        m_images = images;
        emit imagesChanged();
    }
}

CaptionList Page::captions() const
{
    return m_captions;
}

void Page::setcaptions(const CaptionList &captions)
{ // Probably not right
    if (m_captions != captions)
    {
        m_captions = captions;
        emit captionsChanged();
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
