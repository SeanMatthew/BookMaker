#ifndef PAGELIST_H
#define PAGELIST_H

#include "page.h"
#include <QObject>
#include <QList>

class PageList : public QObject
{
    Q_OBJECT

    Q_PROPERTY(quint32 total_pages
               READ    total_pages
               WRITE   settotal_pages
               NOTIFY  total_pagesChanged)

    Q_PROPERTY(QString title
               READ    title
               WRITE   settitle
               NOTIFY  titleChanged)

    Q_PROPERTY(QString author
               READ    author
               WRITE   setauthor
               NOTIFY  authorChanged)

    Q_PROPERTY(QString description
               READ    description
               WRITE   setdescription
               NOTIFY  descriptionChanged)

public:
    typedef QList<Page*> Pages;
    explicit PageList(QObject *parent = 0);

    Pages pages() const;

    Page *createPage();
    bool deletePage(Page *page);

    quint32 total_pages() const;
    void settotal_pages(const quint32 &total_pages);

    QString title() const;
    void settitle(const QString &title);

    QString author() const;
    void setauthor(const QString &author);

    QString description() const;
    void setdescription(const QString &description);

signals:
    void pageAdded(Page *page);
    void pageRemoved(Page *page);
    void total_pagesChanged();
    void titleChanged();
    void authorChanged();
    void descriptionChanged();

public slots:

private:
    Pages m_pages;
    quint32 m_total_pages = 0;
    QString m_title = "New Title",
            m_author = "Me",
            m_description = "This book is fun! (>^^)>";
};

#endif // PAGELIST_H
