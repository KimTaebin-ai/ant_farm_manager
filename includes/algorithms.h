/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:37:35 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/07 21:05:55 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

#include "struct.h"

typedef struct s_queue {
    t_room **data;
    int head;
    int tail;
    int size;
} t_queue;

typedef struct s_path {
    t_room **rooms;    // 경로 상의 방 배열
    int length;        // 경로 길이 (방 개수)
    int assigned_ants; // 이 경로에 할당된 개미 수 (나중에 쓸 것)
} t_path;

typedef struct s_ant {
    int id;
    t_path *path;
    int position;
} t_ant;

t_queue *queue_create(int capacity);
void queue_destroy(t_queue *q);
void enqueue(t_queue *q, t_room *room);
t_room *dequeue(t_queue *q);
int queue_is_empty(t_queue *q);

void reset_visited(t_farm *farm);

// for ant
t_ant *create_ants(t_farm *farm, t_path *path);
void run_ant_simulation(t_farm *farm, t_path *path);

// main logic
int bfs(t_farm* farm);
t_path *extract_path(t_farm *farm);

#endif