#ifndef WEAPON_H
#define WEAPON_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QDataStream>
#include <QFile>
#include <QMessageBox>
#include <QMap>

class Weapon : public QWidget
{
	Q_OBJECT
	
  public:
    Weapon(QWidget *parent = 0);
  
  private slots:

  private:
    QLabel *weapon_label;
	QLineEdit *weapon;
	QLabel *att_bonus_label;
	QLineEdit *att_bonus;
	QLabel *damage_label;
	QLineEdit *damage;
	QLabel *critical_label;
	QLineEdit *critical;
	QLabel *range_label;
	QLineEdit *range;
	QLabel *type_label;
	QLineEdit *type;
	QLabel *notes_label;
	QTextEdit *notes;
	QLabel *ammo_label;
	QLineEdit *ammo;
	QLabel *ammo_num_label;
	QLineEdit *ammo_num;
};

#endif
