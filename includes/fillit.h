/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:36:26 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/13 22:36:26 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 64
# define FILLIT_DEBUG 0

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct			s_tetri
{
	int					id;
	char				letter;
	int					shape[4][4];
	int					pos;
	struct s_tetri		*next;
	struct s_tetri		*prev;
}						t_tetri;

int						ft_quit(char *msg);

char					*ft_read_input(int fd);
char					**ft_split_input(char *input);

t_tetri					*ft_check_input(char **input, int i);
int						ft_cmp_pack(char *input);

void					ft_place_up_and_left(char **input);

t_tetri					*ft_shape(char *input, int input_line);

int						ft_valid_map(char **map, int size, char letter);
char					**ft_map(int size);
void					ft_print_map(char **map, int size);
void					ft_clean_map(char **map, char letter, int size);
void					ft_put_tetro(char **map, int s, t_tetri *t, int p);

char					**ft_backtracking(char **m, int p, int s, t_tetri *t);

#endif
