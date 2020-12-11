#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BeijingSubwayInfoSystenApplication.h"

#include "PathSearchWindow.h"

class BeijingSubwayInfoSystemApplication : public QMainWindow
{
    Q_OBJECT

public:

    BeijingSubwayInfoSystemApplication(QWidget *parent = Q_NULLPTR);

private slots:
    void openPathSearchWindow();

private:
    Ui::BeijingSubwayInfoSystenApplicationClass ui;
};