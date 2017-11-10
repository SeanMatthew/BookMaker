#ifndef PAGE_H
#define PAGE_H

#include <QObject>
#include <QString>
#include <QFont>
#include <QHash>
#include "imagemodel.h"
#include "caption.h"

class Page : public QObject
{
    Q_OBJECT

    Q_PROPERTY(quint32 total_images
               READ total_images
               WRITE settotal_images
               NOTIFY total_imagesChanged)

    Q_PROPERTY(quint32 total_captions
               READ total_captions
               WRITE settotal_captions
               NOTIFY total_captionsChanged)

    Q_PROPERTY(quint32 page_number
               READ    page_number
               WRITE   setpage_number
               NOTIFY  page_numberChanged)
public:
    typedef QList<Caption*> Captions;
    typedef QList<ImageModel*> Images;
    explicit Page(QObject *parent = 0);
    ~Page();

    Images images() const;
    ImageModel *addImage();
    bool deleteImage(ImageModel *image);

    Captions captions() const;
    Caption *addCaption();
    bool deleteCaption(Caption *caption);

    quint32 total_items() const;
    void settotal_items(const quint32 &total_items);

    quint32 page_number() const;
    void setpage_number(const quint32 &page_number);

signals:
    void imageAdded(ImageModel *image);
    void imageRemoved(ImageModel *image);

    void captionAdded(Caption *caption);
    void captionRemoved(Caption *caption);

    void total_itemsChanged();

    void page_numberChanged();

public slots:

private:
    QHash<quint32, ImageModel*> m_imagemap;
    QHash<quint32, Caption*> m_captionmap;
    Captions m_captions;
    Images m_images;
    quint32 m_total_items = 0,
            m_page_number;
};

#endif // PAGE_H
