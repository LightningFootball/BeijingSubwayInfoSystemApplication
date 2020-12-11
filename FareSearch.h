#pragma once

#include <QWidget>
#include "ui_FareSearch.h"

class FareSearch : public QWidget
{
	Q_OBJECT

public:
	FareSearch(QWidget *parent = Q_NULLPTR);
	~FareSearch();

private:
	Ui::FareSearch ui;
};
