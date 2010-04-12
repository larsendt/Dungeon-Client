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

#include "charstats.h"
#include <cstring>

CharStats::CharStats(QWidget *parent)
{
	int WIDTH = 50;
	int HEIGHT = 25;
	
	QGroupBox *box = new QGroupBox(this);
	QVBoxLayout *layout = new QVBoxLayout();
	box->setLayout(layout);
	
	autofill = new QPushButton("Auto-Fill Fields");
	autofill->setMinimumSize(150, 50);
	autofill->setToolTip("Auto-fills most modifier fields.");
	autofill->setMaximumWidth(180);
	
	plus_label = new QLabel("+");
	minus_label = new QLabel("-");
	equals_label = new QLabel("=");

	cur_hp_label = new QLabel("Base Hitpoints: ");
	cur_hp = new QLineEdit();
	cur_hp->setMaximumSize(WIDTH, HEIGHT);
	base_hp_label = new QLabel ("Current Hitpoints: ");
	base_hp = new QLineEdit();
	base_hp->setMaximumSize(WIDTH, HEIGHT);
	
	QGridLayout *hp_layout = new QGridLayout;
	QHBoxLayout *hp_box = new QHBoxLayout;
	hp_layout->addWidget(cur_hp_label, 1, 0, 1, 1);
	hp_layout->addWidget(cur_hp, 1, 1, 1, 1);
	hp_layout->addWidget(base_hp_label, 0, 0, 1, 1);
	hp_layout->addWidget(base_hp, 0, 1, 1, 1);
	hp_box->addLayout(hp_layout);
	hp_box->addStretch(1);
	
/*******************************************/
/*     Stats go in the stat_box group      */
/*******************************************/
		
	str_label = new QLabel("STR: ");
	cur_str_label = new QLabel("Current STR: ");
	cur_str = new QLineEdit("0");
	cur_str->setToolTip("Current STR Total");
	
	cur_str_mod = new QLabel("-5");
	cur_str_mod->setToolTip("Current STR Modifier");
	
	base_str = new QLineEdit("0");
	base_str->setToolTip("Base STR Total");
	
	base_str_mod = new QLabel("-5");
	base_str_mod->setToolTip("Base STR Modifier");
	
	cur_str->setMaximumSize(WIDTH, HEIGHT);
	base_str->setMaximumSize(WIDTH, HEIGHT);
	cur_str_mod->setMaximumSize(WIDTH, HEIGHT);
	base_str_mod->setMaximumSize(WIDTH, HEIGHT);
	cur_str->setMinimumSize(WIDTH, HEIGHT);
	base_str->setMinimumSize(WIDTH, HEIGHT);
	cur_str_mod->setMinimumSize(WIDTH, HEIGHT);
	base_str_mod->setMinimumSize(WIDTH, HEIGHT);

	dex_label = new QLabel("DEX: ");
	cur_dex_label = new QLabel("Current DEX: ");
	cur_dex = new QLineEdit("0");
	cur_dex->setToolTip("Current DEX Total");
	
	cur_dex_mod = new QLabel("-5");
	cur_dex_mod->setToolTip("Current DEX Modifier");
	
	base_dex = new QLineEdit("0");
	base_dex->setToolTip("Base DEX Total");
	
	base_dex_mod = new QLabel("-5");
	base_dex_mod->setToolTip("Base DEX Modifier");
	
	cur_dex->setMaximumSize(WIDTH, HEIGHT);
	base_dex->setMaximumSize(WIDTH, HEIGHT);
	cur_dex_mod->setMaximumSize(WIDTH, HEIGHT);
	base_dex_mod->setMaximumSize(WIDTH, HEIGHT);
	cur_dex->setMinimumSize(WIDTH, HEIGHT);
	base_dex->setMinimumSize(WIDTH, HEIGHT);
	cur_dex_mod->setMinimumSize(WIDTH, HEIGHT);
	base_dex_mod->setMinimumSize(WIDTH, HEIGHT);
	
	con_label = new QLabel("CON: ");
	cur_con_label = new QLabel("Current CON: ");
	cur_con = new QLineEdit("0");
	cur_con->setToolTip("Current CON Total");
	
	cur_con_mod = new QLabel("-5");
	cur_con_mod->setToolTip("Current CON Modifier");
	
	base_con = new QLineEdit("0");
	base_con->setToolTip("Base CON Total");
	
	base_con_mod = new QLabel("-5");
	base_con_mod->setToolTip("Base CON Modifier");
	
	cur_con->setMaximumSize(WIDTH, HEIGHT);
	base_con->setMaximumSize(WIDTH, HEIGHT);
	cur_con_mod->setMaximumSize(WIDTH, HEIGHT);
	base_con_mod->setMaximumSize(WIDTH, HEIGHT);
	cur_con->setMinimumSize(WIDTH, HEIGHT);
	base_con->setMinimumSize(WIDTH, HEIGHT);
	cur_con_mod->setMinimumSize(WIDTH, HEIGHT);
	base_con_mod->setMinimumSize(WIDTH, HEIGHT);
	
	int_label = new QLabel("INT: ");
	cur_int_label = new QLabel("Current INT: ");
	cur_int = new QLineEdit("0");
	cur_int->setToolTip("Current INT Total");
	
	cur_int_mod = new QLabel("-5");
	cur_int_mod->setToolTip("Current INT Modifier");
	
	base_int = new QLineEdit("0");
	base_int->setToolTip("Base INT Total");
	
	base_int_mod = new QLabel("-5");
	base_int_mod->setToolTip("Base INT Modifier");
	
	cur_int->setMaximumSize(WIDTH, HEIGHT);
	base_int->setMaximumSize(WIDTH, HEIGHT);
	cur_int_mod->setMaximumSize(WIDTH, HEIGHT);
	base_int_mod->setMaximumSize(WIDTH, HEIGHT);	
	cur_int->setMinimumSize(WIDTH, HEIGHT);
	base_int->setMinimumSize(WIDTH, HEIGHT);
	cur_int_mod->setMinimumSize(WIDTH, HEIGHT);
	base_int_mod->setMinimumSize(WIDTH, HEIGHT);	

	wis_label = new QLabel("WIS: ");
	cur_wis_label = new QLabel("Current WIS: ");
	cur_wis = new QLineEdit("0");
	cur_wis->setToolTip("Current WIS Total");
	
	cur_wis_mod = new QLabel("-5");
	cur_wis_mod->setToolTip("Current WIS Modifier");
	
	base_wis = new QLineEdit("0");
	base_wis->setToolTip("Base WIS Total");
	
	base_wis_mod = new QLabel("-5");
	base_wis_mod->setToolTip("Base WIS Modifier");
	
	cur_wis->setMaximumSize(WIDTH, HEIGHT);
	base_wis->setMaximumSize(WIDTH, HEIGHT);
	cur_wis_mod->setMaximumSize(WIDTH, HEIGHT);
	base_wis_mod->setMaximumSize(WIDTH, HEIGHT);
	cur_wis->setMinimumSize(WIDTH, HEIGHT);
	base_wis->setMinimumSize(WIDTH, HEIGHT);
	cur_wis_mod->setMinimumSize(WIDTH, HEIGHT);
	base_wis_mod->setMinimumSize(WIDTH, HEIGHT);

	cha_label = new QLabel("CHA: ");
	cur_cha_label = new QLabel("Current CHA: ");
	cur_cha = new QLineEdit("0");
	cur_cha->setToolTip("Current CHA Total");
	
	cur_cha_mod = new QLabel("-5");
	cur_cha_mod->setToolTip("Current CHA Modifier");
	
	base_cha = new QLineEdit("0");
	base_cha->setToolTip("Base CHA Total");
	
	base_cha_mod = new QLabel("-5");
	base_cha_mod->setToolTip("Base CHA Modifier");
	
	base_cha->setMaximumSize(WIDTH, HEIGHT);
	cur_cha->setMaximumSize(WIDTH, HEIGHT);
	cur_cha_mod->setMaximumSize(WIDTH, HEIGHT);
	base_cha_mod->setMaximumSize(WIDTH, HEIGHT);
	base_cha->setMinimumSize(WIDTH, HEIGHT);
	cur_cha->setMinimumSize(WIDTH, HEIGHT);
	cur_cha_mod->setMinimumSize(WIDTH, HEIGHT);
	base_cha_mod->setMinimumSize(WIDTH, HEIGHT);
		
	/*end stat declaration*/
	/*begin stat layout*/
	
	QGridLayout *stat_layout = new QGridLayout;
	stat_layout->addWidget(str_label, 0, 0, 1, 1);
	stat_layout->addWidget(base_str, 0, 1, 1, 1);
	stat_layout->addWidget(base_str_mod, 0, 2, 1, 1);
	stat_layout->addWidget(cur_str_label, 0, 3, 1, 1);
	stat_layout->addWidget(cur_str, 0, 4, 1, 1);
	stat_layout->addWidget(cur_str_mod, 0, 5, 1, 1);
	stat_layout->addWidget(dex_label, 1, 0, 1, 1);
	stat_layout->addWidget(base_dex, 1, 1, 1, 1);
	stat_layout->addWidget(base_dex_mod, 1, 2, 1, 1);
	stat_layout->addWidget(cur_dex_label, 1, 3, 1, 1);
	stat_layout->addWidget(cur_dex, 1, 4, 1, 1);
	stat_layout->addWidget(cur_dex_mod, 1, 5, 1, 1);
	stat_layout->addWidget(con_label, 2, 0, 1, 1);
	stat_layout->addWidget(base_con, 2, 1, 1, 1);
	stat_layout->addWidget(base_con_mod, 2, 2, 1, 1);
	stat_layout->addWidget(cur_con_label, 2, 3, 1, 1);
	stat_layout->addWidget(cur_con, 2, 4, 1, 1);
	stat_layout->addWidget(cur_con_mod, 2, 5, 1, 1);
	stat_layout->addWidget(int_label, 3, 0, 1, 1);
	stat_layout->addWidget(base_int, 3, 1, 1, 1);
	stat_layout->addWidget(base_int_mod, 3, 2, 1, 1);
	stat_layout->addWidget(cur_int_label, 3, 3, 1, 1);
	stat_layout->addWidget(cur_int, 3, 4, 1, 1);
	stat_layout->addWidget(cur_int_mod, 3, 5, 1, 1);
	stat_layout->addWidget(wis_label, 4, 0, 1, 1);
	stat_layout->addWidget(base_wis, 4, 1, 1, 1);
	stat_layout->addWidget(base_wis_mod, 4, 2, 1, 1);
	stat_layout->addWidget(cur_wis_label, 4, 3, 1, 1);
	stat_layout->addWidget(cur_wis, 4, 4, 1, 1);
	stat_layout->addWidget(cur_wis_mod, 4, 5, 1, 1);
	stat_layout->addWidget(cha_label, 5, 0, 1, 1);
	stat_layout->addWidget(base_cha, 5, 1, 1, 1);
	stat_layout->addWidget(base_cha_mod, 5, 2, 1, 1);
	stat_layout->addWidget(cur_cha_label, 5, 3, 1, 1);
	stat_layout->addWidget(cur_cha, 5, 4, 1, 1);
	stat_layout->addWidget(cur_cha_mod, 5, 5, 1, 1);
	
	QHBoxLayout *stat_h_layout = new QHBoxLayout;
	stat_h_layout->addLayout(stat_layout, Qt::AlignLeft);
	stat_h_layout->addStretch(1);
	
	
	/*end stat layout *whew* */
	
	ac_label = new QLabel("Armor Class: ");
	ac = new QLineEdit();
	ten_label = new QLabel("10");
	ac->setMaximumSize(WIDTH, HEIGHT);
	armor_bonus = new QLineEdit();
	armor_bonus->setToolTip("Armor Bonus");
	shield_bonus = new QLineEdit();
	shield_bonus->setToolTip("Shield Bonus");
	ac_size_mod = new QLineEdit();
	ac_size_mod->setToolTip("Size Modifier");
	nat_armor = new QLineEdit();
	nat_armor->setToolTip("Natural Armor Bonus");
	deflection_mod = new QLineEdit();
	deflection_mod->setToolTip("Deflection Modifier");
	ac_misc_mod = new QLineEdit();
	ac_misc_mod->setToolTip("Miscellaneous Modifier");
	ac_dex_mod = new QLabel("-5");
	ac_dex_mod->setToolTip("Current DEX Modifer. Click 'Auto-Fill' to set.");
	armor_bonus->setMaximumSize(WIDTH, HEIGHT);
	shield_bonus->setMaximumSize(WIDTH, HEIGHT);
	ac_size_mod->setMaximumSize(WIDTH, HEIGHT);
	nat_armor->setMaximumSize(WIDTH, HEIGHT);
	deflection_mod->setMaximumSize(WIDTH, HEIGHT);
	ac_misc_mod->setMaximumSize(WIDTH, HEIGHT);
	
	touch_ac_label = new QLabel("Touch AC: ");
	touch_ac = new QLineEdit();
	touch_ac->setToolTip("Touch AC = AC - Armor, Shield, Nat Armor");
	touch_ac->setMaximumSize(WIDTH, HEIGHT);
	
	flat_ac_label = new QLabel("Flat Footed AC: ");
	flat_ac = new QLineEdit();	 
	flat_ac->setToolTip("Flat AC = AC - DEX Mod");
	flat_ac->setMaximumSize(WIDTH, HEIGHT);
	
	QHBoxLayout *ac_layout = new QHBoxLayout;
	QHBoxLayout *ac_layout2 = new QHBoxLayout;
	ac_layout->addWidget(ac_label);
	ac_layout->addWidget(ac);
	ac_layout->addWidget(equals_label);
	ac_layout->addWidget(ten_label);
	ac_layout->addWidget(plus_label);
	ac_layout->addWidget(armor_bonus);
	ac_layout->addWidget(shield_bonus);
	ac_layout->addWidget(ac_dex_mod);
	ac_layout->addWidget(ac_size_mod);
	ac_layout->addWidget(nat_armor);
	ac_layout->addWidget(deflection_mod);
	ac_layout->addWidget(ac_misc_mod);
	ac_layout->addStretch(1);
	ac_layout2->addWidget(touch_ac_label);
	ac_layout2->addWidget(touch_ac);
	ac_layout2->addWidget(flat_ac_label);
	ac_layout2->addWidget(flat_ac);
	ac_layout2->addStretch(1);
	
	init_label = new QLabel("Initiative: ");
	init = new QLineEdit();	
	init_equals = new QLabel("=");
	init_plus = new QLabel("+");
	init_misc = new QLineEdit();
	init_misc->setToolTip("Miscellaneous Modifier");
	init_dex = new  QLabel("-5");
	init_dex->setToolTip("Current DEX Modifier. Click 'Auto-Fill' to set.");
	init->setMaximumSize(WIDTH, HEIGHT);
	init_misc->setMaximumSize(WIDTH, HEIGHT);
	
	QHBoxLayout *init_layout = new QHBoxLayout;
	init_layout->addWidget(init_label);
	init_layout->addWidget(init);
	init_layout->addWidget(init_equals);
	init_layout->addWidget(init_dex);
	init_layout->addWidget(init_plus);
	init_layout->addWidget(init_misc);
	init_layout->addStretch(1);

	fort_save_label = new QLabel("Fortitude Save: ");
	fort_save = new QLineEdit();
	fort_base_save = new QLineEdit();
	fort_base_save->setToolTip("Base Save");
	fort_con = new QLabel("-5");
	fort_con->setToolTip("Current CON Modifier. Click 'Auto-Fill' to set.");
	fort_magic = new QLineEdit();
	fort_magic->setToolTip("Magic Modifier");
	fort_misc = new QLineEdit();
	fort_misc->setToolTip("Miscellaneous Modifier");
	fort_misc_temp = new QLineEdit();
	fort_misc_temp->setToolTip("Temporary Modifier");
	fort_save->setMaximumSize(WIDTH, HEIGHT);
	fort_base_save->setMaximumSize(WIDTH, HEIGHT);
	fort_magic->setMaximumSize(WIDTH, HEIGHT);
	fort_misc->setMaximumSize(WIDTH, HEIGHT);
	fort_misc_temp->setMaximumSize(WIDTH, HEIGHT);
	fort_equals = new QLabel("=");
	fort_plus = new QLabel("+");
	
	will_save_label = new QLabel("Will Save: ");
	will_save = new QLineEdit();
	will_equals = new QLabel("=");
	will_plus = new QLabel("+");
	will_base_save = new QLineEdit();
	will_base_save->setToolTip("Base Save");
	will_wis = new QLabel("-5");
	will_wis->setToolTip("Current WIS Modifier. Click 'Auto-Fill' to set.");
	will_magic = new QLineEdit();
	will_magic->setToolTip("Magic Modifier");
	will_misc = new QLineEdit();
	will_misc->setToolTip("Miscellaneous Modifier");
	will_misc_temp = new QLineEdit();
	will_misc_temp->setToolTip("Temporary Modifier");
	will_save->setMaximumSize(WIDTH, HEIGHT);
	will_base_save->setMaximumSize(WIDTH, HEIGHT);
	will_magic->setMaximumSize(WIDTH, HEIGHT);
	will_misc->setMaximumSize(WIDTH, HEIGHT);
	will_misc_temp->setMaximumSize(WIDTH, HEIGHT);
	
	ref_save_label = new QLabel("Reflex Save: ");
	ref_save = new QLineEdit();
	ref_equals = new QLabel("=");
	ref_plus = new QLabel("+");
	ref_base_save = new QLineEdit();
	ref_base_save->setToolTip("Base Save");
	ref_magic = new QLineEdit();
	ref_magic->setToolTip("Magic Modifier");
	ref_misc = new QLineEdit();
	ref_misc->setToolTip("Miscellaneous Modifier");
	ref_dex = new QLabel("-5");
	ref_dex->setToolTip("Current DEX Modifier. Click 'Auto-Fill' to set.");
	ref_misc_temp = new QLineEdit();
	ref_misc_temp->setToolTip("Temporary Modifier");
	ref_save->setMaximumSize(WIDTH, HEIGHT);
	ref_base_save->setMaximumSize(WIDTH, HEIGHT);
	ref_magic->setMaximumSize(WIDTH, HEIGHT);
	ref_misc->setMaximumSize(WIDTH, HEIGHT);
	ref_misc_temp->setMaximumSize(WIDTH, HEIGHT);
	
	//saves layout, goes next to stat_layout
	QGridLayout *saves_layout = new QGridLayout;
	QHBoxLayout *saves_h_layout = new QHBoxLayout;
	saves_layout->addWidget(fort_save_label, 0, 0, 1, 1);
	saves_layout->addWidget(fort_save, 0, 1, 1, 1);
	saves_layout->addWidget(fort_equals, 0, 2, 1, 1);
	saves_layout->addWidget(fort_plus, 0, 4, 1, 1);
	saves_layout->addWidget(fort_con, 0, 3, 1, 1);
	saves_layout->addWidget(fort_base_save, 0, 5, 1, 1);
	saves_layout->addWidget(fort_magic, 0, 6, 1, 1);
	saves_layout->addWidget(fort_misc, 0, 7, 1, 1);
	saves_layout->addWidget(fort_misc_temp, 0, 8, 1, 1);
	saves_layout->addWidget(will_save_label, 1, 0, 1, 1);
	saves_layout->addWidget(will_save, 1, 1, 1, 1);
	saves_layout->addWidget(will_equals, 1, 2, 1, 1);
	saves_layout->addWidget(will_plus, 1, 4, 1, 1);
	saves_layout->addWidget(will_wis, 1, 3, 1, 1);
	saves_layout->addWidget(will_base_save, 1, 5, 1, 1);
	saves_layout->addWidget(will_magic, 1, 6, 1, 1);
	saves_layout->addWidget(will_misc, 1, 7, 1, 1);
	saves_layout->addWidget(will_misc_temp, 1, 8, 1, 1);
	saves_layout->addWidget(ref_save_label, 2, 0, 1, 1);
	saves_layout->addWidget(ref_save, 2, 1, 1, 1);
	saves_layout->addWidget(ref_equals, 2, 2, 1, 1);
	saves_layout->addWidget(ref_plus, 2, 4, 1, 1);
	saves_layout->addWidget(ref_dex, 2, 3, 1, 1);
	saves_layout->addWidget(ref_base_save, 2, 5, 1, 1);
	saves_layout->addWidget(ref_magic, 2, 6, 1, 1);
	saves_layout->addWidget(ref_misc, 2, 7, 1, 1);
	saves_layout->addWidget(ref_misc_temp, 2, 8, 1, 1);
	saves_h_layout->addLayout(saves_layout);
	saves_h_layout->addStretch(1);
	
	QHBoxLayout *base_att_layout = new QHBoxLayout;	
	base_att_label = new QLabel("Base Attack Bonus: ");
	base_att = new QLineEdit();
	base_att->setMaximumSize(WIDTH, HEIGHT);
	base_att_layout->addWidget(base_att_label);
	base_att_layout->addWidget(base_att);
	base_att_layout->addStretch(1);
	
	QHBoxLayout *size_mod_layout = new QHBoxLayout;
	size_mod_label = new QLabel("Size Modifier: ");
	size_mod = new QLineEdit();
	size_mod->setMaximumSize(WIDTH, HEIGHT);
	size_mod_layout->addWidget(size_mod_label);
	size_mod_layout->addWidget(size_mod);
	size_mod_layout->addStretch(1);
	
	QHBoxLayout *spell_resist_layout = new QHBoxLayout;	
	spell_resist_label = new QLabel("Spell Resistance: ");
	spell_resist = new QLineEdit();
	spell_resist->setMaximumSize(WIDTH, HEIGHT);
	spell_resist_layout->addWidget(spell_resist_label);
	spell_resist_layout->addWidget(spell_resist);
	spell_resist_layout->addStretch(1);
	
	QHBoxLayout *mashup = new QHBoxLayout;
	mashup->addLayout(spell_resist_layout);
	mashup->addLayout(size_mod_layout);
	mashup->addLayout(base_att_layout);
	mashup->addStretch(1);

	QHBoxLayout *grapple_layout = new QHBoxLayout;	
	grapple_label = new QLabel("Grapple Modifier: ");
	grapple = new QLineEdit;
	grapple_equals = new QLabel("=");
	grapple_plus = new QLabel("+");
	grapple_str = new QLabel("-5");
	grapple_str->setToolTip("Current STR Modifier. Click 'Auto-Fill' to set. But you should already know that by now.");
	grapple_size_mod = new QLineEdit();
	grapple_size_mod->setToolTip("Size Modifier");
	grapple_misc_mod = new QLineEdit();
	grapple_misc_mod->setToolTip("Miscellaneous Modifier");
	grapple_base_att = new QLineEdit();
	grapple_base_att->setToolTip("Base Attack Bonus");
	grapple->setMaximumSize(WIDTH, HEIGHT);
	grapple_size_mod->setMaximumSize(WIDTH, HEIGHT);
	grapple_misc_mod->setMaximumSize(WIDTH, HEIGHT);
	grapple_base_att->setMaximumSize(WIDTH, HEIGHT);
	
	grapple_layout->addWidget(grapple_label);
	grapple_layout->addWidget(grapple);
	grapple_layout->addWidget(grapple_equals);
	grapple_layout->addWidget(grapple_str);
	grapple_layout->addWidget(grapple_plus);
	grapple_layout->addWidget(grapple_base_att);
	grapple_layout->addWidget(grapple_size_mod);
	grapple_layout->addWidget(grapple_misc_mod);
	grapple_layout->addStretch(1);
	
	QGridLayout *layout2 = new QGridLayout;
	layout2->addWidget(autofill, 0, 0, 1, 1);
	layout2->addLayout(hp_box, 1, 0, 1, 1);
	layout2->addLayout(stat_h_layout, 0, 1, 3, 1);
	layout2->addLayout(init_layout, 2, 0, 1, 1);
	
	layout->addLayout(layout2);
	layout->insertSpacing(1, 20);
	layout->addLayout(ac_layout);
	layout->addLayout(ac_layout2);
	layout->insertSpacing(4, 20);
	layout->addLayout(saves_h_layout);
	layout->insertSpacing(6, 20);
	layout->addLayout(mashup);
	layout->addLayout(grapple_layout);

	
	connect(autofill, SIGNAL(clicked()), SLOT(fill()));
	
	setLayout(layout);
}

