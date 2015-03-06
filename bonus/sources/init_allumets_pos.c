/*
** init_allumets_pos.c for allumets pos in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 18 14:43:03 2015 quentin gasparotto
** Last update Fri Feb 20 10:48:24 2015 quentin gasparotto
*/

#include "allum_1.h"

void	init_allum_pos(t_system *sys)
{
  sys->pos[0].x = WIN_WDTH / 2;
  sys->pos[0].y = WIN_HGHT / 2 - 150;
  sys->pos[1].x = WIN_WDTH / 2;
  sys->pos[1].y = WIN_HGHT / 2 - 50;
  sys->pos[2].x = WIN_WDTH / 2;
  sys->pos[2].y = WIN_HGHT / 2 + 50;
  sys->pos[3].x = WIN_WDTH / 2;
  sys->pos[3].y = WIN_HGHT / 2 + 150;
}
