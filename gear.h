#ifndef GEAR_H
#define GEAR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDataStream>
#include <QMessageBox>
#include <QHash>
#include <QByteArray>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDialog>

#include <stdlib.h>


class Gear : public QWidget
{
	Q_OBJECT
	
	public:
		Gear(QWidget *parent = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		
	private slots:
		void add();
		void remove();
		void move_up();
		void move_down();
	
	private:
		QHash <QString, QString> hash;
		int num_items;
		
		QPushButton *add_button;
		QPushButton *remove_button;
		QPushButton *up_button;
		QPushButton *down_button;
		
		QTableWidget *table;
		
		

};


#endif
