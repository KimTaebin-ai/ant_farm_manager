/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:23:11 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 16:41:54 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"
#include "parser.h"
#include "libft.h"
#include "ft_printf.h"

t_room *create_room(const char *name, int x, int y) {
    t_room *room;
    room = malloc(sizeof(t_room));

    if (!room)
        return NULL;
    room->name = ft_strdup(name);
    if (!room->name) {
        free(room);
        return NULL;
    }
    room->x = x;
    room->y = y;
    room->is_start = 0;
    room->is_end = 0;
    room->links = NULL;
    room->next = NULL;
    return room;
}

void add_room_to_farm(t_farm *farm, t_room *room) {
    room->next = farm->rooms;
    farm->rooms = room;
    farm->room_count++;
}

t_room *parse_add_room(const char *data, t_farm *farm) {
    t_room *room;
    
    char **tokens = ft_split(data, ' '); 
    if (!tokens || count_tokens(tokens) != 3) {
        free_tokens(tokens);
        return NULL;
    }
    if (tokens[0][0] == 'L' || tokens[0][0] == '#') {
        free_tokens(tokens);
        return NULL;
    }
    if (!ft_str_is_int(tokens[1]) || !ft_str_is_int(tokens[2])) {
        free_tokens(tokens);
        return NULL;
    }
    if (find_room_by_name(farm, tokens[0])) {
        free_tokens(tokens);
        return NULL;
    }
    
    room = create_room(tokens[0], ft_atoi(tokens[1]), ft_atoi(tokens[2]));
    free_tokens(tokens);
    if (!room)
        return NULL;
    add_room_to_farm(farm, room);
    return room;
}