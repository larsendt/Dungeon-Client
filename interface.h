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
	save-as is currently disabled until I can figure out how to detect that a user has 
	cancelled an "open" or "save" operation
*/

#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QWidget>
#include <QDataStream>
#include "tabs.h"


class QAction;
class QMenu;
class QMenuBar;


class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface();
    
private slots:
	void save_to_file();
	//void save_as();
	void load_from_file();
	void show_info_widget();
	void show_contents_widget();
	void show_license();

private:
    void createMenu();

    QMenuBar *menuBar;
    TabWidget *tabWidget;

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *exitAction;
    QAction *openAction;
    QAction *saveAction;
    //QAction *saveAsAction;
    QAction *contentsAction;
    QAction *aboutAction;
    QAction *licenseAction;
};

#endif
