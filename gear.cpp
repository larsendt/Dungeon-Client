#include "gear.h"


Gear::Gear(QWidget *parent)
{
	QGridLayout *layout = new QGridLayout;
	QVBoxLayout *button_l = new QVBoxLayout;
	
	add_button = new QPushButton("Add Item");
	remove_button = new QPushButton("Remove Item");
	edit_button = new QPushButton("Edit Item");
	up_button = new QPushButton("Move Up");
	down_button = new QPushButton("Move Down");
	
	connect(add_button, SIGNAL(clicked()), SLOT(add()));
	connect(remove_button, SIGNAL(clicked()), SLOT(remove()));
	connect(edit_button, SIGNAL(clicked()), SLOT(edit()));
	connect(up_button, SIGNAL(clicked()), SLOT(move_up()));
	connect(down_button, SIGNAL(clicked()), SLOT(move_down()));
	
	button_l->addWidget(add_button);
	button_l->addWidget(remove_button);
	button_l->addWidget(edit_button);
	button_l->addWidget(up_button);
	button_l->addWidget(down_button);
	button_l->addStretch(1);
	
	QTableWidgetItem *col1 = new QTableWidgetItem("Item");
	QTableWidgetItem *col2 = new QTableWidgetItem("Page");
	QTableWidgetItem *col3 = new QTableWidgetItem("Weight");
	
	table = new QTableWidget(1, 3);
	table->setMinimumSize(500, 300);
	table->setHorizontalHeaderItem(0, col1);
	table->setHorizontalHeaderItem(1, col2);
	table->setHorizontalHeaderItem(2, col3);
	
	table->setCellWidget(0, 0, new QLabel("Item"));
	table->setCellWidget(0, 1, new QLabel("Page"));
	table->setCellWidget(0, 2, new QLabel("Weight"));
	num_items = 1;
	
		
	layout->addWidget(table, 0, 0, 1, 1);
	layout->addLayout(button_l, 0, 1, 1, 1);
	
	setLayout(layout);

}

void Gear::add()
{
	num_items++;
	table->setRowCount(num_items);
	table->setCellWidget(num_items-1, 0, new QLabel);
	table->setCellWidget(num_items-1, 1, new QLabel);
	table->setCellWidget(num_items-1, 2, new QLabel);
}

void Gear::remove()
{

}

void Gear::edit()
{

}

void Gear::move_up()
{

}

void Gear::move_down()
{

}
