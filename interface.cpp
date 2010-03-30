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
#include <QScrollArea>

#include "interface.h"

QString DCLIENTVERSION = "0.5.09022010";
QString ABOUT = "Author: Dane Larsen\ndane.t.larsen@gmail.com\n\nAbout: \nDungeon Client is an application geared towards simplicity of D&D character setup, which typically takes quite a long time, and can detract from the experience of a onetime campaign. \n\nThis is accomplished by a moderate amount of automation, but not enough to remove control from the player/DM. \n\nThis automation allows for speedy character creation by removing the need to constantly refer to the Player's Handbook.\n\nBut remember: There is nothing like rolling two handfulls of d6's.";
QString LICENSE = "Dungeon Client - An application geared towards making D&D character setup and use easier.\n\nCopyright (C) 2010 Dane T Larsen \n\nThis program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n\nThis program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. \n\nYou should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.\n\nYou can contact the author at dane.t.larsen@gmail.com";


Interface::Interface()
{
    createMenu();
    
	tabWidget = new TabWidget;
	
	setMenuBar(menuBar);

	setCentralWidget(tabWidget);
    setWindowTitle(tr("Dungeon Client"));
}

void Interface::createMenu()
{
    menuBar = new QMenuBar;


	//construct the menus
    fileMenu = new QMenu(tr("&File"), this);
	networkMenu = new QMenu(tr("&Network"), this);
    helpMenu = new QMenu(tr("&Help"), this);
    
    openAction = fileMenu->addAction(tr("&Open"));
    saveAction = fileMenu->addAction(tr("&Save"));
    fileMenu->addSeparator();
    //saveAsAction = fileMenu->addAction(tr("S&ave As"));
    exitAction = fileMenu->addAction(tr("&Quit"));
    
    contentsAction = helpMenu->addAction(tr("Contents"));
    licenseAction = helpMenu->addAction(tr("License"));
    aboutAction = helpMenu->addAction(tr("About"));
    helpMenu->addSeparator();
    aboutQtAction = helpMenu->addAction(tr("About Qt"));
    
	connectAction = networkMenu->addAction(tr("Co&nnect"));
	disconnectAction = networkMenu->addAction(tr("&Disconnect"));
	ipAction = networkMenu->addAction(tr("Your &IP Address"));
	disconnectAction->setEnabled(false);
    exitAction->setShortcut(tr("CTRL+Q"));
    openAction->setShortcut(tr("CTRL+O"));
    saveAction->setShortcut(tr("CTRL+S"));
    //saveAsAction->setShortcut(tr("CTRL+SHIFT+S"));
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(networkMenu);
    menuBar->addMenu(helpMenu);
    
    connect(exitAction, SIGNAL(triggered()), SLOT(close()));
    connect(saveAction, SIGNAL(triggered()), SLOT(save_to_file()));
    //connect(saveAsAction, SIGNAL(triggered()), SLOT(save_as()));
    connect(openAction, SIGNAL(triggered()), SLOT(load_from_file()));
    connect(aboutAction, SIGNAL(triggered()), SLOT(show_info_widget()));
    connect(contentsAction, SIGNAL(triggered()), SLOT(show_contents_widget()));
    connect(licenseAction, SIGNAL(triggered()), SLOT(show_license()));
    connect(connectAction, SIGNAL(triggered()), SLOT(show_connection_dialog()));
    connect(disconnectAction, SIGNAL(triggered()), SLOT(disconnect()));
    connect(ipAction, SIGNAL(triggered()), SLOT(show_my_ip()));
    connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));
}

//tell tabs to save
void Interface::save_to_file()
{
	tabWidget->saveAll();	
}

//tell tabs to load
//tabs handles all of the file ops
void Interface::load_from_file()
{
    tabWidget->loadAll();   
}

//info is at the top of this file
void Interface::show_info_widget()
{
	QMessageBox::about(this, tr("About Dungeon Client"), ("Using Dungeon Client Version: "+DCLIENTVERSION+"\n\n"+ABOUT));
}

//ditto
void Interface::show_license()
{
	QMessageBox::about(this, tr("License"), LICENSE);
}

void Interface::show_contents_widget()
{
	QMessageBox::about(this, tr("Coming Soon..."), tr("This feature is in progress..."));
}


void Interface::show_connection_dialog()
{
	bool ok; //will be false if user clicks cancel, true if user clicks ok
	QString text = QInputDialog::getText(this, tr("Connect to DM"), tr("Enter your Dungeon Master's IP address."), QLineEdit::Normal, tr("xxx.xxx.xxx.xxx"), &ok); 
	if (ok && !text.isEmpty())
	{
		dm_ip = text;
		disconnectAction->setEnabled(true);
		connectAction->setEnabled(false);
	}
	
	//pass the ip address on to the tab widget
	tabWidget->set_dm_ip(dm_ip);
}

void Interface::disconnect()
{
	connectAction->setEnabled(true);
	disconnectAction->setEnabled(false);
	
	//tell tab widget to disconnect
	tabWidget->disconnect();
}

void Interface::show_my_ip()
{
	//need to figure this one out, also will be useful for obtaining dm_ip
	QString myip = "xxx.xxx.xxx.xxx";
	QMessageBox::information(this, "IP Address", "Your IP Address is: "+myip);
}

//give credit where credit is due (Thanks Nokia for FOSSing Qt!)
void Interface::aboutQt()
{
	QMessageBox::aboutQt(this);
}

