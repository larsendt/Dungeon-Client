#include <QtGui>
#include <QScrollArea>

#include "interface.h"

/*
this is the backup info for compile.sh
vvvv0.1.712010.0001
*/

QString DCLIENTVERSION = "0.1.412010";
QString ABOUT = "Author: Dane Larsen\ndane.t.larsen@gmail.com\n\nAbout: \nDungeon Client is an application geared towards simplicity of D&D character setup, which typically takes quite a long time, and can detract from the experience of a onetime campaign. \n\nThis is accomplished by a moderate amount of automation, but not enough to remove control from the player/DM. \n\nThis automation allows for speedy character creation by removing the need to constantly refer to the Player's Handbook.\n\nBut remember: There is nothing like rolling two handfulls of d6's.";
QString LICENSE = "Step 1: Make a cool D&D application.\nStep 2: ???\nStep 3: Profit!";


Interface::Interface()
{
    createMenu();
    
	tabWidget = new TabWidget;
	connect(tabWidget, SIGNAL(currentChanged(0)), this, SLOT(update()));

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
/*
void Interface::save_as()
{
    	tabWidget->saveAllAs();
}
*/
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



