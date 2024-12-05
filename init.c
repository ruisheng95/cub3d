/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:22:14 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:24:28 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_data_2(t_game *game)
{
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
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error_and_exit("Error: mlx_init failed\n");
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!game->window)
		print_error_and_exit("Error: mlx_new_window failed\n");
	game->filedata = NULL;
	game->map = NULL;
	game->textures.ceilingcolor = malloc(sizeof(int) * 3);
	game->textures.floorcolor = malloc(sizeof(int) * 3);
	game->screen.img_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->screen.img_ptr)
		print_error_and_exit("Error: mlx_new_image failed\n");
	game->screen.img_data = (int *)mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bitsperpixel, &game->screen.linesize,
			&game->screen.endian);
	game->filedata = NULL;
	init_game_data_2(game);
}

void	init_texs(t_game *game)
{
	game->n_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.north_texture, &game->n_tex.img_width,
			&game->n_tex.img_height);
	game->n_tex.img_data = (int *)mlx_get_data_addr(game->n_tex.img_ptr,
			&game->n_tex.bitsperpixel, &game->n_tex.linesize,
			&game->n_tex.endian);
	game->s_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.south_texture, &game->s_tex.img_width,
			&game->s_tex.img_height);
	game->s_tex.img_data = (int *)mlx_get_data_addr(game->s_tex.img_ptr,
			&game->s_tex.bitsperpixel, &game->s_tex.linesize,
			&game->s_tex.endian);
	game->e_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.east_texture, &game->e_tex.img_width,
			&game->e_tex.img_height);
	game->e_tex.img_data = (int *)mlx_get_data_addr(game->e_tex.img_ptr,
			&game->e_tex.bitsperpixel, &game->e_tex.linesize,
			&game->e_tex.endian);
	game->w_tex.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->textures.west_texture, &game->w_tex.img_width,
			&game->w_tex.img_height);
	game->w_tex.img_data = (int *)mlx_get_data_addr(game->w_tex.img_ptr,
			&game->w_tex.bitsperpixel, &game->w_tex.linesize,
			&game->w_tex.endian);
}

void	check_argv(char **argv)
{
	int			len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u'
		|| argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
		print_error_and_exit("File need to have .cub at the back\n");
}

void	import_data(t_game *game, char **argv)
{
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error_and_exit("Error: invalid file\n");
	game->filedata = readfile(fd);
	get_game_data(game);
}