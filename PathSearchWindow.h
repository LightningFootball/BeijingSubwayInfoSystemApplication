#pragma once

#include "BeijingSubwayInfoSystemApplication.h"

#include <QWidget>
#include "ui_PathSearchWindow.h"

class PathSearchWindow : public QWidget
{
	Q_OBJECT

public:

	PathSearchWindow(QWidget *parent = Q_NULLPTR);
	~PathSearchWindow();

private:
	Ui::PathSearchWindow ui;
};
