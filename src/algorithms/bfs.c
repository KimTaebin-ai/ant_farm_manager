/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:13:19 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 19:44:40 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "algorithms.h"

t_path *extract_path(t_farm *farm) {
    t_path  *path;
    t_room  *current;
    int     i;

    if (!farm->end->parent && farm->start != farm->end)
        return NULL;

    // 경로 길이 계산 (end의 distance + 1 = 방의 개수)
    path = malloc(sizeof(t_path));
    if (!path)
        return NULL;
    path->length = farm->end->distance + 1;
    path->assigned_ants = 0;
    path->rooms = malloc(sizeof(t_room *) * path->length);
    if (!path->rooms) {
        free(path);
        return NULL;
    }

    // end 부터 거꾸로 채우기
    current = farm->end;
    i = path->length - 1;
    
    while (current) {
        path->rooms[i] = current;
        current = current->parent;
        i--;
    }

    return path;
}

int bfs(t_farm* farm) {
    t_queue *q;
    t_room  *current;
    t_link  *link;

    reset_visited(farm);
    q = queue_create(farm->room_count);
    if (!q)
        return 0;

    farm->start->visited = 1;
    enqueue(q, farm->start);

    while (!queue_is_empty(q)) {
        current = dequeue(q);
        if (current == farm->end) {
            queue_destroy(q);
            return 1;  // 경로 찾음
        }
        link = current->links;
        while (link) {
            if (!link->to->visited) {
                link->to->visited = 1;
                link->to->parent = current;
                link->to->distance = current->distance + 1;
                enqueue(q, link->to);
            }
            link = link->next;
        }
    }

    queue_destroy(q);
    return 0; //  경로가 없는 경우
}