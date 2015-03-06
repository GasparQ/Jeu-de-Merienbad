/*
** disp_allumets.c for disp allumets in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 18 15:34:59 2015 quentin gasparotto
** Last update Sun Feb 22 14:32:18 2015 quentin gasparotto
*/

#include "allum_1.h"

int	disp_empty(t_system *sys, int x_decal, int line, SDL_Surface *sprite)
{
  SDL_Rect	all_pos;
  int		which_all;

  all_pos.y = sys->pos[line].y;
  which_all = (x_decal - (sys->pos[line].x -
			  sys->allum_tab[0][line] / 2 * 50)) / 50 - 1;
  all_pos.x = x_decal;
  while (all_pos.x <= sys->pos[line].x + sys->allum_tab[0][line] / 2 * 50)
    {
      if (++which_all >= sys->allum_tab[0][line] - sys->allum_tab[1][line])
	{
	  if (SDL_BlitSurface(sprite, NULL, sys->screen, &all_pos) == ERROR)
	    return (my_strerror(BLIT_ERR));
	}
      else
	{
	  if (SDL_BlitSurface(sys->no_allumet_sprite, NULL,
			      sys->screen, &all_pos) == ERROR)
	    return (my_strerror(BLIT_ERR));
	}
      all_pos.x = all_pos.x + 50;
    }
  return (CLEAN);
}

int		disp_allumets(t_system *sys)
{
  int		line;
  int		x_decal;

  line = 0;
  while (line < 4)
    {
      x_decal = sys->pos[line].x - sys->allum_tab[0][line] / 2 * 50;
      if (disp_empty(sys, x_decal, line, sys->allumet_sprite) == ERROR)
	return (ERROR);
      line = line + 1;
    }
  return (CLEAN);
}
