/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:41:23 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/11/05 16:55:21 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUINTERFACE_HPP
# define MENUINTERFACE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <ncurses.h>

class MenuInterface
{
protected:
	int maxMY;
	int maxMX;
	std::string		StartMenuFile;
	std::string*	StartMenu;
	char *			SM;
	int 			button;

public:
	MenuInterface();
	MenuInterface(MenuInterface const & tmp);
	MenuInterface(int maxY, int maxX);
	MenuInterface &	operator=( MenuInterface const & tmp );
	~MenuInterface();
	int 			counter();
	void			readfile();
	std::string		getStartMenu(int n);
	int 			getButton();
	void			setButton(int b);


	void		draw(int y, int x, char * str);
	void		GameScene();
	virtual void		playerInfo(int hp, int score);
	virtual void		EndScene();
};

#endif

