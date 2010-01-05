#ifndef GEARITEM_H
#define GEARITEM_H

#include <QListWidgetItem>

class GearItem : public QListWidgetItem
{
	Q_OBJECT
	
	public:
		GearItem(QListWidget *parent = 0);
	
	private slots:
	
	private:
		QString *item;
		QString *page;
		QString *wt;
	
};

#endif
