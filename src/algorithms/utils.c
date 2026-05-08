/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:39:57 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/08 11:22:37 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algorithms.h"
#include "ft_printf.h"

int can_use_room(t_room *room) {
    if (room->is_start || room->is_end)
        return 1;
    return room->in_flow == 0;
}

int residual_capacity(t_link *link) {
    return (link->capacity - link->flow);
}

void reset_visited(t_farm *farm) {
    t_room *current = farm->rooms;

    while (current) {
        current->visited = 0;
        current->distance = 0;
        current->parent = NULL;
        current->parent_link = NULL;
        current = current->next;
    }
}