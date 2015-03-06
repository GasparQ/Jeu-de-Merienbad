/*
** nbr_to_str.c for convert an int into a str in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 21 19:32:16 2015 quentin gasparotto
** Last update Sat Feb 21 19:43:06 2015 quentin gasparotto
*/

#include "allum_1.h"

int	get_str_len(int nb)
{
  int	i;
  int	pow;

  i = 0;
  if (nb < 0)
    {
      ++i;
      nb = -nb;
    }
  pow = 1;
  while (nb / pow > 0)
    {
      i = i + 1;
      pow = pow * 10;
    }
  return (i);
}

char	*nbr_to_str(int nb)
{
  char	*nb_convert;
  int	len;

  len = get_str_len(nb);
  if ((nb_convert = malloc(len + 1)) == NULL)
    return (NULL);
  if (nb < 0)
    {
      nb_convert[0] = '-';
      nb = -nb;
    }
  nb_convert[len] = '\0';
  while (nb > 0)
    {
      nb_convert[--len] = (char)(nb % 10 + '0');
      nb = nb / 10;
    }
  return (nb_convert);
}
