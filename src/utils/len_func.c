/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:18 by emomkus           #+#    #+#             */
/*   Updated: 2022/10/20 19:41:04 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* 
	Returns a pointer to an integer array
	array represents LENGHTS of char array lines
*/
int	*line_lengths(char **map)
{
	int	*arr;
	int	i;

	i = 0;
	while (map[i])
		i++;
	arr = ft_calloc(i + 1, sizeof(int));
	i = 0;
	while (map[i])
	{
		arr[i] = ft_strlen(map[i]);
		i++;
	}
	return (arr);
}
