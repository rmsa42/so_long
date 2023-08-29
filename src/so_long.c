/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/29 19:02:23 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int esc_close_window(t_mlx *game)
{
	close_game(game);
	return (0);
}

int main(int argc, char *argv[])
{
	t_mlx game;

	game.sprites[C].coin_count = 0;
	if (argc == 2)
	{
		game.mlx_ptr = mlx_init();
		game.map.map_lines = map_array(&game, argv[1]);
		if (game.map.map_lines == NULL)
		{
			mlx_destroy_display(game.mlx_ptr);
			free(game.mlx_ptr);
			ft_printf("Error\nInvalid Map\n");
			exit(1);
		}
		check_map(&game);
		init_sprites(&game);
		game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.x * 42,
									  game.map.y * 42, "so_long");
		put_map(&game);
		mlx_hook(game.win_ptr, 2, KeyPressMask, key_press, &game);
		mlx_hook(game.win_ptr, DestroyNotify, 0, esc_close_window, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}
