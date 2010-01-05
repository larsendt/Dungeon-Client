#include "weapon.h"

Weapon::Weapon(QWidget *parent)
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


