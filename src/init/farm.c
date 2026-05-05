/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:53:04 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 16:02:40 by taebkim          ###   ########.fr       */
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
    farm->number_of_ants = 0;
    farm->rooms = NULL;
    farm->room_count = 0;
    farm->start = NULL;
    farm->end = NULL;
    farm->next_room_role = ROLE_NORMAL; 
    return farm;
}
