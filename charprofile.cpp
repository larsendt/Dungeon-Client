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


#include "charprofile.h"

CharProfile::CharProfile(QWidget *parent, CharDescWidget *character_info)
{
	QGridLayout *layout = new QGridLayout;
	QVBoxLayout *info = new QVBoxLayout;
	
	characterinfo = character_info;
	
	QPixmap profilepic(300, 200);
	selectpic = new QPushButton("Select Picture");
	connect(selectpic, SIGNAL(clicked()), SLOT(load_pic()));
	charname = new QLabel(characterinfo->get_name());
	charname_label = new QLabel("Character: ");
	piclabel = new QLabel();
	piclabel->setPixmap(profilepic);
	profilepic.fill(Qt::white);
	picscroll = new QScrollArea();
	picscroll->setWidget(piclabel);
	picscroll->setMaximumWidth(350);
	picscroll->setMinimumWidth(300);
	
	QHBoxLayout *charname_hbox = new QHBoxLayout;
	charname_hbox->addStretch(1);
	charname_hbox->addWidget(charname_label);
	charname_hbox->addWidget(charname);
	charname_hbox->addStretch(1);
	
	info->addLayout(charname_hbox);
		
	layout->addWidget(picscroll, 0, 0, 1, 1);
	layout->addWidget(selectpic, 1, 0, 1, 1);
	layout->addLayout(info, 0, 1, 1, 1);
	
	setLayout(layout);
}
	
void CharProfile::load_pic()
{
	//profilepic.load("deadpool.jpg");
}	

void CharProfile::update()
{
	charname->setText(characterinfo->get_name());
}



