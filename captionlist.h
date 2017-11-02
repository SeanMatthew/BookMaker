#ifndef CAPTIONLIST_H
#define CAPTIONLIST_H

#include "caption.h"
#include <QObject>
#include <QList>

class CaptionList : public QObject
{
    Q_OBJECT

    Q_PROPERTY(quint32 total_captions
               READ total_captions
               WRITE settotal_captions
               NOTIFY total_captionsChanged)
public:
    typedef QList<Caption*> Captions;
    explicit CaptionList(QObject *parent = 0);

    Captions captions() const;
    Caption *addCaption();
    bool deleteCaption(Caption *caption);
    quint32 total_captions() const;
    void settotal_captions(const quint32 &total_captions);

signals:
    void captionAdded(Caption *caption);
    void captionRemoved(Caption *caption);
    void total_captionsChanged();

public slots:

private:
    Captions m_captions;
    quint32 m_total_captions = 0;
};

#endif // CAPTIONLIST_H
