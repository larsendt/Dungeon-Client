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

/* 
	contains a list for storing an arbitrary number of spells, plus a list for 
	"activated" or "prepared" spells. Currently the prepared spell list does not save.
	Put that on the todo list
*/

#include "spells.h"

Spells::Spells(QWidget *parent)
{
	QHBoxLayout *layout = new QHBoxLayout;
	QVBoxLayout *active_l = new QVBoxLayout;
	QHBoxLayout *button_l = new QHBoxLayout;
	QVBoxLayout *button_l2 = new QVBoxLayout;
	
	add_button = new QPushButton("Add Spell");
	remove_button = new QPushButton("Remove Spell");
	up_button = new QPushButton("Move Up");
	down_button = new QPushButton("Move Down");
	prepare_button = new QPushButton("Prepare Spell");
	
	connect(add_button, SIGNAL(clicked()), SLOT(add()));
	connect(remove_button, SIGNAL(clicked()), SLOT(remove()));
	connect(up_button, SIGNAL(clicked()), SLOT(move_up()));
	connect(down_button, SIGNAL(clicked()), SLOT(move_down()));
	connect(prepare_button, SIGNAL(clicked()), SLOT(prepare()));
	
	button_l2->addWidget(add_button);
	button_l2->addWidget(remove_button);
	button_l2->addWidget(up_button);
	button_l2->addWidget(down_button);
	button_l2->addWidget(prepare_button);
	button_l2->addStretch(1);
		
	tabWidget = new QTabWidget;
	activeSpells = new QListWidget;
	QLabel *activeLabel = new QLabel("<b>Prepared Spells</b>");
	QPushButton *remove_button = new QPushButton("Remove");
	QPushButton *clear_button = new QPushButton ("Clear All");
	connect(remove_button, SIGNAL(clicked()), SLOT(remove_prepared()));
	connect(clear_button, SIGNAL(clicked()), SLOT(clear_prepared()));
	
	button_l->addWidget(remove_button);
	button_l->addWidget(clear_button);
	
	tabWidget->setTabPosition(QTabWidget::West);
	
	active_l->addWidget(activeLabel);
	active_l->addWidget(activeSpells);
	active_l->addLayout(button_l);
	
	level0 = new SpellList(this, 0);
	level1 = new SpellList(this, 1);
	level2 = new SpellList(this, 2);
	level3 = new SpellList(this, 3);
	level4 = new SpellList(this, 4);
	level5 = new SpellList(this, 5);
	level6 = new SpellList(this, 6);
	level7 = new SpellList(this, 7);
	level8 = new SpellList(this, 8);
	level9 = new SpellList(this, 9);
	
	tabWidget->addTab(level0, tr("0th"));
	tabWidget->addTab(level1, tr("1st"));
	tabWidget->addTab(level2, tr("2nd"));
	tabWidget->addTab(level3, tr("3rd"));
	tabWidget->addTab(level4, tr("4th"));
	tabWidget->addTab(level5, tr("5th"));
	tabWidget->addTab(level6, tr("6th"));
	tabWidget->addTab(level7, tr("7th"));
	tabWidget->addTab(level8, tr("8th"));
	tabWidget->addTab(level9, tr("9th"));
	
	tabWidget->setMaximumWidth(500);
	
	layout->addWidget(tabWidget);
	layout->addLayout(button_l2);
	layout->addLayout(active_l);
	
	setLayout(layout);
}

QByteArray* Spells::return_data_bytearray()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::WriteOnly);
	
	//hash all the bytearrays returned by the spell tabs
	hash["level0"] = *level0->return_data_bytearray();
	hash["level1"] = *level1->return_data_bytearray();
	hash["level2"] = *level2->return_data_bytearray();
	hash["level3"] = *level3->return_data_bytearray();
	hash["level4"] = *level4->return_data_bytearray();
	hash["level5"] = *level5->return_data_bytearray();
	hash["level6"] = *level6->return_data_bytearray();
	hash["level7"] = *level7->return_data_bytearray();
	hash["level8"] = *level8->return_data_bytearray();
	hash["level9"] = *level9->return_data_bytearray();
	
	//save the prepared spells
	QByteArray *prep_array = new QByteArray;
	QDataStream prep_stream(prep_array, QIODevice::WriteOnly);
	
	int i = 0;
	for(i; activeSpells->item(i) != NULL; i++)
	{
		prep_hash["prep"+QString::number(i)] = (activeSpells->item(i))->text();
	}
	
	//write i to the hash, for for the load() function
	prep_hash["num_prepped"] = QString::number(i);
	
	//write prep_array to the main hash
	prep_stream.setVersion(QDataStream::Qt_4_5);
	prep_stream << prep_hash;
	hash["prepared_spells"] = *prep_array;
	
	//write the main hash to the hasharray
	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    

    return hasharray;
}

