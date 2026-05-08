/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:37:35 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/08 11:26:37 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

#include "struct.h"

t_queue *queue_create(int capacity);
void queue_destroy(t_queue *q);
void enqueue(t_queue *q, t_room *room);
t_room *dequeue(t_queue *q);
int queue_is_empty(t_queue *q);

// utils
void reset_visited(t_farm *farm);
int residual_capacity(t_link *link);

// for ant
t_ant *create_ants(t_farm *farm, t_path *path);
void run_ant_simulation(t_farm *farm, t_path *path);

// main logic
int bfs(t_farm* farm);
t_path *extract_path(t_farm *farm);

#endif