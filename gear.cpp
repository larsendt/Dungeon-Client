#include "gear.h"

QListWidget *gearlist;
QPushButton *add;
QPushButton *remove;
QPushButton *up;
QPushButton *down;

Gear::Gear(QWidget *parent)
{
	QGridLayout *layout = new QGridLayout;
	
	gearlist = new QListWidget;
	add = new QPushButton("Add");
	remove = new QPushButton("Remove");
	up = new QPushButton("Move Up");
	down = new QPushButton("Move Down");
	
	layout->addWidget(gearlist, 0, 0, 4, 1);
	layout->addWidget(add, 0, 1, 1, 1);
	layout->addWidget(remove, 1, 1, 1, 1);
	layout->addWidget(up, 2, 1, 1, 1);
	layout->addWidget(down, 3, 1, 1, 1);
	
	setLayout(layout);

}
