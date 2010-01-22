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
#include <QListWidget>

class Spells : public QWidget
{
	Q_OBJECT
	
	public:
		Spells(QWidget *parent = 0);
		void prepare(QString *spell_name, int spell_level);
				
	private slots:
		//void remove();
		void prepare();
	
	private:
	
};

class SpellList : public QWidget
{
	Q_OBJECT
	
	public:
		SpellList(Spells *parent = 0, int spell_level = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		QString *get_prepared();
		
	private slots:
		void add();
		void remove();
		void move_up();
		void move_down();
		void prepare();
		
	signals:
		void prepared();
	
	private:
		QHash <QString, QString> hash;
		int num_items;
		
		Spells *parent_widget;
		
		int level;
		
		QPushButton *add_button;
		QPushButton *remove_button;
		QPushButton *up_button;
		QPushButton *down_button;
		QPushButton *prepare_button;
		
		QTableWidget *table;
	
};


#endif
