#ifndef IMWIDGET_H
#define IMWIDGET_H

#include <QWidget>

namespace Ui {
class ImWidget;
}

class ImWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImWidget(QWidget *parent = 0);
    ~ImWidget();

private:
    Ui::ImWidget *ui;
};

#endif // IMWIDGET_H
