#include "BeijingSubwayInfoSystemApplication.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <QtWidgets/qpushbutton.h>

#include "Storage.h"

extern Storage database;

int main(int argc, char *argv[])
{
    Storage database;

    QApplication main(argc, argv);
    
    BeijingSubwayInfoSystemApplication mainScreen;
    mainScreen.show();

    return main.exec();
}