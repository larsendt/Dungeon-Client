#ifndef ARMOR_H
#define ARMOR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDataStream>
#include <QMessageBox>
#include <QHash>
#include <QByteArray>

class Armor : public QWidget
{
	Q_OBJECT
	
	public:
		Armor(QWidget *parent = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		
	private slots:
	
	private:
		int WIDTH;
		QHash <QString, QString> hash;
		QLabel *armor_name_label;
		QLineEdit *armor_name;
		QLabel *armor_type_label;
		QLineEdit *armor_type;
		QLabel *armor_ac_bonus_label;
		QLineEdit *armor_ac_bonus;
		QLabel *max_dex_label;
		QLineEdit *max_dex;
		QLabel *armor_check_penalty_label;
		QLineEdit *armor_check_penalty;
		QLabel *armor_spell_faliure_label;
		QLineEdit *armor_spell_faliure;
		QLabel *armor_speed_label;
		QLineEdit *armor_speed;
		QLabel *armor_weight_label;
		QLineEdit *armor_weight;
		QLabel *armor_special_properties_label;
		QLineEdit *armor_special_properties;
		
		QLabel *shield_name_label;
		QLineEdit *shield_name;
		QLabel *shield_ac_bonus_label;
		QLineEdit *shield_ac_bonus;
		QLabel *shield_weight_label;
		QLineEdit *shield_weight;
		QLabel *shield_check_penalty_label;
		QLineEdit *shield_check_penalty;
		QLabel *shield_spell_faliure_label;
		QLineEdit *shield_spell_faliure;
		QLabel *shield_special_properties_label;
		QLineEdit *shield_special_properties;
		
		QLabel *pro_item_1_label;
		QLineEdit *pro_item_1;
		QLabel *pro_item_1_ac_bonus_label;
		QLineEdit *pro_item_1_ac_bonus;
		QLabel *pro_item_1_weight_label;
		QLineEdit *pro_item_1_weight;
		QLabel *pro_item_1_special_properties_label;
		QLineEdit *pro_item_1_special_properties;		
		
		QLabel *pro_item_2_label;
		QLineEdit *pro_item_2;
		QLabel *pro_item_2_ac_bonus_label;
		QLineEdit *pro_item_2_ac_bonus;
		QLabel *pro_item_2_weight_label;
		QLineEdit *pro_item_2_weight;
		QLabel *pro_item_2_special_properties_label;
		QLineEdit *pro_item_2_special_properties;	
};


#endif
