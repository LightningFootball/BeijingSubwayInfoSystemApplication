#include "BeijingSubwayInfoSystemApplication.h"

BeijingSubwayInfoSystemApplication::BeijingSubwayInfoSystemApplication(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.PathSearch, SIGNAL(clicked()), this, SLOT(openPathSearchWindow()));
}

void BeijingSubwayInfoSystemApplication::openPathSearchWindow()
{
	
}
