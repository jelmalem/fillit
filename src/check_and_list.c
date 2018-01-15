/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:45:11 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/13 22:45:11 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Converts input block (char[20]) into a matrix[4][4] of integers of 0 and 1
*/

t_tetri			*ft_shape(char *input, int input_line)
{
	char		**split_split_input;
	t_tetri		*current;
	int			i;
	int			j;

	current = (t_tetri *)malloc(sizeof(t_tetri));
	split_split_input = ft_strsplit(input, '\n');
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (split_split_input[i][j] == '#')
				current->shape[i][j] = 1;
			else
				current->shape[i][j] = 0;
		}
	}
	current->letter = input_line + 'A';
	current->id = ft_cmp_pack(input);\
	current->next = NULL;
	current->prev = NULL;
	current->pos = 0;
	return (current);
}

/*
** Here are the 19 possibilities of tetrominos of 4, all top left
*/

static int		ft_cmp_pack_2(char *input)
{
	if (ft_strcmp(input, "####\n....\n....\n....\n") == 0)
		return (10);
	if (ft_strcmp(input, "#...\n#...\n#...\n#...\n") == 0)
		return (11);
	if (ft_strcmp(input, "##..\n#...\n#...\n....\n") == 0)
		return (12);
	if (ft_strcmp(input, "###.\n..#.\n....\n....\n") == 0)
		return (13);
	if (ft_strcmp(input, ".#..\n.#..\n##..\n....\n") == 0)
		return (14);
	if (ft_strcmp(input, "#...\n###.\n....\n....\n") == 0)
		return (15);
	if (ft_strcmp(input, ".#..\n##..\n.#..\n....\n") == 0)
		return (16);
	if (ft_strcmp(input, ".#..\n###.\n....\n....\n") == 0)
		return (17);
	if (ft_strcmp(input, "#...\n##..\n#...\n....\n") == 0)
		return (18);
	if (ft_strcmp(input, "###.\n.#..\n....\n....\n") == 0)
		return (19);
	return (0);
}

int				ft_cmp_pack(char *input)
{
	if (ft_strcmp(input, "#...\n##..\n.#..\n....\n") == 0)
		return (1);
	if (ft_strcmp(input, ".#..\n##..\n#...\n....\n") == 0)
		return (2);
	if (ft_strcmp(input, "##..\n##..\n....\n....\n") == 0)
		return (3);
	if (ft_strcmp(input, ".##.\n##..\n....\n....\n") == 0)
		return (4);
	if (ft_strcmp(input, "##..\n.##.\n....\n....\n") == 0)
		return (5);
	if (ft_strcmp(input, "##..\n.#..\n.#..\n....\n") == 0)
		return (6);
	if (ft_strcmp(input, "..#.\n###.\n....\n....\n") == 0)
		return (7);
	if (ft_strcmp(input, "#...\n#...\n##..\n....\n") == 0)
		return (8);
	if (ft_strcmp(input, "###.\n#...\n....\n....\n") == 0)
		return (9);
	return (ft_cmp_pack_2(input));
}

/*
** Add each tetromino to the full input list of tetrominos
*/

static void		ft_tetro_push_front(t_tetri **alst, t_tetri *new)
{
	new->next = *alst;
	*alst = new;
}

/*
** Checks the input (list of single blocks) and quit or store
*/

t_tetri			*ft_check_input(char **input, int i)
{
	t_tetri		*tetromino;
	t_tetri		*all_tetros;

	all_tetros = NULL;
	while (input[i])
		i++;
	if ((all_tetros = (t_tetri *)malloc(sizeof(t_tetri) * i)) == NULL)
		ft_quit("Couldn\'t malloc all tetros");
	while (input[--i])
	{
		if (ft_cmp_pack(input[i]) == 0)
		{
			if (FILLIT_DEBUG)
				ft_putstr(input[i]);
			ft_quit("This input is not a tetromino");
		}
		else
		{
			tetromino = ft_shape(input[i], i);
			ft_tetro_push_front(&all_tetros, tetromino);
		}
	}
	return (all_tetros);
}
