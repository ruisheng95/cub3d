/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:30:09 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:30:30 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_to_hex(int *arr)
{
	int	red;
	int	green;
	int	blue;
	int	res;

	red = arr[0];
	green = arr[1];
	blue = arr[2];
	res = red << 16 | green << 8 | blue;
	return (res);
}
// shift red value by 16 bits because red is the most left component
// shift green by 8 bits cuz middle component

void	draw_rectangle_into_dest_img(int color, int *data, int start, int end)
{
	int	x;
	int	y;

	y = start - 1;
	while (++y < end)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			data[y * WIN_WIDTH + x] = color;
	}
}

void	draw_floor(t_game *game)
{
	int		hex_color;

	hex_color = convert_to_hex(game->textures.floorcolor);
	draw_rectangle_into_dest_img(hex_color, game->screen.img_data,
		WIN_HEIGHT / 2, WIN_HEIGHT);
}

void	draw_ceiling(t_game *game)
{
	int		hex_color;

	hex_color = convert_to_hex(game->textures.ceilingcolor);
	draw_rectangle_into_dest_img(hex_color, game->screen.img_data,
		0, WIN_HEIGHT / 2);
}
