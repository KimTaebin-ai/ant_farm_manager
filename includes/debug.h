/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:05:33 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 19:13:09 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "struct.h"
#include "algorithms.h"

// for debug
void print_queue_for_debug(t_farm *farm);
void print_path_for_debug(t_path *path);
void print_room_list_for_debug(t_farm *farm);
void print_room_link_for_debug(t_farm *farm);


#endif