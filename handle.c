/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:25:25 by rng               #+#    #+#             */
/*   Updated: 2024/12/12 09:39:42 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == RIGHT || keycode == LEFT
		|| keycode == WKEY || keycode == AKEY
		|| keycode == SKEY || keycode == DKEY)
		change_movement_status(game, keycode, 1);
	else if (keycode == ESC)
	{
		free_memory(game);
		exit(0);
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	change_movement_status(game, keycode, 0);
	return (0);
}

int	loop_handle(t_game *game)
{
	if (game->frame_delay++ == FRAME_DELAY)
	{
		move_player(game);
		rotate_player(game);
		render_screen(game);
		game->frame_delay = 0;
	}
	return (1);
}
