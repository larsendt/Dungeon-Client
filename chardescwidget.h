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
	chardescwidget contains the rollplaying aspects of the character, such as name,
	size, age, sex, race, etc
*/

#ifndef CHARDESCWIDGET_H
#define CHARDESCWIDGET_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include <QMap>

class CharDescWidget : public QWidget
{
	Q_OBJECT
	
  public:
    CharDescWidget(QWidget *parent = 0);
    QString get_name();
    QByteArray* return_data_bytearray();
	void load(QByteArray *parent_byte);
  
  private slots:

  private:
    QHash <QString, QString> hash;
    QLabel *character_name_label;
    QLabel *player_name_label;
    QLineEdit *character_name;
    QLineEdit *player_name;
    QLabel *class_label;
    QLineEdit *char_class;
    QLabel *level_label;
    QLineEdit *level;
    QLabel *race_label;
    QLineEdit *race;
    QLabel *align_label;
    QLineEdit *alignment;
    QLabel *deity_label;
    QLineEdit *deity;
    QLabel *size_label;
    QLineEdit *size;
    QLabel *age_label;
    QLineEdit *age;
    QLabel *gender_label;
    QLineEdit *gender;
    QLabel *height_label;
    QLineEdit *height;
    QLabel *weight_label;
    QLineEdit *weight;
    QLabel *eyes_label;
    QLineEdit *eyes;
    QLabel *hair_label;
    QLineEdit *hair;
    QLabel *skin_label;
    QLineEdit *skin;
    QLabel *exp_label;
    QLineEdit *exp; 
    QLabel *notes_label;
    QTextEdit *notes;
};

#endif
