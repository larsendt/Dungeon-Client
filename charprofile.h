#ifndef CHARPROFILE_H
#define CHARPROFILE_H

#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>
#include <QTextEdit>
#include "chardescwidget.h"

class CharProfile : public QWidget
{
	Q_OBJECT
	
	public:
		CharProfile(QWidget *parent = 0, CharDescWidget *character_info = 0);
		void update();
		
	private slots:
		void load_pic();
	
	private:
		QPixmap profilepic;
		QLabel *piclabel;
		QScrollArea *picscroll;
		QPushButton *selectpic;
		QLabel *charname;
		QLabel *charname_label;
		CharDescWidget *characterinfo;
	
};




#endif
