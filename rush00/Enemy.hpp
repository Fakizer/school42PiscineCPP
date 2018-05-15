// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 22:01:17 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/04 22:01:20 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#ifndef ENEMY_HPP
# define ENEMY_HPP

class Enemy
{

private:
	int 	_max_x;
	int 	_max_y;

public:
	Enemy();
	Enemy(Enemy const & en);
	Enemy(char, int, int);
	~Enemy();

	Enemy & operator=(Enemy const & en);

	int		_x;//getter & setter
	int		_y;//getter & setter
	struct timeval _time;
	char	_type;//getter & setter
	bool	_alive;//getter & setter

	void	enemy_move();	
};


#endif