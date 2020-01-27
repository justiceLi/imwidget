#include "imwidget.h"
#include "ui_imwidget.h"

ImWidget::ImWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImWidget)
{
    ui->setupUi(this);
}

ImWidget::~ImWidget()
{
    delete ui;
}
