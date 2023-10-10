/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:37:53 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 11:33:10 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_img
{
    void    *ground;
    void    *wall;
    void    *collect;
    void    *exit;
    void    *player;
}   t_img_src;

typedef struct s_game
{   
    void        *mlx;
    void        *win;

    int         C_cnt;
    int         C_route_cnt;
    int         P_cnt;
    int         P_idx_x;
    int         P_idx_y;
    int         E_cnt;
    
    char        **map;
    int         map_width;
    int         map_height;
    
    int         move_cnt;
    t_img_src   img;
} t_game_info;

void    error_exit(char *str);
void    init_game(t_game_info *game);
void    get_map(char *argv, t_game_info *game);
void	size_check(t_game_info *game);
void    wall_check(t_game_info *game);
void    component_check(t_game_info *game);
void    component_cnt_check(t_game_info *game);
void    path_dfs(t_game_info *game, int row, int col);
void    path_check(t_game_info *game);
void    map_total_check(t_game_info *game);
void    init_map(char *argv, t_game_info *game);
void    draw_map(t_game_info *game);
void    convert_and_draw(t_game_info *game);

#endif