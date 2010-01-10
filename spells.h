#ifndef SPELLS_H
#define SPELLS_H

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
#include <QTabWidget>
#include <QCheckBox>
#include <QTextBrowser>

class Spells : public QWidget
{
	Q_OBJECT
	
	public:
		Spells(QWidget *parent = 0);
		
	private slots:
	
	private:
	
};

class SpellList : public QWidget
{
	Q_OBJECT
	
	public:
		SpellList(int spell_level);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		
	private slots:
		void add();
		void remove();
		void move_up();
		void move_down();
		void prepare();
	
	private:
		QHash <QString, QString> hash;
		int num_items;
		
		int level;
		
		QPushButton *add_button;
		QPushButton *remove_button;
		QPushButton *up_button;
		QPushButton *down_button;
		QPushButton *prepare_button;
		
		QTableWidget *table;
	
};


#endif
