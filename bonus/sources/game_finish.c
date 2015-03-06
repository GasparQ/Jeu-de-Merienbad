/*
** game_finish.c for when the game finish in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Feb 22 10:08:42 2015 quentin gasparotto
** Last update Sun Feb 22 12:51:41 2015 quentin gasparotto
*/

#include "allum_1.h"

void	quit_player(t_system *sys)
{
  if (sys->turn_tell.player[0].disp_text != NULL)
    SDL_FreeSurface(sys->turn_tell.player[0].disp_text);
  if (sys->turn_tell.player[1].disp_text != NULL)
    SDL_FreeSurface(sys->turn_tell.player[1].disp_text);
  if (sys->turn_tell.player[0].text_font != NULL)
    TTF_CloseFont(sys->turn_tell.player[0].text_font);
  SDL_FreeSurface(sys->turn_tell.hide_player[0]);
  SDL_FreeSurface(sys->turn_tell.hide_player[1]);
  SDL_FreeSurface(sys->turn_tell.hide_player[2]);
  SDL_FreeSurface(sys->turn_tell.win);
}

int	disp_win_screen(t_system *sys)
{
  SDL_Rect	win_pos;

  SDL_BlitSurface(sys->turn_tell.hide_player[2], NULL,
		  sys->screen, &(sys->turn_tell.pos));
  SDL_BlitSurface(sys->turn_tell.hide_player[sys->player], NULL,
		  sys->screen, &(sys->turn_tell.player[sys->player].text_pos));
  sys->turn_tell.player[sys->player].text_pos.x =
    WIN_WDTH / 2 - sys->turn_tell.player[sys->player].disp_text->w / 2;
  sys->turn_tell.player[sys->player].text_pos.y =
    WIN_HGHT / 2 - sys->turn_tell.player[sys->player].disp_text->h / 2 - 50;
  SDL_BlitSurface(sys->turn_tell.player[sys->player].disp_text, NULL,
		  sys->screen, &(sys->turn_tell.player[sys->player].text_pos));
  sys->turn_tell.win =
    TTF_RenderText_Blended(sys->turn_tell.player[sys->player].text_font, "WIN",
			   sys->turn_tell.player[sys->player].text_color);
  win_pos.x = WIN_WDTH / 2 - sys->turn_tell.win->w / 2;
  win_pos.y = WIN_HGHT / 2 - sys->turn_tell.win->h / 2 + 50;
  SDL_BlitSurface(sys->turn_tell.win, NULL, sys->screen, &(win_pos));
  SDL_BlitSurface(sys->every_button.menu.sprite, NULL, sys->screen,
		  &(sys->every_button.menu.pos));
  SDL_BlitSurface(sys->every_button.menu.txt.disp_text, NULL, sys->screen,
		  &(sys->every_button.menu.txt.text_pos));
  SDL_Flip(sys->screen);
  return (CLEAN);
}

int	go_back_menu(t_system *sys)
{
  while (42)
    {
      SDL_WaitEvent(&(sys->event));
      if (sys->event.type == SDL_MOUSEBUTTONDOWN &&
	  sys->event.button.x >= sys->every_button.menu.pos.x &&
	  sys->event.button.x <= sys->every_button.menu.pos.x + 200 &&
	  sys->event.button.y >= sys->every_button.menu.pos.y &&
	  sys->event.button.y <= sys->every_button.menu.pos.y + 100)
	{
	  return (CLEAN);
	}
      else if (sys->event.type == SDL_KEYDOWN &&
	       sys->event.key.keysym.sym == SDLK_ESCAPE)
	return (EXIT_PROG);
    }
  return (CLEAN);
}

int		game_finish(t_system *sys)
{
  disp_win_screen(sys);
  SDL_BlitSurface(sys->turn_tell.hide_player[sys->player], NULL,
		  sys->screen, &(sys->turn_tell.player[sys->player].text_pos));
  quit_player(sys);
  if (sys->disp == FALSE)
    return (EXIT_PROG);
  return (go_back_menu(sys));
}
