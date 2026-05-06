/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:21:10 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/06 09:32:27 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_handler.h"
#include "libft.h"

int add_link(t_room *from, t_room *to) {
    t_link *link = malloc(sizeof(t_link));

    if (!link)
        return 0;

    *link = (t_link) {
        .to = to, .next = from->links,
    };
    from->links = link;
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
    if (!add_link(room1, room2) || !add_link(room2, room1)) {
        error_exit(farm);
    }
}