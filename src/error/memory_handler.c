/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:51:46 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 16:33:47 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error_handler.h"
#include "struct.h"

void free_tokens(char **tokens) {
    int i;
    if (!tokens)
        return ;
    i = 0;
    while (tokens[i]) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

void free_links(t_link *links)
{
    t_link *current;
    t_link *next;

    current = links;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_rooms(t_room *rooms)
{
    t_room *current;
    t_room *next;

    current = rooms;
    while (current)
    {
        next = current->next;
        free_links(current->links);
        free(current->name);
        free(current);
        current = next;
    }
}

void free_farm(t_farm *farm) {
    if (!farm)
        return ;
    free_rooms(farm->rooms);
    free(farm);
}

void error_exit(t_farm *farm) {
    write(2, "ERROR\n", 6);
    free_farm(farm);
    exit(1);
}