/*
** sdl_system.h for sdl_system in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 18 11:37:46 2015 quentin gasparotto
** Last update Sun Feb 22 12:06:39 2015 quentin gasparotto
*/

#ifndef SDL_SYSTEM_H_
# define SDL_SYSTEM_H_

# include "SDL.h"
# include "SDL_ttf.h"
# include <math.h>
# include <stdlib.h>

# define WIN_HGHT	800
# define WIN_WDTH	800

# define BUTTON_WDTH	100
# define BUTTON_HGHT	50

# define INIT_ERR	"Can't init sdl system\n"
# define INIT_VID	"Can't init video mode\n"
# define FILL_ERR	"Can't fill surface\n"
# define LOAD_ERR	"Can't load bmp image\n"
# define BLIT_ERR	"Can't blit the surface\n"
# define INIT_TTF_ERR	"Can't init text system\n"
# define FONT_ERR	"Can't load the font\n"
# define TEXT_ERR	"Can't create text surface\n"
# define FLIP_ERR	"Can't flip buffer screen\n"
# define WAIT_ERR	"Problem while waiting an event\n"
# define SURF_ERR	"Can't create the surface\n"

enum	BOOL
  {
    FALSE,
    TRUE
  };

typedef struct	s_text_system
{
  TTF_Font	*text_font;
  SDL_Color	text_color;
  SDL_Rect	text_pos;
  SDL_Surface	*disp_text;
}		t_text_system;

typedef struct	s_button
{
  SDL_Rect	pos;
  SDL_Surface	*sprite;
  int		is_active;
  t_text_system	txt;
}		t_button;

typedef struct	s_GUI
{
  t_button	pvp;
  t_button	pvai;
  t_button	easy;
  t_button	hard;
  t_button	choose;
  t_button	menu;
  t_button	quit;
}		t_GUI;

typedef struct	s_turn
{
  t_text_system	player[3];
  SDL_Surface	*hide_player[3];
  SDL_Surface	*win;
  SDL_Rect	pos;
}		t_turn;

typedef struct	s_system
{
  SDL_Event	event;
  SDL_Surface	*screen;
  SDL_Surface	*background;
  SDL_Surface	*allumet_sprite;
  SDL_Surface	*fire_allumet_sprite;
  SDL_Surface	*no_allumet_sprite;
  SDL_Surface	*cleaner;
  SDL_Surface	*hide_choose;
  SDL_Rect	clean_pos;
  SDL_Rect	pos[4];
  int		selec;
  int		line_hit;
  int		allum_hit;
  int		allum_nb;
  int		disp;
  t_turn	turn_tell;
  char		*allum_tab[2];
  t_GUI		every_button;
  int		player;
}		t_system;

/*
** Prototypes
*/

/*
**	quit_system.c
*/

void	quit_system(t_system *sys);

/*
**	disp_allumets.c
*/

int	disp_allumets(t_system *sys);
int	disp_empty(t_system *sys, int x_decal, int line, SDL_Surface *sprite);

/*
**	resolve_key.c
*/

int	resolve_key(t_system *sys);

/*
**	search_hit.c
*/

int	search_allums(t_system *sys);

/*
**	disp_allumets.c
*/

int	disp_allumets(t_system *sys);

/*
**	init_allumets_pos.c
*/

void	init_allum_pos(t_system *sys);

/*
**	init_sdl_sys.c
*/

int	init_sdl_system(t_system *sys);

#endif /* !SDL_SYSTEM_H_ */
