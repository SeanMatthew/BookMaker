#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QObject>
#include <QPixmap>
#include <QString>

enum ImageType
{
    ImageType_Unknown = 0,
    ImageType_Background,
    ImageType_CaptionBackground,
    ImageType_Cover,
    ImageType_Object,
};

struct ImageTransforms
{
    double x_scale, y_scale;
    quint32 x_position, y_position;
};

class ImageModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QPixmap image
               READ    image
               WRITE   setimage
               NOTIFY  imageChanged)

    Q_PROPERTY(QString filename
               READ    filename
               WRITE   setfilename
               NOTIFY  filenameChanged)

    Q_PROPERTY(QString title
               READ    title
               WRITE   settitle
               NOTIFY  titleChanged)

    Q_PROPERTY(QString description_text
               READ    description_text
               WRITE   setdescription
               NOTIFY  description_textChanged)

    Q_PROPERTY(ImageType type
               READ      type
               WRITE     settype
               NOTIFY    typeChanged)

    Q_PROPERTY(ImageTransforms transforms
               READ            transforms
               WRITE           settransforms
               NOTIFY          transformsChanged)

    Q_PROPERTY(quint32 object_number
               READ    object_number
               WRITE   setobject_number
               NOTIFY  object_numberChanged)
public:
    explicit ImageModel(QObject *parent = 0);
    ~ImageModel();

    QPixmap image() const;
    void setimage(const QPixmap &image);

    QString filename() const;
    void setfilename(const QString &filename);

    QString title() const;
    void settitle(const QString &title);

    QString description_text() const;
    void setdescription(const QString &description_text);

    ImageType type() const;
    void settype(const ImageType &type);

    ImageTransforms transforms() const;
    void settransforms(const ImageTransforms &transforms);

    quint32 object_number() const;
    void setobject_number(const quint32 &object_number);

signals:
    void imageChanged();
    void filenameChanged();
    void titleChanged();
    void description_textChanged();
    void typeChanged();
    void transformsChanged();
    void object_numberChanged();

public slots:

private:
    QString m_filename, m_title, m_description;
    QPixmap m_image;
    ImageType m_type;
    ImageTransforms m_transforms;
    quint32 m_object_number;
};

#endif // IMAGEMODEL_H
