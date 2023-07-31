/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/31 17:04:09 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int key, t_mlx *vars)
{
	if (key == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		exit(0);
	}
	printf("%d\n", key);
	return (0);
}



int main(int argc, char *argv[])
{
	t_mlx	vars;
	t_map	map_info;
	t_player	player;
	
	if (argc == 2)
	{
		vars.mlx_ptr = mlx_init();
		map_info = read_map(argv[1]);
		printf("%d %d\n", map_info.x, map_info.y);
		vars.win_ptr = mlx_new_window(vars.mlx_ptr, map_info.x * 42, map_info.y * 42, "so_long");

		put_map(&vars, map_info, &player, argv[1]);
		mlx_key_hook(vars.win_ptr, key_press, &vars);
		mlx_loop(vars.mlx_ptr);
	}
	return (0);
}
