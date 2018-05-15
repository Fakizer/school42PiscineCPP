// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 22:01:33 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/04 22:01:34 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"
#include "GameClass.hpp"

Enemy::Enemy()
{
	 _type = '*';
	 _max_x = 50;
	 _max_y = 50;
	 _x = 0;
	 _y = 0;
	 _alive = true;	
}

Enemy::Enemy(Enemy const & en)
{
	*this = en;	
}


Enemy::~Enemy(){}

Enemy::Enemy(char type, int max_x, int max_y)
{
	 _type = type;
	 _max_x = max_x;
	 _max_y = max_y;
	 _x = rand() % max_x + 1;
	 _y = 8;
	 _alive = true;
	 gettimeofday(&_time, NULL);

}

Enemy & Enemy::operator=(Enemy const & en)
{
	return *this;
}

void	Enemy::enemy_move()
{

	if (_alive && _y == _max_y + 1)
	{
		move(_y, _x);
		addch(' ');
		refresh();
		_x = rand() % _max_x + 1;
	 	_y = 8;
	}
	else if (_alive)
	{
		_y++;
		move(_y, _x);
		addch(_type);
		move(_y - 1, _x);
		addch(' ');
		refresh();
	}
	refresh();
}