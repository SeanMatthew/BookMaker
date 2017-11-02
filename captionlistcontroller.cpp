#include "captionlistcontroller.h"

captionlistcontroller::captionlistcontroller(
        CaptionList *captions, QObject *parent) :
    QObject(parent), m_captions(captions)
{
    Q_ASSERT(captions != nullptr);
}

CaptionList *captionlistcontroller::createCaption()
{
    Box default_coordinates = {100, 400, 500, 500};
    QFont default_font("Times", 12, QFont::Bold);

    auto result = m_captions->addCaption();
    if (result != nullptr)
    {
        m_captions->settotal_captions(m_captions->total_captions() + 1);
        result->setobject_number(m_captions->total_captions());
        result->settext(tr("New caption..."));
        result->settext_box_coordinates(default_coordinates);
        result->setfont(default_font);
    }
    return result;
}

bool captionlistcontroller::deleteCaption(Caption *caption)
{
    return m_captions->deleteCaption(caption);
}
