// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 20:06:03 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/04 20:06:04 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

#ifndef GAME_HPP
# define GAME_HPP

typedef struct 			s_list
{
	Enemy				*en;
	struct 		s_list 	*next;	
}						t_list;

typedef struct 			s_blist
{
	Bullet				*bl;
	struct 	s_blist 	*next;	
}      					t_blist;

class Game
{
private:
	int			_x;
	int			_y;
	int			_lives;
	int			_maxWidth;
	int			_maxHeight;
	int			_delay;
	char		_frameChar;
	Player 			p;
	
	void		_collision();
	void		_movebot();
	t_blist		*shoot(); 

public:
	Game();
	~Game();
	void	start();

	t_list *e;
	t_blist *b;
};



#endif