// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 11:18:06 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/05 11:18:07 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"
#include "MenuInterface.hpp"

Player::Player()
{
	_x = 0;
	_y = 0;
	_minWidth = 0;
	_minHeight = 0;
	_maxWidth = 0;
	_maxHeight = 0;
	_level = 1;
	_lives = 50;
	_maxX = 1;
	_maxY = 1;
	_score = 0;
	_body[0] = "A";
}

Player::Player(int x, int y, int minWidth,int minHeight, int maxWidth, int maxHeight)
{
	_x = x;
	_y = y;
	_minWidth = minWidth;
	_minHeight = minHeight;
	_maxWidth = maxWidth;
	_maxHeight = maxHeight;
	_level = 1;
	_lives = 50;
	_maxX = 1;
	_maxY = 1;
	_score = 0;
	_body[0] = "A";
}

Player::Player(Player const & pl)
{
	if (this != &pl)
	{
		_x = pl.getX();
		_y = pl.getY();
		_minWidth = pl.getMinWidth();
		_minHeight = pl.getMinHeight();
		_maxWidth = pl.getMaxWidth();
		_maxHeight = pl.getMaxHeight();
		_level = pl.getLevel();
		_lives = pl.getLives();
		_maxX = 1;
		_maxY = 1;
		_score = 0;
		_body[0] = "A";
	}
	*this = pl;
}

Player::~Player(){}

int		Player::getX() const
{
	return _x;
}

int		Player::getY() const
{
	return _y;
}

int		Player::getMinWidth() const
{
	return _minWidth;
}

int		Player::getMinHeight() const
{
	return _minHeight;
}

int		Player::getMaxWidth() const
{
	return _maxWidth;
}

int		Player::getMaxHeight() const
{
	return _maxHeight;
}

int		Player::getLevel() const
{
	return _level;
}

int		Player::getLives() const
{
	return _lives;
}

int		Player::getScore() const
{
	return _score;
}

void	Player::decreaseLives()
{
	_lives -= 1;
	if (_lives < 0)
		_lives = 0;
}

void	Player::setScore(int score)
{
	_score += score;
}

Player & Player::operator=(Player const & pl)
{
	if (this != &pl)
	{
		_x = pl.getX();
		_y = pl.getY();
		_minWidth = pl.getMinWidth();
		_minHeight = pl.getMinHeight();
		_maxWidth = pl.getMaxWidth();
		_maxHeight = pl.getMaxHeight();
		_level = pl.getLevel();
		_maxX = 1;
		_maxY = 1;
		_score = 0;
		_body[0] = "A";
	}
	return *this;
}

void	Player::player_move(int n_x, int n_y)
{
	if (n_x < _minWidth || n_y < _minHeight
		|| ((n_x - _maxX) > (_maxWidth)) || ((n_y - _maxY) > (_maxHeight)))
		return;
	for(int i = 0; i < _maxY; i++)
	{
		for(int j = 0; j <_body[i].length(); j++)
		{
			move(_y + i, _x + j);
			addch(' ');
		}
	}
	_x = n_x;
	_y = n_y;
	for(int i = 0; i < _maxY; i++)
	{
		move(_y + i, _x);
		char * cstr = new char [_body[i].length()+1];
		std::strcpy (cstr, _body[i].c_str());
    	printw("%s", cstr);
    	delete [] cstr;
	}
	playerInfo(_lives, _score);
	refresh();
}

void			Player::EndScene() {
	while (1) {
		attron(A_BOLD);
		mvprintw(maxMY / 2 - 1, maxMX / 2 - 6, "YOU ARE DEAD");
		mvprintw(maxMY / 2, maxMX / 2 - 8, "YOUR SCORE:    %d", _score);
		mvprintw(maxMY / 2 + 1, maxMX / 2 - 10, "TO EXIT PRESS ENTER");
		attroff(A_BOLD);
		button = getch();
		if (button == 10) {
			endwin();
			exit(1);
		}
	}
}

