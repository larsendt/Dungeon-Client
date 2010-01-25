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

//contains five slots for weaponry. if the player has more, (s)he can store them in the
//gear tab

#ifndef WEAPON_H
#define WEAPON_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QDataStream>
#include <QFile>
#include <QMessageBox>
#include <QMap>
#include <QTabWidget>
#include <QHash>
#include <QByteArray>
#include <QDataStream>

class WeaponTab : public QWidget
{
	Q_OBJECT
	
  public:
    WeaponTab(QWidget *parent = 0);
    QByteArray* save();
	void load(QByteArray *parent_byte); 
  
  private slots:

  private:
  	QHash <QString, QString> hash;
    QLabel *weapon_label;
	QLineEdit *weapon;
	QLabel *att_bonus_label;
	QLineEdit *att_bonus;
	QLabel *damage_label;
	QLineEdit *damage;
	QLabel *critical_label;
	QLineEdit *critical;
	QLabel *range_label;
	QLineEdit *range;
	QLabel *type_label;
	QLineEdit *type;
	QLabel *notes_label;
	QTextEdit *notes;
	QLabel *ammo_label;
	QLineEdit *ammo;
	QLabel *ammo_num_label;
	QLineEdit *ammo_num;
};

class Weapon : public QWidget
{
	Q_OBJECT
	
	public:
		Weapon(QWidget *parent = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte); 
	
	private slots:
	
	private:
		QHash <QString, QByteArray> hash;
		QTabWidget *tabs;	
		WeaponTab *weapon0;
		WeaponTab *weapon1;
		WeaponTab *weapon2;
		WeaponTab *weapon3;
		WeaponTab *weapon4;
};

#endif
