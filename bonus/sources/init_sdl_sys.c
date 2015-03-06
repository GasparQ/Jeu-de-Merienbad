/*
** init_sdl_sys.c for init the sdl system in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 18 14:29:50 2015 quentin gasparotto
** Last update Sun Feb 22 12:37:25 2015 quentin gasparotto
*/

#include "allum_1.h"

int	init_button(t_button *button, int x, int y, const char *text)
{
  button->pos.x = x;
  button->pos.y = y;
  if ((button->sprite = SDL_LoadBMP("./img/button_back.bmp")) == NULL)
    return (my_strerror(LOAD_ERR));
  button->is_active = FALSE;
  if ((button->txt.text_font =
       TTF_OpenFont("./font/perfect_match.ttf", 40)) == NULL)
    return (my_strerror(FONT_ERR));
  button->txt.text_color.r = 150;
  button->txt.text_color.g = 0;
  button->txt.text_color.b = 0;
  if ((button->txt.disp_text =
       TTF_RenderText_Blended(button->txt.text_font, text,
			      button->txt.text_color)) == NULL)
    return (my_strerror(TEXT_ERR));
  button->txt.text_pos.x = button->pos.x + (button->sprite->w / 2 -
					    button->txt.disp_text->w / 2);
  button->txt.text_pos.y = button->pos.y + (button->sprite->h / 2 -
					    button->txt.disp_text->h / 2);
  return (CLEAN);
}

int	init_gui(t_system *sys)
{
  if (TTF_Init() == ERROR)
    return (my_strerror(INIT_TTF_ERR));
  if (init_button(&(sys->every_button.pvp), WIN_WDTH / 2 - 100,
		  WIN_HGHT / 2 - 50, "P v P") == ERROR)
    return (ERROR);
  if (init_button(&(sys->every_button.pvai), WIN_WDTH / 2 - 100,
		  WIN_HGHT / 2 + 50, "P v AI") == ERROR)
    return (ERROR);
  if (init_button(&(sys->every_button.easy), WIN_WDTH / 2 - 100,
		  WIN_HGHT / 2 - 50, "Easy") == ERROR)
    return (ERROR);
  if (init_button(&(sys->every_button.hard), WIN_WDTH / 2 - 100,
		  WIN_HGHT / 2 + 50, "Hard") == ERROR)
    return (ERROR);
  if (init_button(&(sys->every_button.menu), WIN_WDTH / 2 - 100,
		  WIN_HGHT / 2 + 250, "Menu") == ERROR)
    return (ERROR);
  if (init_button(&(sys->every_button.choose), WIN_WDTH / 2 + 200,
		  WIN_HGHT / 2 + 250, "Choose") == ERROR)
    return (ERROR);
  if (init_button(&(sys->every_button.quit), WIN_WDTH / 2 - 100,
		  WIN_HGHT / 2 + 250, "Quit") == ERROR)
    return (ERROR);
  return (CLEAN);
}

void	plyr_init(t_system *sys)
{
  sys->turn_tell.player[0].text_font = NULL;
  sys->turn_tell.player[0].disp_text = NULL;
  sys->turn_tell.player[1].text_font = NULL;
  sys->turn_tell.player[1].disp_text = NULL;
  sys->turn_tell.hide_player[2] = NULL;
  sys->turn_tell.pos.x = 0;
  sys->turn_tell.pos.y = 0;
}

int	load_all_img(t_system *sys)
{
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  if ((sys->background = SDL_LoadBMP("./img/back.bmp")) == NULL)
    return (my_strerror(LOAD_ERR));
  if (SDL_BlitSurface(sys->background, NULL, sys->screen, &pos) == ERROR)
    return (my_strerror(BLIT_ERR));
  if ((sys->allumet_sprite = SDL_LoadBMP("./img/allumet.bmp")) == NULL)
    return (my_strerror(LOAD_ERR));
  if ((sys->fire_allumet_sprite = SDL_LoadBMP("./img/fire_allum.bmp")) == NULL)
    return (my_strerror(LOAD_ERR));
  if ((sys->no_allumet_sprite = SDL_LoadBMP("./img/no_allum.bmp")) == NULL)
    return (my_strerror(LOAD_ERR));
  if ((sys->cleaner = SDL_LoadBMP("./img/cleaner.bmp")) == NULL)
    return (my_strerror(LOAD_ERR));
  if ((sys->hide_choose = SDL_LoadBMP("./img/hide_choose.bmp")) == NULL)
    return (my_strerror(LOAD_ERR));
  return (CLEAN);
}

int	init_sdl_system(t_system *sys)
{
  if (SDL_Init(SDL_INIT_VIDEO) == ERROR)
    return (my_strerror(INIT_ERR));
  if (SDL_SetVideoMode(WIN_HGHT, WIN_WDTH, 32, SDL_HWSURFACE) == NULL)
    return (my_strerror(INIT_VID));
  SDL_WM_SetCaption("Allum 1", NULL);
  if ((sys->screen = SDL_SetVideoMode(WIN_HGHT, WIN_WDTH,
				      32, SDL_HWSURFACE)) == NULL)
    return (my_strerror(INIT_VID));
  if (SDL_FillRect(sys->screen, NULL,
		   SDL_MapRGB(sys->screen->format, 0, 0, 0)) == ERROR)
    return (my_strerror(FILL_ERR));
  if (load_all_img(sys) == ERROR)
    return (ERROR);
  sys->clean_pos.x = 250;
  sys->clean_pos.y = 300;
  sys->selec = FALSE;
  if (init_gui(sys) == ERROR)
    return (ERROR);
  plyr_init(sys);
  return (CLEAN);
}
