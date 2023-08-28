/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:22:52 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/28 14:24:18 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