void CharStats::fill()
{
	int bstr = (((base_str->text().toInt())/2)-5);
	int cstr = (((cur_str->text().toInt())/2)-5);
	int bdex = (((base_dex->text().toInt())/2)-5);
	int cdex = (((cur_dex->text().toInt())/2)-5);
	int bcon = (((base_con->text().toInt())/2)-5);
	int ccon = (((cur_con->text().toInt())/2)-5);
	int bint = (((base_int->text().toInt())/2)-5);
	int cint = (((cur_int->text().toInt())/2)-5);
	int bwis = (((base_wis->text().toInt())/2)-5);
	int cwis = (((cur_wis->text().toInt())/2)-5);
	int bcha = (((base_cha->text().toInt())/2)-5);
	int ccha = (((cur_cha->text().toInt())/2)-5);
	int acint = 10;

	cur_str_mod->setText(QString::number(cstr));
	base_str_mod->setText(QString::number(bstr));
	
	cur_dex_mod->setText(QString::number(cdex));
	base_dex_mod->setText(QString::number(bdex));
	
	ac_dex_mod->setText(cur_dex_mod->text());
	
	cur_con_mod->setText(QString::number(ccon));
	base_con_mod->setText(QString::number(bcon));
	
	cur_int_mod->setText(QString::number(cint));
	base_int_mod->setText(QString::number(bint));
	
	cur_wis_mod->setText(QString::number(cwis));
	base_wis_mod->setText(QString::number(bwis));
	
	cur_cha_mod->setText(QString::number(ccha));
	base_cha_mod->setText(QString::number(bcha));
	
	ac_size_mod->setText(size_mod->text());
	
	acint += (armor_bonus->text().toInt());
	acint += (shield_bonus->text().toInt());
	acint += (cur_dex_mod->text().toInt());
	acint += (ac_size_mod->text().toInt());
	acint += (nat_armor->text().toInt());
	acint += (deflection_mod->text().toInt());
	acint += (ac_misc_mod->text().toInt());
	
	int touchac = acint;
	int flatac = acint;
	
	ac->setText(QString::number(acint));
	
	touchac -= (armor_bonus->text().toInt());
	touchac -= (shield_bonus->text().toInt());
	touchac -= (nat_armor->text().toInt());
	
	touch_ac->setText(QString::number(touchac));
	
	flatac -= (cur_dex_mod->text().toInt());
	
	flat_ac->setText(QString::number(flatac));
	
	int init_dex_mod = (cur_dex_mod->text().toInt());
	int init_misc_mod = (init_misc->text().toInt());
	
	init_dex->setText(cur_dex_mod->text());
	init->setText(QString::number(init_dex_mod+init_misc_mod));
	
	int fortsave = 0;
	int willsave = 0;
	int refsave = 0;
	
	fort_con->setText(cur_con_mod->text());
	will_wis->setText(cur_wis_mod->text());
	ref_dex->setText(cur_dex_mod->text());
	
	fortsave += (cur_con_mod->text().toInt());
	fortsave += (fort_base_save->text().toInt());
	fortsave += (fort_magic->text().toInt());
	fortsave += (fort_misc->text().toInt());
	fortsave += (fort_misc_temp->text().toInt());
	
	fort_save->setText(QString::number(fortsave));
	
	willsave += (cur_wis_mod->text().toInt());
	willsave += (will_base_save->text().toInt());
	willsave += (will_magic->text().toInt());
	willsave += (will_misc->text().toInt());
	willsave += (will_misc_temp->text().toInt());
	
	will_save->setText(QString::number(willsave));
	
	refsave += (cur_dex_mod->text().toInt());
	refsave += (ref_base_save->text().toInt());
	refsave += (ref_magic->text().toInt());
	refsave += (ref_misc->text().toInt());
	refsave += (ref_misc_temp->text().toInt());
	
	ref_save->setText(QString::number(refsave));
	
	int grappletotal = 0;
	
	grapple_base_att->setText(base_att->text());
	grapple_str->setText(cur_str_mod->text());
	grapple_size_mod->setText(size_mod->text());
	
	grappletotal += grapple_base_att->text().toInt();
	grappletotal += grapple_str->text().toInt();
	grappletotal += grapple_size_mod->text().toInt();
	grappletotal += grapple_misc_mod->text().toInt();
	
	grapple->setText(QString::number(grappletotal));
	
}

