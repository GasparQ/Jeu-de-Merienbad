/*
** my_putchar.c for my put char in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 17:38:14 2015 quentin gasparotto
** Last update Sun Feb 22 12:26:31 2015 quentin gasparotto
*/

#include "allum_1.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
