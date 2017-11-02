#ifndef PAGELISTCONTROLLER_H
#define PAGELISTCONTROLLER_H

#include "pagelist.h"
#include <QObject>

class PageListController : public QObject
{
    Q_OBJECT
public:
    explicit PageListController(
            PageList *pagelist, QObject *parent = 0);

    Page *createPage();
    bool deletePage(Page *page);

signals:

public slots:

private:
    PageList *m_pagelist;
};

#endif // PAGELISTCONTROLLER_H
