/*
** struct.h for  in /home/mart_4/rendu/last_wolf
** 
** Made by Thomas Martins
** Login   <mart_4@epitech.eu>
** 
** Started on  Sun Dec 21 20:15:14 2014 Thomas Martins
** Last update Mon Feb  9 20:54:32 2015 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/Xlib.h>
# include <stdio.h>

# define INIT			mlx_init
# define NEW_WIN(X, Y)		mlx_new_window((X)->mlx_ptr, (X)->width, (X)->height, Y)
# define NEW_IMG		mlx_new_image
# define GET_DATA		mlx_get_data_addr
# define IMG_TOWIN		mlx_put_image_to_window
# define HOOK			mlx_hook
# define LOOP			mlx_loop
# define XPM_TOIMG		mlx_xpm_file_to_image
# define PUT_STRING		mlx_string_put

# define KEY(x)			(x - 65361)
# define ESC			65307
# define LEFT			2
# define RIGHT			0
# define UP			1
# define DOWN			3

typedef struct s_global	t_global;
typedef struct s_key	t_key;
typedef struct s_param	t_param;
typedef struct s_player	t_player;
typedef struct s_calcul	t_calcul;
typedef struct s_pixel	t_pixel;

struct				s_key
{
  char				left;
  char				right;
  char				up;
  char				down;
};

struct				s_pixel
{
  void				*pixel;
  char				*mat;
  int				bpp;
  int				sizeline;
  int				endian;
};

struct				s_param
{
  void				*mlx_ptr;
  void				*win_ptr;
  t_pixel			*d_pix;
  int				width;
  int				height;
};

struct				s_player
{
  char				tab[24][29];
  float				pos_x;
  float				pos_y;
  float				pos_k;
  int				a;
};

struct				s_calcul
{
  int				a;
  t_param			*one;
  t_player			*two;
  t_key				*keys;
  float				sin[360];
  float				cos[360];
};

void				my_wolf_three_d(t_calcul *play_three);
int				my_pixel_img(int x, int y, t_param *one, int color);
void				set_control(t_calcul *c, t_key *k, char *redraw);
void				my_first_calcul(t_calcul *play_three);
void				my_second_calcul(t_calcul *play_three);
void				my_map(t_player *p);
void				my_putchar(char c);
void				my_strcat(char *dest, char *src);
t_calcul			*get_calcul(t_calcul *c);
int				expose(int unused);
int				key_pressed(int key);
int				key_released(int key);
void				free_all(void);

#endif