QByteArray* CharStats::return_data_bytearray()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::WriteOnly);
    
    /*Add everything to the QMap hash*/
    hash["cur_hp"] = cur_hp->text();
    hash["base_hp"] = base_hp->text();
    hash["cur_str"] = cur_str->text();
    hash["base_str"] = base_str->text();
    hash["cur_dex"] = cur_dex->text();
    hash["base_dex"] = base_dex->text();
    hash["cur_con"] = cur_con->text();
    hash["base_con"] = base_con->text();
    hash["cur_int"] = cur_int->text();
    hash["base_int"] = base_int->text();
    hash["cur_wis"] = cur_wis->text();
    hash["base_wis"] = base_wis->text();
    hash["cur_cha"] = cur_cha->text();
    hash["base_cha"] = base_cha->text();
    hash["ac_dex_mod"] = ac_dex_mod->text();
    hash["ac"] = ac->text();
    hash["armor_bonus"] = armor_bonus->text();
    hash["shield_bonus"] = shield_bonus->text();
    hash["ac_size_mod"] = ac_size_mod->text();
    hash["deflection_mod"] = deflection_mod->text();
    hash["nat_armor"] = nat_armor->text();
    hash["ac_misc_mod"] = ac_misc_mod->text();   
    hash["touch_ac"] = touch_ac->text();
    hash["flat_ac"] = flat_ac->text();
    hash["init"] = init->text();
    hash["init_dex"] = init_dex->text();
    hash["init_misc"] = init_misc->text();
    hash["fort_save"] = fort_save->text();
    hash["fort_base_save"] = fort_base_save->text();
    hash["fort_con"] = fort_con->text();
    hash["fort_magic"] = fort_magic->text();
    hash["fort_misc"] = fort_misc->text();
    hash["fort_misc_temp"] = fort_misc_temp->text();
	hash["will_save"] = will_save->text();
    hash["will_base_save"] = will_base_save->text();
    hash["will_wis"] = will_wis->text();
    hash["will_magic"] = will_magic->text();
    hash["will_misc"] = will_misc->text();
    hash["will_misc_temp"] = will_misc_temp->text();
    hash["ref_save"] = ref_save->text();
    hash["ref_base_save"] = ref_base_save->text();
    hash["ref_dex"] = ref_dex->text();
    hash["ref_magic"] = ref_magic->text();
    hash["ref_misc"] = ref_misc->text();
    hash["ref_misc_temp"] = ref_misc_temp->text();
    hash["base_att"] = base_att->text();
    hash["spell_resist"] = spell_resist->text();
    hash["size_mod"] = size_mod->text();
    hash["grapple"] = grapple->text();
    hash["grapple_str"] = grapple_str->text();
    hash["grapple_base_att"] = grapple_base_att->text();
    hash["grapple_size_mod"] = grapple_size_mod->text();
    hash["grapple_misc_mod"] = grapple_misc_mod->text();

    	
   	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    
    return hasharray;
	
}

