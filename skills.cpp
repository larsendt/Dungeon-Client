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

#include "skills.h"

Skills::Skills(QWidget *parent)
{
	QGridLayout *layout = new QGridLayout;
	QVBoxLayout *button_l = new QVBoxLayout;
	
	add_button = new QPushButton("Add Skill");
	remove_button = new QPushButton("Remove Skill");
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
	
	QTableWidgetItem *col1 = new QTableWidgetItem("CS");
	col1->setToolTip("Class Skils require 2 skillpoints/rank");
	QTableWidgetItem *col2 = new QTableWidgetItem("Skill Name");
	QTableWidgetItem *col3 = new QTableWidgetItem("Ability");
	QTableWidgetItem *col4 = new QTableWidgetItem("Skill Mod");
	QTableWidgetItem *col5 = new QTableWidgetItem("Ability Mod");
	QTableWidgetItem *col6 = new QTableWidgetItem("Ranks");
	QTableWidgetItem *col7 = new QTableWidgetItem("Misc");
	
	
	table = new QTableWidget(0, 7);

	table->setMinimumSize(500, 300);
	table->setHorizontalHeaderItem(0, col1);
	table->setHorizontalHeaderItem(1, col2);
	table->setHorizontalHeaderItem(2, col3);
	table->setHorizontalHeaderItem(3, col4);
	table->setHorizontalHeaderItem(4, col5);
	table->setHorizontalHeaderItem(5, col6);
	table->setHorizontalHeaderItem(6, col7);
	table->setColumnWidth(0, 30);
	
	connect(table, SIGNAL(cellClicked(int, int)), this, SLOT(updateVector(int, int)));
	
	QVBoxLayout *pts_l = new QVBoxLayout;
	QLabel *asp_label = new QLabel("Pts Available");
	available_skillpts = new QLineEdit;
	QLabel *usp_label = new QLabel("Pts Used");
	used_skillpts =  new QLabel("0");
	
	pts_l->addStretch(1);
	pts_l->addWidget(asp_label);
	pts_l->addWidget(available_skillpts);
	pts_l->addWidget(usp_label);
	pts_l->addWidget(used_skillpts);
		
	button_l->addLayout(pts_l);
	
	num_items = 0;
	num_skillpoints = 0;

	layout->addWidget(table, 0, 0, 1, 1);
	layout->addLayout(button_l, 0, 1, 1, 1);
	setLayout(layout);

}

void Skills::add()
{
	num_items++;
	table->setRowCount(num_items);	
	
	QTableWidgetItem *temp_item;
	
	ranks_vector.push_back(0);
	QCheckBox *cbox = new QCheckBox;
	cbox->setCheckState(Qt::Checked);
	table->setCellWidget(num_items-1, 0, cbox);
	table->setItem(num_items-1, 5, new QTableWidgetItem("0"));
	connect(table, SIGNAL(cellChanged(int, int)), this, SLOT(updateSkillPoints(int, int)));
	
	temp_item = new QTableWidgetItem("Skill");
	table->setItem(num_items-1, 1, temp_item);
	
	temp_item = new QTableWidgetItem("Ability");
	table->setItem(num_items-1, 2, temp_item);
	
	temp_item = new QTableWidgetItem("+0");
	table->setItem(num_items-1, 3, temp_item);
	
	temp_item = new QTableWidgetItem("+0");
	table->setItem(num_items-1, 4, temp_item);
	
	temp_item = new QTableWidgetItem("+0");
	table->setItem(num_items-1, 6, temp_item); 
}

void Skills::remove()
{	
	if(table->currentItem() == NULL)
	{
		table->removeRow(table->currentRow());
		table->setCurrentCell(table->currentRow(), 0);
		return;
	}

	int current_row = table->currentRow();
	
	QTableWidgetItem *temp_item = table->item(table->currentRow(), 1);
	QString creme_de_la_text = temp_item->text(); 
		
	int button = QMessageBox::question(this, tr("Confirm Removal"), ("Are you sure you want to remove "+creme_de_la_text+"?"), QMessageBox::Yes | QMessageBox::No);

	if (button == QMessageBox::Yes) 
	{
		table->removeRow(table->currentRow());
		num_items--;
		int ranks = (used_skillpts->text()).toInt();
		ranks -= ranks_vector[current_row];
		used_skillpts->setText(QString::number(ranks));
		ranks_vector.erase(ranks_vector.begin()+(current_row+1));
	}
	
	table->setCurrentCell(current_row, 0);
}

void Skills::move_up()
{
	if(table->currentRow() < 1)
		return;
		
	int current_row = table->currentRow();
	int current_col = table->currentColumn();
	QTableWidgetItem *old_item;
	QTableWidgetItem *new_item;
	QString current_text;
	int tempnum = ranks_vector[current_row];
	ranks_vector[current_row] = ranks_vector[current_row-1];
	ranks_vector[current_row-1] = tempnum;
	
	table->insertRow(current_row-1);
	
	current_row++;
	
	QCheckBox *old_cbox = (QCheckBox*)(table->cellWidget(current_row, 0));
	QCheckBox *new_cbox = new QCheckBox;
	if(old_cbox->isChecked())
		new_cbox->setCheckState(Qt::Checked);
	table->setCellWidget(current_row-2, 0, new_cbox);
	
	old_item = table->item(current_row, 1);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 1, new_item);
	
	old_item = table->item(current_row, 2);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 2, new_item);
	
	old_item = table->item(current_row, 3);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 3, new_item);
	
	old_item = table->item(current_row, 4);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 4, new_item);
	
	old_item = table->item(current_row, 5);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 5, new_item);
	
	old_item = table->item(current_row, 6);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 6, new_item);
	
	table->removeRow(current_row);
	table->setCurrentCell(current_row-2, current_col);
	
}

