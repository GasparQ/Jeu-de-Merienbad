/*
** my_strdup.c for my str dup in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 20 10:42:18 2015 quentin gasparotto
** Last update Fri Feb 20 18:42:36 2015 quentin gasparotto
*/

#include "sdl_system.h"

char	*my_strdup(char *str)
{
  int	len;
  char	*ret_str;

  len = 0;
  while (str[len] != -1)
    len = len + 1;
  if ((ret_str = malloc(len + 1)) == NULL)
    return (NULL);
  ret_str[len] = -1;
  len = 0;
  while (str[len] != -1)
    {
      ret_str[len] = str[len];
      len = len + 1;
    }
  return (ret_str);
}
