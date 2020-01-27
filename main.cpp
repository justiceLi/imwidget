#include "imwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImWidget w;
    w.show();

    return a.exec();
}
