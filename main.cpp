#include <QApplication>
#include <QDesktopWidget>
#include "interface.h"

int main(int argc, char *argv[])
{
 	QApplication app(argc, argv);
 	
	int width, height, x, y;
	width = 660;
	height = 400;
	int screenWidth;
  	int screenHeight;
	QDesktopWidget *desktop = QApplication::desktop();

	screenWidth = desktop->width();
	screenHeight = desktop->height(); 

	x = (screenWidth - width) / 2;
  	y = (screenHeight - height) / 2;
	
    Interface window;
    window.setGeometry(x, y, width, height);
    window.show();
    return app.exec();
}
