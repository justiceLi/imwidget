#ifndef IMWIDGET_H
#define IMWIDGET_H

#include <QWidget>


class ImWidgetPrivate;
class ImWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImWidget(QWidget *parent = 0);
    ~ImWidget();

    //init
    void initUi();

    //add msg text
    void addMsgText(const QString &strText);

private slots:
    void slot_pBtn_sendMsg_clicked();

private:
    ImWidgetPrivate *m_pd;
};

#endif // IMWIDGET_H
