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

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    You can contact the author at dane.t.larsen@gmail.com
*/
#ifndef SPELLS_H
#define SPELLS_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDataStream>
#include <QMessageBox>
#include <QHash>
#include <QByteArray>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTabWidget>
#include <QCheckBox>
#include <QListWidget>

class SpellList : public QWidget
{
	Q_OBJECT
	
	public:
		SpellList(QWidget *parent = 0, int spell_level = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		void add();
		void remove();
		void move_up();
		void move_down();
		QString prepare();
		
	private slots:
	
	private:
		QHash <QString, QString> hash;
		int num_items;
		
		int level;
		
		QTableWidget *table;	
};

class Spells : public QWidget
{
	Q_OBJECT
	
	public:
		Spells(QWidget *parent = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
				
	private slots:
		void add();
		void remove();
		void move_up();
		void move_down();
		void prepare();
		void put_prepared_spell(QString spell);
		void remove_prepared();
		void clear_prepared();
	
	private:
		QHash <QString, QByteArray> hash;
		QPushButton *add_button;
		QPushButton *remove_button;
		QPushButton *up_button;
		QPushButton *down_button;
		QPushButton *prepare_button;
		QTabWidget *tabWidget;
		QListWidget *activeSpells;
		SpellList *level0;
		SpellList *level1;
		SpellList *level2;
		SpellList *level3;
		SpellList *level4;
		SpellList *level5;
		SpellList *level6;
		SpellList *level7;
		SpellList *level8;
		SpellList *level9;
};


#endif
