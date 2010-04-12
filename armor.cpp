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

#include "armor.h"

Armor::Armor(QWidget *parent)
{
	QVBoxLayout *layout = new QVBoxLayout; //main layout of armor widget
	//sub layouts for each piece of armor
	QGridLayout *armor_l = new QGridLayout; 
	QHBoxLayout *proItem1_1 = new QHBoxLayout;
	QHBoxLayout *proItem1_2 = new QHBoxLayout;
	QHBoxLayout *proItem2_1 = new QHBoxLayout;
	QHBoxLayout *proItem2_2 = new QHBoxLayout;
	//blank labels for spacing (bad practice, I know, I know. Easter eggs, right?)
	QLabel *zidane = new QLabel("  ");
	zidane->setToolTip("Zidane");
	QLabel *squall = new QLabel("  ");
	squall->setToolTip("Squall");
	QLabel *cloud = new QLabel("  ");
	cloud->setToolTip("Cloud");
	WIDTH = 50; //convenient for setting lineEdit widths
	
	//make the heap do some work
	armor_name_label = new QLabel("<b>Armor:</b> ");
	armor_name = new QLineEdit;
	armor_name->setMaximumWidth(300);
	armor_type_label = new QLabel("Type: ");
	armor_type = new QLineEdit;
	armor_type->setMaximumWidth(WIDTH);
	armor_ac_bonus_label = new QLabel("AC Bonus: ");
	armor_ac_bonus = new QLineEdit;
	armor_ac_bonus->setMaximumWidth(WIDTH);
	max_dex_label = new QLabel("Max Dex: ");
	max_dex = new QLineEdit;
	max_dex->setMaximumWidth(WIDTH);
	armor_check_penalty_label = new QLabel("Check Penalty: ");
	armor_check_penalty = new QLineEdit;
	armor_check_penalty->setMaximumWidth(WIDTH);
	armor_spell_faliure_label = new QLabel("Spell Faliure: ");
	armor_spell_faliure = new QLineEdit;
	armor_spell_faliure->setMaximumWidth(WIDTH);
	armor_speed_label = new QLabel("Speed: ");
	armor_speed = new QLineEdit;
	armor_speed->setMaximumWidth(WIDTH);
	armor_weight_label = new QLabel("Weight: ");
	armor_weight = new QLineEdit;
	armor_weight->setMaximumWidth(WIDTH);
	armor_special_properties_label = new QLabel("Special Properties: ");
	armor_special_properties = new QLineEdit;
	armor_special_properties->setMaximumWidth(WIDTH);
	
	armor_l->addWidget(armor_name_label, 0, 0, 1, 1);
	armor_l->addWidget(armor_name, 0, 1, 1, 7);
	armor_l->addWidget(armor_type_label, 1, 0, 1, 1);
	armor_l->addWidget(armor_type, 1, 1, 1, 1);
	armor_l->addWidget(armor_ac_bonus_label, 1, 2, 1, 1);
	armor_l->addWidget(armor_ac_bonus, 1, 3, 1, 1);
	armor_l->addWidget(max_dex_label, 1, 4, 1, 1);
	armor_l->addWidget(max_dex, 1, 5, 1, 1);
	armor_l->addWidget(armor_check_penalty_label, 1, 6, 1, 1);
	armor_l->addWidget(armor_check_penalty, 1, 7, 1, 1);
	armor_l->addWidget(armor_spell_faliure_label, 2, 0, 1, 1);
	armor_l->addWidget(armor_spell_faliure, 2, 1, 1, 1);
	armor_l->addWidget(armor_speed_label, 2, 2, 1, 1);
	armor_l->addWidget(armor_speed, 2, 3, 1, 1);
	armor_l->addWidget(armor_weight_label, 2, 4, 1, 1);
	armor_l->addWidget(armor_weight, 2, 5, 1, 1);
	armor_l->addWidget(armor_special_properties_label, 2, 6, 1, 1);
	armor_l->addWidget(armor_special_properties, 2, 7, 1, 1);
	armor_l->addWidget(zidane, 3, 0, 1, 1);
	
	
	shield_name_label = new QLabel("<b>Shield:</b> ");
	shield_name = new QLineEdit;
	shield_name->setMaximumWidth(300);
	shield_ac_bonus_label = new QLabel("AC Bonus: ");
	shield_ac_bonus = new QLineEdit;
	shield_ac_bonus->setMaximumWidth(WIDTH);
	shield_weight_label = new QLabel("Weight: ");
	shield_weight = new QLineEdit;	
	shield_weight->setMaximumWidth(WIDTH);
	shield_check_penalty_label = new QLabel("Check Penalty: ");
	shield_check_penalty = new QLineEdit;
	shield_check_penalty->setMaximumWidth(WIDTH);
	shield_spell_faliure_label = new QLabel("Spell Faliure: ");
	shield_spell_faliure = new QLineEdit;
	shield_spell_faliure->setMaximumWidth(WIDTH);
	shield_special_properties_label = new QLabel("Special Properties: ");
	shield_special_properties = new QLineEdit;
	shield_special_properties->setMaximumWidth(WIDTH);
	
	armor_l->addWidget(shield_name_label, 4, 0, 1, 1);
	armor_l->addWidget(shield_name, 4, 1, 1, 5);
	armor_l->addWidget(shield_ac_bonus_label, 5, 0, 1, 1);
	armor_l->addWidget(shield_ac_bonus, 5, 1, 1, 1);
	armor_l->addWidget(shield_weight_label, 5, 2, 1, 2);
	armor_l->addWidget(shield_weight, 5, 4, 1, 1);
	armor_l->addWidget(shield_check_penalty_label, 5, 5, 1, 2, Qt::AlignRight);
	armor_l->addWidget(shield_check_penalty, 5, 7, 1, 1);
	armor_l->addWidget(shield_spell_faliure_label, 6, 0, 1, 1);
	armor_l->addWidget(shield_spell_faliure, 6, 1, 1, 1);
	armor_l->addWidget(shield_special_properties_label, 6, 2, 1, 2);
	armor_l->addWidget(shield_special_properties, 6, 4, 1, 1);
	armor_l->addWidget(squall, 7, 0, 1, 1);
	
	pro_item_1_label = new QLabel("<b>Protective Item I:</b> ");
	pro_item_1 = new QLineEdit;
	pro_item_1->setMinimumWidth(300);
	pro_item_1_ac_bonus_label = new QLabel("AC Bonus: ");
	pro_item_1_ac_bonus = new QLineEdit;
	pro_item_1_ac_bonus->setMaximumWidth(WIDTH);
	pro_item_1_weight_label = new QLabel("Weight: ");
	pro_item_1_weight = new QLineEdit;
	pro_item_1_weight->setMaximumWidth(WIDTH);
	pro_item_1_special_properties_label = new QLabel("Special Properties: ");	
	pro_item_1_special_properties = new QLineEdit;	
	pro_item_1_special_properties->setMaximumWidth(WIDTH);	
	
	proItem1_1->addWidget(pro_item_1_label);
	proItem1_1->addWidget(pro_item_1);
	proItem1_1->addStretch(1);
	proItem1_2->addWidget(pro_item_1_ac_bonus_label);
	proItem1_2->addWidget(pro_item_1_ac_bonus);
	proItem1_2->addWidget(pro_item_1_weight_label);
	proItem1_2->addWidget(pro_item_1_weight);
	proItem1_2->addWidget(pro_item_1_special_properties_label);
	proItem1_2->addWidget(pro_item_1_special_properties);
	proItem1_2->addStretch(1);
	
	pro_item_2_label = new QLabel("<b>Protective Item II:</b> ");
	pro_item_2 = new QLineEdit;
	pro_item_2->setMinimumWidth(300);
	pro_item_2_ac_bonus_label = new QLabel("AC Bonus: ");
	pro_item_2_ac_bonus = new QLineEdit;
	pro_item_2_ac_bonus->setMaximumWidth(WIDTH);
	pro_item_2_weight_label = new QLabel("Weight: ");
	pro_item_2_weight = new QLineEdit;
	pro_item_2_weight->setMaximumWidth(WIDTH);
	pro_item_2_special_properties_label = new QLabel("Special Properties: ");
	pro_item_2_special_properties = new QLineEdit;	
	pro_item_2_special_properties->setMaximumWidth(WIDTH);
	
	proItem2_1->addWidget(pro_item_2_label);
	proItem2_1->addWidget(pro_item_2);
	proItem2_1->addStretch(1);
	proItem2_2->addWidget(pro_item_2_ac_bonus_label);
	proItem2_2->addWidget(pro_item_2_ac_bonus);
	proItem2_2->addWidget(pro_item_2_weight_label);
	proItem2_2->addWidget(pro_item_2_weight);
	proItem2_2->addWidget(pro_item_2_special_properties_label);
	proItem2_2->addWidget(pro_item_2_special_properties);
	proItem2_2->addStretch(1);
	
	layout->addLayout(armor_l, Qt::AlignLeft);
	layout->addLayout(proItem1_1);
	layout->addLayout(proItem1_2);
	layout->addWidget(cloud); //cloud is purely for spacing (and easter eggs!)
	layout->addLayout(proItem2_1);
	layout->addLayout(proItem2_2);
	layout->addStretch(1);
	
	setLayout(layout);

}

