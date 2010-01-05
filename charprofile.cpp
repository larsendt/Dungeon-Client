#include "charprofile.h"

CharProfile::CharProfile(QWidget *parent, CharDescWidget *character_info)
{
	QGridLayout *layout = new QGridLayout;
	QVBoxLayout *info = new QVBoxLayout;
	
	characterinfo = character_info;
	
	QPixmap profilepic(300, 200);
	selectpic = new QPushButton("Select Picture");
	connect(selectpic, SIGNAL(clicked()), SLOT(load_pic()));
	charname = new QLabel(characterinfo->get_name());
	charname_label = new QLabel("Character: ");
	piclabel = new QLabel();
	piclabel->setPixmap(profilepic);
	profilepic.fill(Qt::white);
	picscroll = new QScrollArea();
	picscroll->setWidget(piclabel);
	picscroll->setMaximumWidth(350);
	picscroll->setMinimumWidth(300);
	
	QHBoxLayout *charname_hbox = new QHBoxLayout;
	charname_hbox->addStretch(1);
	charname_hbox->addWidget(charname_label);
	charname_hbox->addWidget(charname);
	charname_hbox->addStretch(1);
	
	info->addLayout(charname_hbox);
		
	layout->addWidget(picscroll, 0, 0, 1, 1);
	layout->addWidget(selectpic, 1, 0, 1, 1);
	layout->addLayout(info, 0, 1, 1, 1);
	
	setLayout(layout);
}
	
void CharProfile::load_pic()
{
	//profilepic.load("deadpool.jpg");
}	

void CharProfile::update()
{
	charname->setText(characterinfo->get_name());
}



