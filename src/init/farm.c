/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:53:04 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/07 20:53:04 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>
#include <stdio.h>

t_farm *init_farm() {
    t_farm *farm;

    farm = malloc(sizeof(t_farm));
    if (!farm)
        return NULL;
    *farm = (t_farm){
        .number_of_ants = 0,
        .rooms = NULL, .room_count = 0,
        .start = NULL, .end = NULL,
        .next_room_role = ROLE_NORMAL,
        .paths = NULL, .path_count = 0
    };
    return farm;
}
