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

#ifndef ARMOR_H
#define ARMOR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDataStream>
#include <QMessageBox>
#include <QHash>
#include <QByteArray>

class Armor : public QWidget
{
	Q_OBJECT
	
	public:
		Armor(QWidget *parent = 0);
		QByteArray* return_data_bytearray();
		void load(QByteArray *parent_byte);
		
	private slots:
	
	private:
		int WIDTH;
		QHash <QString, QString> hash; //for saving information
		
		QLabel *armor_name_label;
		QLineEdit *armor_name;
		QLabel *armor_type_label;
		QLineEdit *armor_type;
		QLabel *armor_ac_bonus_label;
		QLineEdit *armor_ac_bonus;
		QLabel *max_dex_label;
		QLineEdit *max_dex;
		QLabel *armor_check_penalty_label;
		QLineEdit *armor_check_penalty;
		QLabel *armor_spell_faliure_label;
		QLineEdit *armor_spell_faliure;
		QLabel *armor_speed_label;
		QLineEdit *armor_speed;
		QLabel *armor_weight_label;
		QLineEdit *armor_weight;
		QLabel *armor_special_properties_label;
		QLineEdit *armor_special_properties;
		
		QLabel *shield_name_label;
		QLineEdit *shield_name;
		QLabel *shield_ac_bonus_label;
		QLineEdit *shield_ac_bonus;
		QLabel *shield_weight_label;
		QLineEdit *shield_weight;
		QLabel *shield_check_penalty_label;
		QLineEdit *shield_check_penalty;
		QLabel *shield_spell_faliure_label;
		QLineEdit *shield_spell_faliure;
		QLabel *shield_special_properties_label;
		QLineEdit *shield_special_properties;
		
		QLabel *pro_item_1_label;
		QLineEdit *pro_item_1;
		QLabel *pro_item_1_ac_bonus_label;
		QLineEdit *pro_item_1_ac_bonus;
		QLabel *pro_item_1_weight_label;
		QLineEdit *pro_item_1_weight;
		QLabel *pro_item_1_special_properties_label;
		QLineEdit *pro_item_1_special_properties;		
		
		QLabel *pro_item_2_label;
		QLineEdit *pro_item_2;
		QLabel *pro_item_2_ac_bonus_label;
		QLineEdit *pro_item_2_ac_bonus;
		QLabel *pro_item_2_weight_label;
		QLineEdit *pro_item_2_weight;
		QLabel *pro_item_2_special_properties_label;
		QLineEdit *pro_item_2_special_properties;	
};


#endif
