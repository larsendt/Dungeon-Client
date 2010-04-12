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

#include "diceroller.h"
#include <ctime>
#include <cstdlib>
#include <QGroupBox>

Diceroller::Diceroller(QWidget *parent)
	:QWidget(parent)
{
	totalint = 0;
	QGridLayout *diceLayout = new QGridLayout();
	QGroupBox *box = new QGroupBox(this);
	box->setLayout(diceLayout);
	
	QHBoxLayout *totallayout = new QHBoxLayout();
	QHBoxLayout *dielayout = new QHBoxLayout();
	QHBoxLayout *rolllayout = new QHBoxLayout();
	QHBoxLayout *clearlayout = new QHBoxLayout();
	QVBoxLayout *dynlabel = new QVBoxLayout();
	
	roll_button = new QPushButton("Roll");
	QPushButton *clear_button = new QPushButton("Clear");
	die_size_label = new QLabel("Die Size: ");
  	multiplier_label = new QLabel("Multiplier: ");
  	die_size = new QLineEdit("20");
  	die_size->setMaximumSize(60, 25);
  	multiplier = new QLineEdit("1");
  	multiplier->setMaximumSize(60, 25);
  	output = new QTextBrowser();
  	you_rolled = new QLabel("You rolled: ");
  	xdx = new QLabel("0d0");
  	total_label = new QLabel("Total: ");
  	total = new QLabel("0");
  	notes = new QTextEdit("Some free space for miscellaneous notes.");
  	clear_notes = new QPushButton("Clear");
  	notes->setMinimumSize(330, 250);
  	
  	roll_button->setMinimumSize(120, 25);
  	clear_button->setMinimumSize(120, 25);
  	
  	rolllayout->addWidget(roll_button);
  	rolllayout->addStretch(1);
  	clearlayout->addWidget(clear_button);
  	clearlayout->addStretch(1);
  	
  	dielayout->addWidget(you_rolled);
  	dielayout->addWidget(xdx);
  	dielayout->addStretch(1);
  	totallayout->addWidget(total_label);
  	totallayout->addWidget(total);
  	totallayout->addStretch(1);
  	
  	dynlabel->addLayout(dielayout);
  	dynlabel->addLayout(totallayout);
  	dynlabel->addStretch(1);

	diceLayout->addWidget(multiplier_label, 0, 0, 1, 1);
	diceLayout->addWidget(multiplier, 0, 1, 1, 1);
	diceLayout->addWidget(die_size_label, 1, 0, 1, 1);
	diceLayout->addWidget(die_size, 1, 1, 1, 1);
	diceLayout->addLayout(rolllayout, 0, 2, 1, 1);
	diceLayout->addLayout(clearlayout, 1, 2, 1, 1);
	diceLayout->addWidget(notes, 0, 3, 3, 1);
	diceLayout->addWidget(clear_notes, 3, 3, 1, 1);
	diceLayout->addLayout(dynlabel, 2, 2, 1, 1);
	diceLayout->addWidget(output, 2, 0, 2, 2);
	
	connect(roll_button, SIGNAL(clicked()), SLOT(roll()));
	connect(clear_button, SIGNAL(clicked()), SLOT(clear()));
	connect(clear_notes, SIGNAL(clicked()), SLOT(burn_notes()));
	
	setLayout(diceLayout);

}

void Diceroller::burn_notes()
{
	notes->setText("");
}

void Diceroller::roll()
{
	int die;
  	int mult = multiplier->text().toInt();

  	srand(time(NULL));
  	
  	xdx->setText((multiplier->text())+"d"+(die_size->text()));
  	output->append("Roll: "+(multiplier->text())+"d"+(die_size->text()));
  	
  	for(int i = 0; i < mult; i++)
  	{ 
  		die = die_size->text().toInt();
  		die = (rand()%die) + 1;
  		totalint += die;
  		output->append(QString::number(die));
  	}
  	total->setText(QString::number(totalint));
  	output->append("Total: "+QString::number(totalint));
  	output->append("");
  	totalint = 0;
  		
}

QByteArray* Diceroller::return_data_bytearray()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::WriteOnly);
	
	hash["output"] = output->toPlainText();
	hash["notes"] = notes->toPlainText();
	
	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    
    return hasharray;

}

void Diceroller::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadOnly);
	in >> hash;
    
    output->setText(hash["output"]);
    notes->setText(hash["notes"]);

}

void Diceroller::clear()
{
	output->setText("");
	xdx->setText("0d0");
	total->setText("0");
	totalint = 0;
}

void Diceroller::set_dm_ip(QString ip)
{
	dm_ip = ip;
}
