/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:37:53 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/07 21:20:47 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h" 
# include "../mlx/mlx.h"

struct s_game
{   
    int C_cnt;
    int P_cnt;
    int P_idx_x;
    int P_idx_y;
    int E_cnt;
    
    char **map;
    int map_width;
    int map_height;
    
    int move_cnt;
};

#endif