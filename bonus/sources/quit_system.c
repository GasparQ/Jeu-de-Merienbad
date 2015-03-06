/*
** quit_system.c for function which will normally quit the sdl in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 18 22:39:01 2015 quentin gasparotto
** Last update Sun Feb 22 10:14:11 2015 quentin gasparotto
*/

#include "allum_1.h"

void	quit_button(t_button *button)
{
  SDL_FreeSurface(button->sprite);
  SDL_FreeSurface(button->txt.disp_text);
  TTF_CloseFont(button->txt.text_font);
}

void	quit_gui(t_GUI *every_button)
{
  quit_button(&(every_button->pvp));
  quit_button(&(every_button->pvai));
  quit_button(&(every_button->easy));
  quit_button(&(every_button->hard));
  quit_button(&(every_button->menu));
  quit_button(&(every_button->choose));
  quit_button(&(every_button->quit));
}

void	quit_system(t_system *sys)
{
  quit_gui(&(sys->every_button));
  TTF_Quit();
  SDL_FreeSurface(sys->screen);
  SDL_FreeSurface(sys->background);
  SDL_FreeSurface(sys->allumet_sprite);
  SDL_Quit();
  free(sys->allum_tab[0]);
  free(sys->allum_tab[1]);
}