void Spells::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadWrite);
	in >> hash;
	
	//send the bytearrays to each spell tab
	level0->load(&hash["level0"]);
	level1->load(&hash["level1"]);
	level2->load(&hash["level2"]);
	level3->load(&hash["level3"]);
	level4->load(&hash["level4"]);
	level5->load(&hash["level5"]);
	level6->load(&hash["level6"]);
	level7->load(&hash["level7"]);
	level8->load(&hash["level8"]);
	level9->load(&hash["level9"]);

	//extract the prepared spells bytearray	
	QByteArray *prep_array = &hash["prepared_spells"];
	
	//unwrap the bytearray into a prep_hash with a datastream
	QDataStream prep_stream(prep_array, QIODevice::ReadOnly);
	prep_stream >> prep_hash;
	
	//get the number of saved prepped spells
	int num_prepped_spells = prep_hash["num_prepped"].toInt();
	
	//clear the activeSpells list widget for loading
	activeSpells->clear();
	
	//load the prepped spells into activeSpells
	for(int i = 0; i < num_prepped_spells; i++)
	{
		activeSpells->addItem(prep_hash["prep"+QString::number(i)]);
	}	
}

void Spells::add()
{
	switch(tabWidget->currentIndex())
	{
		case 0:
			level0->add();
			break;
		case 1:
			level1->add();
			break;
		case 2:
			level2->add();
			break;
		case 3:
			level3->add();
			break;
		case 4:
			level4->add();
			break;
		case 5:
			level5->add();
			break;
		case 6:
			level6->add();
			break;
		case 7:
			level7->add();
			break;
		case 8:
			level8->add();
			break;
		case 9:
			level9->add();
			break;
		default:
			QMessageBox::warning(this, "Error", "Funky program error, blort.");
	}
}
	
void Spells::remove()
{
	switch(tabWidget->currentIndex())
	{
		case 0:
			level0->remove();
			break;
		case 1:
			level1->remove();
			break;
		case 2:
			level2->remove();
			break;
		case 3:
			level3->remove();
			break;
		case 4:
			level4->remove();
			break;
		case 5:
			level5->remove();
			break;
		case 6:
			level6->remove();
			break;
		case 7:
			level7->remove();
			break;
		case 8:
			level8->remove();
			break;
		case 9:
			level9->remove();
			break;
		default:
			QMessageBox::warning(this, "Error", "Funky program error, blort.");
	}
}
void Spells::move_up()
{
	switch(tabWidget->currentIndex())
	{
		case 0:
			level0->move_up();
			break;
		case 1:
			level1->move_up();
			break;
		case 2:
			level2->move_up();
			break;
		case 3:
			level3->move_up();
			break;
		case 4:
			level4->move_up();
			break;
		case 5:
			level5->move_up();
			break;
		case 6:
			level6->move_up();
			break;
		case 7:
			level7->move_up();
			break;
		case 8:
			level8->move_up();
			break;
		case 9:
			level9->move_up();
			break;
		default:
			QMessageBox::warning(this, "Error", "Funky program error, blort.");
	}
}

void Spells::move_down()
{
	switch(tabWidget->currentIndex())
	{
		case 0:
			level0->move_down();
			break;
		case 1:
			level1->move_down();
			break;
		case 2:
			level2->move_down();
			break;
		case 3:
			level3->move_down();
			break;
		case 4:
			level4->move_down();
			break;
		case 5:
			level5->move_down();
			break;
		case 6:
			level6->move_down();
			break;
		case 7:
			level7->move_down();
			break;
		case 8:
			level8->move_down();
			break;
		case 9:
			level9->move_down();
			break;
		default:
			QMessageBox::warning(this, "Error", "Funky program error, blort.");
	}
}

