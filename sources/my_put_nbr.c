/*
** my_put_nbr.c for my_put_nbr in /home/gaspar_q/rendu/Piscine_C_J03
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Oct  1 14:02:17 2014 quentin gasparotto
** Last update Mon Feb  9 21:01:12 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb / 10 > 0)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
