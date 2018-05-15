/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:35:56 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/11/05 16:59:54 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MenuInterface.hpp"

# include <ncurses.h>

MenuInterface::MenuInterface()	  {
	StartMenuFile = "qwe.scene";
}

MenuInterface::MenuInterface(MenuInterface const & tmp) {
	*this = tmp;
}

MenuInterface::MenuInterface(int maxMY, int maxMX) : maxMY(maxMY), maxMX(maxMX) {
	StartMenuFile = "qwe.scene";
}

MenuInterface &		MenuInterface::operator=( MenuInterface const & tmp ) {
	maxMX = tmp.maxMX;
	maxMY = tmp.maxMY;
	StartMenuFile = tmp.StartMenuFile;
	StartMenu = tmp.StartMenu;
	SM = tmp.SM;
	return *this;
}

MenuInterface::~MenuInterface() {

}

int 			MenuInterface::counter() {
	int count = 0;
	std::string buff;

	std::ifstream filec(StartMenuFile);
	if (!(filec.is_open()))
		std::cout << "File isn't open" << std::endl;
	while (std::getline(filec, buff))
		count++;
	filec.close();
	return count;
}

void			MenuInterface::readfile() {
	std::string buff;
	int i = 0;
	int count = counter();

	std::ifstream filew(StartMenuFile);
	if (!(filew.is_open()))
		std::cout << "File isn't open" << std::endl;
	std::string* StartMenu = new std::string[count];

	while (std::getline(filew, buff)) {
		StartMenu[i] = buff;
		++i;
	}
	filew.close();
	int y = 2;
	int x = 5;
	for (i = 0; i < count; ++i) {
		char * cstr = new char [StartMenu[i].length()+1];
 		std::strcpy (cstr, StartMenu[i].c_str());
 		draw(y, x, cstr);
 		y++;
	}
}

std::string			MenuInterface::getStartMenu(int n) {
	return StartMenu[n];
}

void			MenuInterface::draw(int y, int x, char * str) {
	mvprintw(y, x, "%s", str);
}

void			MenuInterface::playerInfo(int hp, int score) {
	std::string	str1;
	str1 = "PLAYER HP:";
	char *str = new char[str1.length()+1];
	std::strcpy (str, str1.c_str());
	draw(4, 10, str);
	mvprintw(4, 25, "%d", hp);
	delete [] str;
	str1 = "SCORE:";
	str = new char[str1.length()+1];
	std::strcpy (str, str1.c_str());
	draw(4, 40, str);
	mvprintw(4, 55, "%d", score);
	delete [] str;
	str1 = "TIME PLAY:";
	str = new char[str1.length()+1];
	std::strcpy (str, str1.c_str());
	draw(4, 70, str);
	delete [] str;
}

void			MenuInterface::GameScene() {
	for (int i = 0; i < maxMX; ++i) {
		mvprintw(0, i, "#");
	}
	for (int i = 0; i < maxMY; ++i) {
		mvprintw(i , 0,"#");
	}
	for (int i = 0; i < maxMX; ++i) {
		mvprintw(maxMY - 1, i,"#");
	}
	for (int i = 0; i < maxMY; ++i) {
		mvprintw(i , maxMX - 1,"#");
	}
	for (int i = 1; i < maxMX - 2; ++i) {
		mvprintw(7, i, "-");
	}
}

int 			MenuInterface::getButton() {
	return button;
}

void			MenuInterface::setButton(int b) {
	button = b;
}

void		MenuInterface::EndScene() {

}

