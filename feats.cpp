/*	
	Dungeon Client - An application geared towards making D&D character setup and use
	easier.
    Copyright (C) 2010 Dane T Larsen 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    A copy of the GNU General Public License can be found in the file COPYING
    included with this program.  Or, see <http://www.gnu.org/licenses/>.
    
    You can contact the author at dane.t.larsen@gmail.com
*/

#include "feats.h"


Feats::Feats(QWidget *parent)
{
	QGridLayout *layout = new QGridLayout;
	QVBoxLayout *button_l = new QVBoxLayout;
	
	add_button = new QPushButton("Add Feat");
	remove_button = new QPushButton("Remove Feat");
	up_button = new QPushButton("Move Up");
	down_button = new QPushButton("Move Down");
	
	connect(add_button, SIGNAL(clicked()), SLOT(add()));
	connect(remove_button, SIGNAL(clicked()), SLOT(remove()));
	connect(up_button, SIGNAL(clicked()), SLOT(move_up()));
	connect(down_button, SIGNAL(clicked()), SLOT(move_down()));
	
	button_l->addWidget(add_button);
	button_l->addWidget(remove_button);
	button_l->addWidget(up_button);
	button_l->addWidget(down_button);
	button_l->addStretch(1);
	
	QTableWidgetItem *col1 = new QTableWidgetItem("Feat");
	QTableWidgetItem *col2 = new QTableWidgetItem("Page");
	QTableWidgetItem *col3 = new QTableWidgetItem("Notes");
	
	table = new QTableWidget(0, 3);
	table->setMinimumSize(500, 300);
	table->setHorizontalHeaderItem(0, col1);
	table->setHorizontalHeaderItem(1, col2);
	table->setHorizontalHeaderItem(2, col3);
	
	table->setColumnWidth(0, 150);
	table->setColumnWidth(2, 200);
	
	num_items = 0;
	
		
	layout->addWidget(table, 0, 0, 1, 1);
	layout->addLayout(button_l, 0, 1, 1, 1);
	
	setLayout(layout);

}

void Feats::add()
{
	num_items++;
	table->setRowCount(num_items);
	
	QTableWidgetItem *temp_item;
	
	temp_item = new QTableWidgetItem("Feat");
	//temp_item->setFlags(Qt::ItemIsEnabled);
	table->setItem(num_items-1, 0, temp_item);
	
	temp_item = new QTableWidgetItem("Page");
	//temp_item->setFlags(Qt::ItemIsEnabled);
	table->setItem(num_items-1, 1, temp_item);
	
	temp_item = new QTableWidgetItem("Notes");
	//temp_item->setFlags(Qt::ItemIsTristate);
	table->setItem(num_items-1, 2, temp_item);
	
}

void Feats::remove()
{	
	//this prevents a segfault. YAY!
	if(table->currentItem() == NULL)
	{
		QMessageBox::warning(this, tr("Nothing Selected"), tr("Please select a feat to delete."));
		return;
		
	}
	
	//make sure we pull the correct cell, by picking out (currentrow, 0)
	int current_row = table->currentRow();
	
	QTableWidgetItem *temp_item = table->item(table->currentRow(), 0);
	QString creme_de_la_text = temp_item->text(); //contains the selected item's name
		
	int button = QMessageBox::question(this, tr("Confirm Removal"), ("Are you sure you want to remove "+creme_de_la_text+"?"), QMessageBox::Yes | QMessageBox::No);

	if (button == QMessageBox::Yes) 
	{
		table->removeRow(table->currentRow());
		num_items--;
		
		QMessageBox::information(this, tr("Removal Successful"), (""+creme_de_la_text+" has been removed from your feats."));
	}
	
	table->setCurrentCell(current_row, 0);

}

//swaps the selected item with the item above
void Feats::move_up()
{

	if(table->currentItem() == NULL)
		return;
	
	if(table->currentRow() == 0)
		return;

	int current_col = table->currentColumn();
	int current_row = table->currentRow();
	QTableWidgetItem *old_item;
	QTableWidgetItem *new_item;
	QString current_text;
	
	table->insertRow(current_row-1);
	
	current_row++;
	
	old_item = table->item(current_row, 0);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 0, new_item);
	
	old_item = table->item(current_row, 1);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 1, new_item);
	
	old_item = table->item(current_row, 2);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 2, new_item);
	
	table->removeRow(current_row);
	table->setCurrentCell(current_row-2, current_col);
	
}

//swaps the selected item with the item below
void Feats::move_down()
{

	if(table->currentItem() == NULL)
		return;

	if(table->currentRow() == num_items-1)
		return;
		
	int current_col = table->currentColumn();
	int current_row = table->currentRow();
	QTableWidgetItem *old_item;
	QTableWidgetItem *new_item;
	QString current_text;
	
	table->insertRow(current_row+2);
	
	old_item = table->item(current_row, 0);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row+2, 0, new_item);
	
	old_item = table->item(current_row, 1);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row+2, 1, new_item);
	
	old_item = table->item(current_row, 2);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row+2, 2, new_item);
	
	table->removeRow(current_row);
	table->setCurrentCell(current_row+1, current_col);

}

QByteArray* Feats::save()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::WriteOnly);
	
	QTableWidgetItem *temp_item;
	
	for(int i = 0; i < num_items; i++)
	{
		//the key is stored as thus:
		//the tens digit is the rownum
		//the ones digit is the colnum
		//ex: 1, 2 (second row, third item) is stored under the key 12
		
		
		temp_item = table->item(i, 0);
		hash[QString::number((i*10)+0)] = temp_item->text();
		
		temp_item = table->item(i, 1);
		hash[QString::number((i*10)+1)] = temp_item->text();
		
		temp_item = table->item(i, 2);
		hash[QString::number((i*10)+2)] = temp_item->text();
	
	}
	
	hash["num_items"] = QString::number(num_items);
	
	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    
    return hasharray;

}

void Feats::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadWrite);
	in >> hash;
	
	table->clearContents();
	table->setRowCount(0);
	
	if (hash.isEmpty()) 
    {
    	QMessageBox::information(this, tr("No feats were loaded"), tr("The file you are attempting to open contains no saved feats."));
    } 
    else 
    {
		num_items = hash["num_items"].toInt();
		
		table->setRowCount(num_items);
	
		QTableWidgetItem *temp_item;
	
		for(int i = 0; i < num_items; i++)
		{
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+0)]);
			table->setItem(i, 0, temp_item);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+1)]);
			table->setItem(i, 1, temp_item);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+2)]);
			table->setItem(i, 2, temp_item);
		
		}
	
	}

}
