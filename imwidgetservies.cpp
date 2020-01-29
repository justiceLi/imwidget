#include "imwidgetservies.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>
#include <QResizeEvent>

//view
class ViewPrivate
{
public:
    QGraphicsScene *pScene;
    qreal sceneHeight;
    ViewPrivate()
        : pScene(NULL)
    {
        sceneHeight = 0;
    }
};

View::View(QWidget *parent)
    : QGraphicsView(parent)
    , m_pd(new ViewPrivate)
{
    m_pd->pScene = new QGraphicsScene(this);
    setScene(m_pd->pScene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void View::addMsg(const QString &strText)
{
    ChatHead* pHead = new ChatHead(this);
    pHead->setRect(0, 0, 20, 20);
    pHead->setPos(0, m_pd->sceneHeight);
    m_pd->pScene->addItem(pHead);

    ChatMsg* pMsg = new ChatMsg(this);
    pMsg->setRect(20, 0, width(), 20);
    pMsg->setPos(25, m_pd->sceneHeight);
    pMsg->setText(strText);
    m_pd->pScene->addItem(pMsg);

    m_pd->sceneHeight += 25;
    m_pd->pScene->setSceneRect(0, 0, width(), m_pd->sceneHeight);

}

void View::resizeEvent(QResizeEvent *event)
{
    m_pd->pScene->setSceneRect(0, 0, event->size().width(), m_pd->sceneHeight);
    setSceneRect(0, 0, width(), height());
}

//base
BaseItem::BaseItem(QObject *parent)
    : QObject(parent)
{

}

BaseItem::~BaseItem()
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
    : BaseItem(parent)
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
        rect.setRect(0, 0, 30, 30);
    }
};
ChatMsg::ChatMsg(QObject *parent)
    : BaseItem(parent)
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

void ChatMsg::setText(const QString &strMsg)
{
    m_pd->strMsg = strMsg;
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
    painter->setPen(Qt::black);
    painter->setBrush(Qt::NoBrush);

    //paint text
    painter->drawText(m_pd->rect, m_pd->strMsg);

    painter->restore();
}



