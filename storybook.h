#ifndef STORYBOOK_H
#define STORYBOOK_H

#include "pagelist.h"
#include <QObject>

class StoryBook : public QObject
{
    Q_OBJECT
public:
    explicit StoryBook(QObject *parent = 0);
    ~StoryBook();

signals:
    void

public slots:

private:
    PageList m_pagelist;

};

#endif // STORYBOOK_H
