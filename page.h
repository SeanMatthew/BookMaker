#ifndef PAGE_H
#define PAGE_H

#include <QObject>
#include <QFont>
#include "imagelist.h"
#include "captionlist.h"

class Page : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ImageList images
               READ      images
               WRITE     setimages
               NOTIFY    imagesChanged)

    Q_PROPERTY(CaptionList captions
               READ        captions
               WRITE       setcaptions
               NOTIFY      captionsChanged)

    Q_PROPERTY(quint32 page_number
               READ    page_number
               WRITE   setpage_number
               NOTIFY  page_numberChanged)
public:
    explicit Page(QObject *parent = 0);
    ~Page();

    ImageList images() const;
    void setimages(const ImageList &images);
    CaptionList captions() const;
    void setcaptions(const CaptionList &captions);
    quint32 page_number() const;
    void setpage_number(const quint32 &page_number);
    quint32 total_objects() const;
    void settotal_objects(const quint32 &total_objects);

signals:
    void imagesChanged();
    void captionsChanged();
    void page_numberChanged();

public slots:

private:
    ImageModel m_images;
    CaptionList m_captions;
    quint32 m_page_number;
};

#endif // PAGE_H
