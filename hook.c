/*
** hook.c for  in /home/mart_4/rendu/last_wolf
** 
** Made by Thomas Martins
** Login   <mart_4@epitech.eu>
** 
** Started on  Sun Dec 21 20:13:31 2014 Thomas Martins
** Last update Sun Dec 21 20:13:31 2014 Thomas Martins
*/

#include "struct.h"

int		key_pressed(int key)
{
  t_key		*k;

  k = (get_calcul(NULL))->keys;
  if (key == ESC)
    {
      exit(0);
      free_all();
    }
  else if (KEY(key) == LEFT)
    k->left = 1;
  else if (KEY(key) == RIGHT)
    k->right = 1;
  else if (KEY(key) == UP)
    k->up = 1;
  else if (KEY(key) == DOWN)
    k->down = 1;
  return (0);
}

int		key_released(int key)
{
  t_key		*k;

  k = (get_calcul(NULL))->keys;
  if (KEY(key) == LEFT)
    k->left = 0;
  else if (KEY(key) == RIGHT)
    k->right = 0;
  else if (KEY(key) == UP)
    k->up = 0;
  else if (KEY(key) == DOWN)
    k->down = 0;
  return (0);
}

int		expose(int unused)
{
  char		redraw;
  t_calcul	*c;
  static int	i = 0;

  (void)unused;
  c = get_calcul(NULL);
  redraw = 0;
  if (++i % 15000)
    return (0);
  set_control(c, c->keys, &redraw);
  my_wolf_three_d(c);
  mlx_put_image_to_window(c->one->mlx_ptr, c->one->win_ptr,
			  c->one->d_pix->pixel, 0, 0);
  return (0);
}
