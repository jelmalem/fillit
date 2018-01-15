/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:45:10 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/13 22:45:10 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Display the reason for which fillit quit : define FILLIT_DEBUG 1 in fillit.h
*/

int			ft_quit(char *msg)
{
	if (FILLIT_DEBUG)
	{
		ft_putstr(KYEL);
		ft_putstr("[EXIT] Reason : ");
		ft_putendl(msg);
		ft_putstr(KMAG);
		ft_putendl("error");
		ft_putstr(KWHT);
		exit(0);
	}
	else
	{
		ft_putendl("error");
		exit(-1);
	}
}

/*
** ft_check_arg checks the number of arguments and mights display the usage
*/

static void	ft_check_arg(int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage : ./fillit <source_file>");
		exit(-1);
	}
}

/*
** Parse all the list and get the last tetro->letter
*/

static char	ft_find_last_letter(t_tetri *all_tetros)
{
	char letter;

	while (all_tetros->next)
	{
		all_tetros = all_tetros->next;
		if (all_tetros->letter)
			letter = all_tetros->letter;
	}
	return (letter);
}

/*
** Backtrack until size is big enough and map is valid
*/

static void	ft_solve(t_tetri *all_tetros)
{
	int		size;
	int		pos;
	char	letter;
	char	**map;
	t_tetri	*begin;

	size = 0;
	pos = 0;
	begin = all_tetros;
	letter = ft_find_last_letter(begin);
	map = ft_map(size);
	while (ft_valid_map(map, size, letter) == 0)
	{
		if (pos == size * size)
		{
			pos = 0;
			size++;
		}
		map = ft_backtracking(ft_map(size), pos, size, all_tetros);
		pos++;
	}
	ft_print_map(map, size);
}

/*
** main, baby !
*/

int			main(int argc, char **argv)
{
	char		**split_input;
	t_tetri		*all_tetros;

	ft_check_arg(argc);
	split_input = ft_split_input(ft_read_input(open(argv[1], O_RDONLY)));
	ft_place_up_and_left(split_input);
	all_tetros = ft_check_input(split_input, 0);
	ft_solve(all_tetros);
	return (0);
}
