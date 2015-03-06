/*
** disp_hit.c for display the last hit done in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 21 20:01:36 2015 quentin gasparotto
** Last update Sun Feb 22 12:36:17 2015 quentin gasparotto
*/

#include "allum_1.h"

int	display_new_hit(t_system *sys)
{
  char	*nb;

  sys->turn_tell.pos.y = sys->pos[sys->line_hit - 1].y;
  sys->turn_tell.pos.x = 3 * WIN_WDTH / 4;
  if ((nb = nbr_to_str(-sys->allum_hit)) == NULL)
    return (my_strerror(MALLOC_ERR));
  if ((sys->turn_tell.player[2].disp_text =
       TTF_RenderText_Blended(sys->turn_tell.player[2].text_font, nb,
			      sys->turn_tell.player[2].text_color)) == NULL)
    return (my_strerror(TEXT_ERR));
  free(nb);
  if ((sys->turn_tell.hide_player[2] =
       SDL_CreateRGBSurface(SDL_HWSURFACE,
			    sys->turn_tell.player[2].disp_text->w,
			    sys->turn_tell.player[2].disp_text->h,
			    32, 0, 0, 0, 0)) == NULL)
    return (my_strerror(SURF_ERR));
  if (SDL_BlitSurface(sys->turn_tell.player[2].disp_text, NULL,
		      sys->screen, &(sys->turn_tell.pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  SDL_FreeSurface(sys->turn_tell.player[2].disp_text);
  return (CLEAN);
}

int		disp_hit(t_system *sys)
{
  if (sys->allum_hit > 0)
    {
      if (sys->turn_tell.hide_player[2] != NULL)
	{
	  if (SDL_BlitSurface(sys->turn_tell.hide_player[2], NULL,
			      sys->screen, &(sys->turn_tell.pos)) == ERROR)
	    return (my_strerror(BLIT_ERR));
	  SDL_FreeSurface(sys->turn_tell.hide_player[2]);
	}
      if (display_new_hit(sys) == ERROR)
	return (ERROR);
      sys->allum_hit = 0;
      sys->line_hit = -1;
    }
  return (CLEAN);
}