void Spells::prepare()
{
	switch(tabWidget->currentIndex())
	{
		case 0:
			put_prepared_spell(level0->prepare());
			break;
		case 1:
			put_prepared_spell(level1->prepare());
			break;
		case 2:
			put_prepared_spell(level2->prepare());
			break;
		case 3:
			put_prepared_spell(level3->prepare());
			break;
		case 4:
			put_prepared_spell(level4->prepare());
			break;
		case 5:
			put_prepared_spell(level5->prepare());
			break;
		case 6:
			put_prepared_spell(level6->prepare());
			break;
		case 7:
			put_prepared_spell(level7->prepare());
			break;
		case 8:
			put_prepared_spell(level8->prepare());
			break;
		case 9:
			put_prepared_spell(level9->prepare());
			break;
		default:
			QMessageBox::warning(this, "Error", "Funky program error, blort.");
	}
	

}

void Spells::put_prepared_spell(QString spell)
{
	if(spell != NULL)	
		activeSpells->addItem(spell);
}

void Spells::remove_prepared()
{
	activeSpells->takeItem(activeSpells->currentRow());	
}

void Spells::clear_prepared()
{
	activeSpells->clear();
}


/**************************************/
/*            SpellList               */
/**************************************/

SpellList::SpellList(QWidget *parent, int spell_level)
{
	level = spell_level;
	QGridLayout *layout = new QGridLayout;
	
	QTableWidgetItem *col1 = new QTableWidgetItem("Level "+QString::number(spell_level)+" Spells");
	
	table = new QTableWidget(0, 1);
	table->setMaximumWidth(260);
	table->setMinimumWidth(260);
	table->setHorizontalHeaderItem(0, col1);
	table->setColumnWidth(0, 240);
	
	num_items = 0;
	
	layout->addWidget(table, 0, 0, 1, 1, Qt::AlignLeft);
	
	setLayout(layout);

}

void SpellList::add()
{
	num_items++;
	table->setRowCount(num_items);
	
	QTableWidgetItem *temp_item;
	QCheckBox *checkbox = new QCheckBox;
	checkbox->setCheckState(Qt::Unchecked);
	
	temp_item = new QTableWidgetItem("Spell");
	table->setItem(num_items-1, 0, temp_item);
	
	table->setCellWidget(num_items-1, 1, checkbox);
	
}

void SpellList::remove()
{	
	if(table->currentItem() == NULL)
		return;
		
	int current_row = table->currentRow();
	
	QTableWidgetItem *temp_item = table->item(table->currentRow(), 0);
	QString creme_de_la_text = temp_item->text(); 

	table->removeRow(table->currentRow());
	num_items--;
	
	table->setCurrentCell(current_row, 0);

}

void SpellList::move_up()
{

	if(table->currentItem() == NULL)
		return;

	if(table->currentRow() == 0)
		return;

	int current_row = table->currentRow();
	QTableWidgetItem *old_item;
	QTableWidgetItem *new_item;
	QString current_text;
	
	table->insertRow(current_row-1);
	
	current_row++;
	
	old_item = table->item(current_row, 0);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row-2, 0, new_item);
	
	table->removeRow(current_row);
	table->setCurrentCell(current_row-2, 0);
	
}

void SpellList::move_down()
{

	if(table->currentItem() == NULL)
		return;
		
	if(table->currentRow() == num_items-1)
		return;

	int current_row = table->currentRow();
	QTableWidgetItem *old_item;
	QTableWidgetItem *new_item;
	QString current_text;
	
	table->insertRow(current_row+2);
	
	old_item = table->item(current_row, 0);
	new_item = new QTableWidgetItem(old_item->text());
	table->setItem(current_row+2, 0, new_item);
	
	table->removeRow(current_row);
	table->setCurrentCell(current_row+1, 0);

}

QString SpellList::prepare()
{
	if(table->currentRow() != -1)	
		return table->item(table->currentRow(), 0)->text();
	else
		return NULL;
}

QByteArray* SpellList::return_data_bytearray()
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
		
	
	}
	
	hash["num_items"] = QString::number(num_items);
	
	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    
    return hasharray;

}

void SpellList::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadWrite);
	in >> hash;
	
	table->clearContents();
	table->setRowCount(0);
	
	if (hash.isEmpty()) 
    {
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
		
		}
	
	}

}

