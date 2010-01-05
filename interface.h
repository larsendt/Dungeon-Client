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
	//void update_all();

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
