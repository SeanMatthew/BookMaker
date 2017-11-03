#ifndef CAPTION_H
#define CAPTION_H

#include <QObject>
#include <QString>
#include <QFont>

struct Box
{
    quint32 m_box_x1, m_box_y1, m_box_x2, m_box_y2;
};

class Caption : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString text
               READ    text
               WRITE   settext
               NOTIFY  textChanged)

    Q_PROPERTY(Box     text_box_coordinates
               READ    text_box_coordinates
               WRITE   settext_box_coordinates
               NOTIFY  text_box_coordinatesChanged)

    Q_PROPERTY(QFont   font
               READ    font
               WRITE   setfont
               NOTIFY  fontChanged)

    Q_PROPERTY(quint32 object_number
               READ    object_number
               WRITE   setobject_number
               NOTIFY  object_numberChanged)
public:
    explicit Caption(QObject *parent = nullptr);
    ~Caption();

    QString text() const;
    void settext(const QString &text);
    Box text_box_coordinates() const;
    void settext_box_coordinates(const Box &text_box_coordinates);
    QFont font() const;
    void setfont(const QFont &font);
    quint32 object_number() const;
    void setobject_number(const quint32 &object_number);

signals:
    void textChanged();
    void text_box_coordinatesChanged();
    void fontChanged();
    void object_numberChanged();

public slots:

private:
    QString m_text;
    Box m_text_box_coordinates;
    QFont m_font;
    quint32 m_object_number;
};

#endif // CAPTION_H
