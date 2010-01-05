#ifndef CHARSTATS_H
#define CHARSTATS_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QToolTip>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include <QMap>

class CharStats : public QWidget
{
	Q_OBJECT
	
	public: 
		CharStats(QWidget *parent = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		
	private slots:
		void fill();
		
	private:
		QHash <QString, QString> hash;
		QPushButton *autofill;
		QLabel *plus_label;
		QLabel *minus_label;
		QLabel *equals_label;
	
		QLabel *cur_hp_label;
		QLineEdit *cur_hp;
		QLabel *base_hp_label;
		QLineEdit *base_hp;
		
		QLabel *str_label;
		QLabel *cur_str_label;
		QLabel *cur_str_mod;
		QLineEdit *cur_str;
		QLabel *base_str_mod;
		QLineEdit *base_str;
		
		QLabel *dex_label;
		QLabel *cur_dex_label;
		QLabel *cur_dex_mod;
		QLineEdit *cur_dex;
		QLabel *base_dex_mod;
		QLineEdit *base_dex;
		
		QLabel *con_label;
		QLabel *cur_con_label;
		QLabel *cur_con_mod;
		QLineEdit *cur_con;
		QLabel *base_con_mod;
		QLineEdit *base_con;
		
		QLabel *int_label;
		QLabel *cur_int_label;
		QLabel *cur_int_mod;
		QLineEdit *cur_int;
		QLabel *base_int_mod;
		QLineEdit *base_int;
		
		QLabel *wis_label;
		QLabel *cur_wis_label;
		QLabel *cur_wis_mod;
		QLineEdit *cur_wis;;
		QLabel *base_wis_mod;
		QLineEdit *base_wis;
		
		QLabel *cha_label;
		QLabel *cur_cha_label;
		QLabel *cur_cha_mod;
		QLineEdit *cur_cha;
		QLabel *base_cha_mod;
		QLineEdit *base_cha;
		
		QLabel *ac_label;
		QLabel *ac_dex_mod;
		QLineEdit *ac;
		QLabel *ten_label;
		QLineEdit *armor_bonus;
		QLineEdit *shield_bonus;
		QLineEdit *ac_size_mod;
		QLineEdit *nat_armor;
		QLineEdit *deflection_mod;
		QLineEdit *ac_misc_mod;
		
		QLabel *touch_ac_label;
		QLineEdit *touch_ac;
		
		QLabel *flat_ac_label;
		QLineEdit *flat_ac;
		
		QLabel *init_label;
		QLabel *init_plus;
		QLabel *init_equals;
		QLineEdit *init;
		QLineEdit *init_misc;
		QLabel *init_dex;
		
		QLabel *fort_save_label;
		QLabel *fort_equals;
		QLabel *fort_plus;
		QLineEdit *fort_save;
		QLineEdit *fort_base_save;
		QLabel *fort_con;
		QLineEdit *fort_magic;
		QLineEdit *fort_misc;
		QLineEdit *fort_misc_temp;
		
		QLabel *will_save_label;
		QLabel *will_equals;
		QLabel *will_plus;
		QLineEdit *will_save;
		QLineEdit *will_base_save;
		QLabel *will_wis;
		QLineEdit *will_magic;
		QLineEdit *will_misc;
		QLineEdit *will_misc_temp;
		
		QLabel *ref_save_label;
		QLabel *ref_equals;
		QLabel *ref_plus;
		QLineEdit *ref_save;
		QLineEdit *ref_base_save;
		QLabel *ref_dex;
		QLineEdit *ref_magic;
		QLineEdit *ref_misc;
		QLineEdit *ref_misc_temp;
		
		QLabel *base_att_label;
		QLineEdit *base_att;
		
		QLabel *spell_resist_label;
		QLineEdit *spell_resist;
		
		QLabel *size_mod_label;
		QLineEdit *size_mod;
		
		QLabel *grapple_label;
		QLabel *grapple_equals;
		QLabel *grapple_str;
		QLabel *grapple_plus;
		QLineEdit *grapple;
		QLineEdit *grapple_base_att;
		QLineEdit *grapple_size_mod;
		QLineEdit *grapple_misc_mod;

};


#endif
