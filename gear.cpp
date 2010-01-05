#include "gear.h"

Gear::Gear(QWidget *parent)
{
	QGridLayout *layout = new QGridLayout;
	gear_label = new QLabel("Gear");
	

	layout->addWidget(gear_label);
	setLayout(layout);
}
