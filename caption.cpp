#include "caption.h"

Caption::Caption(QObject *parent) : QObject(parent)
{

}

Caption::~Caption()
{

}

QString Caption::text() const
{
    return m_text;
}

void Caption::settext(const QString &text)
{
    if (m_text != text)
    {
        m_text = text;
        emit textChanged();
    }
}

Box Caption::text_box_coordinates() const
{
    return m_text_box_coordinates;
}

void Caption::settext_box_coordinates(const Box &text_box_coordinates)
{
    bool change = false;
    if (m_text_box_coordinates.m_box_x1 !=
          text_box_coordinates.m_box_x1)
    {
        m_text_box_coordinates.m_box_x1 =
          text_box_coordinates.m_box_x1;
        change = true;
    }

    if (m_text_box_coordinates.m_box_x2 !=
          text_box_coordinates.m_box_x2)
    {
        m_text_box_coordinates.m_box_x2 =
          text_box_coordinates.m_box_x2;
        change = true;
    }

    if (m_text_box_coordinates.m_box_y1 !=
          text_box_coordinates.m_box_y1)
    {
        m_text_box_coordinates.m_box_y1 =
          text_box_coordinates.m_box_y1;
        change = true;
    }

    if (m_text_box_coordinates.m_box_y2 !=
          text_box_coordinates.m_box_y2)
    {
        m_text_box_coordinates.m_box_y2 =
          text_box_coordinates.m_box_y2;
        change = true;
    }

    if (change)
        emit text_box_coordinatesChanged();
}

QFont Caption::font() const
{
    return m_font;
}

quint32 Caption::object_number() const
{
    return m_object_number;
}

void Caption::setobject_number(const quint32 &object_number)
{
    if (m_object_number != object_number)
    {
        m_object_number = object_number;
        emit object_numberChanged();
    }
}

void Caption::setfont(const QFont &font)
{
    if (m_font != font)
    {
        m_font = font;
        emit fontChanged();
    }
}
