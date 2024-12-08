/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:47:47 by rng               #+#    #+#             */
/*   Updated: 2024/12/08 10:52:39 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texs_mlx_get_data_addr(t_game *game)
{
	if (!game->n_tex.img_ptr || !game->s_tex.img_ptr || !game->e_tex.img_ptr
		|| !game->w_tex.img_ptr)
		return (free_memory(game),
			print_n_exit("Error: Smth wrong about textures in .cub file\n"));
	game->n_tex.img_data = (int *)mlx_get_data_addr(game->n_tex.img_ptr,
			&game->n_tex.bitsperpixel, &game->n_tex.linesize,
			&game->n_tex.endian);
	game->s_tex.img_data = (int *)mlx_get_data_addr(game->s_tex.img_ptr,
			&game->s_tex.bitsperpixel, &game->s_tex.linesize,
			&game->s_tex.endian);
	game->e_tex.img_data = (int *)mlx_get_data_addr(game->e_tex.img_ptr,
			&game->e_tex.bitsperpixel, &game->e_tex.linesize,
			&game->e_tex.endian);
	game->w_tex.img_data = (int *)mlx_get_data_addr(game->w_tex.img_ptr,
			&game->w_tex.bitsperpixel, &game->w_tex.linesize,
			&game->w_tex.endian);
}
