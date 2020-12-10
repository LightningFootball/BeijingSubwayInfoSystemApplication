#include "DataProcess.h"
#include "Storage.h"

#include "BeijingSubwayInfoSystemApplication.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <QtWidgets/qpushbutton.h>

#pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{
    Storage storage;

    QApplication main(argc, argv);
    
    BeijingSubwayInfoSystemApplication mainScreen;
    mainScreen.show();

    return main.exec();
}
