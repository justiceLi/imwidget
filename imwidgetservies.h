#ifndef IMWIDGETSERVIES_H
#define IMWIDGETSERVIES_H

#include <QGraphicsItem>
#include <QObject>

//base item
class ImWidgetservies : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    //send msg role
    enum Role
    {
        Role_self = 0x01,
        Role_other,
    };

    explicit ImWidgetservies(QObject *parent = 0);
    virtual ~ImWidgetservies();
};

//chathead
class ChatHeadPrivate;
class ChatHead : public ImWidgetservies
{
  Q_OBJECT
public:
    ChatHead(QObject* parent = NULL);
    ~ChatHead();

    //set rect
    void setRect(int x, int y, int w, int h);

    // QGraphicsItem interface
public:
    //paint rect
    QRectF boundingRect() const;

    //paint self
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
    ChatHeadPrivate* m_pd;
};

//ChatMsg
class ChatMsgPrivate;
class ChatMsg : public ImWidgetservies
{
    Q_OBJECT
public:
    ChatMsg(QObject* parent = NULL);
    ~ChatMsg();

    //set rect
    void setRect(int ix, int iy, int iw, int ih);

    //add msgstr
    void addStrMsg(const QString &strMsg);

    // QGraphicsItem interface
public:
    //paint rect
    QRectF boundingRect() const;

    //paint self
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    ChatMsgPrivate *m_pd;
};

#endif // IMWIDGETSERVIES_H



