void Skills::move_down()
{

	if(table->currentRow() == num_items-1 || table->currentRow() == -1)
		return;
	int current_col = table->currentColumn();
		
	int current_row = table->currentRow();
	QString current_text;
	int tempnum = ranks_vector[current_row];
	ranks_vector[current_row] = ranks_vector[current_row+1];
	ranks_vector[current_row+1] = tempnum;
	
	QCheckBox *old_cbox = (QCheckBox*)(table->cellWidget(current_row, 0));
	QCheckBox *new_cbox = new QCheckBox;
	if(old_cbox->isChecked())
		new_cbox->setCheckState(Qt::Checked);
	
	QTableWidgetItem* old_item1 = table->item(current_row, 1);
	QTableWidgetItem* new_item1 = new QTableWidgetItem(old_item1->text());
	
	QTableWidgetItem* old_item2 = table->item(current_row, 2);
	QTableWidgetItem* new_item2 = new QTableWidgetItem(old_item2->text());
	
	QTableWidgetItem* old_item3 = table->item(current_row, 3);
	QTableWidgetItem* new_item3 = new QTableWidgetItem(old_item3->text());
	
	QTableWidgetItem* old_item4 = table->item(current_row, 4);
	QTableWidgetItem* new_item4 = new QTableWidgetItem(old_item4->text());
	
	QTableWidgetItem* old_item5 = table->item(current_row, 5);
	QTableWidgetItem* new_item5 = new QTableWidgetItem(old_item5->text());
	
	QTableWidgetItem* old_item6 = table->item(current_row, 6);
	QTableWidgetItem* new_item6 = new QTableWidgetItem(old_item6->text());
	
	table->removeRow(current_row);
	
	table->insertRow(current_row+1);
	table->setCellWidget(current_row+1, 0, new_cbox);
	table->setItem(current_row+1, 1, new_item1);
	table->setItem(current_row+1, 2, new_item2);
	table->setItem(current_row+1, 3, new_item3);
	table->setItem(current_row+1, 4, new_item4);
	table->setItem(current_row+1, 5, new_item5);
	table->setItem(current_row+1, 6, new_item6);
	table->setCurrentCell(current_row+1, current_col);
	
}

void Skills::updateSkillPoints(int row, int col)
{
	if(col != 5)
		return;
	
	int old_ranks = ranks_vector[row];
	int ranks = (used_skillpts->text()).toInt();
	int new_ranks = ranks - old_ranks;
	
	QCheckBox *temp_cbox = (QCheckBox*)(table->cellWidget(row, 0));
	
	if(temp_cbox->isChecked())
		new_ranks += ((table->item(row, 5))->text()).toInt();
	else
		new_ranks += 2*(((table->item(row, 5))->text()).toInt());
		
	updateVector(row, col);
	used_skillpts->setText(QString::number(new_ranks));
}

void Skills::updateVector(int row, int col)
{
	if(col != 5)
		return;

	ranks_vector[row] = ((table->item(row, 5))->text()).toInt();
}

QByteArray* Skills::return_data_bytearray()
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
		
		
		QCheckBox *cbox = (QCheckBox*)(table->cellWidget(i, 0));
		if(cbox->isChecked())
			hash[QString::number((i*10)+0)] = "1";
		else
			hash[QString::number((i*10)+0)] = "0";
		
		temp_item = table->item(i, 1);
		hash[QString::number((i*10)+1)] = temp_item->text();
		
		temp_item = table->item(i, 2);
		hash[QString::number((i*10)+2)] = temp_item->text();
		
		temp_item = table->item(i, 3);
		hash[QString::number((i*10)+3)] = temp_item->text();
		
		temp_item = table->item(i, 4);
		hash[QString::number((i*10)+4)] = temp_item->text();
		
		temp_item = table->item(i, 5);
		hash[QString::number((i*10)+5)] = temp_item->text();
		
		temp_item = table->item(i, 6);
		hash[QString::number((i*10)+6)] = temp_item->text();
	
	}
	
	hash["num_items"] = QString::number(num_items);
	hash["num_skillpoints"] = QString::number(num_skillpoints);
	
	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    
    return hasharray;

}

void Skills::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadWrite);
	in >> hash;
	
	table->clearContents();
	table->setRowCount(0);
	
	if (hash.isEmpty()) 
    {
    	QMessageBox::information(this, tr("No skills were loaded"), tr("The file you are attempting to open contains no saved skills."));
    } 
    else 
    {
		num_items = hash["num_items"].toInt();
		num_skillpoints = hash["num_skillpoints"].toInt();
		
		table->setRowCount(num_items);
	
		QTableWidgetItem *temp_item;
	
		for(int i = 0; i < num_items; i++)
		{
			QCheckBox *cbox = new QCheckBox;
			if(hash[QString::number((i*10)+0)] == "1")
				cbox->setCheckState(Qt::Checked);
			else
				cbox->setCheckState(Qt::Unchecked);
			table->setCellWidget(i, 0, cbox);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+1)]);
			table->setItem(i, 1, temp_item);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+2)]);
			table->setItem(i, 2, temp_item);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+3)]);
			table->setItem(i, 3, temp_item);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+4)]);
			table->setItem(i, 4, temp_item);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+5)]);
			table->setItem(i, 5, temp_item);
			
			temp_item = new QTableWidgetItem(hash[QString::number((i*10)+6)]);
			table->setItem(i, 6, temp_item);	
		}	
	}
}
