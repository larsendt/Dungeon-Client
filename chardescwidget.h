#ifndef CHARDESCWIDGET_H
#define CHARDESCWIDGET_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include <QMap>

class CharDescWidget : public QWidget
{
	Q_OBJECT
	
  public:
    CharDescWidget(QWidget *parent = 0);
    QString get_name();
    QByteArray* save();
	void load(QByteArray *parent_byte);
  
  private slots:

  private:
    QHash <QString, QString> hash;
    QLabel *character_name_label;
    QLabel *player_name_label;
    QLineEdit *character_name;
    QLineEdit *player_name;
    QLabel *class_label;
    QLineEdit *char_class;
    QLabel *level_label;
    QLineEdit *level;
    QLabel *race_label;
    QLineEdit *race;
    QLabel *align_label;
    QLineEdit *alignment;
    QLabel *deity_label;
    QLineEdit *deity;
    QLabel *size_label;
    QLineEdit *size;
    QLabel *age_label;
    QLineEdit *age;
    QLabel *gender_label;
    QLineEdit *gender;
    QLabel *height_label;
    QLineEdit *height;
    QLabel *weight_label;
    QLineEdit *weight;
    QLabel *eyes_label;
    QLineEdit *eyes;
    QLabel *hair_label;
    QLineEdit *hair;
    QLabel *skin_label;
    QLineEdit *skin;
    QLabel *exp_label;
    QLineEdit *exp; 
    QLabel *notes_label;
    QTextEdit *notes;
};

#endif
