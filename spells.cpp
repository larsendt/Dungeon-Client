#include "spells.h"

Spells::Spells(QWidget *parent)
{
	QHBoxLayout *layout = new QHBoxLayout;
	QVBoxLayout *active_l = new QVBoxLayout;
	QHBoxLayout *button_l = new QHBoxLayout;
	
	QTabWidget *tabWidget = new QTabWidget;
	QListWidget *activeSpells = new QListWidget;
	QLabel *activeLabel = new QLabel("<b>Prepared Spells</b>");
	QPushButton *remove = new QPushButton("Remove");
	QPushButton *clear = new QPushButton ("Clear All");
	
	button_l->addWidget(remove);
	button_l->addWidget(clear);
	
	tabWidget->setTabPosition(QTabWidget::West);
	
	active_l->addWidget(activeLabel);
	active_l->addWidget(activeSpells);
	active_l->addLayout(button_l);
	
	SpellList *level0 = new SpellList(this, 0);
	SpellList *level1 = new SpellList(this, 1);
	SpellList *level2 = new SpellList(this, 2);
	SpellList *level3 = new SpellList(this, 3);
	SpellList *level4 = new SpellList(this, 4);
	SpellList *level5 = new SpellList(this, 5);
	SpellList *level6 = new SpellList(this, 6);
	SpellList *level7 = new SpellList(this, 7);
	SpellList *level8 = new SpellList(this, 8);
	SpellList *level9 = new SpellList(this, 9);
	
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
	layout->addLayout(active_l);
	
	setLayout(layout);

}

/**************************************/
/*            SpellList               */
/**************************************/

SpellList::SpellList(Spells *parent, int spell_level)
{
	level = spell_level;
	QGridLayout *layout = new QGridLayout;
	QVBoxLayout *button_l = new QVBoxLayout;
	
	parent_widget = parent;
	
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
	
	button_l->addWidget(add_button);
	button_l->addWidget(remove_button);
	button_l->addWidget(up_button);
	button_l->addWidget(down_button);
	button_l->addWidget(prepare_button);
	button_l->addStretch(1);
	
	QTableWidgetItem *col1 = new QTableWidgetItem("Level "+QString::number(spell_level)+" Spells");
	
	
	table = new QTableWidget(0, 1);
	table->setMaximumWidth(260);
	table->setMinimumWidth(260);
	table->setHorizontalHeaderItem(0, col1);
	table->setColumnWidth(0, 240);
	
	num_items = 0;
	
	layout->addWidget(table, 0, 0, 1, 1, Qt::AlignLeft);
	layout->addLayout(button_l, 0, 1, 1, 1);
	
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
	{
		QMessageBox::warning(this, tr("Nothing Selected"), tr("Please select a spell to delete."));
		return;
		
	}
	
	int current_row = table->currentRow();
	
	QTableWidgetItem *temp_item = table->item(table->currentRow(), 0);
	QString creme_de_la_text = temp_item->text(); 
		
	int button = QMessageBox::question(this, tr("Confirm Removal"), ("Are you sure you want to remove "+creme_de_la_text+"?"), QMessageBox::Yes | QMessageBox::No);

	if (button == QMessageBox::Yes) 
	{
		table->removeRow(table->currentRow());
		num_items--;
		
		QMessageBox::information(this, tr("Removal Successful"), (""+creme_de_la_text+" has been removed from your spell list."));
	}
	
	table->setCurrentCell(current_row, 0);

}

void SpellList::move_up()
{

	if(table->currentItem() == NULL)
	{
		QMessageBox::warning(this, tr("Nothing Selected"), tr("Please select a spell to move."));
		return;
		
	}
	
	if(table->currentRow() == 0)
	{
		return;
	}

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
	{
		QMessageBox::warning(this, tr("Nothing Selected"), tr("Please select a spell to move."));
		return;
		
	}
	
	if(table->currentRow() == num_items-1)
	{
		return;
	}

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

void SpellList::prepare()
{
	QString *spell_name = new QString("Fireball!");
	int spell_level = 0;
	
	
	parent_widget->prepare(spell_name, spell_level);


}

QByteArray* SpellList::save()
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
