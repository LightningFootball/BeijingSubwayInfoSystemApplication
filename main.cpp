#include "BeijingSubwayInfoSystenApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeijingSubwayInfoSystenApplication w;
    w.show();
    return a.exec();
}
