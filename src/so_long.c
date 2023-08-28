/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/28 14:23:56 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *game)
{
	close_game(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	game;

	game.sprites[C].coin_count = 0;
	if (argc == 2)
	{
		game.mlx_ptr = mlx_init();
		game.map.map_lines = map_array(&game, argv[1]);
		if (game.map.map_lines == NULL)
			return (1);
		check_map(&game);
		init_sprites(&game);
		game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.x * 42,
				game.map.y * 42, "so_long");
		put_map(&game);
		mlx_hook(game.win_ptr, 2, KeyPressMask, key_press, &game);
		mlx_hook(game.win_ptr, DestroyNotify, 0, close_window, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}
