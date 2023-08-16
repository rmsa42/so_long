/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:08:30 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/16 15:35:33 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_mlx *vars)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_destroy_image(vars->mlx_ptr, vars->sprites[i++].image);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	i = 0;
	while (vars->map.map_lines[i])
		free(vars->map.map_lines[i++]);
	free(vars->map.map_lines);
	free(vars->mlx_ptr);
	exit(0);
}

void	error(t_mlx *vars)
{
	int	i;

	i = 0;
	mlx_destroy_display(vars->mlx_ptr);
	while (vars->map.map_lines[i])
		free(vars->map.map_lines[i++]);
	free(vars->map.map_lines);
	free(vars->mlx_ptr);
	ft_printf("Error\nInvalid Map\n");
	exit(1);
}
