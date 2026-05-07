/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:39:57 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/07 20:56:14 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algorithms.h"
#include "ft_printf.h"

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