#include "BeijingSubwayInfoSystemApplication.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <QtWidgets/qpushbutton.h>

#include "Storage.h"

int main(int argc, char *argv[])
{
    QApplication main(argc, argv);
    
    BeijingSubwayInfoSystemApplication mainScreen;
    mainScreen.show();

    return main.exec();
}