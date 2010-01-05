
#include <QtGui>

#include "tabs.h"

TabWidget::TabWidget(QWidget *parent)
{
	already_saved = false;
	QVBoxLayout *main = new QVBoxLayout;
    tabWidget = new QTabWidget;
    
    char_rp = new QScrollArea;
    char_stats = new QScrollArea;
    charprofile_scroll = new QScrollArea;
    QScrollArea *weaponscroll = new QScrollArea;
    QScrollArea *armorscroll = new QScrollArea;
    QScrollArea *gearscroll = new QScrollArea;
    
    dice_widget = new Diceroller;
    char_widget = new CharDescWidget;
    char_stats_widget = new CharStats;
    charprofile = new CharProfile(this, char_widget);
    weapon = new WeaponList;
    armor = new Armor;
    spells = new Spells;
    gear = new Gear;
    
    char_rp->setWidget(char_widget);
    char_stats->setWidget(char_stats_widget);
    charprofile_scroll->setWidget(charprofile);
    weaponscroll->setWidget(weapon);
    armorscroll->setWidget(armor);
    gearscroll->setWidget(gear);
    
    //tabWidget->addTab(charprofile_scroll, tr("Character Profile"));
    tabWidget->addTab(char_rp, tr("Character Info"));
    tabWidget->addTab(char_stats, tr("Character Stats"));
    tabWidget->addTab(weaponscroll, tr("Weaponry"));
    tabWidget->addTab(armorscroll, tr("Armor"));
    tabWidget->addTab(spells, tr("Spells"));
    tabWidget->addTab(gearscroll, tr("Gear"));
    tabWidget->addTab(dice_widget, tr("Virtual Dice"));
    
    connect(this, SIGNAL(currentChanged(QWidget*)), SLOT(updateProfile()));
	
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
    	    
    	    hash["char_stats"] = *char_stats_widget->save();
			hash["char_widget"] = *char_widget->save();
			hash["armor"] = *armor->save();
			hash["dice"] = *dice_widget->save();
			
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
    	
    }   
    already_saved = true;
}

void TabWidget::update()
{
	charprofile->update();
}


