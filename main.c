/*
** main.c for  in /home/mart_4/rendu/last_wolf
** 
** Made by Thomas Martins
** Login   <mart_4@epitech.eu>
** 
** Started on  Sun Dec 21 20:13:07 2014 Thomas Martins
** Last update Tue Jun  9 23:18:27 2015 Thomas Martins
*/

#include "struct.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

t_calcul	*init_c(void)
{
  t_calcul	*c;

  c = malloc(sizeof(t_calcul));
  c->one = malloc(sizeof(t_param));
  c->two = malloc(sizeof(t_player));
  c->keys = malloc(sizeof(t_key));
  c->one->d_pix = malloc(sizeof(t_pixel));
  get_calcul(c);
  return (c);
}

void		init_key(t_key *k)
{
  k->left = 0;
  k->right = 0;
  k->up = 0;
  k->down = 0;
}

void		init_mlx(t_param *p, t_key *k)
{
  if (!(p->mlx_ptr = INIT()))
    print_error();
  if (!(p->win_ptr = NEW_WIN(p, "wolf3d")))
    print_error();
  p->d_pix->pixel = NEW_IMG(p->mlx_ptr, p->width, p->height);
  p->d_pix->mat = mlx_get_data_addr(p->d_pix->pixel, &(p->d_pix->bpp), &(p->d_pix->sizeline), &(p->d_pix->endian));
  mlx_hook(p->win_ptr, 2, 1L, key_pressed, k);
  mlx_hook(p->win_ptr, 3, (1L << 1), key_released, k);
  mlx_expose_hook(p->win_ptr, expose, p);
  mlx_loop_hook(p->mlx_ptr, expose, p);
  LOOP(p->mlx_ptr);
}

int		main(int ac, char **av, char **env)
{
  t_calcul	*c;

  (void)ac;
  (void)av;
  if (!*env)
    {
      my_putstr("error env, try again please");
      my_putchar('\n');
      return (3);
    }
  c = init_c();
  c->one->width = 1220;
  c->one->height = 720;
  my_map(c->two);
  init_key(c->keys);
  my_first_calcul(c);
  my_second_calcul(c);
  init_mlx(c->one, c->keys);
  return (0);
}
