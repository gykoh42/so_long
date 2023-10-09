/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_total_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:42:46 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/09 12:43:03 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_total_check(struct s_game *game)
{
    size_check(game);
    wall_check(game);
    component_check(game);
    component_cnt_check(game);
    path_check(game);
}