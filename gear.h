#ifndef GEAR_H
#define GEAR_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>

class Gear : public QWidget
{
	Q_OBJECT
	
	public:
		Gear(QWidget *parent = 0);
		
	private slots:
	
	private:
		//for whatever reason, variables declared here cause a segfault, 
		//currently they are residing as globals in the .cpp
		
	
};

#endif
