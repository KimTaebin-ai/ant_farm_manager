/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:26:25 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 16:30:13 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error_handler.h"
#include "struct.h"

int validate_farm(t_farm *farm) {
    if (farm->number_of_ants <= 0)
        return 0;
    if (!farm->start)
        return 0;
    if (!farm->end)
        return 0;
    if (farm->room_count < 2)
        return 0;
    return 1;
}