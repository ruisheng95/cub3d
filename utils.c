/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:27:31 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 17:33:22 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * PI / 180);
}

double	rad_to_deg(double rad)
{
	return (rad * 180 / PI);
}

double	normalise_angle(double degree)
{
	if (degree < 0)
		degree += 360;
	else if (degree > 360)
		degree -= 360;
	return (degree);
}

static void	free_memory_2(t_game *game)
{
	if (game->n_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->n_tex.img_ptr);
	if (game->s_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->s_tex.img_ptr);
	if (game->w_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->w_tex.img_ptr);
	if (game->e_tex.img_ptr)
		mlx_destroy_image(game->mlx, game->e_tex.img_ptr);
	if (game->screen.img_ptr)
		mlx_destroy_image(game->mlx, game->screen.img_ptr);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_memory(t_game *game)
{
	if (game->textures.ceilingcolor)
		free(game->textures.ceilingcolor);
	if (game->textures.floorcolor)
		free(game->textures.floorcolor);
	if (game->filedata)
		free_2d_array(game->filedata);
	if (game->textures.north_texture)
		free(game->textures.north_texture);
	if (game->textures.south_texture)
		free(game->textures.south_texture);
	if (game->textures.west_texture)
		free(game->textures.west_texture);
	if (game->textures.east_texture)
		free(game->textures.east_texture);
	if (game->map)
		free_2d_array(game->map);
	free_memory_2(game);
}
