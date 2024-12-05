/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:15:19 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:17:52 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_struct(t_game *game, t_player *player)
{
	player->curr_tile_x = locate_player_col(game->map);
	player->curr_tile_y = locate_player_row(game->map);
	player->pos_x = player->curr_tile_x * TILE_SIZE + ((double)TILE_SIZE / 2);
	player->pos_y = player->curr_tile_y * TILE_SIZE + ((double)TILE_SIZE / 2);
	if (get_player_start_dir(game->map) == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = 0.66;
	}
	else if (get_player_start_dir(game->map) == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	else if (get_player_start_dir(game->map) == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -0.66;
	}
	else
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
}

//use the rotation matrix given
static void	rotate_player_2(t_game *game)
{
	double	temp;

	if (game->movement.rot_right == true)
	{
		temp = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(deg_to_rad(ROT_SPEED))
			- game->player.dir_y * sin(deg_to_rad(ROT_SPEED));
		game->player.dir_y = game->player.dir_y * cos(deg_to_rad(ROT_SPEED))
			+ temp * sin(deg_to_rad(ROT_SPEED));
		temp = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(deg_to_rad(ROT_SPEED))
			- game->player.plane_y * sin(deg_to_rad(ROT_SPEED));
		game->player.plane_y = game->player.plane_y * cos(deg_to_rad(ROT_SPEED))
			+ temp * sin(deg_to_rad(ROT_SPEED));
	}
}

void	rotate_player(t_game *game)
{
	double	temp;

	if (game->movement.rot_left == true)
	{
		temp = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(deg_to_rad(-ROT_SPEED))
			- game->player.dir_y * sin(deg_to_rad(-ROT_SPEED));
		game->player.dir_y = game->player.dir_y * cos(deg_to_rad(-ROT_SPEED))
			+ temp * sin(deg_to_rad(-ROT_SPEED));
		temp = game->player.plane_x;
		game->player.plane_x = game->player.plane_x
			* cos(deg_to_rad(-ROT_SPEED)) - game->player.plane_y
			* sin(deg_to_rad(-ROT_SPEED));
		game->player.plane_y = game->player.plane_y
			* cos(deg_to_rad(-ROT_SPEED)) + temp
			* sin(deg_to_rad(-ROT_SPEED));
	}
	rotate_player_2(game);
}

void	move_player(t_game *game)
{
	if (game->movement.front == true)
		move_front(game);
	if (game->movement.back == true)
		move_back(game);
	if (game->movement.left == true)
		move_left(game);
	if (game->movement.right == true)
		move_right(game);
	game->player.curr_tile_x = (int)game->player.pos_x / TILE_SIZE;
	game->player.curr_tile_y = (int)game->player.pos_y / TILE_SIZE;
}
