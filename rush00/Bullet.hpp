// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 18:35:26 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/05 18:35:27 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULLET_HPP
# define BULLET_HPP

class Bullet
{

private:
	int 	_max_x;
	int 	_max_y;



public:
	Bullet();
	Bullet(int, int, int, int);
	Bullet(Bullet const & bl);
	~Bullet();

	Bullet & operator=(Bullet const & bl);

	int		_x;//getter & setter
	int		_y;//getter & setter
	bool	_alive;//getter & setter

	void	bullet_move();	
};

#endif