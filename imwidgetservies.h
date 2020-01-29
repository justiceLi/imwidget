#ifndef IMWIDGETSERVIES_H
#define IMWIDGETSERVIES_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsView>

class BaseItem;
class ChatHead;
class ChatMsg;

class ViewPrivate;
class View : public QGraphicsView
{
    Q_OBJECT
public:
    View(QWidget* parent = NULL);

    void addMsg(const QString &strText);
protected:
    void resizeEvent(QResizeEvent *event);

private:
    ViewPrivate* m_pd;
};

//base item
class BaseItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    //send msg role
    enum Role
    {
        Role_self = 0x01,
        Role_other,
    };

    explicit BaseItem(QObject *parent = 0);
    virtual ~BaseItem();
};

//chathead
class ChatHeadPrivate;
class ChatHead : public BaseItem
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
class ChatMsg : public BaseItem
{
    Q_OBJECT
public:
    ChatMsg(QObject* parent = NULL);
    ~ChatMsg();

    //set rect
    void setRect(int ix, int iy, int iw, int ih);

    //add msgstr
    void setText(const QString &strMsg);

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



















