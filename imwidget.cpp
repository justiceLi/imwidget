#include "imwidget.h"
#include "ui_imwidget.h"
#include "imwidgetservies.h"

class ImWidgetPrivate
{
public:
    Ui::ImWidget ui;
    QGraphicsScene scene;
};

ImWidget::ImWidget(QWidget *parent) :
    QWidget(parent),
    m_pd(new ImWidgetPrivate)
{
    m_pd->ui.setupUi(this); 


    connect(m_pd->ui.pb_sendMsg, SIGNAL(clicked()),
            this, SLOT(slot_pBtn_sendMsg_clicked()));
}

ImWidget::~ImWidget()
{
    //delete d_ptr
    if (m_pd != NULL)
    {
        delete m_pd;
        m_pd = NULL;
    }
}

void ImWidget::addMsgLog(const QString &strText)
{
    m_pd->ui.graphicsView->addMsg(strText);
}

void ImWidget::slot_pBtn_sendMsg_clicked()
{
    if (!m_pd->ui.te_input->toPlainText().trimmed().isEmpty())
    {
        QString strText =  m_pd->ui.te_input->toPlainText().trimmed();

        addMsgLog(strText);
    }
}
