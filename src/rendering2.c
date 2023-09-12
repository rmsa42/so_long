/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:22:52 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/04 14:47:32 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_mlx *game)
{
	game->sprites[0].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/path.xpm",
			&game->sprites[0].curr_x, &game->sprites[0].curr_y);
	game->sprites[1].image = mlx_xpm_file_to_image(game->mlx_ptr, 
			"sprites/wall.xpm",
			&game->sprites[1].curr_x, &game->sprites[1].curr_y);
	game->sprites[P].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/player.xpm",
			&game->sprites[P].curr_x, &game->sprites[P].curr_y);
	game->sprites[C].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/coin.xpm",
			&game->sprites[C].curr_x, &game->sprites[C].curr_y);
	game->sprites[E].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/exit.xpm",
			&game->sprites[E].curr_x, &game->sprites[E].curr_y);
}

void	put_map2(t_mlx *game, int x, int y)
{
	if (game->map.map_lines[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[0].image, x * 42, y * 42);
	else if (game->map.map_lines[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[1].image, x * 42, y * 42);
	else if (game->map.map_lines[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[P].image, x * 42, y * 42);
		game->sprites[P].curr_x = x;
		game->sprites[P].curr_y = y;
	}
	else if (game->map.map_lines[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[C].image, x * 42, y * 42);
	}
	else if (game->map.map_lines[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[E].image, x * 42, y * 42);
}

void	put_map(t_mlx *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map_lines[y])
	{
		x = 0;
		while (game->map.map_lines[y][x])
		{
			put_map2(game, x, y);
			x++;
		}
		y++;
	}
}
