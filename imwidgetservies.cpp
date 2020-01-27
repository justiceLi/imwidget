#include "imwidgetservies.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

//base
ImWidgetservies::ImWidgetservies(QObject *parent)
    : QObject(parent)
{

}

ImWidgetservies::~ImWidgetservies()
{

}

//chat head
class ChatHeadPrivate
{
public:
    QRectF rect; //bounding rect
    ChatHeadPrivate()
    {
        rect.setRect(0, 0, 30, 30);
    }
};

ChatHead::ChatHead(QObject *parent)
    : ImWidgetservies(parent)
    , m_pd(new ChatHeadPrivate)
{

}

ChatHead::~ChatHead()
{
    if (m_pd != NULL)
    {
        delete m_pd;
        m_pd = NULL;
    }
}

void ChatHead::setRect(int x, int y, int w, int h)
{
    m_pd->rect.setRect(x, y, w, h);
}

QRectF ChatHead::boundingRect() const
{
   return m_pd->rect;
}

void ChatHead::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawEllipse(m_pd->rect);
    painter->restore();
}

//chat msg
class ChatMsgPrivate
{
public:
    QRect rect;
    QString strMsg;
    ChatMsgPrivate()
    {
        rect.setRect(0, 0, 200, 30);
    }
};
ChatMsg::ChatMsg(QObject *parent)
    : ImWidgetservies(parent)
    , m_pd(new ChatMsgPrivate)
{

}

ChatMsg::~ChatMsg()
{
    if (m_pd != NULL)
    {
        delete m_pd;
        m_pd = NULL;
    }
}

void ChatMsg::setRect(int ix, int iy, int iw, int ih)
{
    m_pd->rect.setRect(ix, iy, iw, ih);
}

void ChatMsg::addStrMsg(const QString &strMsg)
{
    m_pd->strMsg.append(strMsg);
}

QRectF ChatMsg::boundingRect() const
{
    return m_pd->rect;
}

void ChatMsg::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    painter->save();
    painter->setPen(Qt::white);
    painter->setBrush(Qt::blue);

    //paint text
    painter->drawText(m_pd->rect, m_pd->strMsg);

    painter->restore();
}
