// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 18:35:33 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/05 20:54:31 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bullet.hpp"
#include "GameClass.hpp"
#include "ncurses.h"

Bullet::Bullet()
{
	_max_x = 0;
	 _max_y = 0;
	 _x = 0;
	 _y = 0;
	 _alive = true;
}

Bullet::Bullet(Bullet const & bl)
{
	*this = bl;	
}

Bullet::~Bullet(){}

Bullet::Bullet(int max_x, int max_y, int x, int y)
{
	 _max_x = max_x;
	 _max_y = max_y;
	 _x = x;
	 _y = y;
	 _alive = true;

}

Bullet & Bullet::operator=(Bullet const & bl)
{
	return *this;
}

void	Bullet::bullet_move()
{
	if (_alive && _y == 9)
	{
		move(_y, _x);
		addch(' ');
		refresh();
		_alive = false;
	}
	else if (_alive)
	{		
		_y--;
		move(_y, _x);
		addch('^');
		move(_y + 1, _x);
		addch(' ');
		refresh();	
	}
	refresh();
}
