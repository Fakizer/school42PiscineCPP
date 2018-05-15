// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 20:01:23 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/04 20:01:25 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameClass.hpp"
#include "MenuInterface.hpp"
#include "Player.hpp"

# include <ncurses.h>
# include <unistd.h>

void		StartMenu()
{
	MenuInterface StartM;
	int maxHeight;
	int maxWidth;
	int buttend = 0;

	while (true) {
		StartM.setButton(getch());
		if (StartM.getButton() == 27) {
			endwin();
			exit(0);		
		}
		getmaxyx(stdscr, maxHeight, maxWidth);
		MenuInterface StartM(maxHeight, maxWidth);
		StartM.readfile();
		refresh();
		StartM.setButton(getch());
		if (StartM.getButton() == 10) {
			clear();
			refresh();
			StartM.GameScene();
			break ;
		}
	}
}

int		main()
{
	MenuInterface StartM;
	Game g;

	initscr();
	nodelay(stdscr, true); //the getch not wait until the user pree a key
	keypad(stdscr, true);
	noecho();
	curs_set(false);
	StartMenu();
	g.start();
	nodelay(stdscr, false);
	getch();
	endwin();
	return 0;
}