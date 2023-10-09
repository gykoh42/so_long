/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:37:53 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/09 12:49:34 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

struct s_game
{   
    void    *mlx;
    void    *win;

    int     C_cnt;
    int     C_route_cnt;
    int     P_cnt;
    int     P_idx_x;
    int     P_idx_y;
    int     E_cnt;
    
    char    **map;
    int     map_width;
    int     map_height;
    
    int     move_cnt;
};

void    error_exit(char *str);
void    init_game(struct s_game *game);
void    get_map(char *argv, struct s_game *game);
void	size_check(struct s_game *game);
void    wall_check(struct s_game *game);
void    component_check(struct s_game *game);
void    component_cnt_check(struct s_game *game);
void    path_dfs(struct s_game *game, int row, int col);
void    path_check(struct s_game *game);
void    map_total_check(struct s_game *game);

#endif