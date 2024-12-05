/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:25:12 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:24:11 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_helper(char **argv, t_game *game)
{
	check_argv(argv);
	init_game_data(game);
	import_data(game, argv);
	if (check_map(game) != 0)
		ft_exit();
	init_player_struct(game, &game->player);
	init_texs(game);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_exit();
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error_and_exit("Syntax incorrect\n"), 1);
	if (main_helper(argv, &game) != 0)
		return (1);
	mlx_hook(game.window, KEY_PRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, KEY_RELEASE, 1L << 1, handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, &loop_handle, &game);
	mlx_hook(game.window, 17, 0, &close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
