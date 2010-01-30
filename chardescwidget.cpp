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

#include "chardescwidget.h"
#include <QGroupBox>

CharDescWidget::CharDescWidget(QWidget *parent)
    :QWidget(parent)
{

	//final vbox for player and character, and all of the rp elements
	QVBoxLayout *layout = new QVBoxLayout();
	
	QHBoxLayout *player_and_character = new QHBoxLayout();	
	QGridLayout *rp_desc_gbox = new QGridLayout();
	QGridLayout *rp_stats_gbox = new QGridLayout();
	QHBoxLayout *notes_hbox = new QHBoxLayout();
	
	//initialize all of the character description fields
	
	player_name_label = new QLabel("Player: ", this);
	player_name = new QLineEdit(this);
	
	character_name_label = new QLabel("Character: ", this);
	character_name = new QLineEdit(this);
	
	player_and_character->addWidget(player_name_label);
	player_and_character->addWidget(player_name);
	player_and_character->addWidget(character_name_label);
	player_and_character->addWidget(character_name);
				
	class_label = new QLabel("Class: ", this);
    char_class = new QLineEdit(this);
    
    level_label = new QLabel("Level: ", this);
    level = new QLineEdit(this);
    
    race_label = new QLabel("Race: ", this);
    race = new QLineEdit(this);
    
    align_label = new QLabel("Alignment: ", this);
    alignment = new QLineEdit(this);
    
    deity_label = new QLabel("Deity: ", this);
    deity = new QLineEdit(this);
    
    size_label = new QLabel("Size: ", this);
    size = new QLineEdit(this);
    
    age_label = new QLabel("Age: ", this);
    age = new QLineEdit(this);
    
    gender_label = new QLabel("Gender: ", this);
    gender = new QLineEdit(this);
    
    height_label = new QLabel("Height (ft): ", this);
    height = new QLineEdit(this);
    
    weight_label = new QLabel("Weight (lbs): ", this);
    weight = new QLineEdit(this);
    
    eyes_label = new QLabel("Eyes: ", this);
    eyes = new QLineEdit(this);
    
    hair_label = new QLabel("Hair: ", this);
    hair = new QLineEdit(this);
    
    skin_label = new QLabel("Skin: ", this);
    skin = new QLineEdit(this);
    
    exp_label = new QLabel("Experience: ", this);
    exp = new QLineEdit(this); 

	notes_label = new QLabel("Notes: ", this);
	notes = new QTextEdit(this);
	
//begin adding stuff to widgets
	notes_hbox->addWidget(notes_label);
	notes_hbox->addWidget(notes);
    
    rp_stats_gbox->addWidget(race_label, 0, 0);
    rp_stats_gbox->addWidget(race, 0, 1);
    rp_stats_gbox->addWidget(class_label, 0, 2);
    rp_stats_gbox->addWidget(char_class, 0, 3);
    rp_stats_gbox->addWidget(level_label, 1, 0);
    rp_stats_gbox->addWidget(level, 1, 1);
    rp_stats_gbox->addWidget(deity_label, 1, 2);
    rp_stats_gbox->addWidget(deity, 1, 3);
    rp_stats_gbox->addWidget(align_label, 2, 0);
    rp_stats_gbox->addWidget(alignment, 2, 1);
    rp_stats_gbox->addWidget(exp_label, 2, 2);
    rp_stats_gbox->addWidget(exp, 2, 3);
	
	rp_desc_gbox->addWidget(age_label, 0, 0);
	rp_desc_gbox->addWidget(age, 0, 1);
	rp_desc_gbox->addWidget(height_label, 1, 0);
	rp_desc_gbox->addWidget(height, 1, 1);
	rp_desc_gbox->addWidget(weight_label, 2, 0);
	rp_desc_gbox->addWidget(weight, 2, 1);
	rp_desc_gbox->addWidget(gender_label, 3, 0);
	rp_desc_gbox->addWidget(gender, 3, 1);
	rp_desc_gbox->addWidget(eyes_label, 0, 2);
	rp_desc_gbox->addWidget(skin_label, 1, 2);
	rp_desc_gbox->addWidget(hair_label, 2, 2);
	rp_desc_gbox->addWidget(size_label, 3, 2);
	rp_desc_gbox->addWidget(eyes, 0, 3);
	rp_desc_gbox->addWidget(skin, 1, 3);
	rp_desc_gbox->addWidget(hair, 2, 3);
	rp_desc_gbox->addWidget(size, 3, 3);
	

   	layout->addLayout(player_and_character);
   	layout->insertSpacing(1, 20);
   	layout->addLayout(rp_stats_gbox);
   	layout->insertSpacing(3, 20);
   	layout->addLayout(rp_desc_gbox);
   	layout->insertSpacing(5, 20);
   	layout->addLayout(notes_hbox);
   	
   	setLayout(layout);   
 
}


//someday this will be used to transfer info between classes
//need to figure out SIGNAL(tabChanged())
QString CharDescWidget::get_name()
{
	return character_name->text();
}

QByteArray* CharDescWidget::save()
{
	QByteArray *hasharray = new QByteArray;
	QDataStream out(hasharray, QIODevice::ReadWrite);
    
    hash["character_name"] = character_name->text();
    hash["player_name"] = player_name->text();
 	hash["race"] = race->text();
 	hash["char_class"] = char_class->text();
	hash["level"] = level->text();
	hash["deity"] = deity->text();
	hash["alignment"] = alignment->text();
	hash["exp"] = exp->text();
	hash["age"] = age->text();
	hash["eyes"] = eyes->text();
	hash["height"] = height->text();
	hash["weight"] = weight->text();
	hash["skin"] = skin->text();
	hash["hair"] = hair->text();
	hash["gender"] = gender->text();
	hash["size"] = size->text();
	hash["notes"] = notes->toPlainText();
	
	out.setVersion(QDataStream::Qt_4_5);
    out << hash;
    
    return hasharray;

}

void CharDescWidget::load(QByteArray *parent_byte)
{
	QDataStream in(parent_byte, QIODevice::ReadWrite);
	in >> hash;

    if (hash.isEmpty()) 
    {
    	QMessageBox::information(this, tr("No information in file"), tr("The file you are attempting to open contains no stats."));
    } 
    else 
    {
    	character_name->setText(hash["character_name"]);
    	player_name->setText(hash["player_name"]);
 		race->setText(hash["race"]);
 		char_class->setText(hash["char_class"]);
		level->setText(hash["level"]);
		deity->setText(hash["deity"]);
		alignment->setText(hash["alignment"]);
		exp->setText(hash["exp"]);
		age->setText(hash["age"]);
		eyes->setText(hash["eyes"]);
		height->setText(hash["height"]);
		weight->setText(hash["weight"]);
		skin->setText(hash["skin"]);
		hair->setText(hash["hair"]);
		gender->setText(hash["gender"]);
		size->setText(hash["size"]);
    	notes->setText(hash["notes"]);
    	
    }

}



