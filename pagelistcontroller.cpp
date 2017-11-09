#include "pagelistcontroller.h"

PageListController::PageListController(
        PageList *pagelist, QObject *parent) :
    QObject(parent), m_pagelist(pagelist)
{
    Q_ASSERT(pagelist != nullptr);
}

Page *PageListController::createPage()
{
    auto result = m_pagelist->createPage();
    if (result != nullptr)
    {
        m_pagelist->settotal_pages(m_pagelist->total_pages() + 1);
        result->setpage_number(m_pagelist->total_pages());
    }
    return result;
}

bool PageListController::deletePage(Page *page)
{
    return m_pagelist->deletePage(page);
}

QString PageListController::title()
{
    return m_pagelist->title();
}

void PageListController::settitle(QString title)
{
    m_pagelist->settitle(title);
}

QString PageListController::author()
{
    return m_pagelist->author();
}

void PageListController::setauthor(QString author)
{
    m_pagelist->setauthor(author);
}

QString PageListController::description()
{
    return m_pagelist->description();
}

void PageListController::setdescription(QString description)
{
    m_pagelist->setdescription(description);
}