//return_data_bytearray() saves the text of all the elements in a QHash, which then is written to a
//QByteArray with QDataStream.
//it then returns a pointer to that QByteArray

QByteArray* Armor::return_data_bytearray()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::WriteOnly);
    
	hash["armor_name"] = armor_name->text();
	hash["armor_type"] = armor_type->text();	
	hash["armor_ac_bonus"] = armor_ac_bonus->text();
	hash["max_dex"] = max_dex->text();
	hash["armor_check_penalty"] = armor_check_penalty->text();
	hash["armor_spell_faliure"] = armor_spell_faliure->text();
	hash["armor_speed"] = armor_speed->text();
	hash["armor_weight"] = armor_weight->text();
	hash["armor_special_properties"] = armor_special_properties->text();
	
	hash["shield_name"] = shield_name->text();	
	hash["shield_ac_bonus"] = shield_ac_bonus->text();
	hash["shield_weight"] = shield_weight->text();
	hash["shield_check_penalty"] = shield_check_penalty->text();
	hash["shield_spell_faliure"] = shield_spell_faliure->text();
	hash["shield_special_properties"] = shield_special_properties->text();

	hash["pro_item_1"] = pro_item_1->text();
	hash["pro_item_1_ac_bonus"] = pro_item_1_ac_bonus->text();
	hash["pro_item_1_weight"] = pro_item_1_weight->text();
	hash["pro_item_1_special_properties"] = pro_item_1_special_properties->text();		
	
	hash["pro_item_2"] = pro_item_2->text();
	hash["pro_item_2_ac_bonus"] = pro_item_2_ac_bonus->text();
	hash["pro_item_2_weight"] = pro_item_2_weight->text();
	hash["pro_item_2_special_properties"] = pro_item_2_special_properties->text();
	
	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    
    return hasharray;



}

