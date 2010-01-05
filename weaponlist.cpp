#include "weaponlist.h"

WeaponList::WeaponList(QWidget *parent)
{
	layout = new QVBoxLayout;
	add_weapon = new QPushButton("+");
	//connect(add_weapon, SIGNAL(clicked()), SLOT(newWeapon()));
	layout->addWidget(add_weapon);
	setLayout(layout);
	itemcount = 0;
	
}

void WeaponList::newWeapon()
{

/*
	if(itemcount+1 > 10)
	{
		QMessageBox::information(this, tr("Too many weapons!"), tr("You've reached the maximum number of weapons (10). Sorry!"));
		return;
	}
	layout = new QVBoxLayout;
	mainwidget = new QWidget;
	Weapon *newweapon = new Weapon;
	layout->addWidget(newweapon);
	weapon_array[itemcount] = newweapon;
	for(int i = 0; i <= itemcount; i++)
	{
		layout->addWidget(weapon_array[i]);
	}
	itemcount++;
	layout->addWidget(add_weapon);
	//mainwidget.setLayout(layout);
	
	*/

}
