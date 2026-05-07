/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:21:10 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/07 20:55:47 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_handler.h"
#include "libft.h"

int add_link(t_room *room1, t_room *room2) {
    t_link *forward;
    t_link *backward;
    
    forward = malloc(sizeof(t_link));
    if (!forward)
        return 0;
    backward = malloc(sizeof(t_link));
    if (!backward) {
        free(forward);
        return 0;
    }
    *forward = (t_link){
        .to = room2,
        .next = room1->links,
        .capacity = 1,
        .flow = 0,
        .reverse = backward
    };
    *backward = (t_link){
        .to = room1,
        .next = room2->links,
        .capacity = 1,
        .flow = 0,
        .reverse = forward
    };

    room1->links = forward;
    room2->links = backward;
    return 1;
}

void parse_link_line(const char *data, t_farm *farm) {
    char **parts;
    t_room *room1;
    t_room *room2;

    parts = ft_split(data, '-');
    
    if (!parts || count_tokens(parts) != 2) {
        free_tokens(parts);
        error_exit(farm);
    }
        
    room1 = find_room_by_name(farm, parts[0]);
    room2 = find_room_by_name(farm, parts[1]);
    free_tokens(parts);
    if (!room1 || !room2 || room1 == room2)
        error_exit(farm);
    
    // 양방향 추가 (undirected graph)
    if (!add_link(room1, room2)) {
        error_exit(farm);
    }
}