// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 11:17:57 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/05 11:17:59 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <string>
#include "MenuInterface.hpp"

#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player : public MenuInterface
{

private:
	int				_x;
	int				_y;
	int 			_minWidth;
	int				_minHeight;
	int 			_maxWidth;
	int 			_maxHeight;
	int				_level;
	int				_lives;
	int				_maxX;
	int				_maxY;
	int				_score;
	std::string 	_body[20];

public:
	Player();
	Player(int x, int y, int minWidth,int minHeight, int maxWidth,int maxHeight);
	Player(Player const & pl);
	~Player();
	
	void 				player_move(int n_x, int n_y);
	int					getX() const;
	int					getY() const;
	int					getMinWidth() const;
	int					getMinHeight() const;
	int					getMaxWidth() const;
	int					getMaxHeight() const;
	int					getLevel() const;
	int					getLives() const;
	int					getScore() const;
	void				decreaseLives();
	void				setScore(int);
	void				EndScene();
	//increase level ADD


	Player & operator=(Player const & pl);

};

#endif