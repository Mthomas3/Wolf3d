/*
** wall.c for  in /home/mart_4/rendu/last_wolf
** 
** Made by Thomas Martins
** Login   <mart_4@epitech.eu>
** 
** Started on  Sun Dec 21 20:12:49 2014 Thomas Martins
** Last update Sun Dec 21 20:12:49 2014 Thomas Martins
*/

#include <math.h>
#include <mlx.h>
#include "struct.h"

void		print_error(void)
{
  my_putstr("error try again please");
  my_putchar('\n');
  free_all();
  exit(0);
}

void		back_up(t_param *one)
{
  int		x;
  int		y;
  int		color;

  y = 0;
  color = 0x3300FF;
  while (y < one->height)
    {
      x = 0;
      while (x < one->width)
	{
	  my_pixel_img(x, y, one, color);
	  x = x + 1;
	}
      y = y + 1;
      if (y == (one->height / 2))
	color = 0x00ff00;
    }
}

void		wall_one(t_calcul *play_three, int x)
{
  int		giant;
  int		i;
  int		y;

  giant = play_three->one->height / (2 * play_three->two->pos_k);
  i = 0;
  while (i <= giant)
    {
      y = i + play_three->one->height / 2;
      my_pixel_img(x, y, play_three->one, 0xFFF2550);
      i = i + 1;
    }
  i = 0;
  while (i <= giant)
    {
      y = play_three->one->height / 2 - (giant - i);
      my_pixel_img(x, y, play_three->one, 0xFFF2550);
      i = i + 1;
    }
}

void		wall_two(t_calcul *play_three, double x1, double y1)
{
  int		x;
  int		y;

  play_three->two->pos_k = 1.0;
  x = play_three->two->pos_x + play_three->two->pos_k *
    (x1 - play_three->two->pos_x);
  y = play_three->two->pos_y + play_three->two->pos_k *
    (y1 - play_three->two->pos_y);
  while (play_three->two->tab[x][y] != '1')
    {
      x = play_three->two->pos_x + play_three->two->pos_k *
	(x1 - play_three->two->pos_x);
      y = play_three->two->pos_y + play_three->two->pos_k *
	(y1 - play_three->two->pos_y);
      play_three->two->pos_k = play_three->two->pos_k + 0.01;
    }
}

void		my_wolf_three_d(t_calcul *play_three)
{
  double	x1;
  double	y1;
  int		a;

  a = 0;
  back_up(play_three->one);
  while (a < play_three->one->width)
    {
      y1 = ((play_three->one->width / 2) - (double)a) / play_three->one->width;
      x1 = 0.5 * play_three->cos[play_three->two->a] - y1 *
	play_three->sin[play_three->two->a];
      y1 = 0.5 * play_three->sin[play_three->two->a] + y1 *
	play_three->cos[play_three->two->a];
      x1 = x1 + play_three->two->pos_x;
      y1 = y1 + play_three->two->pos_y;
      wall_two(play_three, x1, y1);
      wall_one(play_three, a);
      a++;
    }
}
