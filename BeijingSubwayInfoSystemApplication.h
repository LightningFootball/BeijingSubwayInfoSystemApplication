#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BeijingSubwayInfoSystenApplication.h"

class BeijingSubwayInfoSystemApplication : public QMainWindow
{
    Q_OBJECT

public:
    BeijingSubwayInfoSystemApplication(QWidget *parent = Q_NULLPTR);

    void openPathSearchWindow();

private:
    Ui::BeijingSubwayInfoSystenApplicationClass ui;
};