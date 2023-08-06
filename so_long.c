/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/06 15:34:16 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(int key, t_mlx *vars)
{
	if (key == 115)
	{
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[1].image,
			vars->sprites[2].x * 42, vars->sprites[2].y * 42);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[2].image,
			vars->sprites[2].x * 42, (vars->sprites[2].y + 1) * 42);
		vars->sprites[2].y = vars->sprites[2].y + 1;
	}
	else if (key == 97)
	{
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[1].image,
			vars->sprites[2].x * 42, vars->sprites[2].y * 42);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[2].image,
			(vars->sprites[2].x - 1) * 42, vars->sprites[2].y * 42);
		vars->sprites[2].x = vars->sprites[2].x - 1;
	}
	else if (key == 100)
	{
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[1].image,
			vars->sprites[2].x * 42, vars->sprites[2].y * 42);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[2].image,
			(vars->sprites[2].x + 1) * 42, vars->sprites[2].y * 42);
		vars->sprites[2].x = vars->sprites[2].x + 1;
	}
	else if (key == 119)
	{
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[1].image,
			vars->sprites[2].x * 42, vars->sprites[2].y * 42);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[2].image,
			vars->sprites[2].x * 42, (vars->sprites[2].y - 1) * 42);
		vars->sprites[2].y = vars->sprites[2].y - 1;
	}
}

/* void	free_image(t_mlx *vars)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(vars->sprites[i].image);
		i++;
	}
} */

int key_press(int key, t_mlx *vars)
{
	static int	coin;

	if (key == 65307)
	{
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		/* free_image(vars); */
		free(vars->mlx_ptr);
		exit(0);
	}
	else if (key == 115 || key == 97 || key == 100 || key == 119)
		player_move(key, vars);
	if ((vars->sprites[2].x == vars->sprites[3].x)
			&& (vars->sprites[2].y == vars->sprites[3].y) && coin != 1)
			coin++;
	printf("%d\n", coin);
	printf("%d\n", key);
	return (0);
}



int main(int argc, char *argv[])
{
	t_mlx	vars;
	t_map	map_info;

	if (argc == 2)
	{
		vars.mlx_ptr = mlx_init();
		map_info = read_map(argv[1]);
		printf("%d %d\n", map_info.x, map_info.y);
		vars.win_ptr = mlx_new_window(vars.mlx_ptr, map_info.x * 42, map_info.y * 42, "so_long");

		put_map(&vars, map_info, argv[1]);
		mlx_hook(vars.win_ptr, 2, KeyPressMask, key_press, &vars);
		mlx_loop(vars.mlx_ptr);
	}
	return (0);
}
