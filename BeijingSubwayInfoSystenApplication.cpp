#include "BeijingSubwayInfoSystenApplication.h"

BeijingSubwayInfoSystenApplication::BeijingSubwayInfoSystenApplication(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.PathSearch, SIGNAL(clicked()), this, SLOT(openPathSearchWindow()));
}

void BeijingSubwayInfoSystenApplication::openPathSearchWindow()
{
	
}
