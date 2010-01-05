#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>

class Diceroller : public QWidget
{
	Q_OBJECT
	
  public:
    Diceroller(QWidget *parent = 0);
  
  private slots:
  	void roll();
  	void clear();
  	void burn_notes();

  private:
  	int totalint;
  	QLabel *die_size_label;
  	QLabel *multiplier_label;
  	QLabel *you_rolled;
  	QLabel *xdx;
  	QLabel *total_label;
  	QLabel *total;
  	QLineEdit *die_size;
  	QLineEdit *multiplier;
  	QTextBrowser *output;
  	QPushButton *roll_button;
  	QTextEdit *notes;
  	QPushButton *clear_notes;

  	
  	
};

#endif
