#ifndef PAGELIST_H
#define PAGELIST_H

#include "page.h"
#include <QObject>
#include <QList>

class PageList : public QObject
{
    Q_OBJECT
public:
    typedef QList<Page*> Pages;
    explicit PageList(QObject *parent = 0);

    Pages pages() const;
    Page *createPage() const;
    bool deletePage(Page *page);
    quint32 total_pages() const;
    void settotal_pages(const quint32 &total_pages);

signals:
    void pageAdded(Page *page);
    void pageRemoved(Page *page);
    void total_pagesChanges();

public slots:

private:
    Pages m_pages;
    quint32 m_total_pages = 0;
};

#endif // PAGELIST_H
