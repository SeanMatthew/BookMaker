#ifndef CAPTIONLISTCONTROLLER_H
#define CAPTIONLISTCONTROLLER_H

#include "captionlist.h"
#include <QObject>

class CaptionListController : public QObject
{
    Q_OBJECT
public:
    explicit CaptionListController(
            CaptionList *caption_list, QObject *parent = 0);

    Caption *createCaption();
    bool deleteCaption(Caption *caption);

signals:

public slots:

private:
    CaptionList *m_captions;
};

#endif // CAPTIONLISTCONTROLLER_H
