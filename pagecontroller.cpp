#include "pagecontroller.h"

PageController::PageController(QObject *parent) : QObject(parent)
{

}

ImageModel *PageController::addImage()
{
    auto result = m_page->addImage();
    if (result != nullptr)
    {
        m_page->settotal_items(m_page->total_items() + 1);
        result->setobject_number(m_page->total_items());
        result->setdescription(tr("New description..."));
        result->settitle(tr("New title..."));
        result->settype(ImageType::ImageType_Unknown);
    }
    return result;
}

bool PageController::deleteImage(ImageModel *image)
{
    return m_page->deleteImage(image);
}

Caption *PageController::createCaption()
{
    Box default_coordinates = {100, 400, 500, 500};
    QFont default_font("Times", 12, QFont::Bold);

    auto result = m_page->addCaption();
    if (result != nullptr)
    {
        m_page->settotal_items(m_page->total_items() + 1);
        result->setobject_number(m_page->total_items());
        result->settext(tr("New caption..."));
        result->settext_box_coordinates(default_coordinates);
        result->setfont(default_font);
    }
    return result;
}

bool PageController::deleteCaption(Caption *caption)
{
    return m_page->deleteCaption(caption);
}

bool PageController::objectReplace(quint32 object_from, quint32 object_target)
{
    quint32 temp;
    auto i_from = m_page->m_imagemap.value(object_from);
    auto i_target = m_page->m_imagemap.value(object_target);
    auto c_from = m_page->m_captionmap.value(object_from);
    auto c_target = m_page->m_captionmap.value(object_target);

    if (i_from)
    {
        if (i_target)
        {
            temp = i_from->object_number();
            i_from->setobject_number(i_target->object_number());
            i_target->setobject_number(temp);
        }
        else if (c_target)
        {
            temp = i_from->object_number();
            i_from->setobject_number(c_target->object_number());
            c_target->setobject_number(temp);
        }
        else
        {
            return false;
        }

    }

    else if (c_from)
    {
        if (i_target)
        {
            temp = c_from->object_number();
            c_from->setobject_number(i_target->object_number());
            i_target->setobject_number(temp);
        }
        else if (c_target)
        {
            temp = c_from->object_number();
            c_from->setobject_number(c_target->object_number());
            c_target->setobject_number(temp);
        }
        else
        {
            return false;
        }
    }

    return true;
}
