#include "captionlist.h"

CaptionList::CaptionList(QObject *parent) : QObject(parent)
{

}

CaptionList::Captions CaptionList::captions() const
{
    return m_captions;
}

Caption *CaptionList::addCaption()
{
    auto result = new Caption(this);
    if (result != nullptr)
    {
        m_captions.append(result);
        emit captionAdded(result);
    }
    return result;
}

bool CaptionList::deleteCaption(Caption *caption)
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

quint32 CaptionList::total_captions() const
{
    return m_total_captions;
}

void CaptionList::settotal_captions(const quint32 &total_captions)
{
    if (m_total_captions != total_captions)
    {
        m_total_captions = total_captions;
        emit total_captionsChanged();
    }
}
