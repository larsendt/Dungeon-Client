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
#include "weapon.h"

WeaponTab::WeaponTab(QWidget *parent)
    :QWidget(parent)
{
	weapon_label = new QLabel("Weapon: ");
	weapon = new QLineEdit();
	QGridLayout *wepstat2 = new QGridLayout;
	QHBoxLayout *wepstat = new QHBoxLayout;
	att_bonus_label = new QLabel("Attack Bonus: ");
	att_bonus = new QLineEdit();
	att_bonus->setMaximumWidth(50);
	damage_label = new QLabel("Damage: ");
	damage = new QLineEdit();
	damage->setMaximumWidth(50);
	critical_label = new QLabel("Critical: ");
	critical = new QLineEdit();
	critical->setMaximumWidth(50);
	range_label = new QLabel("Range: ");
	range = new QLineEdit();
	range->setMaximumWidth(50);
	wepstat2->addWidget(att_bonus_label, 0, 0, 1, 1, Qt::AlignRight);
	wepstat2->addWidget(att_bonus, 0, 1, 1, 1);
	wepstat2->addWidget(damage_label, 0, 2, 1, 1, Qt::AlignRight);
	wepstat2->addWidget(damage, 0, 3, 1, 1);
	wepstat2->addWidget(critical_label, 1, 0, 1, 1, Qt::AlignRight);
	wepstat2->addWidget(critical, 1, 1, 1, 1);
	wepstat2->addWidget(range_label, 1, 2, 1, 1, Qt::AlignRight);
	wepstat2->addWidget(range, 1, 3, 1, 1);
	wepstat->addLayout(wepstat2);
	wepstat->addStretch(1);
	type_label = new QLabel("Type: ");
	type = new QLineEdit();
	notes_label = new QLabel("Notes: ");
	notes = new QTextEdit();
	//notes->SetMaximumSize(300, 100);
	ammo_label = new QLabel("Ammo: ");
	ammo = new QLineEdit();
	ammo_num_label = new QLabel("Quantity: ");
	ammo_num = new QLineEdit();
	ammo_num->setMaximumWidth(50);
	
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(weapon_label, 0, 0, 1, 1, Qt::AlignRight);
	layout->addWidget(weapon, 0, 1, 1, 3);
	layout->addLayout(wepstat, 1, 0, 1, 3);
	layout->addWidget(type_label, 2, 0, 1, 1, Qt::AlignRight);
	layout->addWidget(type, 2, 1, 1, 3);
	layout->addWidget(notes_label, 3, 0, 1, 1, Qt::AlignRight);
	layout->addWidget(notes, 3, 1, 1, 3);
	layout->addWidget(ammo_label, 4, 0, 1, 1, Qt::AlignRight);
	layout->addWidget(ammo, 4, 1, 1, 1);
	layout->addWidget(ammo_num_label, 4, 2, 1, 1, Qt::AlignRight);
	layout->addWidget(ammo_num, 4, 3, 1, 1);
	
	setLayout(layout);
 
}

QByteArray* WeaponTab::return_data_bytearray()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::WriteOnly);
	
	hash["weapon"] = weapon->text();
	hash["att_bonus"] = att_bonus->text();
	hash["damage"] = damage->text();
	hash["critical"] = critical->text();
	hash["range"] = range->text();
	hash["type"] = type->text();
	hash["notes"] = notes->toPlainText();
	hash["ammo"] = ammo->text();
	hash["ammo_num"] = ammo_num->text();

	out.setVersion(QDataStream::Qt_4_5);	
	out << hash;
	
	return hasharray;
}

void WeaponTab::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadOnly);
	
	in >> hash;
	
	weapon->setText(hash["weapon"]);
	att_bonus->setText(hash["att_bonus"]);
	damage->setText(hash["damage"]);
	critical->setText(hash["critical"]);
	range->setText(hash["range"]);
	type->setText(hash["type"]);
 	notes->setText(hash["notes"]);
	ammo->setText(hash["ammo"]);
	ammo_num->setText(hash["ammo_num"]	);
	
}

Weapon::Weapon(QWidget *parent)
{
	QHBoxLayout *layout = new QHBoxLayout;
	tabs = new QTabWidget;
	tabs->setTabPosition(QTabWidget::West);
	
	weapon0 = new WeaponTab;
	weapon1 = new WeaponTab;
	weapon2 = new WeaponTab;
	weapon3 = new WeaponTab;
	weapon4 = new WeaponTab;
	
	tabs->addTab(weapon0, "Weapon 1");
	tabs->addTab(weapon1, "Weapon 2");
	tabs->addTab(weapon2, "Weapon 3");
	tabs->addTab(weapon3, "Weapon 4");
	tabs->addTab(weapon4, "Weapon 5");
		
	layout->addWidget(tabs);
	setLayout(layout);

}

QByteArray* Weapon::return_data_bytearray()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::WriteOnly);
	
	hash["weapon0"] = *weapon0->return_data_bytearray();	
	hash["weapon1"] = *weapon1->return_data_bytearray();
	hash["weapon2"] = *weapon2->return_data_bytearray();
	hash["weapon3"] = *weapon3->return_data_bytearray();
	hash["weapon4"] = *weapon4->return_data_bytearray();

	out.setVersion(QDataStream::Qt_4_5);
	out << hash;
	
	return hasharray;
}

void Weapon::load(QByteArray* parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadOnly);
	in >> hash;
	
	weapon0->load(&hash["weapon0"]);
	weapon1->load(&hash["weapon1"]);
	weapon2->load(&hash["weapon2"]);
	weapon3->load(&hash["weapon3"]);
	weapon4->load(&hash["weapon4"]);
	
}
