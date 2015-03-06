/*
** resolve_player.c for resolve player text system in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 21 12:40:59 2015 quentin gasparotto
** Last update Sun Feb 22 12:46:10 2015 quentin gasparotto
*/

#include "allum_1.h"

void	init_plyr_tab(int (*plyr_o_ai[3])(t_system *),
		      char *sys_text[3])
{
  plyr_o_ai[0] = &player_interface;
  plyr_o_ai[1] = &montecarle;
  plyr_o_ai[2] = &xor;
  sys_text[0] = "Player 2";
  sys_text[1] = "AI";
  sys_text[2] = "AI";
}

int	init_txt_sys(t_system *sys)
{
  if ((sys->turn_tell.player[0].text_font =
       TTF_OpenFont("./font/perfect_match.ttf", 55)) == NULL)
    return (my_strerror(FONT_ERR));
  sys->turn_tell.player[1].text_font = sys->turn_tell.player[0].text_font;
  sys->turn_tell.player[2].text_font = sys->turn_tell.player[0].text_font;
  sys->turn_tell.player[0].text_color.r = 255;
  sys->turn_tell.player[0].text_color.g = 100;
  sys->turn_tell.player[0].text_color.b = 100;
  sys->turn_tell.player[1].text_color = sys->turn_tell.player[0].text_color;
  sys->turn_tell.player[2].text_color = sys->turn_tell.player[0].text_color;
  return (CLEAN);
}

int	init_player(t_system *sys)
{
  if (init_txt_sys(sys) == ERROR)
    return (ERROR);
  if ((sys->turn_tell.player[0].disp_text =
       TTF_RenderText_Blended(sys->turn_tell.player[0].text_font, "Player 1",
			      sys->turn_tell.player[0].text_color)) == NULL)
    return (my_strerror(TEXT_ERR));
  sys->turn_tell.player[0].text_pos.x = 3 * WIN_WDTH / 4 -
    sys->turn_tell.player[0].disp_text->w / 2;
  sys->turn_tell.player[0].text_pos.y = WIN_HGHT / 4 -
    sys->turn_tell.player[0].disp_text->h / 2;
  if ((sys->turn_tell.hide_player[0] =
       SDL_CreateRGBSurface(SDL_HWSURFACE,
			    sys->turn_tell.player[0].disp_text->w,
			    sys->turn_tell.player[0].disp_text->h,
			    32, 0, 0, 0, 0)) == NULL)
    return (my_strerror(SURF_ERR));
  sys->turn_tell.hide_player[2] = NULL;
  return (CLEAN);
}

int	resolve_player(t_system *sys, int (*plyr_o_ai)(t_system *))
{
  int	(*tab_func[3])(t_system *);
  char	*sys_text[3];
  int	i;

  if (init_player(sys) == ERROR)
    return (ERROR);
  init_plyr_tab(tab_func, sys_text);
  i = -1;
  while (tab_func[++i] != plyr_o_ai);
  if ((sys->turn_tell.player[1].disp_text =
       TTF_RenderText_Blended(sys->turn_tell.player[1].text_font,
			      sys_text[i],
			      sys->turn_tell.player[1].text_color)) == NULL)
    return (my_strerror(TEXT_ERR));
  sys->turn_tell.player[1].text_pos.x =
    3 * WIN_WDTH / 4 - sys->turn_tell.player[1].disp_text->w / 2;
  sys->turn_tell.player[1].text_pos.y =
    WIN_HGHT / 4 - sys->turn_tell.player[1].disp_text->h / 2;
  if ((sys->turn_tell.hide_player[1] =
       SDL_CreateRGBSurface(SDL_HWSURFACE,
			    sys->turn_tell.player[1].disp_text->w,
			    sys->turn_tell.player[1].disp_text->h,
			    32, 0, 0, 0, 0)) == NULL)
    return (my_strerror(SURF_ERR));
  return (CLEAN);
}
