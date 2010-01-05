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

class Gear : public QWidget
{
	Q_OBJECT
	
	public:
		Gear(QWidget *parent = 0);
		QByteArray* save();
		void load(QByteArray *parent_byte);
		
	private slots:
	
	private:
		QHash <QString, QString> hash;
		QLabel *gear_label;

};


#endif
