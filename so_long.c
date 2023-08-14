/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/14 16:33:01 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *vars)
{
	close_game(vars);
	return (0);
}

int main(int argc, char *argv[])
{
	t_mlx	vars;

	vars.sprites[C].coin_count = 0;
	if (argc == 2)
	{
		vars.mlx_ptr = mlx_init();
		read_map(&vars, argv[1]);
		/* check_map(vars.map, &vars); */
		vars.map.map_lines = split_map(vars.map, argv[1]);
		init_sprites(&vars);
		vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.map.x * 42, vars.map.y * 42, "so_long");
		put_map(&vars);
		mlx_hook(vars.win_ptr, 2, KeyPressMask, key_press, &vars);
		mlx_hook(vars.win_ptr, DestroyNotify, 0, close_window, &vars);
		mlx_loop(vars.mlx_ptr);
	}
	return (0);
}
