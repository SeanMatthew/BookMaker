#include "pagelist.h"

PageList::PageList(QObject *parent) : QObject(parent)
{

}

PageList::Pages PageList::pages() const
{
    return m_pages;
}

Page *PageList::createPage()
{
    auto result = new Page(this);
    if (result != nullptr)
    {
        m_pages.append(result);
        emit pageAdded(result);
    }
    return result;
}

bool PageList::deletePage(Page *page)
{
    if (m_pages.contains(page))
    {
        emit pageRemoved(page);
        m_pages.removeOne(page);
        delete page;
        return true;
    }
    return false;
}

quint32 PageList::total_pages() const
{
    return m_total_pages;
}

void PageList::settotal_pages(const quint32 &total_pages)
{
    if (m_total_pages != total_pages)
    {
        m_total_pages = total_pages;
        emit total_pagesChanged();
    }
}

QString PageList::title() const
{
    return m_title;
}

void PageList::settitle(const QString &title)
{
    if (m_title != title)
    {
        m_title = title;
        emit titleChanged();
    }
}

QString PageList::author() const
{
    return m_author;
}

void PageList::setauthor(const QString &author)
{
    if (m_author != author)
    {
        m_author = author;
        emit authorChanged();
    }
}

QString PageList::description() const
{
    return m_description;
}

void PageList::setdescription(const QString &description)
{
    if (m_description != description)
    {
        m_description = description;
        emit descriptionChanged();
    }
}
