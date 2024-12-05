/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:32:14 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:36:26 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//calculates where the ray hits on the wall so we know how to print it
//line 1 - 4 calculates where the ray hits in EXACT coordinates
//line 5 calculates the PERCENTAGE of the wall we wanna print
//Example:
//wallX = 3.75
//floor(wallX) = 3;
//wallX = 0.75, this means the ray hit the wall at 75% along the wall
//line 6 times the wall width to get the actual wall coordinates 
//we have to print

void	calc_tex(t_game *game)
{
	double	wall_x;

	if (game->ray.hori_side_hit == 0)
		wall_x = game->player.pos_y + game->ray.perp_wall_dist
			* game->ray.ray_dir_y;
	else
		wall_x = game->player.pos_x + game->ray.perp_wall_dist
			* game->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	game->ray.tex_x = (int)(wall_x * game->n_tex.img_width);
}

void	calc_draw_values(t_game *game)
{
	game->draw.line_height = (int)(WIN_HEIGHT / game->ray.perp_wall_dist);
	game->draw.draw_start = (WIN_HEIGHT / 2.0) - (game->draw.line_height / 2);
	if (game->draw.draw_start < 0)
		game->draw.draw_start = 0.00001;
	game->draw.draw_end = (WIN_HEIGHT / 2.0) + (game->draw.line_height / 2);
	if (game->draw.draw_end >= WIN_HEIGHT)
		game->draw.draw_end = WIN_HEIGHT - 1;
}

// line 2: get how much we shud increment the index which iterates thru the
// 		   image data after we draw one pixel
// line 3: gets the starting index which is used to interate thru the image 
//         data (most of the time gonna be 0 unless our image is bigger than
//		   the screen)
// line 5: get the color of the pixel (modulus so instead of stretching we can
//         print each tile repeatedly)
// line 6: put the color in the screen data
void	actually_drawing(t_game *game, int x)
{
	int	y;

	y = game->draw.draw_start - 1;
	game->draw.step = (double)game->draw.tex.img_height
		/ game->draw.line_height;
	game->draw.tex_pos = (game->draw.draw_start - WIN_HEIGHT / 2.0
			+ game->draw.line_height / 2) * game->draw.step;
	while (++y < game->draw.draw_end)
	{
		game->draw.color = game->draw.tex.img_data[game->n_tex.img_height
			* (int)game->draw.tex_pos + (game->ray.tex_x
				% game->n_tex.img_width)];
		game->screen.img_data[y * WIN_WIDTH + x] = game->draw.color;
		game->draw.tex_pos += game->draw.step;
	}
}

// see which texture to draw
// line 1: if hit vertical side (east or west)
// line 3: then see if ray_dir_x < 0, means ray travelling to the left,
//		   also means east direction
// line 8: if hit horizontal side (north or south)
// line 10: then see if ray_dir_y < 0, that means travelling up (in this 
// 			game y decrease as it goes up), so north dir
void	get_tex_to_draw(t_game *game)
{
	if (game->ray.hori_side_hit == 0)
	{
		if (game->ray.ray_dir_x < 0)
			game->draw.tex = game->e_tex;
		else
			game->draw.tex = game->w_tex;
	}
	else
	{
		if (game->ray.ray_dir_y < 0)
			game->draw.tex = game->n_tex;
		else
			game->draw.tex = game->s_tex;
	}
}

void	draw_line(t_game *game, int x)
{
	get_tex_to_draw(game);
	calc_draw_values(game);
	calc_tex(game);
	actually_drawing(game, x);
}
