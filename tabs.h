#ifndef TABDIALOG_H
#define TABDIALOG_H

#include "chardescwidget.h"
#include "diceroller.h"
#include "charstats.h"
#include "charprofile.h"
#include "weapon.h"
#include "armor.h"
#include "spells.h"
#include "gear.h"
#include "feats.h"

#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QDataStream>
#include <QFile>
#include <QHash>

class QTabWidget;

class TabWidget: public QWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget *parent = 0);
    void saveAll();
    //void saveAllAs();
    void loadAll();
    void update();
    
private slots:

private:
	bool already_saved;
	QString fileName;
	QHash<QString, QByteArray> hash;
	
    QTabWidget *tabWidget;
    QHBoxLayout *dice;
    QScrollArea *char_rp;
    QScrollArea *char_stats;
    QScrollArea *charprofile_scroll;
    CharDescWidget *char_widget;
    Diceroller *dice_widget;
    CharStats *char_stats_widget;
    CharProfile *charprofile;
    Weapon *weapon;
    Armor *armor;
    Spells *spells;
    Gear *gear;
    Feats *feats;
    
    
};

 #endif
