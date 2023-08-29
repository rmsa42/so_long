/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:02:23 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/29 15:01:38 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_sprite
{
	int		curr_x;
	int		curr_y;
	int		coin_count;
	void	*image;
}				t_sprite;

typedef struct s_map
{
	int		x;
	int		y;
	char	**map_lines;
}				t_map;

typedef enum s_id
{
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	Esc = 65307,
	P = 2,
	C = 3,
	E = 4
}		t_id;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprite	sprites[5];
	t_map		map;
}				t_mlx;

void	change_map(t_mlx *game, char *map_name);
void	check_map_pce(t_mlx *game);
char	**map_array(t_mlx *game, char *map_name);
void	init_sprites(t_mlx *game);
void	put_map(t_mlx *game);
int		key_press(int key, t_mlx *game);
void	check_map(t_mlx *game);
int		ft_strlen_sl(char *str);
void	close_game(t_mlx *game);
void	error(t_mlx *game);

#endif