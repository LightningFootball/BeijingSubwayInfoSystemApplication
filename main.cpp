#include "BeijingSubwayInfoSystenApplication.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <qtextcodec.h>

#include "DataProcess.h"

#pragma execution_character_set("utf-8")

using namespace std;

int main(int argc, char *argv[])
{
    //QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForLocale(codec);
    dataProcess();

    //QApplication a(argc, argv);
    //BeijingSubwayInfoSystenApplication w;
    //w.show();
    //QLabel* label = new QLabel("Hello World!");
    //label->show();
    //return a.exec();
}
