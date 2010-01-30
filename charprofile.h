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
	charprofile is not currently used. Charprofile need to be able to pull information
	from other classes automatically. To do this the Tabs class needs to have the signal
	tabChanged(). This currently does not work, so I've disabled the profile.
	
	When I do get the signal working, the char profile will (ideally) contain a picture
	selectable by the user, and information pulled from the other classes
	
*/

#ifndef CHARPROFILE_H
#define CHARPROFILE_H

#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>
#include <QTextEdit>
#include "chardescwidget.h"

class CharProfile : public QWidget
{
	Q_OBJECT
	
	public:
		CharProfile(QWidget *parent = 0, CharDescWidget *character_info = 0);
		void update();
		
	private slots:
		void load_pic();
	
	private:
		QPixmap profilepic;
		QLabel *piclabel;
		QScrollArea *picscroll;
		QPushButton *selectpic;
		QLabel *charname;
		QLabel *charname_label;
		CharDescWidget *characterinfo;
	
};




#endif
