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
	tabs contains the main save() function that calls all the save() functions of the other
	classes. Tabs writes all of those QByteArrays to a single file
*/

#ifndef TABDIALOG_H
#define TABDIALOG_H

#include "chardescwidget.h"
#include "diceroller.h"
#include "charstats.h"
#include "weapon.h"
#include "armor.h"
#include "spells.h"
#include "gear.h"
#include "feats.h"
#include "skills.h"

#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QDataStream>
#include <QFile>
#include <QHash>

class QTabWidget;

class TabWidget: public QWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget *parent = 0);
    void saveAll();
    //void saveAllAs();
    void loadAll();
    void update();
    void set_dm_ip(QString ip);
    void disconnect();
    
private slots:
	void update(int index);

private:
	bool already_saved;
	QString fileName;
	QHash<QString, QByteArray> hash;
	
    QTabWidget *tabWidget;
    QHBoxLayout *dice;
    QScrollArea *char_rp;
    QScrollArea *char_stats;
    QScrollArea *charprofile_scroll;
    CharDescWidget *char_widget;
    Diceroller *dice_widget;
    CharStats *char_stats_widget;
    Weapon *weapon;
    Armor *armor;
    Spells *spells;
    Gear *gear;
    Feats *feats;
    Skills *skills;
    
    QString dm_ip;
	bool connected;    
};

 #endif
