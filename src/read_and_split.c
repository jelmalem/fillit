/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:45:10 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/13 22:45:10 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** ft_validate_input checks the len of what appears to be a block
*/

static void	ft_validate_input(char **split_input)
{
	int i;

	i = 0;
	while (split_input[i])
	{
		if (ft_strlen(split_input[i]) != 20)
			ft_quit("Block not correctly formated.");
		i++;
	}
	if (i > 26)
		ft_quit("Too many tetrominos in input.");
}

/*
** ft_split_input replace the \n between blocks by '+' and split by it
*/

char		**ft_split_input(char *input)
{
	int		i;
	int		count_endl;
	char	**split_output;

	i = -1;
	count_endl = 0;
	while (input[++i])
	{
		if (input[i] == '\n')
			count_endl++;
		if (count_endl == 5)
		{
			input[i] = '+';
			count_endl = 0;
		}
	}
	split_output = ft_strsplit(input, '+');
	ft_validate_input(split_output);
	return (split_output);
}

/*
** ft_check_newline checks \n's at the begin and at the end of the read input
*/

static void	ft_check_newline(char *full_fd)
{
	size_t len;

	len = ft_strlen(full_fd);
	if (len < 20)
		ft_quit("Not even a block.");
	if (full_fd[0] == '\n')
		ft_quit("Newline at the begining.");
	if (full_fd[len - 1] == '\n' && full_fd[len - 2] == '\n')
		ft_quit("Too many newlines at the end.");
}

/*
** ft_read_input creates a biiiig and single line with the input file
*/

char		*ft_read_input(int fd)
{
	int		n;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*full_fd;
	size_t	bytes_read;

	if (fd < 0)
		ft_quit("Error while opening fillit file.");
	n = 0;
	full_fd = "";
	while ((bytes_read = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		n += BUFF_SIZE;
		buf[bytes_read] = '\0';
		tmp = ft_strnew(n);
		ft_strcpy(tmp, full_fd);
		full_fd = ft_strnew(n);
		ft_strcpy(full_fd, tmp);
		ft_strcat(full_fd, buf);
	}
	ft_check_newline(full_fd);
	return (full_fd);
}
