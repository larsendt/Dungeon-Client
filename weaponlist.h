#ifndef WEAPONLIST_H
#define WEAPONLIST_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "weapon.h"


class WeaponList : public QWidget
{
	Q_OBJECT
	
	public:
		WeaponList(QWidget *parent = 0);
		
	private slots:
		void newWeapon();
	
	private:
		Weapon *weapon_array[10];
		QListWidget *list;
		int itemcount;
		QPushButton *add_weapon;
		QVBoxLayout *layout;
		


};

#endif
