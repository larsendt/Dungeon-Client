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

class SpellList : public QWidget
{
	Q_OBJECT
	
	public:
		SpellList(QWidget *parent = 0, int spell_level = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		void add();
		void remove();
		void move_up();
		void move_down();
		QString prepare();
		
	private slots:
	
	private:
		QHash <QString, QString> hash;
		int num_items;
		
		int level;
		
		QTableWidget *table;	
};

class Spells : public QWidget
{
	Q_OBJECT
	
	public:
		Spells(QWidget *parent = 0);
				
	private slots:
		void add();
		void remove();
		void move_up();
		void move_down();
		void prepare();
		void put_prepared_spell(QString spell);
		void remove_prepared();
		void clear_prepared();
	
	private:
		QPushButton *add_button;
		QPushButton *remove_button;
		QPushButton *up_button;
		QPushButton *down_button;
		QPushButton *prepare_button;
		QTabWidget *tabWidget;
		QListWidget *activeSpells;
		SpellList *level0;
		SpellList *level1;
		SpellList *level2;
		SpellList *level3;
		SpellList *level4;
		SpellList *level5;
		SpellList *level6;
		SpellList *level7;
		SpellList *level8;
		SpellList *level9;
};


#endif
