/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:48:11 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 20:01:43 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "algorithms.h"
#include "struct.h"
#include "error_handler.h"
#include "ft_printf.h"

int simulate_one_turn(t_ant *ants, int ant_count) {
    int     i;
    int     printed;             // 이번 턴에 뭔가 출력했는지
    int     all_arrived;         // 모두 도착했는지
    int     started_this_turn;   // 이번 턴에 start 에서 출발한 개미 있는지
    t_room  *next_room;

    printed = 0;
    all_arrived = 1;
    started_this_turn = 0;

    i = 0;
    while (i < ant_count) {
        // (1) 이미 end 에 도착한 개미는 건너뜀
        if (ants[i].position >= ants[i].path->length - 1) {
            i++;
            continue;
        }

        // 도착 안 한 개미가 있음 = 아직 안 끝남
        all_arrived = 0;

        // (2) start 에 있는 개미는 한 턴에 1마리만 출발 가능
        if (ants[i].position == 0) {
            if (started_this_turn) {
                i++;
                continue;
            }
            started_this_turn = 1;
        }

        // (3) 한 칸 전진
        ants[i].position++;
        next_room = ants[i].path->rooms[ants[i].position];

        // (4) 출력: "Lid-방이름"
        if (printed)
            ft_printf(" ");
        ft_printf("L%d-%s", ants[i].id, next_room->name);
        printed = 1;

        i++;
    }

    if (printed)
        ft_printf("\n");

    return (all_arrived);
}

t_ant *create_ants(t_farm *farm, t_path *path) {
    t_ant *ants;
    
    ants = malloc(sizeof(t_ant) * farm->number_of_ants);
    if (!ants)
        return NULL;
    int i = 0;

    write(1, "\n", 1);
    while (i < farm->number_of_ants) {
        ants[i].id = i + 1;
        ants[i].path = path;
        ants[i].position = 0;
        i++;
    }
    return ants;
}

void run_ant_simulation(t_farm *farm, t_path *path) {
    t_ant   *ants;
    int     all_arrived;

    ants = create_ants(farm, path);
    if (!ants)
        return ;

    while (1) {
        all_arrived = simulate_one_turn(ants, farm->number_of_ants);
        if (all_arrived)
            break;
    }

    free_ants(ants);
}