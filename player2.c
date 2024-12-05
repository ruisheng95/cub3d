/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:28:14 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:29:55 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	locate_player_row(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	locate_player_col(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

char	get_player_start_dir(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				return (map[i][j]);
			j++;
		}
		i++;
	}
	return ('\0');
}
