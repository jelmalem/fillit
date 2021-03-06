/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 17:11:35 by nsampre           #+#    #+#             */
/*   Updated: 2016/08/09 14:55:19 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 'a') && (str[count] <= 'z'))
		{
			str[count] = str[count] - 'a' + 'A';
		}
		count++;
	}
	return (str);
}
