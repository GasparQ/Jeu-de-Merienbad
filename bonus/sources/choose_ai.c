/*
** choose_ai.c for choose the ai in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 20 11:21:31 2015 quentin gasparotto
** Last update Sun Feb 22 12:34:38 2015 quentin gasparotto
*/

#include "allum_1.h"

int	display_ai_choices(t_system *sys)
{
  if (SDL_BlitSurface(sys->cleaner, NULL,
		      sys->screen, &(sys->clean_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.easy.sprite, NULL, sys->screen,
		      &(sys->every_button.easy.pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.hard.sprite, NULL, sys->screen,
		      &(sys->every_button.hard.pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.menu.sprite, NULL, sys->screen,
		      &(sys->every_button.menu.pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.easy.txt.disp_text, NULL, sys->screen,
		      &(sys->every_button.easy.txt.text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.hard.txt.disp_text, NULL, sys->screen,
		      &(sys->every_button.hard.txt.text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.menu.txt.disp_text, NULL, sys->screen,
		      &(sys->every_button.menu.txt.text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  return (CLEAN);
}

int	(*choose_ai(t_system *sys))(t_system *)
{
  if (display_ai_choices(sys) == ERROR)
    return (NULL);
  while (42)
    {
      if (flip_n_wait(sys) == ERROR)
	return (NULL);
      if (sys->event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (COL(sys->event.button.x))
	    {
	      if (BT1(sys->event.button.y))
		return (&montecarle);
	      else if (BT2(sys->event.button.y))
		return (&xor);
	      else if (BT3(sys->event.button.y))
		return (NULL);
	    }
	}
    }
}
