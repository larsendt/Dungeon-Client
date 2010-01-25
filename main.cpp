/*	
	Dungeon Client - An application geared towards making D&D character setup and use
	easier.
    Copyright (C) 2010 Dane T Larsen 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    You can contact the author at dane.t.larsen@gmail.com
*/

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
    window.setGeometry(x, y, width, height); //centers the window
    window.show();
    return app.exec();
}