void CharStats::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadWrite);
	in >> hash;

    if (hash.isEmpty()) 
    {
    	QMessageBox::information(this, tr("No information in file"), tr("The file you are attempting to open contains no stats."));
    } 
    else 
    {
    	cur_hp->setText(hash["cur_hp"]);
    	base_hp->setText(hash["base_hp"]);
    	cur_str->setText(hash["cur_str"]);
    	base_str->setText(hash["base_str"]);
    	cur_dex->setText(hash["cur_dex"]);
    	base_dex->setText(hash["base_dex"]);
    	cur_con->setText(hash["cur_con"]);
    	base_con->setText(hash["base_con"]);
    	cur_int->setText(hash["cur_int"]);
    	base_int->setText(hash["base_int"]);
    	cur_wis->setText(hash["cur_wis"]);
    	base_wis->setText(hash["base_wis"]);
    	cur_cha->setText(hash["cur_cha"]);
    	base_cha->setText(hash["base_cha"]);
    	ac_dex_mod->setText(hash["ac_dex_mod"]);
    	ac->setText(hash["ac"]);
    	armor_bonus->setText(hash["armor_bonus"]);
    	shield_bonus->setText(hash["shield_bonus"]);
    	ac_size_mod->setText(hash["ac_size_mod"]);
    	deflection_mod->setText(hash["deflection_mod"]);
    	nat_armor->setText(hash["nat_armor"]);
    	ac_misc_mod->setText(hash["ac_misc_mod"]);
    	touch_ac->setText(hash["touch_ac"]);
    	flat_ac->setText(hash["flat_ac"]);
    	init->setText(hash["init"]);
    	init_dex->setText(hash["init_dex"]);
    	init_misc->setText(hash["init_misc"]);
    	fort_save->setText(hash["fort_save"]);
    	fort_base_save->setText(hash["fort_base_save"]);
    	fort_con->setText(hash["fort_con"]);
    	fort_magic->setText(hash["fort_magic"]);
    	fort_misc->setText(hash["fort_misc"]);
    	fort_misc_temp->setText(hash["fort_misc_temp"]);
		will_save->setText(hash["will_save"]);
    	will_base_save->setText(hash["will_base_save"]);
    	will_wis->setText(hash["will_wis"]);
    	will_magic->setText(hash["will_magic"]);
    	will_misc->setText(hash["will_misc"]);
    	will_misc_temp->setText(hash["will_misc_temp"]);
    	ref_save->setText(hash["ref_save"]);
    	ref_base_save->setText(hash["ref_base_save"]);
    	ref_dex->setText(hash["ref_dex"]);
    	ref_magic->setText(hash["ref_magic"]);
    	ref_misc->setText(hash["ref_misc"]);
    	ref_misc_temp->setText(hash["ref_misc_temp"]);
    	base_att->setText(hash["base_att"]);
    	spell_resist->setText(hash["spell_resist"]);
    	size_mod->setText(hash["size_mod"]);
    	grapple->setText(hash["grapple"]);
    	grapple_str->setText(hash["grapple_str"]);
    	grapple_base_att->setText(hash["grapple_base_att"]);
    	grapple_size_mod->setText(hash["grapple_size_mod"]);
    	grapple_misc_mod->setText(hash["grapple_misc_mod"]);
    }
}
		
