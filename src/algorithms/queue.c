/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:37:01 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 17:57:36 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "algorithms.h"

t_queue *queue_create(int capacity) {
    t_queue *q;

    q = malloc(sizeof(t_queue));
    if (!q)
        return NULL;
    q->data = malloc(sizeof(t_room *) * capacity);
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->size = capacity;
    return q;
}

void queue_destroy(t_queue *q) {
    if (!q)
        return ;
    free(q->data);
    free(q);
}

void enqueue(t_queue *q, t_room *room) {
    if (!q || q->tail >= q->size)
        return ;
    q->data[q->tail] = room;
    q->tail++;
}

t_room *dequeue(t_queue *q) {
    t_room  *room;

    if (!q || q->head >= q->tail)
        return NULL;
    room = q->data[q->head];
    q->head++;
    return room;
}

int queue_is_empty(t_queue *q) {
    if (!q)
        return 1;
    return (q->head >= q->tail);
}