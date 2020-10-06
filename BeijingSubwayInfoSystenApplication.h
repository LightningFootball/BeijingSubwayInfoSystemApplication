#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BeijingSubwayInfoSystenApplication.h"

class BeijingSubwayInfoSystenApplication : public QMainWindow
{
    Q_OBJECT

public:
    BeijingSubwayInfoSystenApplication(QWidget *parent = Q_NULLPTR);

private:
    Ui::BeijingSubwayInfoSystenApplicationClass ui;
};
