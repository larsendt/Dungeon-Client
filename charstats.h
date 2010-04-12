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
	charstats contains much of the information required for the mechanics of D&D gameplay
*/

#ifndef CHARSTATS_H
#define CHARSTATS_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QToolTip>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include <QMap>
#include <QHash>

class CharStats : public QWidget
{
	Q_OBJECT
	
	public: 
		CharStats(QWidget *parent = 0);
		QByteArray* return_data_bytearray();
		void load(QByteArray *parent_byte);
		
	private slots:
		void fill();
		
	private:
		QHash <QString, QString> hash;
		QPushButton *autofill;
		QLabel *plus_label;
		QLabel *minus_label;
		QLabel *equals_label;
	
		QLabel *cur_hp_label;
		QLineEdit *cur_hp;
		QLabel *base_hp_label;
		QLineEdit *base_hp;
		
		QLabel *str_label;
		QLabel *cur_str_label;
		QLabel *cur_str_mod;
		QLineEdit *cur_str;
		QLabel *base_str_mod;
		QLineEdit *base_str;
		
		QLabel *dex_label;
		QLabel *cur_dex_label;
		QLabel *cur_dex_mod;
		QLineEdit *cur_dex;
		QLabel *base_dex_mod;
		QLineEdit *base_dex;
		
		QLabel *con_label;
		QLabel *cur_con_label;
		QLabel *cur_con_mod;
		QLineEdit *cur_con;
		QLabel *base_con_mod;
		QLineEdit *base_con;
		
		QLabel *int_label;
		QLabel *cur_int_label;
		QLabel *cur_int_mod;
		QLineEdit *cur_int;
		QLabel *base_int_mod;
		QLineEdit *base_int;
		
		QLabel *wis_label;
		QLabel *cur_wis_label;
		QLabel *cur_wis_mod;
		QLineEdit *cur_wis;;
		QLabel *base_wis_mod;
		QLineEdit *base_wis;
		
		QLabel *cha_label;
		QLabel *cur_cha_label;
		QLabel *cur_cha_mod;
		QLineEdit *cur_cha;
		QLabel *base_cha_mod;
		QLineEdit *base_cha;
		
		QLabel *ac_label;
		QLabel *ac_dex_mod;
		QLineEdit *ac;
		QLabel *ten_label;
		QLineEdit *armor_bonus;
		QLineEdit *shield_bonus;
		QLineEdit *ac_size_mod;
		QLineEdit *nat_armor;
		QLineEdit *deflection_mod;
		QLineEdit *ac_misc_mod;
		
		QLabel *touch_ac_label;
		QLineEdit *touch_ac;
		
		QLabel *flat_ac_label;
		QLineEdit *flat_ac;
		
		QLabel *init_label;
		QLabel *init_plus;
		QLabel *init_equals;
		QLineEdit *init;
		QLineEdit *init_misc;
		QLabel *init_dex;
		
		QLabel *fort_save_label;
		QLabel *fort_equals;
		QLabel *fort_plus;
		QLineEdit *fort_save;
		QLineEdit *fort_base_save;
		QLabel *fort_con;
		QLineEdit *fort_magic;
		QLineEdit *fort_misc;
		QLineEdit *fort_misc_temp;
		
		QLabel *will_save_label;
		QLabel *will_equals;
		QLabel *will_plus;
		QLineEdit *will_save;
		QLineEdit *will_base_save;
		QLabel *will_wis;
		QLineEdit *will_magic;
		QLineEdit *will_misc;
		QLineEdit *will_misc_temp;
		
		QLabel *ref_save_label;
		QLabel *ref_equals;
		QLabel *ref_plus;
		QLineEdit *ref_save;
		QLineEdit *ref_base_save;
		QLabel *ref_dex;
		QLineEdit *ref_magic;
		QLineEdit *ref_misc;
		QLineEdit *ref_misc_temp;
		
		QLabel *base_att_label;
		QLineEdit *base_att;
		
		QLabel *spell_resist_label;
		QLineEdit *spell_resist;
		
		QLabel *size_mod_label;
		QLineEdit *size_mod;
		
		QLabel *grapple_label;
		QLabel *grapple_equals;
		QLabel *grapple_str;
		QLabel *grapple_plus;
		QLineEdit *grapple;
		QLineEdit *grapple_base_att;
		QLineEdit *grapple_size_mod;
		QLineEdit *grapple_misc_mod;

};


#endif
