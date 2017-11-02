#include "pagelistcontroller.h"

PageListController::PageListController(
        PageList pagelist, QObject *parent) :
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
        result->setimages(new ImageList(m_pagelist));
        result->setcaptions(new CaptionList(m_pagelist));
    }
    return result;
}

bool PageListController::deletePage(Page *page)
{
    return m_pagelist->deletePage(page);
}
