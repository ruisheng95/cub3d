/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:34:24 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 17:38:00 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_height_for_malloc(t_game *game, int i)
{
	int	j;

	j = i;
	while (game->filedata[j])
		j++;
	return (j - i);
}

char	**readfile(int fd)
{
	char	**res;
	int		j;

	j = 0;
	res = (char **)malloc(sizeof(char *) * 10000);
	if (!res)
		return (NULL);
	res[0] = get_next_line(fd);
	while (res[j++] != NULL)
		res[j] = get_next_line(fd);
	if (res[0] == NULL)
	{
		ft_printf("Error: file contains nth bruh\n");
		free_2d_array(res);
		return (0);
	}
	res[j] = NULL;
	return (res);
}

int	count_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
