/*
** turn_to_turn.c for turn to turn >> ask usr in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 18:09:04 2015 quentin gasparotto
** Last update Sun Feb 15 19:36:10 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

void	show_allum(char *allum_tab, int line, int retired_allum)
{
  int	i;
  int	allum_nb;

  i = 0;
  while (allum_tab[i] != -1)
    {
      my_put_nbr(i + 1);
      my_putstr(": ");
      allum_nb = allum_tab[i];
      while (allum_nb > 0)
	{
	  my_putchar('|');
	  allum_nb = allum_nb - 1;
	}
      if (i == line - 1)
	{
	  my_putstr(" <- (-");
	  my_put_nbr(retired_allum);
	  my_putchar(')');
	}
      my_putchar('\n');
      i = i + 1;
    }
  my_putchar('\n');
}

void	turn_to_turn(char *allum_tab, int allum_nb,
		     int (*plyr_o_ia)(char *, int *, int *))
{
  int	player;
  int	line;
  int	allum;

  line = 0;
  allum = 0;
  player = choose_usr();
  while ((allum_nb -= allum) > 0)
    {
      if (!player)
	my_putstr("Player 1 turn\n\n");
      else
	my_putstr("Player 2 turn\n\n");
      show_allum(allum_tab, line, allum);
      if (player)
	plyr_o_ia(allum_tab, &line, &allum);
      else
	ask_usr(allum_tab, &line, &allum);
      player = !player;
    }
  show_allum(allum_tab, line, allum);
  if (!player)
    my_putstr("Player 1 Win\n");
  else
    my_putstr("Player 2 Win\n");
}
