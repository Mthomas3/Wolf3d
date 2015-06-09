/*
** my_map.c for  in /home/mart_4/rendu/last_wolf
** 
** Made by Thomas Martins
** Login   <mart_4@epitech.eu>
** 
** Started on  Sun Dec 21 20:13:44 2014 Thomas Martins
** Last update Sun Dec 21 20:13:44 2014 Thomas Martins
*/

#include "struct.h"

void			free_all(void)
{
  t_calcul		*c;

  c = get_calcul(NULL);
  free(c->one->d_pix);
  free(c->one);
  free(c->two);
  free(c->keys);
  free(c);
}

t_calcul                *get_calcul(t_calcul *c)
{
  static t_calcul       *cal = NULL;

  if (c)
    cal = c;
  return (cal);
}

void			my_map(t_player *two)
{
  my_strcat(two->tab[0], "111111111111111111111111111111");
  my_strcat(two->tab[1], "100000000000000000000000000001");
  my_strcat(two->tab[2], "100000000000000000000000000001");
  my_strcat(two->tab[3], "111111111111000111111111001111");
  my_strcat(two->tab[4], "111111111111000111111111001111");
  my_strcat(two->tab[5], "110000000000001000000000000001");
  my_strcat(two->tab[6], "110000000000011000000000000001");
  my_strcat(two->tab[7], "110011111111111001111001100111");
  my_strcat(two->tab[8], "1100000000000110000000011O0111");
  my_strcat(two->tab[9], "110000000000011000000001100111");
  my_strcat(two->tab[10], "11111111110011111001111100111");
  my_strcat(two->tab[11], "11111000000011111001111100111");
  my_strcat(two->tab[12], "11111000000001111000000000111");
  my_strcat(two->tab[13], "11111001111111111000000000111");
  my_strcat(two->tab[14], "11000000000111111111111111111");
  my_strcat(two->tab[15], "11000000000111111111111111111");
  my_strcat(two->tab[16], "11000000000111111111111111111");
  my_strcat(two->tab[17], "11111111111111111111111111111");
  two->pos_x = 2;
  two->pos_y = 2;
  two->pos_k = 0;
  two->a = 90;
}
