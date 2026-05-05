/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:21:10 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 16:00:57 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "libft.h"

int add_link(t_room *from, t_room *to) {
    t_link *link = malloc(sizeof(t_link));

    if (!link)
        return 0;

    link->to = to;
    link->next = from->links;
    from->links = link;
    return 1;
}

t_room *find_room_by_name(t_farm *farm, const char *name) {
    t_room *current;

    if (!farm || !name)
        return NULL;
    
    current = farm->rooms;
    while (current != NULL) {
        // 방 이름이 일치하면 해당 방의 포인터를 반환
        if (ft_strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

void parse_link_line(const char *data, t_farm *farm) {
    char **parts;
    t_room *room1;
    t_room *room2;

    parts = ft_split(data, '-');
    
    if (count_tokens(parts) != 2) {
        free_tokens(parts);
        error_exit(farm);
    }
        
    room1 = find_room_by_name(farm, parts[0]);
    room2 = find_room_by_name(farm, parts[1]);
    free_tokens(parts);
    if (!room1 || !room2 || room1 == room2)
        error_exit(farm);
    
    // 양방향 추가 (undirected graph)
    if (!add_link(room1, room2) || !add_link(room2, room1)) {
        free_tokens(parts);
        error_exit(farm);
    }
}