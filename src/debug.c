/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:55:34 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 19:07:32 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "struct.h"
#include "ft_printf.h"
#include "algorithms.h"

void print_queue_for_debug(t_farm *farm) {
    t_queue *q;
    t_room  *room;

    q = queue_create(farm->room_count);

    // 모든 방을 enqueue
    room = farm->rooms;
    while (room) {
        enqueue(q, room);
        room = room->next;
    }

    // 다시 dequeue 해서 출력
    ft_printf("=== Queue test ===\n");
    while (!queue_is_empty(q))
    {
        room = dequeue(q);
        ft_printf("dequeued: %s\n", room->name);
    }

    queue_destroy(q);
}

void print_path_for_debug(t_path *path) {
    if (!path) {
        ft_printf("경로 없음\n");
        return ;
    }

    ft_printf("경로 (길이 %d): ", path->length);
    int i = 0;
    while (i < path->length) {
        ft_printf("%s", path->rooms[i]->name);
        if (i < path->length - 1)
            ft_printf(" -> ");
        i++;
    }
    ft_printf("\n");
}


void print_room_list_for_debug(t_farm *farm) {
    ft_printf("count: %d\n", farm->number_of_ants);

    t_room *current;

    if (!farm || !farm->rooms)
        ft_printf("출력할 수 있는 방 없음\n");
    
    current = farm->rooms;

    while (current != NULL) {
        ft_printf("%s: (%d, %d)\n", current->name, current->x, current->y);
        current = current->next;
    }
}

void print_room_link_for_debug(t_farm *farm) {
    t_room *curr_room;
    t_link *curr_link;

    if (!farm || !farm->rooms) {
        ft_printf("출력할 연결 정보 없음\n");
        return;
    }

    curr_room = farm->rooms;
    while (curr_room != NULL) {
        ft_printf("Room [%s] 연결된 엣지: ", curr_room->name);
        
        curr_link = curr_room->links;
        if (curr_link == NULL) {
            ft_printf("없음");
        } else {
            while (curr_link != NULL) {
                // curr_link->to는 연결된 상대방 t_room의 포인터
                ft_printf("%s", curr_link->to->name);
                
                curr_link = curr_link->next;
                if (curr_link != NULL)
                    ft_printf(", "); // 다음 연결이 있으면 쉼표 표시
            }
        }
        ft_printf("\n");
        curr_room = curr_room->next;
    }
}