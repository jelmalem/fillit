/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_and_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:45:11 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/13 22:45:11 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** After ft_place_up() has split the input and place it up, join it
*/

static char	*ft_strjoin_input(char **split_input)
{
	char	*output;
	int		i;

	output = "";
	i = -1;
	while (++i < 4)
	{
		output = ft_strjoin(output, split_input[i]);
		output = ft_strjoin(output, "\n");
	}
	return (output);
}

/*
** Places 'block' up..
*/

static char	*ft_place_up(char *input)
{
	char	**split_input;
	char	*temp;
	int		i;
	int		j;

	split_input = ft_strsplit(input, '\n');
	i = 0;
	while (split_input[i++] && ft_strcmp(split_input[0], "....") == 0)
	{
		j = -1;
		while (split_input[++j + 1])
		{
			if (ft_strcmp(split_input[j], "....") == 0)
			{
				temp = split_input[j];
				split_input[j] = split_input[j + 1];
				split_input[j + 1] = temp;
			}
		}
	}
	return (ft_strjoin_input(split_input));
}

/*
** Useful for ft_place_left(), shift 'block' left
*/

static void	ft_swap_columns(char **split_input, int i)
{
	char	temp;
	int		j;

	j = -1;
	while (++j < 4)
	{
		temp = split_input[j][i];
		split_input[j][i] = split_input[j][i + 1];
		split_input[j][i + 1] = temp;
	}
}

/*
** Places 'block' left...
*/

static char	*ft_place_left(char *input)
{
	char	**split_input;
	char	column[5];
	int		i;
	int		j;

	split_input = ft_strsplit(input, '\n');
	j = 0;
	while (j++ < 4)
	{
		i = -1;
		while (++i < 3)
		{
			column[0] = split_input[0][i];
			column[1] = split_input[1][i];
			column[2] = split_input[2][i];
			column[3] = split_input[3][i];
			column[4] = '\0';
			if (ft_strcmp(column, "....") == 0)
				ft_swap_columns(split_input, i);
		}
	}
	return (ft_strjoin_input(split_input));
}

/*
** For each lines (block), place it to the top left
*/

void		ft_place_up_and_left(char **input)
{
	int i;

	i = 0;
	while (input[i])
	{
		input[i] = ft_place_left(input[i]);
		input[i] = ft_place_up(input[i]);
		i++;
	}
}
