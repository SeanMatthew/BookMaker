#include "imagemodel.h"

ImageModel::ImageModel(QObject *parent) : QObject(parent)
{

}

ImageModel::~ImageModel()
{

}

QPixmap ImageModel::image() const
{
    return m_image;
}

void ImageModel::setimage(const QPixmap &image)
{
    m_image = QPixmap(image);
    emit imageChanged();
}

QString ImageModel::filename() const
{
    return m_filename;
}

void ImageModel::setfilename(const QString &filename)
{
    if (m_filename != filename)
    {
        m_filename = filename;
        emit filenameChanged();
    }
}

QString ImageModel::title() const
{
    return m_title;
}

void ImageModel::settitle(const QString &title)
{
    if (m_title != title)
    {
        m_title = title;
        emit titleChanged();
    }
}

QString ImageModel::description_text() const
{
    return m_description;
}

void ImageModel::setdescription(const QString &description_text)
{
    if (m_description != description_text)
    {
        m_description = description_text;
        emit description_textChanged();
    }
}

ImageType ImageModel::type() const
{
    return m_type;
}

void ImageModel::settype(const ImageType &type)
{
    if (m_type != type)
    {
        m_type = type;
        emit typeChanged();
    }
}

ImageTransforms ImageModel::transforms() const
{
    return m_transforms;
}

void ImageModel::settransforms(const ImageTransforms &transforms)
{
    bool change = false;
    if (m_transforms.x_position !=
          transforms.x_position)
    {
        m_transforms.x_position =
          transforms.x_position;
        change = true;
    }

    if (m_transforms.y_position !=
          transforms.y_position)
    {
        m_transforms.y_position =
          transforms.y_position;
        change = true;
    }

    if (m_transforms.x_scale !=
          transforms.x_scale)
    {
        m_transforms.x_scale =
          transforms.x_scale;
        change = true;
    }

    if (m_transforms.y_scale !=
          transforms.y_scale)
    {
        m_transforms.y_scale =
          transforms.y_scale;
        change = true;
    }

    if (change)
        emit transformsChanged();
}

quint32 ImageModel::object_number() const
{
    return m_object_number;
}

void ImageModel::setobject_number(const quint32 &object_number)
{
    if (m_object_number != object_number)
    {
        m_object_number = object_number;
        emit object_numberChanged();
    }
}

