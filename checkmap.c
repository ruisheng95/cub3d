/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:52:43 by rng               #+#    #+#             */
/*   Updated: 2024/12/12 09:32:03 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_bounds(t_mapchecks *check, int row, int col)
{
	if (row < 0 || col < 0 || row >= get_map_height(check->map)
		|| col >= (int)ft_strlen(check->map[row]))
		return ;
	if (check->map[row][col] == '1' || check->map[row][col] == 'V')
		return ;
	check->map[row][col] = 'V';
	check_bounds(check, row + 1, col);
	check_bounds(check, row - 1, col);
	check_bounds(check, row, col + 1);
	check_bounds(check, row, col - 1);
}

char	**copy_map(char **map)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc(sizeof(char *) * (get_map_height(map) + 1));
	while (i < get_map_height(map))
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	check_bounds_helper(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		if (ft_strlen(map[i]) == 1)
			return (1);
		while (j < ft_strlen(map[i]))
		{
			if (i == 0 && map[i][j] == 'V')
				return (1);
			if ((j == 0 || j == ft_strlen(map[i]) - 1) && map[i][j] == 'V')
				return (1);
			if (i == get_map_height(map) - 1 && map[i][j] == 'V')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_num_of_players(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < get_map_height(map))
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_map(t_game *game)
{
	t_mapchecks	check;

	check.map = copy_map(game->map);
	if (!game->map)
		return (free_memory(game), print_n_exit("copy_map failed\n"));
	if (check_num_of_players(game->map) != 1)
		return (free_2d_array(check.map), free_memory(game),
			print_n_exit("Error: Wrong num of players\n"));
	check_bounds(&check, locate_player_row(check.map),
		locate_player_col(check.map));
	if (check_bounds_helper(check.map) == 1)
		return (free_2d_array(check.map), free_memory(game),
			print_n_exit("Error: Map is NOT bounded by walls\n"));
	free_2d_array(check.map);
}
