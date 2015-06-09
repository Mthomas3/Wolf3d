/*
** function_all.c for  in /home/mart_4/rendu/last_wolf
** 
** Made by Thomas Martins
** Login   <mart_4@epitech.eu>
** 
** Started on  Sun Dec 21 20:14:56 2014 Thomas Martins
** Last update Sun Dec 21 20:14:56 2014 Thomas Martins
*/

#include "struct.h"
#include <math.h>

int		my_putstr(char *str)
{
  int		a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a++;
    }
  return (0);
}

void		my_strcat(char *dest, char *src)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
}

int		my_pixel_img(int x, int y, t_param *one, int color)
{
  int		a;
  int		b;
  int		c;
  int		d;

  d = x * one->d_pix->bpp / 8 + y * one->d_pix->sizeline;
  a = (color >> 16) & 255;
  b = (color >> 8) & 255;
  c = color & 255;
  one->d_pix->mat[d + 0] = c;
  one->d_pix->mat[d + 1] = b;
  one->d_pix->mat[d + 2] = a;
  one->d_pix->mat[d+ 3] = 0;
  return (0);
}

void		my_first_calcul(t_calcul *play_three)
{
  int		a;
  double	b;

  a = -1;
  while (++a <= 360)
    {
      b = (double)a * (M_PI / 180);
      play_three->sin[a] = sin(b);
    }
}

void		my_second_calcul(t_calcul *play_three)
{
  int		a;
  double	b;

  a = -1;
  while (++a <= 360)
    {
      b = (double)a * (M_PI / 180);
      play_three->cos[a] = cos(b);
    }
}
