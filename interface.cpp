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

#include <QtGui>
#include <QScrollArea>

#include "interface.h"

QString DCLIENTVERSION = "0.5.24012010";
QString ABOUT = "Author: Dane Larsen\ndane.t.larsen@gmail.com\n\nAbout: \nDungeon Client is an application geared towards simplicity of D&D character setup, which typically takes quite a long time, and can detract from the experience of a onetime campaign. \n\nThis is accomplished by a moderate amount of automation, but not enough to remove control from the player/DM. \n\nThis automation allows for speedy character creation by removing the need to constantly refer to the Player's Handbook.\n\nBut remember: There is nothing like rolling two handfulls of d6's.";
QString LICENSE = "Dungeon Client - An application geared towards making D&D character setup and use easier.\n\nCopyright (C) 2010 Dane T Larsen \n\nThis program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n\nThis program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. \n\nYou should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.\n\nYou can contact the author at dane.t.larsen@gmail.com";


Interface::Interface()
{
    createMenu();
    
	tabWidget = new TabWidget;
	//connect(tabWidget, SIGNAL(currentChanged(0)), this, SLOT(update()));

	setMenuBar(menuBar);

	setCentralWidget(tabWidget);
    setWindowTitle(tr("Dungeon Client"));


}

void Interface::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    helpMenu = new QMenu(tr("&Help"), this);
    openAction = fileMenu->addAction(tr("&Open"));
    saveAction = fileMenu->addAction(tr("&Save"));
    fileMenu->addSeparator();
    //saveAsAction = fileMenu->addAction(tr("S&ave As"));
    exitAction = fileMenu->addAction(tr("&Quit"));
    contentsAction = helpMenu->addAction(tr("&Contents"));
    aboutAction = helpMenu->addAction(tr("A&bout"));
    licenseAction = helpMenu->addAction(tr("&License"));
    exitAction->setShortcut(tr("CTRL+Q"));
    openAction->setShortcut(tr("CTRL+O"));
    saveAction->setShortcut(tr("CTRL+S"));
    //saveAsAction->setShortcut(tr("CTRL+SHIFT+S"));
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);
    
    connect(exitAction, SIGNAL(triggered()), SLOT(close()));
    connect(saveAction, SIGNAL(triggered()), SLOT(save_to_file()));
    //connect(saveAsAction, SIGNAL(triggered()), SLOT(save_as()));
    connect(openAction, SIGNAL(triggered()), SLOT(load_from_file()));
    connect(aboutAction, SIGNAL(triggered()), SLOT(show_info_widget()));
    connect(contentsAction, SIGNAL(triggered()), SLOT(show_contents_widget()));
    connect(licenseAction, SIGNAL(triggered()), SLOT(show_license()));
}

void Interface::save_to_file()
{

	tabWidget->saveAll();
    	
}

void Interface::load_from_file()
{
    tabWidget->loadAll();
    
}


void Interface::show_info_widget()
{
	QMessageBox::about(this, tr("About Dungeon Client"), ("Using Dungeon Client Version: "+DCLIENTVERSION+"\n\n"+ABOUT));
}

void Interface::show_license()
{
	QMessageBox::about(this, tr("License"), LICENSE);
}

void Interface::show_contents_widget()
{
	QMessageBox::about(this, tr("Coming Soon..."), tr("This feature is in progress..."));
}



