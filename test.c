/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:27:37 by rui               #+#    #+#             */
/*   Updated: 2023/08/09 15:51:56 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    change_map(t_mlx *vars, char *map_name)
{
    mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
    free(vars->map.map_lines);
    vars->map = read_map(map_name);
    vars->map.map_lines = split_map(vars->map, map_name);
    put_map(vars);
}