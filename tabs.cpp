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
#include <QtGui>

#include "tabs.h"

TabWidget::TabWidget(QWidget *parent)
{
	already_saved = false;
	QVBoxLayout *main = new QVBoxLayout;
    tabWidget = new QTabWidget;
    
    //set the network connection state to false
    connected = false;
    
    char_rp = new QScrollArea;
    char_stats = new QScrollArea;
    QScrollArea *armorscroll = new QScrollArea;
    
    dice_widget = new Diceroller;
    char_widget = new CharDescWidget;
    char_stats_widget = new CharStats;
    weapon = new Weapon;
    armor = new Armor;
    spells = new Spells;
    gear = new Gear;
    feats = new Feats;
    skills = new Skills;
    
    char_rp->setWidget(char_widget);
    char_stats->setWidget(char_stats_widget);
    armorscroll->setWidget(armor);
    
    QIcon weapon_icon("ico/weapons.png");
    QIcon armor_icon("ico/armor.png");   
    QIcon spells_icon("ico/spells.png");
    QIcon gear_icon("ico/gear.png");
    QIcon dice_icon("ico/dice.png");
    QIcon skills_icon("ico/skills.png");
    tabWidget->addTab(char_rp, tr("Character Info"));
    tabWidget->addTab(char_stats, tr("Character Stats"));
    tabWidget->addTab(weapon, weapon_icon, tr("Weaponry"));
    tabWidget->addTab(armorscroll, armor_icon, tr("Armor"));
    tabWidget->addTab(spells, spells_icon, tr("Spells"));
    tabWidget->addTab(gear, gear_icon, tr("Gear"));
    tabWidget->addTab(skills, skills_icon, tr("Skills"));
    tabWidget->addTab(feats, tr("Feats"));
    tabWidget->addTab(dice_widget, dice_icon, tr("Virtual Dice"));
    
    connect(this, SIGNAL(currentChanged(int)), SLOT(update(int)));
	
	main->addWidget(tabWidget);
	setLayout(main);

}

void TabWidget::saveAll()
{
	
	//if(!already_saved)
	//{
		fileName = QFileDialog::getSaveFileName(this, tr("Save Character Sheet"), "saves/", tr("*.csh;;All Files (*)"));
    
    	if(!fileName.endsWith(".csh"))
    	{
    		fileName.append(".csh");
   		}
         
    	if (fileName.isEmpty())
    	    return;
    	else 
    	{
    	    QFile file(fileName);
    	    if (!file.open(QIODevice::WriteOnly)) 
    	    {
    	        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
    	        return;
    	    }
    	    QDataStream out(&file);
    	    
    	    hash["char_stats"] = *char_stats_widget->return_data_bytearray();
			hash["char_widget"] = *char_widget->return_data_bytearray();
			hash["armor"] = *armor->return_data_bytearray();
			hash["dice"] = *dice_widget->return_data_bytearray();
			hash["gear"] = *gear->return_data_bytearray();
			hash["feats"] = *feats->return_data_bytearray();
			hash["spells"] = *spells->return_data_bytearray();
			hash["weapon"] = *weapon->return_data_bytearray();
			hash["skills"] = *skills->return_data_bytearray();
			
			out.setVersion(QDataStream::Qt_4_5);
    	    out << hash;
    	    already_saved = true;
    	}
   // }
   /* else
    {
    	
    	QFile file(fileName);
    	if (!file.open(QIODevice::WriteOnly)) 
    	{
    	    QMessageBox::information(this, tr("Unable to open file"), file.errorString());
    	    return;
    	}
    	QDataStream out(&file);
    	
    	hash["char_stats"] = *char_stats_widget->save();
		hash["char_widget"] = *char_widget->save();
		hash["armor"] = *armor->save();
			
		out.setVersion(QDataStream::Qt_4_5);
    	out << hash;
    	already_saved = true;
    }
    */
    	
}

/*

void TabWidget::saveAllAs()
{
	fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "saves/", tr("*.csh;;All Files (*)"));
    
    if(!fileName.endsWith(".csh"))
    {
    	fileName.append(".csh");
   	}
         
    if (fileName.isEmpty())
        return;
    else 
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) 
        {
        	QMessageBox::information(this, tr("Unable to open file"), file.errorString());
       		return;
       	}
       	
       	QDataStream out(&file);
 
    	hash["char_stats"] = *char_stats_widget->save();
		hash["char_widget"] = *char_widget->save();
		hash["armor"] = *armor->save();
			
		out.setVersion(QDataStream::Qt_4_5);
    	out << hash;
    	already_saved = true;
	}

}

*/

void TabWidget::loadAll()
{
	
	fileName = QFileDialog::getOpenFileName(this,
        tr("Load Character Sheet"), "saves/",
        tr("*.csh;;All Files(*)"));
    
    if (fileName.isEmpty())
        return;
    else 
    {
    	QFile file(fileName);
    	if (!file.open(QIODevice::ReadOnly)) 
    	{
        	QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    	}
    	
    	QDataStream in(&file);
	
		in >> hash;
    	
    	char_stats_widget->load(&hash["char_stats"]);
		char_widget->load(&hash["char_widget"]);
		armor->load(&hash["armor"]);
		dice_widget->load(&hash["dice"]);
		gear->load(&hash["gear"]);
		feats->load(&hash["feats"]);
		spells->load(&hash["spells"]);
		weapon->load(&hash["weapon"]);
		skills->load(&hash["skills"]);
    	
    }   
    already_saved = true;
}

void TabWidget::update(int index)
{
	//QByteArray *temp_array = char_widget->return_data_bytearray();
}

void TabWidget::set_dm_ip(QString ip)
{
	dm_ip = ip;
	connected = true;
	dice_widget->set_dm_ip(dm_ip);
}

void TabWidget::disconnect()
{
	connected = false;
}

