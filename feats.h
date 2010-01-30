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
	feats stores an arbitrary number of feats
	pretty straightforward
	
*/

#ifndef FEATS_H
#define FEATS_H

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

#include <stdlib.h>


class Feats : public QWidget
{
	Q_OBJECT
	
	public:
		Feats(QWidget *parent = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		
	private slots:
		void add();
		void remove();
		void move_up();
		void move_down();
	
	private:
		QHash <QString, QString> hash;
		int num_items;
		
		QPushButton *add_button;
		QPushButton *remove_button;
		QPushButton *up_button;
		QPushButton *down_button;
		
		QTableWidget *table;
		
		

};


#endif
