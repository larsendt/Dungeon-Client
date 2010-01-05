#include "diceroller.h"
#include <ctime>
#include <cstdlib>
#include <QGroupBox>

Diceroller::Diceroller(QWidget *parent)
	:QWidget(parent)
{
	totalint = 0;
	QGridLayout *diceLayout = new QGridLayout();
	QGroupBox *box = new QGroupBox(this);
	box->setLayout(diceLayout);
	
	QHBoxLayout *totallayout = new QHBoxLayout();
	QHBoxLayout *dielayout = new QHBoxLayout();
	QHBoxLayout *rolllayout = new QHBoxLayout();
	QHBoxLayout *clearlayout = new QHBoxLayout();
	QVBoxLayout *dynlabel = new QVBoxLayout();
	
	roll_button = new QPushButton("Roll");
	QPushButton *clear_button = new QPushButton("Clear");
	die_size_label = new QLabel("Die Size: ");
  	multiplier_label = new QLabel("Multiplier: ");
  	die_size = new QLineEdit("20");
  	die_size->setMaximumSize(60, 25);
  	multiplier = new QLineEdit("1");
  	multiplier->setMaximumSize(60, 25);
  	output = new QTextBrowser();
  	you_rolled = new QLabel("You rolled: ");
  	xdx = new QLabel("0d0");
  	total_label = new QLabel("Total: ");
  	total = new QLabel("0");
  	notes = new QTextEdit("Some free space for miscellaneous notes.");
  	clear_notes = new QPushButton("Clear");
  	notes->setMinimumSize(330, 250);
  	
  	roll_button->setMinimumSize(120, 25);
  	clear_button->setMinimumSize(120, 25);
  	
  	rolllayout->addWidget(roll_button);
  	rolllayout->addStretch(1);
  	clearlayout->addWidget(clear_button);
  	clearlayout->addStretch(1);
  	
  	dielayout->addWidget(you_rolled);
  	dielayout->addWidget(xdx);
  	dielayout->addStretch(1);
  	totallayout->addWidget(total_label);
  	totallayout->addWidget(total);
  	totallayout->addStretch(1);
  	
  	dynlabel->addLayout(dielayout);
  	dynlabel->addLayout(totallayout);
  	dynlabel->addStretch(1);

	diceLayout->addWidget(multiplier_label, 0, 0, 1, 1);
	diceLayout->addWidget(multiplier, 0, 1, 1, 1);
	diceLayout->addWidget(die_size_label, 1, 0, 1, 1);
	diceLayout->addWidget(die_size, 1, 1, 1, 1);
	diceLayout->addLayout(rolllayout, 0, 2, 1, 1);
	diceLayout->addLayout(clearlayout, 1, 2, 1, 1);
	diceLayout->addWidget(notes, 0, 3, 3, 1);
	diceLayout->addWidget(clear_notes, 3, 3, 1, 1);
	diceLayout->addLayout(dynlabel, 2, 2, 1, 1);
	diceLayout->addWidget(output, 2, 0, 2, 2);
	
	connect(roll_button, SIGNAL(clicked()), SLOT(roll()));
	connect(clear_button, SIGNAL(clicked()), SLOT(clear()));
	connect(clear_notes, SIGNAL(clicked()), SLOT(burn_notes()));
	
	setLayout(diceLayout);

}

void Diceroller::burn_notes()
{
	notes->setText("");
}

void Diceroller::roll()
{
	int die;
  	int mult = multiplier->text().toInt();

  	srand(time(NULL));
  	
  	xdx->setText((multiplier->text())+"d"+(die_size->text()));
  	
  	
  	for(int i = 0; i < mult; i++)
  	{ 
  		die = die_size->text().toInt();
  		die = (rand()%die) + 1;
  		totalint += die;
  		output->append(QString::number(die));
  	}
  	total->setText(QString::number(totalint));
  	totalint = 0;
  	output->append("***");
  		
}

void Diceroller::clear()
{
	output->setText("");
	xdx->setText("0d0");
	total->setText("0");
	totalint = 0;
}
