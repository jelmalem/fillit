/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:09:30 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/15 20:09:30 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_can_put_tetro(char **map, t_tetri *tetro, int pos, int size)
{
	int		x;
	int		y;
	int		line;
	int		column;
	int		count;

	count = 0;
	line = 0;
	x = pos / size - 1;
	while (++x < size && line < 4)
	{
		y = pos % size - 1;
		column = 0;
		while (++y < size && column < 4)
		{
			if (map[x][y] == '.' && tetro->shape[line][column] == 1)
				count++;
			if (map[x][y] != '.' && tetro->shape[line][column] == 1)
				return (0);
			column++;
		}
		line++;
	}
	return ((count == 4) ? 1 : 0);
}

char	**ft_backtracking(char **map, int pos, int size, t_tetri *tetro)
{
	if (pos == size * size - 1 && tetro->next == NULL)
		return (map);
	if (pos == size * size - 1 && tetro->next)
	{
		pos = 0;
		return (ft_backtracking(map, pos, size, tetro->next));
	}
	if (ft_can_put_tetro(map, tetro, pos, size))
	{
		ft_put_tetro(map, size, tetro, pos);
		pos = 0;
		return (ft_backtracking(map, pos, size, tetro->next));
	}
	else
		return (ft_backtracking(map, pos + 1, size, tetro));
	return (NULL);
}