//load() takes an argument of a QByteArray that contains the previously saved QHash

void Armor::load(QByteArray *parent_byte)
{

	QDataStream in(parent_byte, QIODevice::ReadWrite);
	in >> hash;
    
    if (hash.isEmpty()) 
    {
    	QMessageBox::information(this, tr("Blank Areas"), tr("No Armor information was saved to this file."));
    } 
    else
    {
    	armor_name->setText(hash["armor_name"]);
		armor_type->setText(hash["armor_type"]);	
		armor_ac_bonus->setText(hash["armor_ac_bonus"]);
		max_dex->setText(hash["max_dex"]);
		armor_check_penalty->setText(hash["armor_check_penalty"]);
		armor_spell_faliure->setText(hash["armor_spell_faliure"]);
		armor_speed->setText(hash["armor_speed"]);
		armor_weight->setText(hash["armor_weight"]);
		armor_special_properties->setText(hash["armor_special_properties"]);
		
		shield_name->setText(hash["shield_name"]);	
		shield_ac_bonus->setText(hash["shield_ac_bonus"]);
		shield_weight->setText(hash["shield_weight"]);
		shield_check_penalty->setText(hash["shield_check_penalty"]);
		shield_spell_faliure->setText(hash["shield_spell_faliure"]);
		shield_special_properties->setText(hash["shield_special_properties"]);
		
		pro_item_1->setText(hash["pro_item_1"]);
		pro_item_1_ac_bonus->setText(hash["pro_item_1_ac_bonus"]);
		pro_item_1_weight->setText(hash["pro_item_1_weight"]);
		pro_item_1_special_properties->setText(hash["pro_item_1_special_properties"]);		
		
		pro_item_2->setText(hash["pro_item_2"]);
		pro_item_2_ac_bonus->setText(hash["pro_item_2_ac_bonus"]);
		pro_item_2_weight->setText(hash["pro_item_2_weight"]);
		pro_item_2_special_properties->setText(hash["pro_item_2_special_properties"]);	
    
    }

}
