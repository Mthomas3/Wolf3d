/*
** control.c for  in /home/mart_4/rendu/last_wolf
** 
** Made by Thomas Martins
** Login   <mart_4@epitech.eu>
** 
** Started on  Sun Dec 21 20:13:14 2014 Thomas Martins
** Last update Sun Dec 21 20:13:14 2014 Thomas Martins
*/

#include "struct.h"

void		lets_go(t_calcul *play_three)
{
  double	x;
  double	y;
  double	dx;
  double	dy;

  dx = 0.1 * play_three->cos[play_three->two->a];
  dy = 0.1 * play_three->sin[play_three->two->a];
  x = play_three->two->pos_x;
  y = play_three->two->pos_y;
  if (play_three->two->tab[(int)(x + dx)][(int)y] != '1')
    play_three->two->pos_x = x + dx;
  if (play_three->two->tab[(int)x][(int)(y + dy)] != '1')
    play_three->two->pos_y = y + dy;
}

void		go_back(t_calcul *play_three)
{
  double	x;
  double	y;
  double	dx;
  double	dy;

  dx = 0.1 * play_three->cos[play_three->two->a];
  dy = 0.1 * play_three->sin[play_three->two->a];
  x = play_three->two->pos_x;
  y = play_three->two->pos_y;
  if (play_three->two->tab[(int)(x - dy)][(int)y] != '1')
    play_three->two->pos_x = x - dx;
  if (play_three->two->tab[(int)x][(int)(y - dy)] != '1')
    play_three->two->pos_y = y - dy;
}

void		turn_right(t_calcul *play_three)
{
  play_three->two->a = (play_three->two->a + 2) % 360;
}

void		turn_left(t_calcul *play_three)
{
  play_three->two->a = play_three->two->a - 2;
	if (play_three->two->a < 0)
	  play_three->two->a = 360 + play_three->two->a;
}

void		set_control(t_calcul *c, t_key *k, char *redraw)
{
  if (k->left && (*redraw = 1))
    turn_left(c);
  if (k->right && (*redraw = 1))
    turn_right(c);
  if (k->up && (*redraw = 1))
    lets_go(c);
  if (k->down && (*redraw = 1))
    go_back(c);
}
