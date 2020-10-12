#include "BeijingSubwayInfoSystenApplication.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <QtWidgets/qpushbutton.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeijingSubwayInfoSystenApplication w;
    w.show();
    QLabel* label = new QLabel("Hello World!");
    label->show();
    return a.exec();
}
