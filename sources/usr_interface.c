/*
** usr_interface.c for user interface in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb 10 10:51:25 2015 quentin gasparotto
** Last update Sat Feb 14 20:05:43 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

int	get_line_nb(char *allum_tab)
{
  int	i;

  i = 0;
  while (allum_tab[i] != -1)
    {
      i = i + 1;
    }
  return (i);
}

int	read_user(char *message)
{
  char	ask[4097];
  int	end;
  int	nb;
  
  end = -1;
  ask[0] = '\0';
  while (end == -1 || check_nb(ask) == 0)
    {
      my_putstr(message);
      if ((end = read(0, ask, 4096)) == -1)
	return (my_strerror(MALLOC_ERR));
      if (ask[end - 1] == '\n')
	ask[end - 1] = '\0';
      else
	ask[end] = '\0';
      nb = my_getnbr(ask);
    }
  return (nb);
}

int	ask_sentences(char *message, char *err_mess, int ref)
{
  int	nb;

  nb = -1;
  while (nb > ref || nb <= 0)
    {
      if ((nb = read_user(message)) == ERROR)
	return (ERROR);
      if (nb > ref || nb <= 0)
	my_puterrstr(err_mess);
    }
  return (nb);
}

int	ask_usr(char *allum_tab, int *line, int *allum)
{
  int	nb_of_line;

  nb_of_line = get_line_nb(allum_tab);
  *line = -1;
  *allum = -1;
  while (*line == -1 || allum_tab[(*line) - 1] == 0)
    {
      if (*line != -1)
	my_puterrstr("La rangee est vide\n");
      if ((*line = ask_sentences("Indiquez la rangee choisie: ",
				 "La rangee choisie est erronee\n",
				 nb_of_line)) == ERROR)
	return (ERROR);
    }
    if ((*allum = ask_sentences("Indiquez le nombre d'allumettes a retirer: ",
				"Mauvais nombre d'allumettes\n",
				allum_tab[(*line) - 1])) == ERROR)
      return (ERROR);
    allum_tab[(*line) - 1] = allum_tab[(*line) - 1] - (*allum);
    my_putchar('\n');
    return (CLEAN);
}
