/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:39:31 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:40:33 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player_stats(t_player *player)
{
	printf("\n\n========================================\n");
	printf("curr X tile = %d\n", player->curr_tile_x);
	printf("curr Y tile = %d\n", player->curr_tile_y);
	printf("curr X pixel = %f\n", player->pos_x);
	printf("curr Y pixel = %f\n", player->pos_y);
	printf("========================================\n");
}

void	print_textures(t_game *game)
{
	printf("==================================================\n");
	if (game->textures.north_texture && game->textures.south_texture
		&& game->textures.east_texture && game->textures.west_texture)
	{
		printf("NORTH TEXTURE = %s\n", game->textures.north_texture);
		printf("SOUTH TEXTURE = %s\n", game->textures.south_texture);
		printf("WEST  TEXTURE = %s\n", game->textures.west_texture);
		printf("EAST  TEXTURE = %s\n", game->textures.east_texture);
		printf("FLOOR   = %d, %d, %d\n", game->textures.floorcolor[0],
			game->textures.floorcolor[1], game->textures.floorcolor[2]);
		printf("CEILING = %d, %d, %d\n", game->textures.ceilingcolor[0],
			game->textures.ceilingcolor[1], game->textures.ceilingcolor[2]);
	}
	else
		return ;
	if (game->map)
	{
		printf("========MAP=========\n");
		print_2d_array(game->map);
	}
	else
		return ;
	printf("==================================================\n");
}

void	print_key(int keycode)
{
	if (keycode == UP)
		printf("up arrow key pressed\n");
	if (keycode == DOWN)
		printf("down arrow key pressed\n");
	if (keycode == LEFT)
		printf("left arrow key pressed\n");
	if (keycode == RIGHT)
		printf("right arrow key pressed\n");
	if (keycode == WKEY)
		printf("W key pressed\n");
	if (keycode == AKEY)
		printf("A key pressed\n");
	if (keycode == SKEY)
		printf("S key pressed\n");
	if (keycode == DKEY)
		printf("D key pressed\n");
}
