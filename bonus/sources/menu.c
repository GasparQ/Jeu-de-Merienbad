/*
** menu.c for menu system in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 20 11:03:41 2015 quentin gasparotto
** Last update Sun Feb 22 12:49:11 2015 quentin gasparotto
*/

#include "allum_1.h"

int	display_menu(t_system *sys)
{
  if (SDL_BlitSurface(sys->cleaner, NULL, sys->screen,
		      &(sys->clean_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.pvp.sprite, NULL, sys->screen,
		      &(sys->every_button.pvp.pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.pvai.sprite, NULL, sys->screen,
		      &(sys->every_button.pvai.pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.quit.sprite, NULL, sys->screen,
		      &(sys->every_button.quit.pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.pvp.txt.disp_text, NULL, sys->screen,
		      &(sys->every_button.pvp.txt.text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.pvai.txt.disp_text, NULL, sys->screen,
		      &(sys->every_button.pvai.txt.text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->every_button.quit.txt.disp_text, NULL, sys->screen,
		      &(sys->every_button.quit.txt.text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  return (CLEAN);
}

int	(*infinite_wheel(t_system *sys))(t_system *)
{
  int	(*ret_fptr)(t_system *);

  while (42)
    {
      if (flip_n_wait(sys) == ERROR)
	return (NULL);
      if (sys->event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (COL(sys->event.button.x))
	    {
	      if (BT1(sys->event.button.y))
		return (&player_interface);
	      else if (BT2(sys->event.button.y))
		{
		  if ((ret_fptr = choose_ai(sys)) != NULL)
		    return (ret_fptr);
		  if (display_menu(sys) == ERROR)
		    return (NULL);
		}
	      else if (BT3(sys->event.button.y))
		return (NULL);
	    }
	}
    }
}

int	(*choose_mode(t_system *sys))(t_system *)
{
  if (display_menu(sys) == ERROR)
    return (NULL);
  return (infinite_wheel(sys));
}

