// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 20:16:44 by vrybchyc          #+#    #+#             //
//   Updated: 2017/11/04 20:16:44 by vrybchyc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameClass.hpp"
#include "Player.hpp"
#include "MenuInterface.hpp"
#include "Bullet.hpp"

Game::Game()
{
	initscr();
    nodelay(stdscr, true); //the getch not wait until the user pree a key
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, _maxHeight, _maxWidth);

    _frameChar = '_';
    _x = _maxWidth / 2;
    _y = _maxHeight - 2;
    _lives = 5;
    _delay = 40000;
	srand(time(0));
	p = Player(_x, _y, 1, 8, _maxWidth - 1, _maxHeight - 1);

	b = new t_blist;
	b->bl = new Bullet(_maxWidth -3 , _maxHeight - 3, _maxWidth / 2 , 9);
	b->next = NULL;

	e = new t_list;
	e->en = new Enemy('*', _maxWidth -3 , _maxHeight - 3);
	e->next = NULL;
	t_list *begin = e;
	t_list *tmp;
	for(int i = 1; i < _maxHeight; i++)
	{
		tmp = new t_list;
		tmp->en = new Enemy('*', _maxWidth -3 , _maxHeight - 3);
		tmp->next = NULL;
		e->next = tmp;
		e = e->next;		
	}
	e = begin;

	for(int i = 0; i < _maxWidth; i++)
	{
		move(7, i);
		addch(_frameChar);
	}

	refresh();
}

Game::~Game()
{
	nodelay(stdscr, false);
    getch();
    endwin();
}

t_blist	*Game::shoot()
{
	t_blist *begin;
	t_blist *tmp;

	begin = b;
	while (b->next)
		b = b->next;
	tmp = new t_blist;
	tmp->bl = new Bullet(_maxWidth -3 , _maxHeight - 3, _x, _y - 1);
	tmp->next = NULL;
	b->next = tmp;
	b = begin;

	return b;
}

void 	Game::_movebot()
{
	int  key = getch();

	if(key == KEY_LEFT && _x > 1)
	{
		p.player_move(_x - 1, _y);
		_x--;
	}
	if(key == KEY_RIGHT && (_x < _maxWidth - 2))
	{
		p.player_move(_x + 1, _y);
		_x++;
	}
	if(key == KEY_UP && (_y > 8))
	{
		p.player_move(_x, _y - 1);
		_y--;
	}
	if (key == 27) {
		while (1) {
			attron(A_BOLD);
			mvprintw(_maxHeight / 2 - 3, _maxWidth / 2 - 3, "PAUSE");
			mvprintw(_maxHeight / 2 - 2, _maxWidth / 2 - 10, "TO CONTINUE PRESS ESC");
			mvprintw(_maxHeight / 2 - 1, _maxWidth / 2 - 10, "TO EXIT PRESS ENTER");
			mvprintw(_maxHeight / 2 + 1, _maxWidth / 2 - 10, "YOUR SCORE:   %d", p.getScore());
			attroff(A_BOLD);
			int button = getch();
			if (button == 10) {
				endwin();
				exit(1);
			}
			if (button == 27) {
				mvprintw(_maxHeight / 2 - 3, _maxWidth / 2 - 3, "     ");
				mvprintw(_maxHeight / 2 - 2, _maxWidth / 2 - 10, "                     ");
				mvprintw(_maxHeight / 2 - 1, _maxWidth / 2 - 10, "                   ");
				mvprintw(_maxHeight / 2 + 1, _maxWidth / 2 - 10, "                ");
				break ;
			}
		}
	}
	if(key == KEY_DOWN && (_y < _maxHeight - 2))
	{
		p.player_move(_x, _y + 1);
		_y++;
	}
	if(key == 32)
		b = shoot();
}

void		Game::_collision()
{
	t_blist *begin = b;
	t_list *begin_en = e;
	while(e)
	{
		if (e->en->_x == p.getX() && e->en->_y == p.getY())
		{		
			p.decreaseLives();
			e->en->_alive = false;
			b = begin;
			e = begin_en;
			return ;
		}
		b = begin;
		if (!e->en->_alive)
		{
			e = e->next;
			continue;
		}
		while (b)
		{
			if (!b->bl->_alive)
			{
				b = b->next;
				continue;
			}
			if (e->en->_x == b->bl->_x && e->en->_y == b->bl->_y)
			{
				e->en->_alive = false;
				b->bl->_alive = false;
				p.setScore(10);
				move(e->en->_x, e->en->_y);
				addch(' ');
			}
			b = b->next;
		}
		e = e->next;

	}
	b = begin;
	e = begin_en;
	refresh();
}

void	Game::start()
{

	int z = 0;
	move(_y, _x);
	addch('A');
	t_list 		*begin = e;
	t_blist 	*begin_b = b;
	time_t 		ti = time(0);
	while(1)
	{
		time_t now = time(0);
		mvprintw(4, 90, "%d", now - ti);
		if (z >= _maxHeight)
			z = _maxHeight;
		e = begin;
		b = begin_b;
		_movebot();
		for (int i = 0; i < z-1; i++)
		{		 	
		 	e->en->enemy_move();
			e = e->next;		 	
		}
		e = begin;
		z++;
		_collision();
		while (b)
		 {
		 	b->bl->bullet_move();
		 	b = b->next;
		 }
		_collision();
		if (p.getLives() <= 0)
		{
			p.EndScene();
			break ;
		}
		usleep(_delay);
	}
	while(e)
	{
		t_list *tmp_en;
		delete e->en;
		tmp_en = e;
		e = e->next;
		delete tmp_en;
	}
	while(b) {
		t_blist *tmp_b;
		delete b->bl;
		tmp_b = b;
		b = b->next;
		delete tmp_b;
    }
}





















