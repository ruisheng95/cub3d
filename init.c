/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:22:14 by rng               #+#    #+#             */
/*   Updated: 2024/12/08 10:51:52 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_data_2(t_game *game)
{
	game->textures.ceilingcolor = malloc(sizeof(int) * 3);
	game->textures.floorcolor = malloc(sizeof(int) * 3);
	game->screen.img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->screen.img_ptr)
		return (free_memory(game), print_n_exit("mlx_new_image failed\n"));
	game->screen.img_data = (int *)mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bitsperpixel, &game->screen.linesize,
			&game->screen.endian);
	game->player.curr_tile_x = 0;
	game->player.curr_tile_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->player.pos_x = 0;
	game->player.pos_y = 0;
	game->movement.back = false;
	game->movement.front = false;
	game->movement.left = false;
	game->movement.right = false;
	game->movement.rot_left = false;
	game->movement.rot_right = false;
}

void	init_game_data(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->screen.img_ptr = NULL;
	game->textures.ceilingcolor = NULL;
	game->textures.floorcolor = NULL;
	game->filedata = NULL;
	game->textures.north_texture = NULL;
	game->textures.south_texture = NULL;
	game->textures.west_texture = NULL;
	game->textures.east_texture = NULL;
	game->map = NULL;
	game->n_tex.img_ptr = NULL;
	game->s_tex.img_ptr = NULL;
	game->w_tex.img_ptr = NULL;
	game->e_tex.img_ptr = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_memory(game), print_n_exit("mlx_init failed\n"));
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!game->window)
		return (free_memory(game), print_n_exit("mlx_new_window failed\n"));
	init_game_data_2(game);
}

void	init_texs(t_game *game)
{
	game->n_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.north_texture, &game->n_tex.img_width,
			&game->n_tex.img_height);
	game->s_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.south_texture, &game->s_tex.img_width,
			&game->s_tex.img_height);
	game->e_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.east_texture, &game->e_tex.img_width,
			&game->e_tex.img_height);
	game->w_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.west_texture, &game->w_tex.img_width,
			&game->w_tex.img_height);
	init_texs_mlx_get_data_addr(game);
}

void	check_argv(char **argv)
{
	int			len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u'
		|| argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
		print_n_exit("Error: File need to have .cub at the back\n");
}

void	import_data(t_game *game, char **argv)
{
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (free_memory(game), print_n_exit("Error: Invalid file\n"));
	game->filedata = readfile(fd);
	close(fd);
	if (!game->filedata)
		return (free_memory(game), exit(1));
	get_game_data(game);
}
