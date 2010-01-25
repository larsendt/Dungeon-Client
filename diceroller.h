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

/* 
	diceroller, as the name implies, contains a virtual dice roller, plus a space for notes
	the diceroller allows the player to specify the die size and the multiplier (xdx)
*/

#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QHash>
#include <QDataStream>
#include <QByteArray>

class Diceroller : public QWidget
{
	Q_OBJECT
	
  public:
    Diceroller(QWidget *parent = 0);
    QByteArray* save();
    void load(QByteArray *parent_byte);
  
  private slots:
  	void roll();
  	void clear();
  	void burn_notes();

  private:
  	int totalint;
  	QHash <QString, QString> hash;
  	QLabel *die_size_label;
  	QLabel *multiplier_label;
  	QLabel *you_rolled;
  	QLabel *xdx;
  	QLabel *total_label;
  	QLabel *total;
  	QLineEdit *die_size;
  	QLineEdit *multiplier;
  	QTextBrowser *output;
  	QPushButton *roll_button;
  	QTextEdit *notes;
  	QPushButton *clear_notes;

  	
  	
};

#endif
