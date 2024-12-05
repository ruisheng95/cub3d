/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:37:35 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:38:31 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_front(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player.pos_x + game->player.dir_x * MOV_SPEED;
	new_pos_y = game->player.pos_y + game->player.dir_y * MOV_SPEED;
	if (game->map[(int)new_pos_y][(int)new_pos_x] != '1')
	{
		game->player.pos_x = new_pos_x;
		game->player.pos_y = new_pos_y;
	}
}

void	move_back(t_game *game)
{
	double	new_pox_x;
	double	new_pox_y;

	new_pox_x = game->player.pos_x - game->player.dir_x * MOV_SPEED;
	new_pox_y = game->player.pos_y - game->player.dir_y * MOV_SPEED;
	if (game->map[(int)new_pox_y][(int)new_pox_x] != '1')
	{
		game->player.pos_x = new_pox_x;
		game->player.pos_y = new_pox_y;
	}
}

void	move_left(t_game *game)
{
	double	new_pox_x;
	double	new_pos_y;

	new_pox_x = game->player.pos_x + game->player.dir_y * MOV_SPEED;
	new_pos_y = game->player.pos_y - game->player.dir_x * MOV_SPEED;
	if (game->map[(int)new_pos_y][(int)new_pox_x] != '1')
	{
		game->player.pos_x = new_pox_x;
		game->player.pos_y = new_pos_y;
	}
}

void	move_right(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player.pos_x - game->player.dir_y * MOV_SPEED;
	new_pos_y = game->player.pos_y + game->player.dir_x * MOV_SPEED;
	if (game->map[(int)new_pos_y][(int)new_pos_x] != '1')
	{
		game->player.pos_x = new_pos_x;
		game->player.pos_y = new_pos_y;
	}
}
