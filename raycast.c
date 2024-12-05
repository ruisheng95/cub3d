/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:40:45 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:47:55 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 
line 1: calculate the coordinate of the ray in the camera plane 
		(-1 is the most left, 1 is the most right)
line 2 and 3 : determines the x and y component of the ray angle. 
			   Lets say player is facing 1, 0 (right), since camera 
			   perpendicular then plane_x will be 0, plane_y will be 0.66 
			   ray_dir_x = 1 
			   ray_dir_y = -0.66 (left) to 0.66 (right)
line 4 and 5: calculates how much the rays length increase due to one unit 
			  of increase in X or Y 
*/

void	init_ray_values(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * (x / (double)WIN_WIDTH) - 1;
	game->ray.ray_dir_x = game->player.dir_x + (game->player.plane_x
			* camera_x);
	game->ray.ray_dir_y = game->player.dir_y + (game->player.plane_y
			* camera_x);
	game->ray.delta_dist_x = sqrt(1 + (game->ray.ray_dir_y
				* game->ray.ray_dir_y) / (game->ray.ray_dir_x
				* game->ray.ray_dir_x));
	game->ray.delta_dist_y = sqrt(1 + (game->ray.ray_dir_x
				* game->ray.ray_dir_x) / (game->ray.ray_dir_y
				* game->ray.ray_dir_y));
	game->ray.map_x = game->player.curr_tile_x;
	game->ray.map_y = game->player.curr_tile_y;
}

void	calc_first_part_of_ray_distance(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - game->player.curr_tile_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (TILE_SIZE - game->player.pos_x
				+ game->player.curr_tile_x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - game->player.curr_tile_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (TILE_SIZE - game->player.pos_y
				+ game->player.curr_tile_y) * game->ray.delta_dist_y;
	}
}

//when u increase side_dist_x ray will ALWAYSSSS hit the vertical side
void	dda(t_game *game)
{
	while (1)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.hori_side_hit = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.hori_side_hit = 1;
		}
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			break ;
	}
}

void	calc_perp_dist(t_game *game)
{
	if (game->ray.hori_side_hit == 0)
	{
		if (game->ray.step_x == -1)
			game->ray.perp_wall_dist = (game->ray.map_x
					- game->player.pos_x + 1.0) / game->ray.ray_dir_x;
		else
			game->ray.perp_wall_dist = (game->ray.map_x
					- game->player.pos_x) / game->ray.ray_dir_x;
	}
	else
	{
		if (game->ray.step_y == -1)
			game->ray.perp_wall_dist = (game->ray.map_y - game->player.pos_y
					+ 1.0) / game->ray.ray_dir_y;
		else
			game->ray.perp_wall_dist = (game->ray.map_y - game->player.pos_y)
				/ game->ray.ray_dir_y;
	}
}
// First main part : calculate distance of ray from
// 					 player to first grid intersection
// Second main part : dda 
// Third main part : calculate perp dist

void	raycasting(t_game *game, int x)
{
	init_ray_values(game, x);
	calc_first_part_of_ray_distance(game);
	dda(game);
	calc_perp_dist(game);
}
