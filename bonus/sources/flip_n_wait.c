/*
** flip_n_wait.c for flip screen and wait event in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Feb 22 11:29:55 2015 quentin gasparotto
** Last update Sun Feb 22 11:31:32 2015 quentin gasparotto
*/

#include "allum_1.h"

int	flip_n_wait(t_system *sys)
{
  if (SDL_Flip(sys->screen) == ERROR)
    return (my_strerror(FLIP_ERR));
  if (SDL_WaitEvent(&(sys->event)) == 0)
    return (my_strerror(WAIT_ERR));
  return (CLEAN);
}
